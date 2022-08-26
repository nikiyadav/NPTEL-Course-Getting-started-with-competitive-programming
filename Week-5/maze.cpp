#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {
    int t;
    cin >> t;
    int h,w;
    while (t--) { // for each test case, do the following
        cin >> h >> w;
        vector<vector<char>> adj(h, vector<char>(w));  // adjacency list representation
        for(int i=0;i<h;i++) {
            for(int j=0;j<w;j++) {
                cin >> adj[i][j];
            }
        }

        int ans = -1;
        for(int i=0;i<h;i++) {
            for (int j=0;j<w;j++) {
                vector<vector<int>> d(h, vector<int>(w, -1));  // 2D vector with h elements where each element is a vector<int> (w,-1).
                                                        // vector<int> (w,-1) means vector having w elements each of value -1
                                                        // We will use this array to track visited vertices too
                queue<pair<int,int>> q;
                int ans_ij = -1;
                if (adj[i][j] == '#') continue;
                // otherwise, set (i,j) as source vertex
                q.push(pair<int,int>(i,j)); // push it in queue
                d[i][j] = 0; // update dist as 0
                while(!q.empty()) {
                    pair<int,int> p = q.front();
                    q.pop();
                    int r = p.first; int c = p.second;
                    // visit all adjacent nodes
                    if (r-1 >=0 && adj[r-1][c] == '.' && d[r-1][c] == -1) {
                        d[r-1][c] = d[r][c] + 1;
                        q.push(pair<int,int>(r-1,c));
                        ans_ij = max(ans_ij, d[r-1][c]);
                    }
                    if (c-1 >= 0 && adj[r][c-1] == '.' && d[r][c-1] == -1) {
                        d[r][c-1] = d[r][c] + 1;
                        q.push(pair<int,int> (r,c-1));
                        ans_ij = max(ans_ij, d[r][c-1]);
                    }
                    if (c+1 < w && adj[r][c+1] == '.' && d[r][c+1] == -1) {
                        d[r][c+1] = d[r][c] + 1;
                        q.push(pair<int,int> (r,c+1));
                        ans_ij = max(ans_ij, d[r][c+1]);
                    }
                    if (r+1 < h && adj[r+1][c] == '.' && d[r+1][c] == -1) {
                        d[r+1][c] = d[r][c] + 1;
                        q.push(pair<int,int> (r+1,c));
                        ans_ij = max(ans_ij, d[r+1][c]);
                    }
                }
                ans = max(ans, ans_ij);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}