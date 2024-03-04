#include <stdio.h>  //编译预处理，引用标准函数库中的输入输出
#include <stdlib.h> //引用杂项函数及内存分配函数
#include <time.h>   //引用时间处理函数
#include <math.h>   //引用数学函数
#include <string.h> //引用字符串处理函数

#define LOGICAL_ADDRESS_BITS 32
#define PHYSICAL_ADDRESS_BITS 24
#define PAGE_SIZE 2048 // 2KB
#define OFFSET_BITS 11 // 由于页大小为2KB，因此偏移量占11位
#define PAGE_NUMBER_BITS (LOGICAL_ADDRESS_BITS - OFFSET_BITS) // 页号所占的位数

typedef unsigned int logical_address;
typedef unsigned int physical_address;

/**
打“<>”这种尖括号，说的是，这个文件是编程环境标配拥有的文件，到默认的标配的地方去找这个文件
打引号，表示这不是编程环境标配拥有的文件，要在你的工程文件所在的目录中找，或是在编程环境设定中要查找的目录中去找。
*/

// 宏定义，不占内存，在编译之前处理，是为常量，不可更改。
#define N 8         // 定义每行的位示图的最大块数，每块128kB，一行为1024KB，也即1M，2的10次方
#define page_len 2  // 页长 2KB
#define blockSize 2 // 块大小2KB

int empty_block = 16; // 空块个数，页框数，这里的大小定义将决定LRU算法是否会执行以及执行的频率
int page;             // 进程页数
int Ltimes;           // 程序时间

typedef struct page_trend
{
  int process_name;
  int page_name;
  int *next;
} pat;

/**
    进程控制块结构体
    包括：进程名称，进程剩余执行时间、进程大小以及下一个进程的地址next
*/
typedef struct PCB
{                  // 进程控制块
  int priority;    // 进程优先级
  int name;        // 进程名称
  int times;       // 进程运行时间
  int p_prioruity; // 进程优先级
  struct PCB *next;
  int sizeKB; // 进程大小
} pcb;
// typedef，为结构体去一个新的名字

/**
    父链表结构体
    包括：
        进程页数
        进程名称
        子链头指针
        下一个父链表地址next
*/
typedef struct pts
{                   // 父链表结构
  int priority;     // 进程优先级
  int process;      // 进程名称
  int p_amount;     // 进程页数
  struct pt *pHead; // 指向子链表头
  struct pts *next; // 指向下一个父链表
} PTS;

/**
    子链表结构体
    包括：
        页号（逻辑地址）
        块号（物理地址）
        最近访问时间
        下一个子链表地址next
*/
typedef struct pt
{ // 子链表（页表）结构

  int p_number; // 页号
  int p_block;  // 块号
  int in_memory;
  int LRUtime; // 进程最近被访问时间
  struct pt *next;
} pt;

// 方法名放在结构体的下方，代码块的上方(记得加分号)。
pcb *Init(void);                                                   // 初始化链表
pcb *create(pcb *head, int num);                                   // 创建单链表
void Traverl_all(pcb *head);                                       // 遍历所有链表信息
void Traverl_one(pcb *p);                                          // 遍历一行链表信息
void init_graph(int g[N][N]);                                      // 1、初始化位示图
void print_graph(int g[N][N]);                                     // 2、打印位示图
PTS *Init_Father_Table(void);                                      // 3、初始化父链
PTS *create_table(pcb *head, PTS *T_head);                         // 4、创建父链
void print_table_one(PTS *T_head);                                 // 5、打印父链表
int isIn(PTS *tp, int amount);                                     // 判断页面是否装入
pt *create_page(int amount, PTS *tp, int i, int j, int g[N][N]);   // 6、创建子链
void init_pageTable(pcb *head, PTS *T_head, int num, int g[N][N]); // 7、初始化页表
void print_table_two(PTS *T_head);                                 // 8、打印子链表
void LRU(int g[N][N], PTS *T_head);                                // 9、LRU淘汰算法
int Sort1(pcb *head);

