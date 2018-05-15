#include<iostream>
#include<string>
#include<stack>
using namespace std;
string multiplyString(string num1, string num2) {
	int len1 = num1.size(), len2 = num2.size();
	if (len1 == 0 || len2 == 0)
		return "";
	stack<int> res;
	if (len1 > len2)
	{
		string s1(num1.rbegin(), num1.rend());
		string s2(num2.rbegin(), num2.rend());
		num1 = s1;
		num2 = s2;
	}
	else
	{
		len1 = len1 + len2;
		len2 = len1 - len2;
		len1 = len1 - len2;
		string s1(num2.rbegin(), num2.rend());
		string s2(num1.rbegin(), num1.rend());
		num1 = s1;
		num2 = s2;
	}
	/*if (len1 < len2)
	{
		string s1;
		s1 = num1;
		num1 = num2;
		num2 = s1;
	}*/
	int cnt = 0;
	for (int i = 0; i < len1 + len2; i++)
	{
		int number = 0;
		for (int j = i; j >= 0; j--)
		{
			if (j > len1 - 1)
				continue;
			if (i - j > len2 - 1)
				break;
			number += (int)(num1[j] - '0')*(int)(num2[i - j] - '0');
		}
		number += cnt;
		res.push(number % 10);
		cnt = number / 10;
	}
	while (!res.empty() && res.top() == 0 )
		res.pop();
	if (res.empty())
		return "0";
	string result;
	len1 = res.size();
	while (!res.empty())
	{
		result += (res.top() + '0');
		res.pop();
	}
	return result;
}
void main()
{
	string s1 = "98765";
	string s2 = "0";
	string ss = multiplyString(s1, s2);
	cout << ss << endl;
	system("pause");
}