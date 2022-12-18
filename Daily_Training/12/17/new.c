#include <stdio.h>
int main() {
  int n, q, i = 0, count = 1, flag = 0, m;
  scanf("%d %d", &n, &m);//输入人数
  getchar();
  q = 3;
  int a[n];
  for (i = 0; i < n; i++) {//给每个人设置“生”的状态
    a[i] = 0;
  }
  i = 0;
  int ans = 0;
  int res;
  while (1) {
    ans++;
    if (flag == n - 1) break;//当只剩下一个人时，跳出循环
    if (a[i] == 1) i++;//如果该人为死亡的状态，则跳过该人
    else {
      if (count == q) {//满足被杀死的条件
        a[i] = 1;//设置死亡状态
        flag++;//死亡人数加一
        if (i == m - 1) {
          res = flag;
        }
        count = 1;//重置报数
        i++;//移动到下一个人开始
      } else {//不满足被杀死的状态
        count++;//继续报数
        i++;
      }
    }
    if (i == n) i = 0;//由于数组下标从0开始，所以当i=n时，应该是移动到第一个人了
  }
  printf("%d", res);
  return 0;
}