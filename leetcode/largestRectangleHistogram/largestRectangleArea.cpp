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

int largestRectangleArea(vector<int> &heights) {

	return 0;
}



int main()
{

	int n;
	cin >> n;

	vector<int> vecin(n);
	for(int j = 0; j < n; ++j)
		cin >> vecin[j];
	
	cout << largestRectangleArea(vecin) << endl;
	return 0;

}
