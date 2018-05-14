#include<string>
#include<iostream>
#include<vector>
using namespace std;
vector<int> intCount(int n)
{
	vector<int> res;
	if (n == 1)
	{
		res.push_back(1);
		return res;
	}
	vector<int> num;
	num = intCount(n - 1);
	int len = num.size();
	int count = num[0], say = 1;
	for (int i = 0; i<len - 1; i++)
	{
		if (num[i + 1] == num[i])
			say++;
		else
		{
			res.push_back(say);
			res.push_back(count);
			count = num[i + 1];
			say = 1;
		}
	}
	res.push_back(say);
	res.push_back(count);
	return res;
}

string countAndSay(int n) {
	if (n == 0)
		return "";
	vector<int> num;
	num = intCount(n);
	int len = num.size();
	string res;
	for (int i = 0; i<len; i++)
	{
		res += to_string(num[i]);
	}
	return res;
}

void main()
{
	int n = 4;
	string s = countAndSay(n);
	cout << s << endl;
	system("pause");
}