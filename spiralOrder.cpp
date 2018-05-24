#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> res;
	int n = matrix.size();
	if (n == 0)
		return res;
	int m = matrix[0].size();
	if (m == 0)
		return res;
	int line = 0;
	if (m >= n)
	{
		while (line < n / 2)
		{
			for (int i = line; i<m - line; i++)
				res.push_back(matrix[line][i]);
			for (int i = line + 1; i<n - line; i++)
				res.push_back(matrix[i][m - 1 - line]);
			for (int i = m - 2 - line; i >= line; i--)
				res.push_back(matrix[n - line - 1][i]);
			for (int i = n - 2 - line; i>line; i--)
				res.push_back(matrix[i][line]);
			line++;
		}
		if (n % 2 != 0)
			for (int i = line; i<m - line; i++)
				res.push_back(matrix[line][i]);
	}
	else if (n>m)
	{
		while (line < m / 2)
		{
			for (int i = line; i<m - line; i++)
				res.push_back(matrix[line][i]);
			for (int i = line + 1; i<n - line; i++)
				res.push_back(matrix[i][m - 1 - line]);
			for (int i = m - 2 - line; i >= line; i--)
				res.push_back(matrix[n - line - 1][i]);
			for (int i = n - 2 - line; i>line; i--)
				res.push_back(matrix[i][line]);
			line++;
		}
		if(m%2!=0)
			for (int i = line ; i<n - line; i++)
				res.push_back(matrix[i][m - 1 - line]);

	}
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
	int width = 1, height = 3;
	vector<vector<int>> v(height,vector<int> (width,0));
	int num = 0;
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			v[i][j] = num++;
	printMatrix(v);
	vector<int> res = spiralOrder(v);
	cout << endl;
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << setw(6);
	cout <<  endl;
	system("pause");

}