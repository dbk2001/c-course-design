#ifndef _GOBANG_H_
#define _GOBANG_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include<vector>
#include <Windows.h>

using namespace std;

const int N = 15;		//15*15的棋盘
const int flag1 = 1;	//玩家1或电脑标志
const int flag2 = 2;	//玩家2标志

/*坐标*/
typedef struct Position	
{
	int row;	//行
	int col;	//列
}Position;

#endif
