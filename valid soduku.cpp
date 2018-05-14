#include<iostream>
#include<vector>
using namespace std;
bool isValidSudoku(vector<vector<char>>& board) {
	int i = 0, j = 0;
	int num[9];
	for (i = 0; i<9; i++)
		num[i] = 10;
	int number = 0;
	int cl = 0;
	for (i = 0; i<9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (board[i][j] == '.')
				continue;
			else
			{
				number = board[i][j] - '1';
				if (num[number] != 10)
					return false;
				else
					num[number] = i;
			}
		}
		for (cl = 0; cl<9; cl++)
			num[cl] = 10;
	}
	for (i = 0; i<9; i++)
		num[i] = 10;
	for (i = 0; i<9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (board[j][i] == '.')
				continue;
			else
			{
				number = board[j][i] - '1';
				if (num[number] != 10)
					return false;
				else
					num[number] = i;
			}
		}
		for (cl = 0; cl<9; cl++)
			num[cl] = 10;
	}
	for (i = 0; i<9; i++)
		num[i] = 10;
	for (int n = 1; n<8; n += 3)
	{
		for (int m = 1; m<8; m += 3)
		{
			for (i = n - 1; i <= n + 1; i++)
			{
				for (j = m - 1; j <= m + 1; j++)
				{
					if (board[i][j] == '.')
						continue;
					else
					{
						number = board[i][j] - '1';
						if (num[number] != 10)
							return false;
						else
							num[number] = (i - n + 1) * 3 + j - m + 1;
					}
				}
			}
			for (cl = 0; cl<9; cl++)
				num[cl] = 10;
		}
	}
	return true;

}
void main()
{
	char a[9][9] = { {'.', '.', '4', '.', '.', '.', '6', '3', '.'},{'.', '.', '.', '.', '.', '.', '.', '.', '.'},{'5', '.', '.', '.', '.', '.', '.', '9', '.' }, {'.', '.', '.', '5', '6', '.', '.', '.', '.'},{'4', '.', '3', '.', '.', '.', '.', '.', '1'},{'.', '.', '.', '7', '.', '.', '.', '.', '.'},{'.', '.', '.', '5', '.', '.', '.', '.', '.'},{'.', '.', '.', '.', '.', '.', '.', '.', '.'},{'.', '.', '.', '.', '.', '.', '.', '.', '.'} };
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
	res = isValidSudoku(board);
}