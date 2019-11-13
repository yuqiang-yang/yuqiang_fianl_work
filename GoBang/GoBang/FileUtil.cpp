#include "FileUtil.h"

FileUtil::FileUtil()
{	
}


FileUtil::~FileUtil()
{
}
/*存档函数*/
void FileUtil::boardSave(ChessBoard& board,char firstPlayer,string name1,string name2)
{
	string fileName;			//存储的文件名
	Chess * temp;				//临时存储变量
	
	
	DrawUtil::moveCursor(80, 14);
	cout << "请输入存档的名称：";
	getline(cin, fileName);
	DrawUtil::moveCursor(80, 14);
	cout << "                                         ";
	DrawUtil::moveCursor(80, 14);
	cout << "存档成功";
	ofstream ofs(path + '\\'+fileName + ".dat");		//初始化输出流，存储的文件，在path目录下，名字为filename，后缀为.dat


	for (int i = 0; i < 15; i++)			//转义处理部分。若棋盘中无棋子，输出‘2’，若有0颜色的棋子，输出‘0’，若有1颜色的棋子，输出‘1’
	{
		for (int j = 0; j < 15; j++)
		{
			temp = board.getChess(i, j);
			if (board.getChess(i, j) == nullptr)
			{
				ofs << '2';
			}
			else if ((board.getChess(i, j) != nullptr )&& (board.getChess(i, j)->getColor() == 0))
			{
				ofs << '0';
			}
			else if ((board.getChess(i, j) != nullptr) && (board.getChess(i, j)->getColor() == 1))
			{
				ofs << '1';
			}
		}
	}

	/*存档时保存最后存档时是谁的回合，玩家1和玩家2的姓名，方便读档后继续游戏*/
	ofs << firstPlayer;
	ofs << name1 + '\n';
	ofs << name2;

	ofs.close();	//关闭输出流


}
/*读档函数*/
void FileUtil::boardRead(ChessBoard & board, char& firstPlayer, string& name1, string& name2)
{
	string fileName;			//要读取文件的名称
	char temp;					//临时变量
	DrawUtil::moveCursor(0, 3);
	showDir();					//显示path路径下，所有.dat后缀的文件
	
	cout << "请要读取的文件名称：";
	getline(cin,fileName);		
	ifstream ifs(path + '\\' + fileName + ".dat");
	board.clearBoard();			//读取时，先清空board里面的所有变量
	board.printBoard();

	for (int i = 0; i < 15; i++)		//转义部分，若读取到为‘2’，则该位置不放置棋子，若读取到为1，则放置颜色为1的棋子，若读取到为0，则放置颜色为0的棋子
	{
		for (int j = 0; j < 15; j++)
		{
			ifs >> temp;
			if (temp == '0')
			{
				board.putChess(new Chess(0, i, j));
			}
			else if (temp == '1')
			{
				board.putChess(new Chess(1, i, j));

			}
			else if (temp == '2')
			{

			}
		}
	}
	/*读取谁的回合，玩家1、玩家2的姓名*/
	ifs >> firstPlayer;
	ifs >> name1;
	ifs >> name2;
}
/*目录显示函数*/
/*此函数的实现来源于网上，经修改而使用*/
void FileUtil::showDir()
{
	vector<string> file;
	intptr_t hFile = 0;   
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*.dat").c_str(), &fileinfo)) != -1)//设置只读取.dat为后缀的文件
	{
		do
		{
			if ((fileinfo.attrib &  _A_SUBDIR))
			{
				//如果读取到的是目录，不采取任何操作
			}
			else
			{
				//读取到的是文件，则放入vector中
				file.push_back(fileinfo.name);
			}
		} while (_findnext(hFile, &fileinfo) == 0);

		_findclose(hFile);
	}
	/*输出文件名*/
	for (unsigned int i = 0; i < file.size(); i++)
	{
		cout << file[i].c_str() << endl;
	}
}
