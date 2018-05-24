#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
vector<Interval> merge(vector<Interval>& intervals) {
	int len = intervals.size();
	vector<Interval> res;
	if (len == 0)
		return res;
	vector<int> nums;
	nums.push_back(intervals[0].start);
	nums.push_back(intervals[0].end);
	int count = 1, startpos = 0, endpos = 2;
	for (int i = 1; i < len; i++)
	{
		if (nums[0] > intervals[i].end)
		{
			nums.insert(nums.begin(), intervals[i].start);
			nums.insert(nums.begin() + 1, intervals[i].end);
			count++;
		}
		else if (nums[0] == intervals[i].end)
		{
			nums[0] = intervals[i].start;
		}
		else if (nums[2 * count - 1] == intervals[i].start)
		{
			nums[2 * count - 1] = intervals[i].end;
		}
		else if (nums[2 * count - 1] < intervals[i].start)
		{
			nums.push_back(intervals[i].start);
			nums.push_back( intervals[i].end);
			count++;
		}
		else if (nums[2 * count - 1] < intervals[i].end && nums[0] > intervals[i].start)
		{
			nums.erase(nums.begin(), nums.end());
			nums.push_back(intervals[i].start);
			nums.push_back(intervals[i].end);
			count = 1;
		}
		else 
		{
			startpos = 0, endpos = 2 * count;
			for (int j = 1; j < count * 2; j++)
			{
				if (nums[j - 1] < intervals[i].start && intervals[i].start <= nums[j] )
					startpos = j;
				if (nums[j - 1] < intervals[i].end && intervals[i].end <= nums[j])
				{
					endpos = j;
					break;
				}
			}
			nums.erase(nums.begin() + startpos, nums.begin() + endpos);
			if (startpos % 2 == 0 && endpos % 2 == 0)
			{
				if (nums[startpos] == intervals[i].end)
					nums[startpos] = intervals[i].start;
				else 
				{
					nums.insert(nums.begin() + startpos, intervals[i].end);
					nums.insert(nums.begin() + startpos, intervals[i].start);
				}
			}
			else if (startpos % 2 == 0 && endpos % 2 == 1)
			{
				nums.insert(nums.begin() + startpos, intervals[i].start);
			}
			else if (startpos % 2 == 1 && endpos % 2 == 0)
			{

				if (nums[startpos] == intervals[i].end)
					nums.erase(nums.begin() + startpos);
				else
					nums.insert(nums.begin() + startpos, intervals[i].end);
			}
			count = nums.size()/2;
		}
	}
	for (int i = 1; i < count * 2; i += 2)
	{
		Interval s(nums[i - 1], nums[i]);
		res.push_back(s);
	}
	return res;
}
void main()
{
	int a[] = { 1,3,5,7,3,5};
	vector<Interval> nums;
	for (int i = 1; i < sizeof(a) / sizeof(int); i+=2)
	{
		Interval s(a[i - 1], a[i]);
		nums.push_back(s);
	}
	vector<Interval> res;
	res = merge(nums);
	for (int i = 0; i <res.size(); i ++)
	{
		cout << res[i].start << "    " << res[i].end << endl;
	}
	system("pause");
}