#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
vector<vector<int>> generateMatrix(int n) {
	if (n == 0)
	{
		vector<vector<int>> res;
		return res;
	}
	vector<vector<int>> res(n, vector<int>(n, 0));
	int line = 0;
	int count = 1;
	while (line < n / 2)
	{
		for (int i = line; i<n - line; i++)
			res[line][i] = count++;
		for (int i = line + 1; i<n - line; i++)
			res[i][n - 1 - line] = count++;
		for (int i = n - 2 - line; i >= line; i--)
			res[n - line - 1][i] = count++;
		for (int i = n - 2 - line; i>line; i--)
			res[i][line] = count++;
		line++;
	}
	if (n % 2 == 1)
		res[n / 2][n / 2] = count;
	return res;
}
void printMatrix(vector<vector<int>>& matrix)
{
	int n = matrix.size();
	int m = matrix[0].size();
	cout << setw(6);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << matrix[i][j] << setw(6);
		cout << endl;
	}
}
void main()
{
	int n = 3;
	vector<vector<int>> res = generateMatrix(n);
	printMatrix(res);
	system("pause");
}