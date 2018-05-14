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
	while (i<(int)candidates.size() - 1)
	{
		i++;
		while (i - pos >= 2 && i<candidates.size() && candidates[i] == candidates[i - 1])
			i++;
		if (curSum + candidates[i] > target)
			return;
		curRes.push_back(candidates[i]);
		checkCurrentPos(candidates, curSum + candidates[i], target, curRes, i, res);
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
	checkCurrentPos(candidates, 0, target, curRes, -1, res);
	vector<vector<int>>::iterator new_end = unique(res.begin(), res.end());
	res.erase(new_end, res.end());
	return res;
}
void main()
{
	int a[] = { 29,18,26,13,9,28,16,10,5,17,18,8,20,25,26,17,5,16,10,14,22,30,14,7,16,16,12,16,21,25,13,15,30,34,15,34,19,18,10,19,22,15,14,7,28,6,19,28,9,16,29,26,11,9,29 };
	//int a[] = { 3,1,3,5,1,5,2,3,2,5,4 };
	vector<int> ve(a, a + 55);
	vector<vector<int>> res;
	res = combinationSum(ve, 20);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << "  ";
		cout << endl;
	}
	system("pause");
}