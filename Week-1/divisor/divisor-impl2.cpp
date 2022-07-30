#include <bits/stdc++.h>
using namespace std;

vector<int> getDivisors(int M) {
    vector<int> divisors;
    
	/* Find the divisors of M and store in vector*/
    for(int i=1;i*i<=M;i++) {
        if (M%i == 0){
            divisors.push_back(i);
			if (i * i != M) divisors.push_back(M / i);
		}
    }
	sort(divisors.begin(), divisors.end());
    return divisors;
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> divisors = getDivisors(M);
	int ans = 1;
	/* Find the largest divisor D which satisfies the condition M >= N*D */
	for(int i=0; i < divisors.size(); i++) {
	    if (N <= M / divisors[i]) {
	        ans = divisors[i];
	    }
	}
	cout << ans <<"\n";
	return 0;
}
