#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int maxSubArrayFindCross(vector<int>& nums, int start, int end, int mid)
{
	int leftsum = nums[mid], rightsum = nums[mid];
	int sum = 0, maxleft = mid;
	for (int i = mid; i >= start; i--)
	{
		sum += nums[i];
		if (sum>leftsum)
		{
			leftsum = sum;
			maxleft = i;
		}
	}
	sum = 0;
	int maxright = mid;
	for (int i = mid; i <= end; i++)
	{
		sum += nums[i];
		if (sum>rightsum)
		{
			rightsum = sum;
			maxright = i;
		}
	}
	return rightsum + leftsum - nums[mid];
}

int maxSubArrayFind(vector<int>& nums, int start, int end)
{
	if (start >= end)
		return nums[start];
	int mid = (start + end) / 2;
	int leftsum, rightsum, midsum;
	leftsum = maxSubArrayFind(nums, start, mid);
	rightsum = maxSubArrayFind(nums, mid + 1, end);
	midsum = maxSubArrayFindCross(nums, start, end, mid);
	if (leftsum >= rightsum && leftsum >= midsum)
		return leftsum;
	else if (leftsum<rightsum && rightsum >= midsum)
		return rightsum;
	else if (midsum >= leftsum && midsum >= rightsum)
		return midsum;
}

int maxSubArray(vector<int>& nums) {
	int len = nums.size();
	if (len == 0)
		return INT_MIN;
	return maxSubArrayFind(nums, 0, len - 1);
}
void main()
{
	int a[] = { -2,1,-3,4,-1,2,1,-5,4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	int maxnum = maxSubArray(v);
	cout << maxnum << endl;
	system("pause");

}