#include<iostream>
#include<vector>
using namespace std;
int trap(vector<int>& height) {
	int len = height.size();
	if (len == 0)
		return 0;
	int i = 0;
	while (height[i] <= height[i+1] && i<len-1)
		i++;
	int water = 0;
	int ls = i;
	i = len - 1;
	while (height[i] <= height[i-1] && i>0)
		i--;
	int rs = i;
	int lmax = 0, rmax = 0,lpos=ls,rpos=rs,max1= height[ls],max2=0,pos1=ls,pos2=0;
	i = ls+1;
	while (i <= rs)
	{
		if (height[i] > max1)
		{
			max2 = max1;
			pos2 = pos1;
			max1 = height[i];
			pos1 = i;
		}
		else if(height[i] > max2)
		{
			pos2 = i;
			max2 = height[i];
		}
		i++;
	}
	if (pos2 > pos1)
	{
		rpos = pos2;
		lpos = pos1;
		lmax = max1;
		rmax = max2;
	}
	else
	{
		rpos = pos1;
		lpos = pos2;
		lmax = max2;
		rmax = max1;
	}
	int h = lmax > rmax ? rmax : lmax;
	for (i = lpos + 1; i < rpos; i++)
		water += h - height[i]>0? h - height[i]:0;
	int le = lpos,re=rpos;
	lmax = 0;
	while (le > ls)
	{
		for (i = ls; i < le; i++)
		{
			if (height[i] >= lmax)
			{
				lmax = height[i];
				lpos = i;
			}
		}
		i = lpos + 1;
		while (i < le)
		{
			water += lmax - height[i] > 0 ? lmax - height[i] : 0;
			i++;
		}
		le = lpos;
		lmax = 0;
	}
	rmax = 0;
	while (re < rs)
	{
		for (i = rs; i > re; i--)
		{
			if (height[i] >= rmax)
			{
				rmax = height[i];
				rpos = i;
			}
		}
		i = rpos - 1;
		while (i > re)
		{
			water += rmax - height[i] > 0 ? rmax - height[i] : 0;
			i--;
		}
		re = rpos;
		rmax = 0;
	}
	return water;
}
void main()
{
	int a[] = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	vector<int> height(a,a+ sizeof(a) / sizeof(int));
	int water = trap(height);
	cout << water;
	system("pause");
}