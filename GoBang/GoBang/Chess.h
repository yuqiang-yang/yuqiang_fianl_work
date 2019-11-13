#pragma once
class Chess
{
public:
	Chess(char color, int row, int column);
	~Chess();


	inline char getColor() { return color; }
	inline void getPosition(int& row, int& column) { row = this->row; column = this->column; }
private:
	char color = -1;			//���ӵ���ɫ��0Ϊ�ף�1Ϊ�ڡ�	-1��ʾδ����ʼ��
	int row = -1, column = -1;	//�������ڵ��к��У�0-14		-1��ʾδ����ʼ��
};

