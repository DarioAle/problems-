#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int firstDayBeenInAllRooms(vector<int>& nextVisit)
{
	int numberOfDays = 0;
	int visitedRooms = 0;
	int n = nextVisit.size();
	vector<int> hist(n, 0);
	const int bigP = 1000000007;
	int i = 0;

	while(visitedRooms < n)
	{
		if(hist[i] == 0)
			visitedRooms++;
		
		hist[i]++;
		if(hist[i] % 2 == 1)
			i = nextVisit[i];
		else
			i = ( i + 1 ) % n;
		
		numberOfDays = (numberOfDays % bigP) + 1;
	}	
	return numberOfDays - 1;
}

int firstDayBeenInAllRoomsOptimized(vector<int>& nextVisit) {
	vector<int> cumSum(nextVisit.size(), 0);
	const int MOD = 1000000007;
			
	cumSum[0] = 2;

	for(int i = 1; i < nextVisit.size(); ++i)
	{
	    int left = nextVisit[i];
	    int temp = (cumSum[i - 1]  - (left ? cumSum[left - 1] : 0) % MOD);
	    temp = (temp + MOD) % MOD;
	    cumSum[i] = ( (temp) + (cumSum[i - 1]) + 2) % MOD;
	}
	
	// for(auto x : cumSum)
        //     cout << x << " ";
	//                 
        return cumSum[nextVisit.size() - 2 ];
}

int main () 
{
	vector<int> v{0, 1, 2, 0 };
	cout << "ans: " << firstDayBeenInAllRooms(v) << endl;
}
	
