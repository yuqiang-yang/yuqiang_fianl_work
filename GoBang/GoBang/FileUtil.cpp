#include "FileUtil.h"

FileUtil::FileUtil()
{	
}


FileUtil::~FileUtil()
{
}
/*�浵����*/
void FileUtil::boardSave(ChessBoard& board,char firstPlayer,string name1,string name2)
{
	string fileName;			//�洢���ļ���
	Chess * temp;				//��ʱ�洢����
	
	
	DrawUtil::moveCursor(80, 14);
	cout << "������浵�����ƣ�";
	getline(cin, fileName);
	DrawUtil::moveCursor(80, 14);
	cout << "                                         ";
	DrawUtil::moveCursor(80, 14);
	cout << "�浵�ɹ�";
	ofstream ofs(path + '\\'+fileName + ".dat");		//��ʼ����������洢���ļ�����pathĿ¼�£�����Ϊfilename����׺Ϊ.dat


	for (int i = 0; i < 15; i++)			//ת�崦���֡��������������ӣ������2��������0��ɫ�����ӣ������0��������1��ɫ�����ӣ������1��
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

	/*�浵ʱ�������浵ʱ��˭�Ļغϣ����1�����2����������������������Ϸ*/
	ofs << firstPlayer;
	ofs << name1 + '\n';
	ofs << name2;

	ofs.close();	//�ر������


}
/*��������*/
void FileUtil::boardRead(ChessBoard & board, char& firstPlayer, string& name1, string& name2)
{
	string fileName;			//Ҫ��ȡ�ļ�������
	char temp;					//��ʱ����
	DrawUtil::moveCursor(0, 3);
	showDir();					//��ʾpath·���£�����.dat��׺���ļ�
	
	cout << "��Ҫ��ȡ���ļ����ƣ�";
	getline(cin,fileName);		
	ifstream ifs(path + '\\' + fileName + ".dat");
	board.clearBoard();			//��ȡʱ�������board��������б���
	board.printBoard();

	for (int i = 0; i < 15; i++)		//ת�岿�֣�����ȡ��Ϊ��2�������λ�ò��������ӣ�����ȡ��Ϊ1���������ɫΪ1�����ӣ�����ȡ��Ϊ0���������ɫΪ0������
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
	/*��ȡ˭�Ļغϣ����1�����2������*/
	ifs >> firstPlayer;
	ifs >> name1;
	ifs >> name2;
}
/*Ŀ¼��ʾ����*/
/*�˺�����ʵ����Դ�����ϣ����޸Ķ�ʹ��*/
void FileUtil::showDir()
{
	vector<string> file;
	intptr_t hFile = 0;   
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*.dat").c_str(), &fileinfo)) != -1)//����ֻ��ȡ.datΪ��׺���ļ�
	{
		do
		{
			if ((fileinfo.attrib &  _A_SUBDIR))
			{
				//�����ȡ������Ŀ¼������ȡ�κβ���
			}
			else
			{
				//��ȡ�������ļ��������vector��
				file.push_back(fileinfo.name);
			}
		} while (_findnext(hFile, &fileinfo) == 0);

		_findclose(hFile);
	}
	/*����ļ���*/
	for (unsigned int i = 0; i < file.size(); i++)
	{
		cout << file[i].c_str() << endl;
	}
}
