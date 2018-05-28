#include<iostream>
using namespace std;
long frac(int start, int len)
{
	if (len == 0)
		return 1;
	else
		return start*frac(start - 1, len - 1);
}
int uniquePaths(int m, int n) {
	if (m == 1 || n == 1)
		return 1;
	else
		return frac(m + n - 2, m >= n ? n - 1 : m - 1) / frac(m >= n ? n - 1 : m - 1, m >= n ? n - 1 : m - 1);
}
void main()
{
	int m = 5, n = 5;
	int res = uniquePaths(m, n);
	cout << res << endl;
	system("pause");
}