#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void checkCurrentPos(vector<int>& candidates, int curSum, int target, vector<int>& curRes, int pos, vector<vector<int>>& res)
{
	if (curSum == target)
	{
		res.push_back(curRes);
		return;
	}
	if (curSum>target)
		return;
	int i = pos;
	while (i<candidates.size())
	{
		curRes.push_back(candidates[i]);
		checkCurrentPos(candidates, curSum + candidates[i], target, curRes, i, res);
		i++;
		curRes.pop_back();
	}
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> res;
	sort(candidates.begin(), candidates.end());
	int len = candidates.size();
	if (len == 0)
		return res;
	if (target<candidates[0])
		return res;
	vector<int> curRes;
	checkCurrentPos(candidates, 0, target, curRes, 0, res);
	return res;
}
void main()
{
	int a[] = { 2,3,6,7};
	vector<int> ve(a, a + 4);
	vector<vector<int>> res;
	res = combinationSum(ve, 8);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j]<<"  ";
		cout << endl;
	}
	system("pause");
}