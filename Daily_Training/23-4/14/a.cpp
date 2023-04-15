#include <stdio.h>
#include <string.h>
#define MAXSIZE 100
// 汽车的三项信息
typedef struct
{
  char ch;  // 车辆的识别符，到达or离去
  int time; // 车辆停车时间
  int car;  // 车辆车牌号
} CarData;
// 顺序栈实现停车场
typedef struct
{
  CarData data[MAXSIZE]; // 停车场最大可以停放100量汽车
  int top;
} StopCar;
// 链队实现排队进停车场
typedef struct WaitCar
{
  CarData data[MAXSIZE]; // 等候区最大可以停放100量汽车
  struct WaitCar *next;
} WaitCar;
typedef struct
{
  WaitCar *front;
  WaitCar *rear;
} WaitCarLink;
// 顺序栈实现给临时出来的汽车让路
typedef struct
{
  CarData data[MAXSIZE]; // 临时停车最大可以停放100量汽车
  int top;
} TemporaryCar;

void InitStopCar(StopCar *);           // 停车场初始化
int InitWaitCarLink(WaitCarLink *);    // 初始化等候区
void InitTemporaryCar(TemporaryCar *); // 临时停车初始化

void ArrivalCar(StopCar *, WaitCarLink *, char, int, int); // 入库函数
void DepartureCar(StopCar *, char, int, int);              // 离开函数
int IfTheCar(StopCar *, char);                             // 判断是否有输入的这辆车
void WaitToStop(StopCar *, WaitCarLink *);                 // 将便道上的车进入车库

int n, cost, j = 0, k = 0; // 全局变量 n表示用户输入停车场停放的车  cost用户输入每小时停车的费用
int main()
{
  int car, time = 1; //  time存放时间
  char ch = ' ';     // 车的状态，  car 车牌号
  StopCar sc;        // 停车场
  InitStopCar(&sc);
  WaitCarLink wcl; // 等候区
  InitWaitCarLink(&wcl);
  WaitCar *wc; // 创建节点指针
  printf("请输入停车场可以停放的最大车辆，以及停车每小时收取的费用（元）(用空格间隔)：");
  scanf("%d %d", &n, &cost);
  while (ch != 'E' && time != 0)
  {
    fflush(stdin); // 清除缓存区回车，不然多循环一次
    printf("\n请输入车的状态（A进站,D出站），车的车牌号，车的时间（进站时间,出站时间）(用空格间隔)：");
    scanf("%c %d %d", &ch, &car, &time);
    if (ch == 'A')
      ArrivalCar(&sc, &wcl, ch, car, time);
    else if (ch == 'D')
    {
      DepartureCar(&sc, ch, car, time);
      // if(sc.top+1<n)//车离开后判断车库有没有满，没有满 便道的车进
      WaitToStop(&sc, &wcl); // 不需要判断车库有没有车，当执行出库的时候，车库已经有位置了
    }
    else
    {
      printf("请输入正确的编号,A是进库，D是出库！\n");
    }
  }
  return 0;
}
void WaitToStop(StopCar *sc, WaitCarLink *wcl) // 将便道上的车进入车库
{
  if (wcl->front == wcl->rear) // 便道没有车
    printf("便道没有车！\n");
  else
  {
    // 出队
    WaitCar *S;
    S = wcl->front->next;       // S指向队头
    wcl->front->next = S->next; // S指向的队头出队
    if (wcl->rear == S)         // 如果S是最后一个元素，则让队尾指针指向队头，防止变成野指针
      wcl->rear = wcl->front;
    printf("%d出便道成功！\n", S->data[k].car);
    // 进栈
    sc->data[sc->top + 1].car = S->data[k].car;
    sc->data[sc->top + 1].ch = S->data[k].ch;
    sc->data[sc->top + 1].time = S->data[k].time;
    printf("%d进库成功！\n", S->data[k].car);
    k++;
    sc->top++;
  }
}
void DepartureCar(StopCar *sc, char ch, int car, int time) // 离开函数
{
  // 先确定有没有车和有没有出库的车，如果有，则前面的车出栈到临时的栈里，等需要出来的车出来之后，在顺序进栈
  TemporaryCar tc; // 临时停车
  InitTemporaryCar(&tc);
  int timesum; // 计算时间
  // int i=sc->top;// 如果一辆车，sc的top是0,,,,top怎么改变，先减在加，可以变

  if (sc->top == -1)
    printf("车库没有车！无法离开\n");
  else if (IfTheCar(sc, car))
  {
    printf("车库里没有此车！\n");
  }
  else
  {
    while (sc->data[sc->top].car != car) // 在此车前面的车，依次到临时停车区
    {
      tc.data[tc.top + 1].car = sc->data[sc->top].car;
      tc.data[tc.top + 1].ch = sc->data[sc->top].ch;
      tc.data[tc.top + 1].time = sc->data[sc->top].time;
      tc.top++;
      sc->top--; // 注意是下移,先出
    }
    timesum = time - sc->data[sc->top].time;
    printf("车牌是%d在停车停留的时间是%d，停车费用是%d\n", sc->data[sc->top].car, timesum, timesum * cost);
    sc->top--;           // 将此车出栈
    while (tc.top != -1) // 临时停车区依次进入停车场
    {
      sc->data[sc->top + 1].car = tc.data[tc.top].car;
      sc->data[sc->top + 1].ch = tc.data[tc.top].ch;
      sc->data[sc->top + 1].time = tc.data[tc.top].time;
      tc.top--;
      sc->top++;
    }
  }
}
void ArrivalCar(StopCar *sc, WaitCarLink *wcl, char ch, int car, int time) // 入库函数
{
  // 当停车场满的时候，在输入A的时候，在等候区上
  // WaitCarLink wcl;//等候区,不能在这定义
  // InitWaitCarLink(&wcl);
  WaitCar *wc; // 创建节点指针
  wc = new WaitCar;
  wc->next = NULL;
  if ((sc->top + 1) < n) // 车库没有满
  {
    sc->data[sc->top + 1].ch = ch;
    sc->data[sc->top + 1].car = car;
    // strcpy(sc->data[sc->top+1].car,car);
    sc->data[sc->top + 1].time = time;
    sc->top++;
    printf("\n车牌号是%d的车停的位置是：%d\n", car, sc->top + 1);
  }
  else // 满了，进便道
  {
    wc->data[j].car = car;
    wc->data[j].ch = ch;
    wc->data[j].time = time;
    wc->next = NULL;
    wcl->rear->next = wc;
    wcl->rear = wc;
    printf("车牌号是%d的车在便道上的位置是%d\n", car, j + 1);
    j++;
  }
}
int IfTheCar(StopCar *sc, char car) // 判断是否有输入的这辆车
{
  int i = 0;
  while (i < sc->top + 1)
  {
    if (sc->data[i].car == car)
      return 0;
    i++;
  }
  return 1;
}
void InitStopCar(StopCar *sc) // 停车场初始化
{
  sc->top = -1;
}
int InitWaitCarLink(WaitCarLink *wcl)
{ // 等候区初始化
  wcl->front = new WaitCar;
  if (wcl->front != NULL)
  {
    wcl->rear = wcl->front;
    wcl->front->next = NULL;
    return 0;
  }
  else
    return 1;
}
void InitTemporaryCar(TemporaryCar *tc) // 临时停车初始化
{
  tc->top = -1;
}