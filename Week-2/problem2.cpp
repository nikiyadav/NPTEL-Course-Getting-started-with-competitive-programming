#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool myComparator (int i,int j) { return (i>j); }

int main() {
    int N, Ai;
    cin >> N;
    vector<int> V;
    for(int i=0; i<N; i++) {
        cin >> Ai;
        V.push_back(Ai);
    }
    sort(V.begin(), V.end(), myComparator);

    int ans = 0;
    int numVibes = N-1;
    if(numVibes != 0) {
        ans += V[0];
        numVibes--;
        int i=1;
        while(numVibes) {
            if (numVibes > 1) {
                ans += 2*V[i];
                numVibes-=2;
            }
            else {
                ans += V[i];
                numVibes--;
            }
            i++;
        }
    }
    cout << ans << "\n";
    return 0;
}

// Time complexity: O(NlogN)