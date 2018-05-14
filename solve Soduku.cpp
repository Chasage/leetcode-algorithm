/*参考https://www.cnblogs.com/grandyang/p/4421852.html*/
#include<iostream>
#include<vector>
using namespace std;
bool vaildNumber(vector<vector<char>>& board, int i, int j)
{
	char num = board[i][j];
	for (int m = 0; m<9; m++)
		if (board[m][j] == num && m != i)
			return false;
	for (int m = 0; m<9; m++)
		if (board[i][m] == num && m != j)
			return false;
	for (int m = i / 3 * 3; m<i / 3 * 3 + 3; m++)
		for (int n = j / 3 * 3; n<j / 3 * 3 + 3; n++)
			if (board[m][n] == num && (m != i || n != j))
				return false;
	return true;
}

bool fillSodukuBlank(vector<vector<char>>& board, int i, int j)
{
	if (i == 9)
		return true;
	if (j >= 9)
		return fillSodukuBlank(board, i + 1, 0);
	if (board[i][j] == '.')
	{
		for (int num = 1; num<10; num++)
		{
			board[i][j] = (char)(num + '0');
			if (vaildNumber(board, i, j))
			{
				if (fillSodukuBlank(board, i, j + 1))
					return true;
			}
			board[i][j] = '.';
		}
	}
	else
		return fillSodukuBlank(board, i, j + 1);
	return false;
}

void solveSudoku(vector<vector<char>>& board) {
	fillSodukuBlank(board, 0, 0);
}


void main()
{
	char a[9][9] = { { '5', '3', '.', '.', '7', '.', '.', '.', '.' },{ '6', '.', '.', '1', '9', '5', '.', '.', '.' },{ '.', '9', '8', '.', '.', '.', '.', '6', '.' },{ '8', '.', '.', '.', '6', '.', '.', '.', '3' },{ '4', '.', '.', '8', '.', '3', '.', '.', '1' },{ '7', '.', '.', '.', '2', '.', '.', '.', '6' },{ '.', '6', '.', '.', '.', '.', '2', '8', '.' },{ '.', '.', '.', '4', '1', '9', '.', '.', '5' },{ '.', '.', '.', '.', '8', '.', '.', '7', '9' } };
	vector<vector<char>> board;
	for (int i = 0; i < 9; i++)
	{
		vector<char> s;
		for (int j = 0; j < 9; j++)
		{
			s.push_back(a[i][j]);
		}
		board.push_back(s);
	}
	bool res;
	cout << "原数独为：" << endl;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << board[i][j] << "    ";
			if ((j + 1) % 3 == 0 && j != 0)
				cout << "  ";
		}
		cout << endl;
		if ((i + 1) % 3 == 0 && i != 0)
			cout << endl;
	}
	cout << endl << endl;
	solveSudoku(board);
	cout << "填完后数独为：" << endl;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << board[i][j] << "    ";
			if ((j + 1) % 3 == 0 && j != 0)
				cout << "  ";
		}
		cout << endl;
		if ((i + 1) % 3 == 0 && i != 0)
			cout << endl;
	}
	system("pause");
}