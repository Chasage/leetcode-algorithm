#include<iostream>
#include<vector>
using namespace std;

int findPos(vector<int>& nums, int target, int start, int end)
{
	if (start>end)
		return -1;
	if (start == end)
	{
		if (nums[start] == target)
			return start;
		else
			return -1;
	}
	int mid = (start + end) / 2;
	if (target == nums[mid])
		return mid;
	if (target == nums[start])
		return start;
	if (mid == start)
	{
		if (nums[start] == target)
			return start;
		else if (nums[end] == target)
			return end;
		else
			return -1;
	}
	if (target>nums[mid] && target>nums[start] && nums[mid]>nums[start])
		return findPos(nums, target, mid, end);
	if (target>nums[mid] && target>nums[start] && nums[mid]<nums[start])
		return findPos(nums, target, start, mid);
	if (target>nums[mid] && target<nums[start])
		return findPos(nums, target, mid, end);
	if (target<nums[mid] && target<nums[start] && nums[mid]<nums[start])
		return findPos(nums, target, start, mid);
	if (target<nums[mid] && target<nums[start] && nums[mid]>nums[start])
		return findPos(nums, target, mid, end);
	if (target<nums[mid] && target>nums[start])
		return findPos(nums, target, start, mid);
}

int search(vector<int>& nums, int target) {
	int len = nums.size();
	if (len == 0)
		return -1;
	if (len == 1 && nums[0] != target)
		return -1;
	int result = 0;
	result = findPos(nums, target, 0, len - 1);
	return result;
}

int main()
{
	int a[] = { 4,5,6,7,8,0,1,2,3 };
	vector<int> nums(a, a + 9);
	int target = 6;
	int pos = 0;
	pos = search(nums, target);
	cout << pos;
	system("pause");
}