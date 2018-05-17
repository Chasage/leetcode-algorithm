#include<iostream>
#include<string>
using namespace std;
bool isMatch(string s, string p) {
	int len1 = s.size(), len2 = p.size();
	if (len1 == 0 && len2 == 0)   return true;
	int si = 0, pi = 0;
	int spos = -1, ppos = -1;
	while (si < len1)
	{
		if (pi < len2 && p[pi] == '*')
		{
			ppos = pi++;
			spos = si;   // si对应xidx的位置  
		}
		else if (pi < len2 && (s[si] == p[pi] || p[pi] == '?'))
		{
			++si;
			++pi;
		}
		else if (ppos > -1)
		{  // 上一个 '*' 的位置  
			pi = ppos + 1;
			si = ++spos;
		}
		else
			return false;
	}
	while (pi < len2 && p[pi] == '*')  ++pi;
	return (pi == len2);
}

void main()
{
	string s = "babbbbaabababaabbababaababaabbaabababbaaababbababaaaaaabbabaaaabababbabbababbbaaaababbbabbbbbbbbbbaabbb";
	string p = "b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a";
	bool res = isMatch(s, p);
	cout << res << endl;
	system("pause");
}
/* 测试用例
"aaaabaaaabbbbaabbbaabbaababbabbaaaababaaabbbbbbaabbbabababbaaabaabaaaaaabbaabbbbaababbababaabbbaababbbba"
"*****b*aba***babaa*bbaba***a*aaba*b*aa**a*b**ba***a*a*"
"babbbbaabababaabbababaababaabbaabababbaaababbababaaaaaabbabaaaabababbabbababbbaaaababbbabbbbbbbbbbaabbb"
"b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a"
*/