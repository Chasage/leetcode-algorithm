#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int FactorialNum(int n)
{
	int num = 1;
	while (n>1)
	{
		num = n*num;
		n--;
	}
	return num;
}
string getPermutation(int n, int k) {
		if (n == 1)
			return "1";
		k = k - 1;
		int pos = 0;
		string s = "";
		while (pos++<n)
			s += to_string(pos);
		pos = 0;
		while (k != 0)
		{
			int len = FactorialNum(n - 1 - pos);
			int num = k / len;
			if (num != 0)
			{
				string temp = s.substr(pos + num, 1);
				s.erase(pos + num,1);
				s.insert(pos, temp);
				k = k%len;
			}
			pos++;
		}
		return s;
}
void main()
{
	int n = 8, k = 40000;
	string s = getPermutation(n, k);
	cout << s << endl;
	system("pause");
}