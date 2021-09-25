#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>      // std::setw
#include <set>      // std::setw

using namespace std;

void printMatrix(vector<vector<int>> &matrix)
{
	for(auto x : matrix)
	{
	       for(auto y : x)
	       		cout << setw(2) << y << ' ';
		cout << endl;	
	}
	cout << endl;
} 

void printVector(vector<int> &v)
{
       for(auto y : v)
		cout << setw(2) << y << ' ';
	cout << endl;	
}
// this is just for the lols
void reverseArrayRecursively(vector<int> &arr)
{

}


int kadaneLessThanK(vector<int> v, int n, int k)
{
	int ans =INT_MIN, sum = 0;
	set<int> s;
	s.insert(0);
	for(int i = 0; i < n; ++i)
	{
		sum += v[i];
		auto it = s.lower_bound(sum - k);
		if(it != s.end())
		{
			ans = max(ans, sum - *it);
		}
		s.insert(sum);
	}
	return ans;
}

int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
{
	int m = matrix.size();
	int n = matrix[0].size();
	int ans = INT_MIN;

	for(int i = 0; i < m; ++i)
	{
		vector<int> mat(n, 0);
		for(int j = i; j < m; ++j)
		{
			for(int k = 0; k < n; ++k)
			{
				mat[k] += matrix[j][k];
			}
			printVector(mat);
			ans = max(ans, kadaneLessThanK(mat, n, k));
		}
		cout << endl;
	}
	return ans;

}

int main()
{

	// vector<vector<int>> vec  {{1,0,1},{0,-2,3}};
	// vector<vector<int>> vec { { 1, 2, 3, 4, 5}, { 6, 7, 8, 9, 10}, {11, 12, 13, 14, 15} };
	vector<vector<int>> vec { { 1, 0, 1, 0, 0}, { 1, 0, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 0, 0, 1, 0} };
	cout << maxSumSubmatrix(vec, 120) << endl;
}
