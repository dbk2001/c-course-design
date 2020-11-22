#include "GoBang.h"

class GoBang	//五子棋类
{
	public:

		/*开始下棋*/
		void Play()
		{
			Position Play1;   //玩家1或电脑
			Position Play2;   //玩家2
			while (1) 
			{
				int mode = ChooseMode();
				while (1) 
				{
					if (mode == 1)		//电脑VS玩家2
					{
						ComputerChess(Play1, flag1);	//电脑走
						if (GetVictory(Play1, 0, flag1))	//为真则电脑获胜，0指电脑
						{
							break;
						}
						PlayChess(Play2, 2, flag2);		//玩家2走
						//PrintChessBoard();
						if (GetVictory(Play2, 2, flag2))	//为真则玩家2获胜，2指玩家2
						{
							break;
						}
					}
					else				//玩家1VS玩家2
					{
						PlayChess(Play1, 1, flag1);		//玩家1走
						//PrintChessBoard();
						if (GetVictory(Play1, 1, flag1))	//为真则玩家1获胜，1指玩家1
						{
							break;
						}
						PlayChess(Play2, 2, flag2);		//玩家2走
						//PrintChessBoard();
						if (GetVictory(Play2, 2, flag2))	//为真则玩家2获胜，2指玩家2
						{
							break;
						}
					}
				}

				/*游戏结束，重新游戏或退出*/
				cout << "======再来一局=======" << endl;
				cout << "yes or no :";
				char s[] = "yes";
				cin >> s;	//输入yes或no
				if (strcmp(s, "no") == 0)	//输入no则退出循环，结束程序
				{
					break;
				}
			}
		}

	protected:

