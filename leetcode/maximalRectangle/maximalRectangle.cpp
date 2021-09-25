#include<iostream>
#include<vector>
#include<iomanip>

// Given a rows x cols binary matrix filled with 0's and 1's, find 
//the largest rectangle containing only 1's and return its area.


using namespace std;

void printMatrix(vector<vector<char>> &matrix) 
{
	for(auto x : matrix) 
	{
		for(auto y : x)
			cout << setw(2) << y << ' ';
		cout << endl;
	}
	cout << endl;
}

void printVec(int a[], int n)
{
	for(int i = 0; i < n; ++i)
		cout << setw(2) << a[i] << ' ';
	cout << endl;
}	
int maximalRectangle(vector<vector<char>> &matrix) {
	
	printMatrix(matrix);
	int ans = 0;

	// generate matrix with accumulated rows
	for(int i = 0; i < matrix.size(); ++i)
		for(int j = 0; j < matrix[0].size(); ++j)
		{
			matrix[i][j] -= 0x30;
			if(j > 0)
				matrix[i][j] = matrix[i][j - 1] + matrix[i][j];
		}
	
	for(int i = 0; i < matrix[0].size(); ++i)
		for(int j = i; j < matrix[0].size(); ++j)
		{
			int bestSoFar = 0;
			for(int k = 0; k < matrix.size(); ++k)
			{
				int val = matrix[k][j] - (i > 0 ? matrix[k][i - 1] : 0); 
				cout << val << " este es val " << i << " " << j << endl;
				if(val == j - i + 1)
				{
					bestSoFar += val;
				}
				else {
					bestSoFar = 0;
				}
				ans = max(ans, bestSoFar);
			}
		}
				

	printMatrix(matrix);	
		
	return ans;
}

int maximalRectangleOptimized(vector<vector<char>> &matrix)
{

	if(matrix.empty()) return 0;
	const int m = matrix.size();
	const int n = matrix[0].size();
	int left[n], right[n], height[n];

	fill_n(left, n, 0); fill_n(right, n, n); fill_n(height, n,  0);
	int maxA = 0;
	for(int i = 0; i < m; ++i)
	{
		int cur_left = 0, cur_right = n;
		for(int j = 0; j < n; ++j)
		{
			height[j] = matrix[i][j] == '1' ? height[j] + 1 : 0;
		}
		cout << "height: ";
		printVec(height, n);
		for(int j = 0; j < n; ++j)
		{
			if( matrix[i][j] == '1')
				left[j] = max(left[j], cur_left);
			else { left[j] = 0; cur_left = j + 1; }
		}
		cout << "left:   ";
		printVec(left, n);
		for(int j = n - 1; j >= 0; --j)
		{
			if(matrix[i][j] == '1')
				right[j] = min(right[j], cur_right);
			else { right[j] = n; cur_right = j; }
		}
		cout << "right:  ";
		printVec(right, n);
		for(int j = 0; j < n; ++j)
			maxA = max(maxA, (right[j] - left[j]) * height[j]);
		cout << maxA << endl;
		cout << endl;
	}
	return maxA;
}

int main()
{
//	vector<vector<int>> vec  {{1,0,1},{0,-2,3}};
//	vector<vector<int>> vec { { 1, 2, 3, 4, 5}, { 6, 7, 8, 9, 10}, {11, 12, 13, 14, 15} };

	vector<vector<char>> vec { { '1', '0', '1', '0', '0'}, { '1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'} };
	vector<vector<char>> vec1 {{'1', '1'}};

	int m, n;
	cin >> m;
	cin >> n;

	vector<vector<char>> vecin(m, vector<char>(n));
	for(int i = 0; i < m; ++i)
		for(int j = 0; j < n; ++j)
			cin >> vecin[i][j];


	printMatrix(vecin);
	cout << maximalRectangleOptimized(vecin) << endl;
	return 0;

}
