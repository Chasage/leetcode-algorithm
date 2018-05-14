#include <vector>
#include<iostream>
using namespace std;
int searchInsert(vector<int>& nums, int target) {
	int len = nums.size();
	int start = 0, end = len - 1;
	while (start<end)
	{
		int mid = (start + end) / 2;
		if (nums[mid] == target)
			return mid;
		else if (nums[mid]<target)
			start = mid + 1;
		else
			end = mid - 1;
	}
	if (nums[start] >= target)
		return start;
	else
		return start + 1;
}
void main()
{
	int a[] = { 1,3,5,7,9,11,15,17,19 };
	vector<int> nums(a, a + 9);
	int target = 19;
	int pos = searchInsert(nums, target);
	cout << pos << endl;
	system("pause");
}