#include<iostream>
#include<vector>
using namespace std;
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	int height = obstacleGrid.size();
	int width = obstacleGrid[0].size();
	if (obstacleGrid[0][0] == 1 || obstacleGrid[height - 1][width - 1] == 1)
		return 0;
	for (int i = 0; i<height; i++)
	{
		for (int j = 0; j<height; j++)
		{
			if (obstacleGrid[i][j] == 1)
			{
				obstacleGrid[i][j] = -1;
				continue;
			}
			if (i == 0 && j == 0)
			{
				obstacleGrid[i][j] = 1;
				continue;
			}
			int left = 0, up = 0;
			if (j>0 && j<width)
				if (obstacleGrid[i][j - 1] != -1)
					left = obstacleGrid[i][j - 1];
			if (i>0 && i<height)
				if (obstacleGrid[i - 1][j] != -1)
					up = obstacleGrid[i - 1][j];
			obstacleGrid[i][j] = left + up;
		}
	}
	return obstacleGrid[height - 1][width - 1];
}
void main()
{
	int a[] = {0, 0};
	int height = 1;
	vector<vector<int>> obstacleGrid;
	for(int i = 0; i < sizeof(a) / sizeof(int); i+=height)
	{
		vector<int> n(a + i, a + i + height);
		obstacleGrid.push_back(n);
	}
	int num = uniquePathsWithObstacles(obstacleGrid);
	cout << num << endl;
	system("pause");
}