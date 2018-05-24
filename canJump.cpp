#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool canJump(vector<int>& nums) {
	int len = nums.size();
	if (len <= 1)
		return true;
	vector<int>::iterator pos;
	pos = find(nums.begin(), nums.end(), 0);
	int position = pos - nums.begin();
	while (pos != nums.end())
	{
		int i = 0;
		for (; i<position; i++)
		{
			if (nums[i] + i >= len - 1)
				return true;
			if (nums[i] + i>position)
				break;
		}
		if (i == position)
			return false;
		pos = find(nums.begin() + position + 1, nums.end(), 0);
		position = pos - nums.begin();
	}
	return true;
}
void main()
{
	int a[] = { 2,3,1,0,4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	bool res = canJump(v);
	cout << res << endl;
	system("pause");


}