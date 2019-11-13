#pragma once
#include "ChessBoard.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <io.h>
#include "Chess.h"
#include "DrawUtil.h"
using namespace std;
class FileUtil
{
public:
	FileUtil();
	~FileUtil();
	void boardSave(ChessBoard& board, char firstPlayer, string name1, string name2);		/*�浵����*/
	void boardRead(ChessBoard& board, char& firstPlayer, string& name1, string& name2);		/*��������*/
	void showDir();			/*�浵�ļ���ʾ*/
	inline void setPath(string path) { this->path = path; }	/*���ô洢·��������Ĭ��Ϊsave*/
private:
	string path;
};