// 对进程的优先级进行排序
int Sort1(pcb *head) // 参数为头指针，传值时传入头指针的地址
{
  pcb *q, *p, *tail, *temp;
  tail = NULL; // 将链表的尾部置为NULL
  q = head;    // 将链表的头指针地址赋值给q，从而进行操作

  while ((head->next) != tail) // 如果还没跑到链表的尾部，则继续执行
  {
    p = head->next;
    q = head;
    while (p->next != tail) // 链表没跑到尾部，继续执行
    {
      // 将优先级低的进程放到链表的尾部
      if ((p->priority) > (p->next->priority))
      { // 如果p的优先级没有下一个节点的优先级高（优先级的数字越小，优先级越高）
        q->next = p->next;
        temp = p->next->next;
        p->next->next = p;
        p->next = temp;
        p = q->next;
      }
      p = p->next; // 指针后移，继续比较
      q = q->next;
    }
    tail = p;
  }
  // 相当于一个冒泡排序
  head->next->priority += 1;
  return head->next->name;
}

// 核心调度算法
/**
pcb *sch(pcb *head){
    pcb * ptr = head->next;
    while(ptr != NULL){ //有进程
        printf("当前调度进程名： %d, 进程优先级： %d, , 进程剩余运行时间： %d\n", ptr->name, ptr->priority,  ptr->times);

        ptr->priority = ptr->priority + 1;     //运行过的进程优先级降低，防止后面的进程陷入忙等

        ptr->times = ptr->times - 1;             //进程的剩余运行时间减少
        if(ptr->times > 0) {                    //如果当前进程还没运行完，则继续进行优先级排序进行下一轮运行
            Sort1(head);
        } else {
          //进程运行结束，将运行时间置为0，运行态转为结束态（1->0），同时删除该节点
        ptr->times = 0;
            head->next = ptr->next; //进程结束，删除
            printf("当前调度进程名： %d, 进程优先级： %d , 进程剩余运行时间： %d\n", ptr->name, ptr->priority, ptr->times);
        }

    //	printf("list:\n");
    //	Print(head);
    //	printf("\n\n");

    ptr = head->next;//继续从优先级高的进程开始下一轮的调度
    }
    return head;
}
*/

// 初始化进程控制块
// 作用：为进程的头指针申请控件并返回头指针
pcb *Init(void)
{
  pcb *head;                         // 定义表头
  head = (pcb *)malloc(sizeof(pcb)); // 申请空间
  if (head == NULL)
    printf("error!\n");

  head->next = NULL;
  return (head);
}

// 随机生成指定数量的进程的基本信息
pcb *create(pcb *head, int num)
{             // 进程控制块头指针，进程数量
  int i;      // 进程个数变量
  pcb *p, *q; // 创建两个进程控制块指针

  if (num > 10)
  { // 进程个数超过最大并发度，修正为10并提醒用户
    printf("并发度最大为10,已经将进程个数修正为10");
    num = 10;
  }

  p = head; // p指针指向进程控制块首地址。

  /**
  用法:它初始化随机种子，会提供一个种子，这个种子会对应一个随机数，
  如果使用相同的种子后面的rand()函数会出现一样的随机数，如: srand(1);
  直接使用1来初始化种子。不过为了防止随机数每次重复，常常使用系统时间来初始化，

  当srand()的参数值固定的时候，rand()获得的数也是固定的，
  如果想在一个程序中生成随机数序列，需要至多在生成随机数之前设置一次随机种子。
  即：只需在主程序开始处调用srand((unsigned)time(NULL)); 后面直接用rand就可以了。
  不要在for等循环放置srand((unsigned)time(NULL));
  */
  srand((unsigned)time(NULL)); // 随机数种子

  for (i = 0; i < num; i++)
  {

    q = (pcb *)malloc(sizeof(pcb)); // 为当前进程申请pcb型的堆控件
    q->name = i + 1;                // 生成进程名字
    q->times = rand() % 10 + 1;     // 生成1到10之间的随机整数作为进程的运行时间
    q->sizeKB = 10 * q->times;      // 进行的大小设置为运行时间的十倍（也是随机数）
    q->priority = q->name + 10;     // 设置进程优先级
    q->next = p->next;              // 将进程加入进程链表
    p->next = q;
    p = q; // 指针后移
  }
  return head;
}

