#ifndef _AIchess_H_
#define _AIchess_H_

#include"GoBang.h"


//point结构体，用来表示点的坐标
struct point{
    int col;
    int row;
}; 


//drctn结构体，用来表示向量
//其可以将4个方向用一个简单的drctn d的方向变量来处理
struct drctn{
    int dy;
    int dx;
};

//定义四个常量向量
const drctn d1 = {0, 1};//横
const drctn d2 = {1, 0};//竖 
const drctn d3 = {1, -1};//右斜 
const drctn d4 = {1, 1};//左斜


class operate:public GoBang{
private: 
    int m_person;//玩家棋子 
    int m_computer;//电脑棋子 
    point m_luozi;//落子位置 ，包含横纵坐标
public:
/***************************
构造函数
析构函数
****************************/
	operate();
	~operate() {};
	
	
/*************************
参数：int i， GoBang &g
返回值：void
功能：人机对战的中心操作
*************************/
    void centrOprt(int n, GoBang &g);
	

/************************************
参数：GoBang &g
返回值：void
功能：电脑操作部分，调用calScore()函数
统计每个空位置的最大分值，决定进攻或防守
方式
*************************************/
    void comptrOprt(GoBang &g);


/**************************************
参数：GoBang &g
返回值：1或0
功能：判断游戏是否结束，即是否连成五子
**************************************/
    bool endJudge(GoBang &g);


protected:
/************************
参数：point p
返回值：1或0
功能：判断p点是否在棋盘内
************************/
    bool inBoardJudge(point p); 


/**********************************
参数：point p,int side，GoBang &g
返回值：int(最高得分)
功能：计算电脑下一步走法的得分，分为
进攻得分和防守得分
**********************************/
    int calScore(point p, int side, GoBang &g);



/**********************************************************
参数：point p为点的位置，int lenth为向量的模，drctn d为单位向量
返回值：point结构体，实际上就是返回一个向量
功能：计算出并返回新的向量
***********************************************************/
    point newPoint(point p, drctn d, int lenth)
	{
    point p1 = {p.col + d.dy * lenth, p.row + d.dx * lenth};
    return p1;
    }
};


#endif