		/*初始化棋盘*/
		void InitChessBoard()
		{
			/*逐一对vector初始化*/
			for (int i = 0; i < N; i++)
			{
				_iChessBoard.push_back(Array);	
				for (int j = 0; j < N; j++)
				{
					_iChessBoard[i].push_back(j);
				}
			}
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					_iChessBoard[i][j] = 0;
				}
			}
		}

        /*选择模式*/
		int ChooseMode() 
		{
			system("cls");	//系统调用，清屏
			InitChessBoard();	//重新初始化棋盘
			cout << "+-------------------------------------------------+" << endl;
			cout << "|-----------------[ 0、退出游戏 ]-----------------|" << endl;
			cout << "|-----------------[1、电脑VS玩家]-----------------|" << endl;
			cout << "|-----------------[2、玩家VS玩家]-----------------|" << endl;
			cout << "+-------------------------------------------------+" << endl;
			while (1) 
			{
				int i = 0;
				cout << "请选择模式：";
				cin >> i;
				if (i == 0)		//退出
				{
					exit(1);
				}
				if (i == 1 || i == 2) 
				{
					return i;	//返回模式对应值到void Play()
				}
				else	//输入非法值
				{
					cout << "非法输入，请重新输入！" << endl;
				}
			}
		}

		/*打印棋盘*/
		void PrintChessBoard()
		{
			//printf("   |---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|\n");
			for (int i = 0; i < N; i++)
			{
				printf("%2d ", i + 1);//打印纵坐标
				/*输出行对应位置符号*/
				for (int j = 0; j < N; j++)
				{
					switch (_iChessBoard[i][j])
					{
						case 0:		//棋盘
							cout << "  . ";
							break;
						case 1:		//玩家1黑棋
							cout << " ○ ";
							break;
						case 2:		//玩家2白棋
							cout << " ● ";
							break;
						case 3:		//光标
							cout << " ╋  ";
							break;
					}
				}
				cout << endl;
				cout << endl;
			}
			printf("     1   2   3   4   5   6   7   8   9  10  11  12  13  14  15\n");	//横坐标
			cout << endl;
		}

		/*电脑走*/
		void ComputerChess(Position& pos, char flag)
		{
		}

		/*玩家走*/
		void PlayChess(Position& pos, int player, char flag) 
		{
			/*初始化光标位置，定位（8，8）*/
			int X = 8 - 1;
			int Y = 8 - 1;

			system("cls");		//清屏
			PrintChessBoard();	//打印棋盘

			/*游戏提示*/
			cout << "玩家" << player << "棋型";
			if (1 == player)
			{
				cout << "○" << "当前位置：" << (Y + 1) << ", " << (X + 1) << endl;
			}
			else if (2 == player)
			{
				cout << "●" << "当前位置：" << (Y + 1) << ", " << (X + 1) << endl;
			}

			/*根据键值执行相应操作*/
			while (1) 
			{
				char c = _getch();
				cout << c;
				//if ('w' == c) 
				if ('H' == c)	//↑键
				{
					if (Y != 0) 
					{
						Y--;
						if (_iChessBoard[Y][X] != 1 && _iChessBoard[Y][X] != 2)
						{
							_iChessBoard[Y][X] = 3;
						}
					}
				}
				//else if ('s' == c) 
				else if ('P' == c)	//↓键
				{
					if (Y != 14) 
					{
						Y++;
						if (_iChessBoard[Y][X] != 1 && _iChessBoard[Y][X] != 2)
						{
							_iChessBoard[Y][X] = 3;
						}
					}
				}
				//else if ('a' == c) 
				else if ('K' == c)	//←键
				{
					if (X != 0) 
					{
						X--;
						if (_iChessBoard[Y][X] != 1 && _iChessBoard[Y][X] != 2)
						{
							_iChessBoard[Y][X] = 3;
						}
					}
				}
				//else if ('d' == c) 
				else if ('M' == c)	//→键
				{
					if (X != 14) 
					{
						X++;
						if (_iChessBoard[Y][X] != 1 && _iChessBoard[Y][X] != 2)
						{
							_iChessBoard[Y][X] = 3;
						}
					}
				}
				else if (13 == c && 3 == _iChessBoard[Y][X])	//Enter键且光标存在，即没有棋子的位置
				{
					pos.row = Y;
					pos.col = X;
					_iChessBoard[Y][X] = player;
					break;
				}

				/*遍历棋盘，清除残留光标*/
				for (int i = 0; i < N; i++)
				{
					for (int j = 0; j < N; j++)
					{
						if (i != Y || j != X)
						{
							if (_iChessBoard[i][j] != 1 && _iChessBoard[i][j] != 2)
							{
								//_ChessBoard[i][j] = ' ';
								_iChessBoard[i][j] = 0;
							}
						}
					}
				}
				system("cls");		//清屏
				PrintChessBoard();	//打印棋盘

				/*游戏提示*/
				cout << "玩家" << player << "棋型";
				if (1 == player)
				{
					cout << "○" << "当前位置：" << (Y + 1) << ", " << (X + 1) << endl;
				}
				else if (2 == player)
				{
					cout << "●" << "当前位置：" << (Y + 1) << ", " << (X + 1) << endl;
				}
			}
			PrintChessBoard();
		}

		/*判断是否有玩家获胜（底层判断）*/
		int JudgeVictory(Position pos, int player)
		{
			int begin = 0;
			int end = 0;

			/*1.判断行是否满足条件*/
			(pos.col - 4) > 0 ? begin = (pos.col - 4) : begin = 1;
			(pos.col + 4) > N ? end = N : end = (pos.col + 4);
			for (int i = pos.row, j = begin; j + 4 <= end; ++j) 
			{
				if (_iChessBoard[i][j] == player && _iChessBoard[i][j + 1] == player &&
					_iChessBoard[i][j + 2] == player && _iChessBoard[i][j + 3] == player &&
					_iChessBoard[i][j + 4] == player)
					return 1;
			}
			/*2.判断列是否满足条件*/
			(pos.row - 4) > 0 ? begin = (pos.row - 4) : begin = 1;
			(pos.row + 4) > N ? end = N : end = (pos.row + 4);
			for (int j = pos.col, i = begin; i + 4 <= end; ++i) 
			{
				if (_iChessBoard[i][j] == player && _iChessBoard[i + 1][j] == player &&
					_iChessBoard[i + 2][j] == player && _iChessBoard[i + 3][j] == player &&
					_iChessBoard[i + 4][j] == player)
					return 1;
			}
			/*3.判断主对角线是否满足条件*/
			int len = 0;    //相对长度
			int start = 0;
			int finish = 0;
			pos.row > pos.col ? len = pos.col - 1 : len = pos.row - 1;
			if (len > 4) 
			{
				len = 4;
			}
			begin = pos.row - len;       //横坐标起始位置
			start = pos.col - len;       //纵坐标起始位置

			pos.row > pos.col ? len = N - pos.row : len = N - pos.col;
			if (len > 4) 
			{
				len = 4;
			}
			end = pos.row + len;         //横坐标结束位置
			finish = pos.col + len;      //纵坐标结束位置

			for (int i = begin, j = start; (i + 4 <= end) && (j + 4 <= finish); ++i, ++j) 
			{
				if (_iChessBoard[i][j] == player && _iChessBoard[i + 1][j + 1] == player &&
					_iChessBoard[i + 2][j + 2] == player && _iChessBoard[i + 3][j + 3] == player &&
					_iChessBoard[i + 4][j + 4] == player)
					return 1;
			}
			/*4.判断副对角线是否满足条件*/
			(pos.row - 1) > (N - pos.col) ? len = N - pos.col : len = pos.row - 1;
			if (len > 4) 
			{
				len = 4;
			}
			begin = pos.row - len;       //横坐标起始位置
			start = pos.col + len;       //纵坐标起始位置

			(N - pos.row) > (pos.col - 1) ? len = pos.col - 1 : len = N - pos.row;
			if (len > 4) 
			{
				len = 4;
			}
			end = pos.row + len;         //横坐标结束位置
			finish = pos.col - len;      //纵坐标结束位置 
			for (int i = begin, j = start; (i + 4 <= end) && (j - 4 >= finish); ++i, --j) 
			{
				if (_iChessBoard[i][j] == player && _iChessBoard[i + 1][j - 1] == player &&
					_iChessBoard[i + 2][j - 2] == player && _iChessBoard[i + 3][j - 3] == player &&
					_iChessBoard[i + 4][j - 4] == player)
					return 1;
			}
			//该位置并未下棋
			for (int x = 0; x < N; x++) 
			{
				for (int y = 0; y < N; y++) 
				{
					if (_iChessBoard[x][y] == 0) 
					{
						return 0;       //未下棋
					}
				}
			}
			return -1;      //和局
		}

		/*判断具体获胜玩家*/
		bool GetVictory(Position& pos, int player, char flag) 
		{
			if (JudgeVictory(pos, player) != 0)	//判断有无人获胜
			{
				if (JudgeVictory(pos, player) == 1)	//判断是否有人获胜,1表示获胜
				{
					PrintChessBoard();		//打印棋盘
					if (player == 0) 
					{
						cout << "电脑获胜！" << endl;
					}
					else 
					{
						printf("恭喜玩家%d获胜！\n", player);
					}
				}
				else 
				{
					printf("和局！\n");
				}
				return true;	//有人获胜
			}
			return false;		//没人获胜
		}

	private:
		vector< int > Array;
		vector< vector<int> > _iChessBoard;	//构建动态二维数组

};

int main()
{
	GoBang g;
	g.Play();
	system("pause");
	return 0;
}
