/*
##################################################################
#                                                                #                       
#     Advent of Code 2024 - Day 16, Part 2                       #                       
#     Problem Link: https://adventofcode.com/2024/day/16         #                       
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
// ll a, b,c;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 141;
    int a[n][n];
    int sx, sy, ex, ey;
    vector<vector<ll>> dist(n, vector<ll>(n, -1));
    int aa[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            aa[i][j] = 0;
            char x;
            cin >> x;
            // cout << x;
            if (x == '#') a[i][j] = 1;
            if (x == '.') a[i][j] = 0;
            if (x == 'S') {
                a[i][j] = 0;
                sx = i;
                sy = j;
            }
            if (x == 'E') {
                a[i][j] = 0;
                ex = i;
                ey = j;
            }
            // cout << a[i][j];
        }
        // cout << endl;
    }

    priority_queue<pair<vector<ll>, string>, vector<pair<vector<ll>, string>>, greater<pair<vector<ll>, string>>> pq;
    pq.push({{0, 0, 1, sx, sy}, ""});
    ll dp[n][n][4];
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            for (int k = 0; k<4; k++){
                dp[i][j][k] = 1e9;
            }
        }
    }
    vector<string> sum;
    map<pair<int, int>, int> m;
    m[{0,1}] = 0;
    m[{0,-1}] = 1;
    m[{-1,0}] = 2;
    m[{1,0}] = 3;
    ll best = 1e9;
    while (!pq.empty()) {
        ll currDist = pq.top().f[0];
        ll currDx = pq.top().f[1];
        ll currDy = pq.top().f[2];
        ll x = pq.top().f[3];
        ll y = pq.top().f[4];
        string as = pq.top().s;
        pq.pop();
        if (currDist > dp[x][y][m[{currDx, currDy}]]) continue;
        else dp[x][y][m[{currDx, currDy}]] = currDist;
        if (x == ex && y == ey && currDist <= best) {
            best = currDist;
            sum.push_back(as);
            // cout << currDist << endl;
        }

        vector<pair<ll, ll>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        for (int i = 0; i<4; i++) {
            pair<ll, ll> dir = directions[i];
            ll tx = x + dir.first, ty = y + dir.second;
            if (tx >= 0 && tx < n && ty >= 0 && ty < n && a[tx][ty] == 0) {
                if (make_pair(currDx, currDy) == make_pair(-dir.f, -dir.s)) continue;
                ll newDist = currDist + (make_pair(currDx, currDy) == dir ? 1 : 1001);
                string temp = as;
                if (i == 0) temp += 'R';
                if (i == 1) temp+='L';
                if (i == 2) temp += 'U';
                if (i == 3) temp += 'D';
                pq.push({{newDist, dir.first, dir.second, tx, ty}, temp});
            }
        }
    }
    // cout << "YES" << endl;
    aa[ex][ey] = 1;
    aa[sx][sy] = 1;
    for (auto ss: sum){
        cout << ss << endl;
        int currx = ex;
        int curry = ey;
        reverse(all(ss));
        for (int i = 0; i<(int)ss.size(); i++){
            if (ss[i] == 'U'){
                currx += 1;
            }
            if (ss[i] == 'D'){
                currx -= 1;
            }
            if (ss[i] == 'L'){
                curry += 1;
            }if (ss[i] == 'R'){
                curry -= 1;
            }
            aa[currx][curry] = 1;
        }
    }
    ll ans = 0;
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            if (aa[i][j] == 1) ans++;
            cout << aa[i][j];
            // cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    cout << ans << endl;
    return 0;
}
