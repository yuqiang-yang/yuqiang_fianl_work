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
	void boardSave(ChessBoard& board, char firstPlayer, string name1, string name2);		/*存档函数*/
	void boardRead(ChessBoard& board, char& firstPlayer, string& name1, string& name2);		/*读档函数*/
	void showDir();			/*存档文件显示*/
	inline void setPath(string path) { this->path = path; }	/*设置存储路径函数，默认为save*/
private:
	string path;
};

