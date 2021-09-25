#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {	
public:	
	// missing early exit for the loop for 
	// faster iteration. 
	// If I go left to right I can stop
	// the moment my max reach falls short from the current
	// posion. Starting max reach at zero
	bool canJump(vector<int>& nums) {
		const int n = nums.size();
		int goal = n - 1;	


		for(int i = n - 2; i >= 0; --i) 
		{
			if( nums[i] >= goal - i)
				goal = i;
		}
		return goal == 0;
	}

	// optimized version
	bool canJumpEarlyExit(vector<int>& nums) {
		int n = nums.size();
		int reach= 0;
		for(int i=0;i<nums.size();i++){
			if(reach< i) {
				return false;
			}
			reach = max(reach, i+nums[i]);						        
		}		        
		return true;
	}
};

int main () 
{
	vector<int> v{1, 2, 1, 0, 4};
	Solution* obj = new Solution();
	int param_1 = obj->canJump(v);

	cout << (param_1 ? "true"  : "false") << endl;

	return 0;
}
	
