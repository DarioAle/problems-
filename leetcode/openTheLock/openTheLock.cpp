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
	for(string x : deadends)
	{
		visited[stoi(x)] = true;
	}

	int curr = 0000;
	int answer = -1;
	queue<int> q;
	do
	{
		if(curr == goal)
			break;

		if(!visited[curr])
		{
			visited[curr] = true;
			// push al neighbors
			int pow = 1;
			for(int j = 0; j < 4; ++j, pow *= 10)
			{

				int temp = (curr / pow) % 10;
				int temp2 = curr -( temp * pow);

				q.push(temp2 + ((temp + 1) % 10) * pow);
				q.push(temp2 + (temp ? temp - 1 : 9) * pow);

			}	
			answer++;
		}
		curr = q.front();
		q.pop();
	}
	while(!q.empty());

	while(!q.empty()){
		cout << q.front()<< " ";
		q.pop();
	}
	cout << endl;
	return answer;

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
