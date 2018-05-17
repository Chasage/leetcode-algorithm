#include<iostream>
using namespace std;
double myPow(double x, int n) {
	if (n == 0)
		return 1.0;
	if (n<0)
	{
		if (n == INT_MIN)
			return 1.0 / myPow(x, INT_MAX) / x;
		return 1.0 / myPow(x, -n);
	}
	double half = myPow(x, n / 2);
	if (n % 2 == 0)
		return half*half;
	else
		return half*half*x;
}
void main()
{
	int n = 100;
	double x = 11.22;
	double res = myPow(x, n);
	cout << res << endl;
	system("pause");
}