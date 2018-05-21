#include<iostream>
#include<vector>
#include<iomanip>  
using namespace std;
void PrintMatrix(vector<vector<int>>& matrix)
{
	int len = matrix.size();
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
			cout << matrix[i][j] << setw(4);
		cout << endl;
	}
}
void rotate(vector<vector<int>>& matrix) {
	int len = matrix.size();
	if (len <= 1)
		return;
	for (int i = 0; i<len / 2; i++)
	{
		for (int j = i; j<len -  i - 1; j++)
		{
			int n = matrix[i][j];
			matrix[i][j] = matrix[len - 1 - j][i];
			matrix[len - 1 - j][i] = matrix[len - 1 - i][len - 1 - j];
			matrix[len - 1 - i][len - 1 - j] = matrix[j][len - 1 - i];
			matrix[j][len - 1 - i] = n;
			PrintMatrix(matrix);
			cout << endl;
		}
	}
}
void main()
{
	int len = 4;
	vector<vector<int>> matrix;
	for (int i = 0; i < len; i++)
	{
		vector<int> num;
		for (int j = 0; j < len; j++)
		{
			num.push_back(i*len + j + 1);
		}
		matrix.push_back(num);
	}
	cout << "Ô­¾ØÕó£º" << endl;
	PrintMatrix(matrix);
	cout << endl;
	rotate(matrix);
	system("pause");
}