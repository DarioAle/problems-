#include <iostream>
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

// this is just for the lols
void reverseArrayRecursively(vector<int> &arr)
{

}



int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
{
	printMatrix(matrix);

	// generate matrix with accumulated rows
	for(int i = 0; i < matrix.size(); ++i)
		for(int j = 1; j < matrix[0].size(); ++j)
		{ 
			matrix[i][j] = matrix[i][j - 1] + matrix[i][j];
		}	
	
	printMatrix(matrix);

	int answer = -100000;
	for(int i = 0; i < matrix[0].size(); ++i) 
		for(int j = i; j < matrix[0].size(); ++j){
			int partialAns = -100000; 
			int sumj = 0;
			set<int> auxSet;
			auxSet.insert(0);		
			for(int l = 0; l < matrix.size(); ++l) {
				int val = matrix[l][j] - (i > 0 ? matrix[l][i - 1] : 0); 
				sumj += val;
				auto gap = auxSet.lower_bound(sumj - k);
				if(gap != auxSet.end()) {
					partialAns = max(partialAns, sumj - *gap);

				}
				auxSet.insert(sumj);

			}
			cout << endl << endl;
			answer = max(answer, partialAns);
		}	

	
	return answer;
}

int main()
{

	vector<vector<int>> vec  {{1,0,1},{0,-2,3}};
//	vector<vector<int>> vec { { 1, 2, 3, 4, 5}, { 6, 7, 8, 9, 10}, {11, 12, 13, 14, 15} };
	cout << maxSumSubmatrix(vec, 2) << endl;
}
