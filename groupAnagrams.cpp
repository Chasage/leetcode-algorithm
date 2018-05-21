#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string>& strs) {
	int len = strs.size();
	vector<vector<string>> res;
	if (len == 0)
		return res;
	vector<string> sorted;
	for (int i = 0; i<len; i++)
	{
		string s;
		s = strs[i];
		sort(s.begin(), s.end());
		vector<string>::iterator pos = find(sorted.begin(), sorted.end(), s);
		if (pos == sorted.end())
		{
			vector<string> newone;
			newone.push_back(strs[i]);
			res.push_back(newone);
			sorted.push_back(s);
		}
		else
			res[pos - sorted.begin()].push_back(strs[i]);

	}
	return res;
}
void main()
{
	string a[] = { "eat", "tea", "tan", "ate", "nat", "bat" };
	vector<string> s(a, a + 6);
	vector<vector<string>> res;
	res = groupAnagrams(s);
	cout << setw(6);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << setw(6);
		}
		cout << endl;
	}
	system("pause");
}