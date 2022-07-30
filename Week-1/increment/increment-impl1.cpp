#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t; // number of test cases
	cin >> t;
	int n,e;
	while (t--) {
	    cin >> n;
	    vector<int> vec;
	    for(int i=0;i<n;i++) {
	        cin >> e;  
	        vec.push_back(e); // vector of integers
	    }
	    sort(vec.begin(), vec.end());
	    cout << "\n" <<  vec[n-1] - vec[0];
	}
	return 0;
}
