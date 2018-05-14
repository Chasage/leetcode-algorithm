#include<iostream>
#include<vector>
using namespace std;
vector<int> findPos(vector<int>& nums, int target, int start, int end)
{
	if (start > end)
	{
		vector<int> res(2, -1);
		return res;
	}
	int mid = (start + end) / 2;
	if (nums[mid] == target)
	{
		int s1 = mid - 1, s2 = mid + 1;
		while (s1 >= start)
		{
			if (target == nums[s1])
				s1--;
			else
				break;
		}
		while (s2 <= end)
		{
			if (target == nums[s2])
				s2++;
			else
				break;
		}
		vector<int> res;
		res.push_back(s1 + 1);
		res.push_back(s2 - 1);
		return res;
	}
	if (nums[mid]>target)
		return findPos(nums, target, start, mid - 1);
	if (nums[mid]<target)
		return findPos(nums, target, mid + 1, end);
}
vector<int> searchRange(vector<int>& nums, int target) {
	int len = nums.size();
	vector<int> res;
	if (len == 0)
	{
		res.push_back(-1);
		res.push_back(-1);
		return res;
	}
	return findPos(nums, target, 0, len - 1);
}
int main()
{
	int a[] = { 1,4,6,6,8,8,10 };
	vector<int> nums(a, a + 7);
	int target = 2;
	vector<int> pos;
	pos = searchRange(nums,target);
	cout << pos[0] << "   " << pos[1]<<endl;
	system("pause");
}