#include "GoBang.h"




GoBang::GoBang(ChessBoard board)
{
	this->board = board;
	fileUtil.setPath("save");				//默认设置的存档文件夹为save，可更改为其他
}
GoBang::~GoBang()
{

}
void GoBang::control()
{
	char key;			//用以接收键盘输入
	selectDisplay();
	while (key = _getch())
	{
		switch (key)
		{
		case '1':
			playerMode();			//玩家对战模式
			DrawUtil::clear();
			selectDisplay();
			break;
		case '2':
			computerMode();			//人机对战模式
			DrawUtil::clear();
			selectDisplay();

			break;
		case '3':
			DrawUtil::clear();
			saveMode();				//读档模式
			DrawUtil::clear();
			selectDisplay();
			break;
		case '4':
			exit(0);				//退出程序
		}
	}

}
/*选择界面显示*/
void GoBang::selectDisplay()
{
	/*画边框*/
	DrawUtil::moveCursor(0,0);
	DrawUtil::setText(FOREGROUND_RED | FOREGROUND_GREEN);
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * " <<endl;
	for (int i = 0; i < 29; i++)
	{
		cout << "*                                                                    *" << endl;
	}
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * " << endl;
	DrawUtil::moveCursor(0, 7);
	DrawUtil::setText(FOREGROUND_RED | FOREGROUND_GREEN);
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * " << endl;

	/*写标题*/
	DrawUtil::setText( FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
	DrawUtil::moveCursor(27, 3);
	cout << "五    子    棋";
	DrawUtil::moveCursor(53, 5);
	cout << "Author: yuqiang";
	

	/*写菜单*/
	DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);	
	DrawUtil::moveCursor(5, 10);
	cout << "请  选  择：";

	DrawUtil::moveCursor(10, 14);
	cout << "1、 玩    家    对    战";

	DrawUtil::moveCursor(10, 18);
	cout << "2、 人    机    对    战";

	DrawUtil::moveCursor(10, 22);
	cout << "3、 存    档    读    档";

	DrawUtil::moveCursor(10, 26);
	cout << "4、 退    出    游    戏";

}
/*玩家对战模式*/
void GoBang::playerMode()
{
	int key;						//记录键盘输入的键值
	char firstPlayer;				//记录谁的回合   ‘1’为玩家1   ‘2’为玩家2
	char winPerson = 0;				//记录谁赢		‘1’为玩家1   ‘2’为玩家2
	int returnFlag = 0;				//用来接收下棋函数的返回值， 0表示正常 1表示悔棋 2表示存档	
	string name1, name2;			//玩家1和玩家2的姓名
	Chess* chess = nullptr;			//临时存储的变量



	DrawUtil::clear();
	board.printBoard();
	
	DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
	/*从标准输入中获取玩家1的姓名*/
	DrawUtil::moveCursor(70, 5);
	cout << "请输入玩家1的名称：";	
	getline(cin, name1);
	
	/*从标准输入中获取玩家2的姓名*/
	DrawUtil::moveCursor(70, 7);
	cout << "请输入玩家2的名称：";
	getline(cin, name2);
	
	/*初始化两个玩家对象*/
	PeoplePlayer player1(name1);
	PeoplePlayer player2(name2);
	
	while(1)
	{
		DrawUtil::clear();
		board.clearBoard();
		board.printBoard();
		DrawUtil::moveCursor(70, 9);

		/*每轮开始时均要选择先手玩家*/
		cout << "请选择先手玩家: \t玩家1\t玩家2";
		while ((firstPlayer = _getch()) != '1' && firstPlayer != '2'){} //while循环保证输入为1或2


		DrawUtil::clear();
		board.printBoard();

		/*输出玩家对战信息*/
		DrawUtil::moveCursor(80, 4);
		DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
		cout << "玩家对战模式";
		DrawUtil::moveCursor(60, 7);
		cout << "玩家1：" << name1;
		DrawUtil::moveCursor(60, 9);
		cout << "玩家2：" << name2;
		DrawUtil::moveCursor(60, 11);
		if (firstPlayer == '1')
		{
			cout << "玩家1先手";
		}
		else
		{
			cout << "玩家2先手";
		}
		DrawUtil::moveCursor(60, 21);
		DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
		cout << "操作说明：";
		DrawUtil::moveCursor(60, 23);
		cout << "选择落点：←↑→↓";
		DrawUtil::moveCursor(60, 25);
		cout << "落子：回车键（←┘）";
		DrawUtil::moveCursor(60, 27);
		cout << "按9悔棋，一次最多可悔10步";
		DrawUtil::moveCursor(60, 29);
		cout << "按8存档";

		/*将光标复位在中间*/
		coord.X = 28;
		coord.Y = 14;
		while (1)
		{
			if (firstPlayer == '1')		/*假如是玩家1的回合*/
			{
				DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_RED );
				DrawUtil::moveCursor(100, 7);
				cout <<  "玩家1的回合" ;
				DrawUtil::moveCursor(coord.X, coord.Y);

				do
				{
					returnFlag = player1.nextStep(coord.X, coord.Y, board);	//获取下一步的X和Y值
					if(returnFlag == 0)										//返回值为0才是获取成功，才进行新对象的初始化
						chess = new Chess(0, coord.X / 4, coord.Y / 2);	
				} while (returnFlag == 0 && !board.putChess(chess));		//一直循环，直到一次落子成功

				DrawUtil::moveCursor(80, 14);
				cout << "             ";		//"存档成功"的文字消除
				
				DrawUtil::moveCursor(100, 9);	//悔棋文字消除
				cout << "           ";

				if (board.win())
				{
					winPerson = '1';
					break;
				}

				if (returnFlag == 1)		//返回值为1证明要悔棋了
				{
					returnFlag = 0;
					DrawUtil::setText( FOREGROUND_INTENSITY | FOREGROUND_RED);
					DrawUtil::moveCursor(100, 9);
					cout << "玩家2悔棋了";
					board.regret();
				}
				if (returnFlag == 2)		//返回值为2证明要存档了
				{
					fileUtil.boardSave(board,firstPlayer,player1.getName(),player2.getName());
				}
				turn(firstPlayer);			//每轮结束后要换人

			}
			else if(firstPlayer == '2')		//所有注释和上一样，省略~~~~~~~~~~~~~~~~
			{
				DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_RED);

				DrawUtil::moveCursor(100, 7);
				cout << "玩家2的回合";
				DrawUtil::moveCursor(coord.X, coord.Y);

				do
				{
					returnFlag = player2.nextStep(coord.X, coord.Y, board);
					if( returnFlag==0)
						chess = new Chess(1, coord.X / 4, coord.Y / 2);
				} while (returnFlag == 0 && !board.putChess(chess));

				DrawUtil::moveCursor(100, 9);
				cout << "           ";

				DrawUtil::moveCursor(80, 14);
				cout << "             ";

				if (board.win())
				{
					winPerson = '2';
					break;
				}

				if (returnFlag == 1)
				{
					returnFlag = 0;
					DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_RED);
					DrawUtil::moveCursor(100, 9);
					cout << "玩家1悔棋了";
					board.regret();
				}
				if (returnFlag == 2)
				{
					fileUtil.boardSave(board, firstPlayer, player1.getName(), player2.getName());
				}
				turn(firstPlayer);					
			}
		}
		/*跳出以上循环之后说明有玩家赢了*/
		if (winPerson == '1')
		{
			DrawUtil::moveCursor(60, 16);
			DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_RED);
			cout << player1.getName() << " 胜！！";
		}
		else
		{
			DrawUtil::moveCursor(60, 16);
			DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_RED);
			cout << player2.getName() << " 胜！！";
		}

		/*输出结束菜单*/
		DrawUtil::moveCursor(60, 18);
		DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cout << "按q返回主菜单，其他键开始新的游戏";
		
		if ((key = _getch()) == 'q')	//假如键盘输入q，则直接退出此函数，即返回主菜单，否则重新回到本函数的循环
			return;
	}
}
/*人机对战模式*/
void GoBang::computerMode()
{
	int key;							//获取从键盘中所输入的值
	int row1, colunm1;					//作为传出参数来获得由电脑只能决定的下一步棋的行和列
	char firstPlayer = '1';				//记录这是谁的回合，'1'为玩家，‘2’为电脑
	char winPerson = 0;					//记录谁赢		‘1’为玩家 ‘2’为电脑
	int returnFlag = 0;					//存储返回的结果
	string name1;						//存储玩家的姓名
	Chess* chess = nullptr;				//临时存储

	DrawUtil::clear();
	board.printBoard();

	/*获得玩家1的姓名*/
	DrawUtil::moveCursor(70, 5);
	DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
	cout << "请输入玩家1的名称：";
	getline(cin, name1);

	/*初始化两个对象*/
	PeoplePlayer player1(name1);
	ComputerPlayer player2;

	while (1)
	{
		DrawUtil::clear();
		board.clearBoard();
		board.printBoard();

		/*打印对战菜单*/
		DrawUtil::moveCursor(80, 4);
		DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
		cout << "电脑对战模式";
		DrawUtil::moveCursor(60, 7);
		cout << "玩家1：" << player1.getName();
		DrawUtil::moveCursor(60, 9);
		cout << "玩家2：电脑" ;
		DrawUtil::moveCursor(60, 11);

		firstPlayer = '1';
		if (firstPlayer == '1')
		{
			cout << "玩家1先手";
		}
		else
		{
			cout << "电脑先手";
		}

		DrawUtil::moveCursor(60, 21);
		DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
		cout << "操作说明：";
		DrawUtil::moveCursor(60, 23);
		cout << "选择落点：←↑→↓";
		DrawUtil::moveCursor(60, 25);
		cout << "落子：回车键（←┘）";
		DrawUtil::moveCursor(60, 27);
		cout << "按9悔棋，一次最多可悔10步";
		

		/*光标复位*/
		coord.X = 28;
		coord.Y = 14;
		while (1)
		{
			if (firstPlayer == '1')
			{
				DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_RED);

				DrawUtil::moveCursor(100, 7);
				cout << "玩家1的回合";
				DrawUtil::moveCursor(coord.X, coord.Y);

				do
				{
					returnFlag = player1.nextStep(coord.X, coord.Y, board);
					if (returnFlag == 0)
						chess = new Chess(0, coord.X / 4, coord.Y / 2);
				} while (returnFlag == 0 && !board.putChess(chess));

				DrawUtil::moveCursor(80, 14);
				cout << "             ";	//’存档成功‘的消除
				DrawUtil::moveCursor(100, 9);
				cout << "           ";		//'悔棋'文字消除


				if (board.win())
				{
					winPerson = '1';
					break;
				}
				if (returnFlag == 1)
				{
					returnFlag = 0;
					DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_RED);
					DrawUtil::moveCursor(100, 9);
					cout << "玩家悔棋了";
					board.regret();
					board.regret();

					continue;
				}

				if (returnFlag == 2)
				{
					fileUtil.boardSave(board, firstPlayer, player1.getName(), "电脑");
				}

				turn(firstPlayer);

			}

			else if (firstPlayer == '2')
			{
				DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_RED);

				DrawUtil::moveCursor(100, 7);
				cout << "电脑的回合";

				DrawUtil::moveCursor(coord.X, coord.Y);
				do
				{
					returnFlag = player2.nextStep(row1, colunm1, board.board);	//获得电脑决定下一步棋的row1和column1
					if (returnFlag == 0)
						chess = new Chess(1, row1, colunm1);
				} while (returnFlag == 0 && !board.putChess(chess));

				DrawUtil::moveCursor(100, 9);
				cout << "           ";
				if (board.win())
				{
					winPerson = '2';
					break;
				}
				turn(firstPlayer);
			}
		}
		if (winPerson == '1')
		{
			DrawUtil::moveCursor(60, 16);
			DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_RED);
			cout << player1.getName() << " 胜！！";
		}
		else
		{
			DrawUtil::moveCursor(60, 16);
			DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_RED);
			cout << "电脑" << " 胜！！";
		}

		DrawUtil::moveCursor(60, 18);
		DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cout << "按q返回主菜单，其他键开始新的游戏";
		if ((key = _getch()) == 'q')
			return;
	}
}
/*读档模式*/
void GoBang::saveMode()
{
	char firstFlag = 1;			//一次的标志位，第一次进入while循环时为1，此后都为0
	char firstPlayer;			//记录是谁的回合
	string name1,name2;			//玩家1玩家2的姓名
	fileUtil.boardRead(this->board,firstPlayer,name1,name2);	//读取存档
	int key;					//获得键值
	char winPerson = 0;			//记录谁赢
	int returnFlag = 0;			//下棋函数的返回值接收
	Chess* chess = nullptr;
	PeoplePlayer player1(name1);
	PeoplePlayer player2(name2);

	while (1)
	{
		if (firstFlag == 0)
		{
			DrawUtil::clear();
			board.clearBoard();
			board.printBoard();
		}
		firstFlag = 0;

		/*打印对战信息*/
		DrawUtil::moveCursor(80, 4);
		DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
		cout << "玩家对战模式（读档）";

		DrawUtil::moveCursor(60, 7);
		cout << "玩家1：" << name1;
		DrawUtil::moveCursor(60, 9);
		cout << "玩家2：" << name2;

		DrawUtil::moveCursor(60, 21);
		DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
		cout << "操作说明：";
		DrawUtil::moveCursor(60, 23);
		cout << "选择落点：←↑→↓";
		DrawUtil::moveCursor(60, 25);
		cout << "落子：回车键（←┘）";
		DrawUtil::moveCursor(60, 27);
		cout << "按9悔棋，一次最多可悔10步";
		DrawUtil::moveCursor(60, 29);
		cout << "按8存档";

		/*光标复位*/
		coord.X = 28;
		coord.Y = 14;
		while (1)
		{
			if (firstPlayer == '1')
			{
				DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_RED);

				DrawUtil::moveCursor(100, 7);
				cout << "玩家1的回合";
				DrawUtil::moveCursor(coord.X, coord.Y);

				do
				{
					returnFlag = player1.nextStep(coord.X, coord.Y, board);
					if (returnFlag == 0)
						chess = new Chess(0, coord.X / 4, coord.Y / 2);
				} while (returnFlag == 0 && !board.putChess(chess));

				DrawUtil::moveCursor(80, 14);
				cout << "             ";	//存档成功的消除
				DrawUtil::moveCursor(100, 9);
				cout << "           ";		//悔棋成功的消除
				if (board.win())
				{
					winPerson = '1';
					break;
				}
				if (returnFlag == 1)
				{
					returnFlag = 0;
					DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_RED);
					DrawUtil::moveCursor(100, 9);
					cout << "玩家2悔棋了";
					board.regret();
				}
				if (returnFlag == 2)
				{
					fileUtil.boardSave(board, firstPlayer, player1.getName(), player2.getName());
				}
				turn(firstPlayer);

			}
			else if (firstPlayer == '2')
			{
				DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_RED);

				DrawUtil::moveCursor(100, 7);
				cout << "玩家2的回合";
				DrawUtil::moveCursor(coord.X, coord.Y);

				do
				{
					returnFlag = player2.nextStep(coord.X, coord.Y, board);
					if (returnFlag == 0)
						chess = new Chess(1, coord.X / 4, coord.Y / 2);
				} while (returnFlag == 0 && !board.putChess(chess));
				DrawUtil::moveCursor(100, 9);
				cout << "           ";
				if (board.win())
				{
					winPerson = '2';
					break;
				}
				if (returnFlag == 1)
				{
					returnFlag = 0;
					DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_RED);

					DrawUtil::moveCursor(100, 9);
					cout << "玩家1悔棋了";
					board.regret();
				}
				if (returnFlag == 2)
				{
					fileUtil.boardSave(board, firstPlayer, player1.getName(), player2.getName());
				}
				turn(firstPlayer);


			}
		}
		if (winPerson == '1')
		{
			DrawUtil::moveCursor(60, 16);
			DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_RED);
			cout << player1.getName() << " 胜！！";
		}
		else
		{
			DrawUtil::moveCursor(60, 16);
			DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_RED);
			cout << player2.getName() << " 胜！！";
		}

		DrawUtil::moveCursor(60, 18);
		DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cout << "按q返回主菜单，其他键开始新的游戏";
		if ((key = _getch()) == 'q')
			return;
	}
}
/*切换回合*/
void GoBang::turn(char& player)
{
	if (player == '1') 
	{
		player = '2';
	}
	else if (player == '2')
	{
		player = '1';
	}
}