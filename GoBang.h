#ifndef _GoBang_H_
#define _GoBang_H_

class operate;

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
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
//vector< int > Array;
//vector< vector<int> > _iChessBoard;
//int _iChessBoard[N][N];

class GoBang	//五子棋类
{
	Position Play1;   //玩家1或电脑
	Position Play2;   //玩家2
public:
	int _iChessBoard[N][N];
	GoBang();
	~GoBang() {};
	void Play(operate & WZQ, GoBang & g);//开始下棋
	void PrintChessBoard();//打印棋盘
	void PlayChess(int player, int flag);//玩家走

protected:
	void InitChessBoard();//初始化棋盘
	int ChooseMode();//选择模式
	int JudgeVictory(Position pos, int player);//判断是否有玩家获胜（底层判断）
	bool GetVictory(Position& pos, int player, int flag);//判断具体获胜玩家
};

#endif
