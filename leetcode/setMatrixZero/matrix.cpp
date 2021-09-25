#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


string longestCommonPrefix(vector<string>& strs)
{
	string res;
	
	string min = *min_element(strs.begin(), strs.end(), 
		                     [] (const string& s1, const string& s2) { 
				                              return s1.length() < s2.length(); }
							                           );
	bool isDifferent = false;
	int j = 0;
	char c = '_';
	while(!isDifferent && j <= min.length()) {		
		res += c;
		c = strs[0][j];
		for(int i = 0; i < strs.size(); ++i)
			if(strs[i][j] != c)
				isDifferent = true;
		++j;
	}
	return res.substr(1, res.length() - 1);	

}

int main () 
{
	vector<string> s;

	s.push_back("flower");
	s.push_back("flow");
	s.push_back("flowing");
	cout << longestCommonPrefix(s) << endl;
}
	
