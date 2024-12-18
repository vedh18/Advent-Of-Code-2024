/*
##################################################################
#                                                                #                       
#     Advent of Code 2024 - Day 15, Part 1                       #                       
#     Problem Link: https://adventofcode.com/2024/day/15         #                       
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
    
    int n = 50;
    char a[n][n];
    int x = -1, y = -1;
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            cin >> a[i][j];
            if (a[i][j] == '@'){
                x = i;
                y = j;
            }
        }
    }
    int m = 20019;
    vector<char> v(m);
    for (int i = 0; i<m; i++){
        cin >> v[i];
    }
    // printvec(v);
    for (auto ch: v){
        int dx = -1, dy = -1;
        if (ch == '^'){
            dx = -1;
            dy = 0;
        }
        else if (ch == '>'){
            dx = 0;
            dy = 1;
        }
        else if (ch == '<'){
            dx = 0;
            dy = -1;
        }
        else{
            dx = 1;
            dy = 0;
        }
        // cout << dx << " " << dy << endl;
        if (x + dx >=0 && x + dx <=n-1 && y + dy >=0 && y + dy <=n-1){
            if (a[x+dx][y+dy] == '.'){
                swap(a[x+dx][y+dy], a[x][y]);
                x += dx;
                y += dy;
            }
            else{
                int ix = x;
                int iy = y;
                while (a[x+dx][y+dy] == 'O'){
                    x += dx;
                    y += dy;
                }
                if (a[x+dx][y+dy]=='#'){
                    x = ix;
                    y = iy;
                    continue;
                }
                else{
                    swap(a[ix+dx][iy+dy], a[x+dx][y+dy]);
                    swap(a[ix+dx][iy+dy], a[ix][iy]);
                    x = ix + dx;
                    y = iy + dy;

                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            if (a[i][j] == 'O'){
                ans += 100 * (i) + j;
            }
            // cout << a[i][j];
        }
        // cout << endl;
    }
    cout << ans << endl;
    return 0;
}