// 遍历所有的进程并输出进程的pcb信息
void Traverl_all(pcb *head)
{
  pcb *p;
  p = head->next;
  while (p != NULL)
  {
    printf("%3d     %3d    %3d    \n", p->name, p->times, p->sizeKB);
    p = p->next;
  }
}

// 遍历单个进程的pcb信息
void Traverl_one(pcb *p)
{
  printf(" %3d    %3d    %3d    \n", p->name, p->times, p->sizeKB);
}

// 初始化位示图
// 因为根据计算位示图共有8196块，这里为了执行LRU算法，只打印前两行，也即只分配16个页框
void init_graph(int g[2][N])
{
  int i, j;
  for (i = 0; i < 2; i++)
  {
    for (j = 0; j < N; j++)
    {
      if ((i == 0) && (j == 0 || j == 1))
      { // 前两块被操作系统内核（引导区）占用
        g[i][j] = 1;
      }
      else
      { // 其他的初始化为0
        g[i][j] = 0;
      }
    }
  }

  empty_block -= 2; // 空块被定义为了全局变量：16

  print_graph(g); // 调用打印方法
}

// 打印位示图（1024行太多，这里只打印2行）
void print_graph(int g[2][N])
{
  int i, j;
  printf("--------位示图---------\n");
  for (i = 0; i < 2; i++)
  {
    for (j = 0; j < N; j++)
    {
      printf(" %d ", g[i][j]);
    }
    printf("\n");
  }
  printf("\n剩余块:%d\n", empty_block); // 输出剩余块数（剩余页框数）
  printf("该时刻为：%d\n", Ltimes);
  // printf("\n");
}

// 初始化父链表
PTS *Init_Father_Table(void)
{
  PTS *head; // 定义表头
  head = (PTS *)malloc(sizeof(PTS));
  if (head == NULL)
    printf("error!\n");

  head->next = NULL;
  return (head);
}

// 创建父链表
PTS *create_table(pcb *head, PTS *T_head)
{               // 需传入父链表地址，子链表地址
  pcb *p, *q;   // 进程指针
  PTS *tp, *tq; // 父链表指针
  pt *sHead;    // 子链表指针

  tp = T_head; // 父链表首地址
  p = head;    // 进程链表首地址
  q = p->next;

  while (q != NULL)
  {                                  // 如果进程不为空
    tq = (PTS *)malloc(sizeof(PTS)); // 申请空间

    tq->process = q->name; // 计算进程分页数量
    if (q->sizeKB % 2 == 0)
    { // 进程大小是否能被页大小整除
      tq->p_amount = q->sizeKB / page_len;
    }
    else // 如果不能整除，则要多分一页
      tq->p_amount = (q->sizeKB / page_len) + 1;
    sHead = (pt *)malloc(sizeof(pt)); // 申请空间

    tq->pHead = sHead;      // 将子链表的首地址赋给父链表指向的子链表地址
    tq->pHead->next = NULL; // 末尾标注
    tq->next = tp->next;    // 加入子链表地址
    tp->next = tq;
    tp = tq; // 父链表指向的子链表地址指针后移

    q = q->next; // 进程指针后移
  }
  print_table_one(T_head); // 打印父链表信息
  return T_head;
}

// 打印父链表
void print_table_one(PTS *T_head)
{
  PTS *p;
  p = T_head->next;
  printf("进程名  进程页数\n");
  while (p != NULL)
  {
    printf("  %d         %d\n", p->process, p->p_amount);
    page += p->p_amount;
    p = p->next;
  }
}

// 判断页面是否放入
int isIn(PTS *tp, int amount)
{            // 需传入父链表地址，页号
  pt *p, *q; // 定义两个子链表指针，
  int count2 = 0;

  p = tp->pHead; // 指针从父链表指向子链表头
  q = p->next;   // q指针为p指针后移一位
  while (q != NULL)
  { // 如果父链表中有子链表

    if (q->p_number == amount)
    {                      // 进程页数
      count2++;            // 进程装入标志
      Ltimes++;            // 程序时间++
      q->LRUtime = Ltimes; // 进程最近访问时间
      printf("%d页已经装入\n", amount);
      printf("修改最近访问时间为：%d\n", Ltimes);
      break;
    }
    else
      q = q->next; // 指针后移
  }
  return count2; // 返回1为已经装入，返回0为没有装入
}

