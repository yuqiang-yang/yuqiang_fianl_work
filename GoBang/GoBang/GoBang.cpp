#include "GoBang.h"




GoBang::GoBang(ChessBoard board)
{
	this->board = board;
	fileUtil.setPath("save");				//Ĭ�����õĴ浵�ļ���Ϊsave���ɸ���Ϊ����
}
GoBang::~GoBang()
{

}
void GoBang::control()
{
	char key;			//���Խ��ռ�������
	selectDisplay();
	while (key = _getch())
	{
		switch (key)
		{
		case '1':
			playerMode();			//��Ҷ�սģʽ
			DrawUtil::clear();
			selectDisplay();
			break;
		case '2':
			computerMode();			//�˻���սģʽ
			DrawUtil::clear();
			selectDisplay();

			break;
		case '3':
			DrawUtil::clear();
			saveMode();				//����ģʽ
			DrawUtil::clear();
			selectDisplay();
			break;
		case '4':
			exit(0);				//�˳�����
		}
	}

}
/*ѡ�������ʾ*/
void GoBang::selectDisplay()
{
	/*���߿�*/
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

	/*д����*/
	DrawUtil::setText( FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
	DrawUtil::moveCursor(27, 3);
	cout << "��    ��    ��";
	DrawUtil::moveCursor(53, 5);
	cout << "Author: yuqiang";
	

	/*д�˵�*/
	DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);	
	DrawUtil::moveCursor(5, 10);
	cout << "��  ѡ  ��";

	DrawUtil::moveCursor(10, 14);
	cout << "1�� ��    ��    ��    ս";

	DrawUtil::moveCursor(10, 18);
	cout << "2�� ��    ��    ��    ս";

	DrawUtil::moveCursor(10, 22);
	cout << "3�� ��    ��    ��    ��";

	DrawUtil::moveCursor(10, 26);
	cout << "4�� ��    ��    ��    Ϸ";

}
/*��Ҷ�սģʽ*/
void GoBang::playerMode()
{
	int key;						//��¼��������ļ�ֵ
	char firstPlayer;				//��¼˭�Ļغ�   ��1��Ϊ���1   ��2��Ϊ���2
	char winPerson = 0;				//��¼˭Ӯ		��1��Ϊ���1   ��2��Ϊ���2
	int returnFlag = 0;				//�����������庯���ķ���ֵ�� 0��ʾ���� 1��ʾ���� 2��ʾ�浵	
	string name1, name2;			//���1�����2������
	Chess* chess = nullptr;			//��ʱ�洢�ı���



	DrawUtil::clear();
	board.printBoard();
	
	DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
	/*�ӱ�׼�����л�ȡ���1������*/
	DrawUtil::moveCursor(70, 5);
	cout << "���������1�����ƣ�";	
	getline(cin, name1);
	
	/*�ӱ�׼�����л�ȡ���2������*/
	DrawUtil::moveCursor(70, 7);
	cout << "���������2�����ƣ�";
	getline(cin, name2);
	
	/*��ʼ��������Ҷ���*/
	PeoplePlayer player1(name1);
	PeoplePlayer player2(name2);
	
	while(1)
	{
		DrawUtil::clear();
		board.clearBoard();
		board.printBoard();
		DrawUtil::moveCursor(70, 9);

		/*ÿ�ֿ�ʼʱ��Ҫѡ���������*/
		cout << "��ѡ���������: \t���1\t���2";
		while ((firstPlayer = _getch()) != '1' && firstPlayer != '2'){} //whileѭ����֤����Ϊ1��2


		DrawUtil::clear();
		board.printBoard();

		/*�����Ҷ�ս��Ϣ*/
		DrawUtil::moveCursor(80, 4);
		DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
		cout << "��Ҷ�սģʽ";
		DrawUtil::moveCursor(60, 7);
		cout << "���1��" << name1;
		DrawUtil::moveCursor(60, 9);
		cout << "���2��" << name2;
		DrawUtil::moveCursor(60, 11);
		if (firstPlayer == '1')
		{
			cout << "���1����";
		}
		else
		{
			cout << "���2����";
		}
		DrawUtil::moveCursor(60, 21);
		DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
		cout << "����˵����";
		DrawUtil::moveCursor(60, 23);
		cout << "ѡ����㣺��������";
		DrawUtil::moveCursor(60, 25);
		cout << "���ӣ��س�����������";
		DrawUtil::moveCursor(60, 27);
		cout << "��9���壬һ�����ɻ�10��";
		DrawUtil::moveCursor(60, 29);
		cout << "��8�浵";

		/*����긴λ���м�*/
		coord.X = 28;
		coord.Y = 14;
		while (1)
		{
			if (firstPlayer == '1')		/*���������1�Ļغ�*/
			{
				DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_RED );
				DrawUtil::moveCursor(100, 7);
				cout <<  "���1�Ļغ�" ;
				DrawUtil::moveCursor(coord.X, coord.Y);

				do
				{
					returnFlag = player1.nextStep(coord.X, coord.Y, board);	//��ȡ��һ����X��Yֵ
					if(returnFlag == 0)										//����ֵΪ0���ǻ�ȡ�ɹ����Ž����¶���ĳ�ʼ��
						chess = new Chess(0, coord.X / 4, coord.Y / 2);	
				} while (returnFlag == 0 && !board.putChess(chess));		//һֱѭ����ֱ��һ�����ӳɹ�

				DrawUtil::moveCursor(80, 14);
				cout << "             ";		//"�浵�ɹ�"����������
				
				DrawUtil::moveCursor(100, 9);	//������������
				cout << "           ";

				if (board.win())
				{
					winPerson = '1';
					break;
				}

				if (returnFlag == 1)		//����ֵΪ1֤��Ҫ������
				{
					returnFlag = 0;
					DrawUtil::setText( FOREGROUND_INTENSITY | FOREGROUND_RED);
					DrawUtil::moveCursor(100, 9);
					cout << "���2������";
					board.regret();
				}
				if (returnFlag == 2)		//����ֵΪ2֤��Ҫ�浵��
				{
					fileUtil.boardSave(board,firstPlayer,player1.getName(),player2.getName());
				}
				turn(firstPlayer);			//ÿ�ֽ�����Ҫ����

			}
			else if(firstPlayer == '2')		//����ע�ͺ���һ����ʡ��~~~~~~~~~~~~~~~~
			{
				DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_RED);

				DrawUtil::moveCursor(100, 7);
				cout << "���2�Ļغ�";
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
					cout << "���1������";
					board.regret();
				}
				if (returnFlag == 2)
				{
					fileUtil.boardSave(board, firstPlayer, player1.getName(), player2.getName());
				}
				turn(firstPlayer);					
			}
		}
		/*��������ѭ��֮��˵�������Ӯ��*/
		if (winPerson == '1')
		{
			DrawUtil::moveCursor(60, 16);
			DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_RED);
			cout << player1.getName() << " ʤ����";
		}
		else
		{
			DrawUtil::moveCursor(60, 16);
			DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_RED);
			cout << player2.getName() << " ʤ����";
		}

		/*��������˵�*/
		DrawUtil::moveCursor(60, 18);
		DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cout << "��q�������˵�����������ʼ�µ���Ϸ";
		
		if ((key = _getch()) == 'q')	//�����������q����ֱ���˳��˺��������������˵����������»ص���������ѭ��
			return;
	}
}
/*�˻���սģʽ*/
void GoBang::computerMode()
{
	int key;							//��ȡ�Ӽ������������ֵ
	int row1, colunm1;					//��Ϊ��������������ɵ���ֻ�ܾ�������һ������к���
	char firstPlayer = '1';				//��¼����˭�Ļغϣ�'1'Ϊ��ң���2��Ϊ����
	char winPerson = 0;					//��¼˭Ӯ		��1��Ϊ��� ��2��Ϊ����
	int returnFlag = 0;					//�洢���صĽ��
	string name1;						//�洢��ҵ�����
	Chess* chess = nullptr;				//��ʱ�洢

	DrawUtil::clear();
	board.printBoard();

	/*������1������*/
	DrawUtil::moveCursor(70, 5);
	DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
	cout << "���������1�����ƣ�";
	getline(cin, name1);

	/*��ʼ����������*/
	PeoplePlayer player1(name1);
	ComputerPlayer player2;

	while (1)
	{
		DrawUtil::clear();
		board.clearBoard();
		board.printBoard();

		/*��ӡ��ս�˵�*/
		DrawUtil::moveCursor(80, 4);
		DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
		cout << "���Զ�սģʽ";
		DrawUtil::moveCursor(60, 7);
		cout << "���1��" << player1.getName();
		DrawUtil::moveCursor(60, 9);
		cout << "���2������" ;
		DrawUtil::moveCursor(60, 11);

		firstPlayer = '1';
		if (firstPlayer == '1')
		{
			cout << "���1����";
		}
		else
		{
			cout << "��������";
		}

		DrawUtil::moveCursor(60, 21);
		DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
		cout << "����˵����";
		DrawUtil::moveCursor(60, 23);
		cout << "ѡ����㣺��������";
		DrawUtil::moveCursor(60, 25);
		cout << "���ӣ��س�����������";
		DrawUtil::moveCursor(60, 27);
		cout << "��9���壬һ�����ɻ�10��";
		

		/*��긴λ*/
		coord.X = 28;
		coord.Y = 14;
		while (1)
		{
			if (firstPlayer == '1')
			{
				DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_RED);

				DrawUtil::moveCursor(100, 7);
				cout << "���1�Ļغ�";
				DrawUtil::moveCursor(coord.X, coord.Y);

				do
				{
					returnFlag = player1.nextStep(coord.X, coord.Y, board);
					if (returnFlag == 0)
						chess = new Chess(0, coord.X / 4, coord.Y / 2);
				} while (returnFlag == 0 && !board.putChess(chess));

				DrawUtil::moveCursor(80, 14);
				cout << "             ";	//���浵�ɹ���������
				DrawUtil::moveCursor(100, 9);
				cout << "           ";		//'����'��������


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
					cout << "��һ�����";
					board.regret();
					board.regret();

					continue;
				}

				if (returnFlag == 2)
				{
					fileUtil.boardSave(board, firstPlayer, player1.getName(), "����");
				}

				turn(firstPlayer);

			}

			else if (firstPlayer == '2')
			{
				DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_RED);

				DrawUtil::moveCursor(100, 7);
				cout << "���ԵĻغ�";

				DrawUtil::moveCursor(coord.X, coord.Y);
				do
				{
					returnFlag = player2.nextStep(row1, colunm1, board.board);	//��õ��Ծ�����һ�����row1��column1
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
			cout << player1.getName() << " ʤ����";
		}
		else
		{
			DrawUtil::moveCursor(60, 16);
			DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_RED);
			cout << "����" << " ʤ����";
		}

		DrawUtil::moveCursor(60, 18);
		DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cout << "��q�������˵�����������ʼ�µ���Ϸ";
		if ((key = _getch()) == 'q')
			return;
	}
}
/*����ģʽ*/
void GoBang::saveMode()
{
	char firstFlag = 1;			//һ�εı�־λ����һ�ν���whileѭ��ʱΪ1���˺�Ϊ0
	char firstPlayer;			//��¼��˭�Ļغ�
	string name1,name2;			//���1���2������
	fileUtil.boardRead(this->board,firstPlayer,name1,name2);	//��ȡ�浵
	int key;					//��ü�ֵ
	char winPerson = 0;			//��¼˭Ӯ
	int returnFlag = 0;			//���庯���ķ���ֵ����
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

		/*��ӡ��ս��Ϣ*/
		DrawUtil::moveCursor(80, 4);
		DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
		cout << "��Ҷ�սģʽ��������";

		DrawUtil::moveCursor(60, 7);
		cout << "���1��" << name1;
		DrawUtil::moveCursor(60, 9);
		cout << "���2��" << name2;

		DrawUtil::moveCursor(60, 21);
		DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
		cout << "����˵����";
		DrawUtil::moveCursor(60, 23);
		cout << "ѡ����㣺��������";
		DrawUtil::moveCursor(60, 25);
		cout << "���ӣ��س�����������";
		DrawUtil::moveCursor(60, 27);
		cout << "��9���壬һ�����ɻ�10��";
		DrawUtil::moveCursor(60, 29);
		cout << "��8�浵";

		/*��긴λ*/
		coord.X = 28;
		coord.Y = 14;
		while (1)
		{
			if (firstPlayer == '1')
			{
				DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_RED);

				DrawUtil::moveCursor(100, 7);
				cout << "���1�Ļغ�";
				DrawUtil::moveCursor(coord.X, coord.Y);

				do
				{
					returnFlag = player1.nextStep(coord.X, coord.Y, board);
					if (returnFlag == 0)
						chess = new Chess(0, coord.X / 4, coord.Y / 2);
				} while (returnFlag == 0 && !board.putChess(chess));

				DrawUtil::moveCursor(80, 14);
				cout << "             ";	//�浵�ɹ�������
				DrawUtil::moveCursor(100, 9);
				cout << "           ";		//����ɹ�������
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
					cout << "���2������";
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
				cout << "���2�Ļغ�";
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
					cout << "���1������";
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
			cout << player1.getName() << " ʤ����";
		}
		else
		{
			DrawUtil::moveCursor(60, 16);
			DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_RED);
			cout << player2.getName() << " ʤ����";
		}

		DrawUtil::moveCursor(60, 18);
		DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cout << "��q�������˵�����������ʼ�µ���Ϸ";
		if ((key = _getch()) == 'q')
			return;
	}
}
/*�л��غ�*/
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