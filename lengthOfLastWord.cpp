#include<iostream>
#include<string>
using namespace std;
int lengthOfLastWord(string s) {
		int len = s.size();
		if (len == 0)
			return 0;
		int n = len - 1;
		while (s[n] == ' ') { n--; }
		int res = 0;
		while (s[n] != ' '&& n >= 0) { res++; n--; }
		return res;
}
void main()
{
	string s = "Hello World";
	int len = lengthOfLastWord(s);
	cout << s << "  最后单词长度为" << len<<endl;
	system("pause");
}