// 创建子链
// 需传入页号，父链表节点地址
pt *create_page(int amount, PTS *tp, int i, int j, int g[2][N])
{                // tp表示父链表上的一个结点
  pt *p, *q;     // 子链表指针
  int count2;    // 当前页是否在工作集中
  p = tp->pHead; // 从父链表处获得子链表首地址
  q = p->next;   // 指针后移

  int len; // 进程页数
  // int time;
  int block; // 块号

  len = tp->p_amount; // 进程页数

  // 页表中已经存在该页面，只需要修改时间
  count2 = isIn(tp, amount);

  q = p->next;

  // 页面不在当前的页框中存在
  while (len > 0 && count2 == 0)
  {
    if (p->next == NULL)
    {
      block = i * N + j;
      g[i][j] = 1;
      empty_block--;                // 空块数量减少
      q = (pt *)malloc(sizeof(pt)); // 申请空间
      q->p_number = amount;         // 修改进程信息
      q->p_block = block;
      Ltimes++;            // 系统时间++
      q->LRUtime = Ltimes; // 修改被调用时间
      q->next = p->next;   // 将进程加入进程列表
      p->next = q;
      p = q;
      break;
    }
    else
    {
      p = p->next; // 指针后移
      len--;       // 进程页数--，装入别的页
    }
  }

  return tp->pHead;
}

// 初始化页表
/**
    执行的进程号为随机生成
    调页为随机调页
    有空块（页框）则直接装入最近的页框
    没空块则执行LRU算法（淘汰最近距离现在最久没有使用的页）
*/
void init_pageTable(pcb *head, PTS *T_head, int num, int g[2][N])
{
  PTS *p, *q;
  int process_number; // 进程名称
  int amount;         // 页数
  int i, j;
  p = T_head;
  // 进程号只有随机生成才能执行全局替换LRU算法

  process_number = Sort1(head); // 随机生成要执行的进程号[1,num]
  printf("\n当前要执行进程%d\n", process_number);
  p = T_head;
  q = p->next;
  while (q != NULL)
  { // 如果父链表不为空
    if (q->process == process_number)
    {                                // 如果当前父链表指向的是当前要执行的进程
      amount = rand() % q->p_amount; //[0,p_amount-1] 随机挑出该进程中的一页进行执行。
      printf("当前执行页%d\n", amount);

      if (empty_block > 0)
      { // 如果当前空块（页框）仍有剩余

        for (int c = 2; c < 2 * N; c++)
        {            // 查找空块，0,1已经被OS内核占用
          i = c / N; // 行数
          j = c % N; // 列数
          if (g[i][j] == 0)
          {
            create_page(amount, q, i, j, g);
            break;
          }
        }
      }

      else
      { // 没有空块，执行置换算法
        int count1;
        count1 = isIn(q, amount);
        if (count1 == 0)
        {
          printf("\n!!!!     执行LRU进行页面替换     !!!!\n");
          LRU(g, T_head);
          printf("!!!!     页面替换完成     !!!!\n");
          printf("\n");

          for (int c = 2; c < 2 * N; c++)
          { // 将替换进入的进程装入
            i = c / N;
            j = c % N;
            if (g[i][j] == 0)
            {
              create_page(amount, q, i, j, g);
              break;
            }
          }
        }
      }
    }
    q = q->next;
  }
}

// 打印
void print_table_two(PTS *T_head)
{
  PTS *p;
  pt *pp;
  p = T_head->next;

  while (p != NULL)
  {
    printf("\n进程名  进程页数  \n");

    printf(" %d         %d\n", p->process, p->p_amount);
    printf("页号  块号  最近使用时间\n");
    pp = p->pHead->next;
    while (pp != NULL)
    {
      printf(" %2d     %2d      %2d\n", pp->p_number, pp->p_block, pp->LRUtime);
      pp = pp->next;
    }
    p = p->next;
  }
}

