/***
You are given integers N and M.

Consider a sequence 
a of length N consisting of positive integers such that a1​+a2​+...+aN​ = M. Find the maximum possible value of the greatest common divisor of 

a1​,a2​,...,aN​.
Constraints

    All values in input are integers.

1≤N≤105

    N≤M≤109

Input

Input is given from standard input in the following format:

N M

Output

Print the maximum possible value of the greatest common divisor of a sequence a1​,a2​,...,aN​ that satisfies the condition.

Examples
Sample Input 1

3 14

Sample Output 1

2

Consider the sequence (a1​,a2​,a3​)=(2,4,8). Their greatest common divisor is 2, and this is the maximum value. In particular, there is no sequence involving numbers larger than two for which the sum is 14 and the GCD is larger than two.
****/


#include <bits/stdc++.h>
using namespace std;

vector<int> getDivisors(int M) {
    vector<int> divisors;
    
    for(int i=1;i<M;i++) {
        if (M%i == 0)
            divisors.push_back(i);
    }
    return divisors;
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> divisors = getDivisors(M);
	int ans = 1;
	for(int i=0; i < divisors.size(); i++) {
	    if (N <= M / divisors[i]) {
	        ans = divisors[i];
	    }
	}
	cout << ans <<"\n";
	return 0;
}
