#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int binary_search(vector<int> &V, int low, int high, int X) {
    if (low > high) return -1;
    else {
        int mid = (low+high)/2;
        if ((mid == low && V[mid] > X ) || (mid > low && V[mid] > X && V[mid-1] <= X) ) {
            return mid;
        }
        else if (V[mid] <= X) {  // search on the right side
            binary_search(V, mid+1, high, X);
        }
        else {                  // search on the left side
            binary_search(V, low, mid-1, X);
        }
    }
}

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
    for(int i=1;i<N-1;i++) {
        for(int j=i+1;j<N;j++) {
            int diff = V[j]-V[i];
            bool flag = false;
            int k;
            /*for(k=0;k<i;k++) {    // summation{i=1 to i<N} i*(N-i) = O(N^3)
                if (V[k]>diff) {
                    flag = true;
                    break;
                }
            }
            if (flag) ans =  ans + (i-k);
            else break;*/
            int k = binary_search(V, 0, i-1, diff);
            if (k != -1) {
                ans += (i-k);
            }
            else break;
        }
    }

    cout << ans << "\n";
    return 0;
}

// Time complexity: O(N^3) without binary search, O(N^2 logN) with binary search