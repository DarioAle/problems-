#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#define n_ 1000
using namespace std;

class Solution 
{
private:
	bool sieve_[n_ + 1];
	void printPrimes() {
		for(int i = 2; i <= n_; ++i) {
			if(sieve_[i] == true) {
				cout << i << " ";
			}
		}
		cout << endl;
	}
public:
	Solution()  
	{
		memset(sieve_, true, sizeof(sieve_));
		for(int p = 2; p * p <= n_; ++p) {
			if(sieve_[p] == true) {
				for(int j = p * p; j <= n_; j += p)
					sieve_[j] = false;
			}
		}
		//printPrimes();
	}

	
	int minSteps(int n) 
	{
		int answer = 0;
		int j = 2;
		while(n > 1) {
			while(sieve_[j] == true && n % j == 0){
				answer += j;
				n /= j;
			}
			++j;
		}
		return answer;
	}
};

int main() {

	cout << "Hello keys" << endl;
	Solution mySol;
	
	cout << mySol.minSteps(32) << endl;
	return 0;
}
