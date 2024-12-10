/*
##################################################################
#                                                                #                       
#     Advent of Code 2024 - Day 10, Part 2                       #                       
#     Problem Link: https://adventofcode.com/2024/day/10         #                       
#                                                                #                       
##################################################################
*/


#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define ll long long int
#define all(v) (v).begin(), (v).end()
#define printvec(vec) {for(int i = 0; i < vec.size(); i++) cout << vec[i] << " "; cout << endl;} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    
    int n = 45; // Input was a square grid of 45 x 45
    
    int a[n][n]; // Storing input as int for easier processing 
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            char x;
            cin >> x;
            a[i][j] = x - '0';
        }
    }

    int ans = 0;

    // Starting bfs when encountering a trailhead.
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            if (a[i][j] == 0){
                // quqeue contains coordinates (i, j)
                queue<pair<int, int>> q;
                q.push({i, j});
                while (!q.empty()){
                    // Coordinates of current point
                    int xo = q.front().f;
                    int yo = q.front().s;
                    q.pop();
                    int val = a[xo][yo];
                    vector<pair<int, int>> diff = {{1, 0}, {0, 1}, {-1, 0}, {0,-1}}; // To store the directions in which we can move from current point
                    for (auto x: diff){
                        // Coordinates of next point
                        int xn = xo + x.f;
                        int yn = yo + x.s;

                        // If the points are valid
                        if (xn >= 0 && xn <=n-1 && yn>=0 && yn<=n-1){
                            // If the new coordinates point to 9 and previous coordinate was 8
                            // Now, each time a 9, is reached we increment ans, as it will indicate a new unique path
                            if (a[xn][yn] == 9 && val == 8){
                                ans++;
                            }
                            // If not equal 9
                            // If the current value is 1 greater than the previous cell value in the path we continue the path
                            else if (a[xn][yn] == val + 1){
                                q.push({xn, yn});
                            }
                        }
                    }
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
