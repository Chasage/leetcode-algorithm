#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool check(vector<string>& line, int n, int i, int j)
{
	for (int k = 0; k<n; k++)
		if (line[i][k] == 'Q'&&k != j)
			return false;
	for (int k = 0; k<n; k++)
		if (line[k][j] == 'Q'&&k != i)
			return false;
	int k = 1;
	while (i - k >= 0 && j - k >= 0)
	{
		if (line[i - k][j - k] == 'Q')
			return false;
		k++;
	}
	k = 1;
	while (i - k >= 0 && j + k<n)
	{
		if (line[i - k][j + k] == 'Q')
			return false;
		k++;
	}
	k = 1;
	while (i + k<n&&j - k >= 0)
	{
		if (line[i + k][j - k] == 'Q')
			return false;
		k++;
	}
	k = 1;
	while (i + k<n&&j + k<n)
	{
		if (line[i + k][j + k] == 'Q')
			return false;
		k++;
	}
	return true;
}
bool checkall(vector<string>& line, int n)
{
	int cnt = 0;
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (line[i][j] == 'Q')
			{
				cnt++;
				if (!check(line, n, i, j))
					return false;
			}
		}
	}
	if (cnt == n)
		return true;
	else
		return false;
}
void choosePlace(vector<vector<string>>& res, int i, int j, vector<string>& line, int n)
{
	if (i >= n)
	{
		if (checkall(line, n))
			res.push_back(line);
		return;
	}
	else if (j == n)
	{
		choosePlace(res, i + 1, 0, line, n);
		return;
	}
	line[i][j] = 'Q';
	if (check(line, n, i, j))
		choosePlace(res, i + 1, 0, line, n);
	line[i][j] = '.';
	choosePlace(res, i, j + 1, line, n);
}
int solveNQueens(int n) {
	vector<vector<string>> res;
	if (n <= 1)
		return n;
	string dot = "";
	vector<string> line;
	for (int i = 0; i<n; i++)
		dot = dot + '.';
	for (int i = 0; i<n; i++)
		line.push_back(dot);
	choosePlace(res, 0, 0, line, n);
	return res.size();
}
void main()
{
	vector<vector<string>> res;
	int n = 4;
	int num= solveNQueens(n);
	cout << num<<endl;
	system("pause");
}