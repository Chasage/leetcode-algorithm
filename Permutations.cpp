#include<iostream>
#include<vector>
using namespace std;
void permuteCircle(vector<int>& nums, int start, int end, vector<vector<int>>& res)
{
	if (start == end)
		res.push_back(nums);
	else if (start>end)
		return;
	else
	{
		for (int i = start ; i <= end; i++)
		{
			swap(nums[start], nums[i]);
			permuteCircle(nums, start + 1, end, res);
			swap(nums[start], nums[i]);
		}
	}
}
vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> res;
	if (nums.size() == 0)
		return res;
	permuteCircle(nums, 0, nums.size() - 1, res);
	return res;
}
void main()
{
	int a[] = { 1,2,3,4 };
	vector<int> nums (a, a + sizeof(a) / sizeof(int));
	vector<vector<int>> res;
	res = permute(nums);
	int n1 = nums.size(),n2=res.size();
	for (int i = 0; i < n2; i++)
	{
		for (int j = 0; j < n1; j++)
			cout << res[i][j] << "  ";
		cout << endl;
	}
	system("pause");
	
}