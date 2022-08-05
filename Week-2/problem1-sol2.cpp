#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int N, Li;
    cin >> N;
    vector<int> V;
    for(int i=0; i<N; i++) {
        cin >> Li;
        V.push_back(Li);
    }
    sort(V.begin(), V.end());

    int ans = 0;
    for(int i=N-1; i>1; i--) {
        int r = i-1;
        int l = 0;
        while (l<r) {
            int sum = V[l] + V[r];
            if (sum > V[i]) {
                ans += (r-l);
                r--;
            }
            else {
                l++;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}

// Time Complexity: O(N^2)