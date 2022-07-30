#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; // number of test cases
	cin >> t;
	int n,e;
	while (t--) {
	    cin >> n;
        int min=INT_MAX, max=INT_MIN;
	    for(int i=0;i<n;i++) {
	        cin >> e;  
            if (e < min) min = e;
            if ( e > max) max = e;
	    }
        cout << "\n" << max-min;
    }
    return 0;
}