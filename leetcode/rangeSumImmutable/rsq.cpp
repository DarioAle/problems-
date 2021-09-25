#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class NumArray {
private:
	vector<int> arr;
public:
	NumArray(vector<int>& nums)
	{
		arr = nums;	
		for(int i = 1; i < arr.size(); ++i)
			arr[i] = arr[i - 1] + arr[i];
	}

	int sumRange(int left, int right)
	{
		return arr[right] - ((left > 0) ? arr[left - 1] : 0 );
	}

};

int main () 
{
	vector<int> v{0, 1, 2, 0 };
//	NumArray n = NumArray(v);
	NumArray* obj = new NumArray(v);
	int param_1 = obj->sumRange(0,3);

	cout << param_1 << endl;

	return 0;
}
	
