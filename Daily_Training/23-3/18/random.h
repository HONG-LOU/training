#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int som()
{
    srand((int)time(0));  // 产生随机种子  把0换成NULL也行
    return rand() % 1000;
}

int soom()
{
    srand((int)time(0));  // 产生随机种子  把0换成NULL也行
    return rand() % 100;
}