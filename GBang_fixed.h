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

/*构建动态二维数组*/
vector< int > Array;
vector< vector<int> > _iChessBoard;

class GoBang	//五子棋类
{
public:
	void Play();//开始下棋

protected:
	void InitChessBoard();//初始化棋盘
	int ChooseMode();//选择模式
	void PrintChessBoard();//打印棋盘
	void ComputerChess(Position& pos, char flag);//电脑走
	void PlayChess(Position& pos, int player, char flag);//玩家走			 
	int JudgeVictory(Position pos, int player);//判断是否有玩家获胜（底层判断）
	bool GetVictory(Position& pos, int player, char flag);//判断具体获胜玩家
};

#endif
