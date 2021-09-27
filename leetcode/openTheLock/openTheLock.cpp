#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>

using namespace std;

void printVec(vector<string>& a) 
{
	for(auto x : a)
		cout << x << " ";
	cout << endl;
}	

int openLock(vector<string>& deadends, string target)
{
	int goal = stoi(target);
	bool visited[10001];
	memset(visited, false, 10001);

        // all deadends are already visited
	for(string x : deadends)
		visited[stoi(x)] = true;

        // if start is a deadend we cannot get anywhere
	if(visited[0])
		return -1;

	int answer = -1;
	queue<int> q;
	q.push(0);
	visited[0] = true;
	
        while(!q.empty())
	{
		
		int q_size = q.size();
		for(int k = 0; k < q_size; ++k) 
		{

			int curr = q.front();q.pop();
			if(curr == goal)
				return ++answer;

			// push al neighbors
			for(int j = 0, pow = 1; j < 4; ++j, pow *= 10)
			{
				int temp = (curr / pow) % 10;      // get digit corresponding to iteration
				int temp2 = curr -( temp * pow);   // substract digit corresponding to iteration
				int up   = temp2 + ((temp + 1) % 10) * pow;     // add digit with 1 increment
				int down = temp2 + (temp ? temp - 1 : 9) * pow; // add digit with one decrement
				if(!visited[up]) {
					visited[up] = true;
					q.push(up);
				}
				if(!visited[down]) {
					visited[down] = true;
					q.push(down);
				}
			}
		}
		answer++;
	}
        return -1;
}

int main()
{
	string target;
	cin >> target;
	cout << "target: " << target << '\n';
	
	int n;
	cin >> n;

	vector<string>  arr(n);
	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	// printVec(arr);
	cout << "Open the lock" << endl;

	cout <<	openLock(arr, "1111") << endl;
	return 0;
}