// LRU淘汰算法
void LRU(int g[2][N], PTS *T_head)
{ // 只要使用过就放到队尾，优先淘汰链表前面的
  PTS *p, *q, *r;
  pt *pp, *qq;
  pt *pp1, *qq1;
  p = T_head;
  q = p->next;
  r = q;
  int shortime = 100;
  int process;
  while (q != NULL)
  { // 找出距离上次访问间隔最久的进程
    pp = q->pHead;
    qq = pp->next;
    while (qq != NULL)
    {
      if (qq->LRUtime < shortime)
      {
        shortime = qq->LRUtime;
        process = q->process;
      }

      qq = qq->next;
    }
    q = q->next;
  }
  printf("当前置换：进程 %d\n", process); // 将列表最前面的进程置换出去。
  while (r != NULL)
  {
    if (r->process == process)
    {                 // 如果当前指针指向的进程是要被置换的进程则进行置换，否则指针后移
      pp1 = r->pHead; // 页表首地址
      qq1 = pp1->next;

      while (qq1 != NULL)
      { // 页表链表不为空

        if (qq1->LRUtime == shortime)
        {

          int p_block;
          int i, j;
          p_block = qq1->p_block;
          printf("          页号 %d,块号 %d   \n", qq1->p_number, qq1->p_block);
          i = p_block / N;
          j = p_block % N;

          Ltimes++;
          qq1->LRUtime = Ltimes;
          g[i][j] = 0;
          empty_block++;
          printf("\n****LRU位示图****\n");
          print_graph(g);

          break;
        }
        qq1 = qq1->next;
      }
      break;
    }

    r = r->next;
  }
}

/**
  最后输出的页表被淘汰的页也会被打印出来，因为被调用过就会加入页表，
  而已经加入的页只会更新最近被调用时间
*/
void input(pcb *head, int num)
{

  create(head, num);
  printf("\nInitial state\n");
  printf("进程名 进程需要执行时间  进程大小(KB)\n");
  printf("------------------------------------ \n");
  Traverl_all(head);
}

void handle_page_fault(PTS *process_table, int page_number)
{
  int frame = find_free_frame();
  if (frame == -1)
  {
    frame = replace_page_LRU(process_table);
  }
  load_page_into_frame(page_number, frame);
  update_page_table(process_table, page_number, frame);
}

int logical_to_physical(int logical_address, PTS *process_table)
{
  int page_number = logical_address / PAGE_SIZE;
  int offset = logical_address % PAGE_SIZE;
  pt *page_entry = find_page_entry(process_table, page_number);

  if (page_entry == NULL || page_entry->in_memory == 0)
  {
    // 缺页中断处理
    handle_page_fault(process_table, page_number);
    page_entry = find_page_entry(process_table, page_number);
  }

  return page_entry->p_block * PAGE_SIZE + offset;
}

int main()
{

  pcb *head;
  PTS *thead;

  int num;
  int G[2][N];
  int choice = 1;
  int i;

  printf("                     ----------------------------存储管理子系统------------------------------\n");

  while (choice != 0)
  {
    printf("\n1.退出程序        2.进入存储管理子系统 \n ");
    printf("                     ----------------------------**************------------------------------\n");
    printf("请输入您的选择：");
    scanf("%d", &choice);
    head = Init();

    switch (choice)
    {
    case 1:
      printf("\n 程序运行结束，再见！");
      choice = 0;
      break;
    case 2:
      printf("\n 请输入进程数目:");
      scanf("%d", &num);
      input(head, num); // 输出随机生成的进程
      Ltimes = 0;
      init_graph(G); // （324行）初始化位示图
      thead = Init_Father_Table();
      create_table(head, thead); // 创建父链表（进程名称、进程页数（根据计算得出）、进程对应的页表地址）

      printf("\n要处理页的个数为:%d\n", page); // 输出要处理的进程页数之和（page为全局变量）
      for (i = 0; i < page; i++)
      {
        init_pageTable(head, thead, num, G); // 调页
        print_graph(G); // 打印位示图观察执行情况
      }
      print_table_two(thead); // 打印进程被调页的情况（这里的调页每个进程由于随机调页所以打印的输出的页表不会涵盖所有的页）

      break;
    default:
      printf("选择错误！\n");
      break;
    }
  }
  return 0;
}