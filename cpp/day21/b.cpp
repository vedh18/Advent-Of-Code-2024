/*
##################################################################
#                                                                #                       
#     Advent of Code 2024 - Day 21, Part 2                       #                       
#     Problem Link: https://adventofcode.com/2024/day/21         #                       
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

// dp[i][j] is a set which stores all the possible paths from i to j in the original 0-9, A keypad. 
// A is represented by index 10.
// +---+---+---+
// | 7 | 8 | 9 |
// +---+---+---+
// | 4 | 5 | 6 |
// +---+---+---+
// | 1 | 2 | 3 |
// +---+---+---+
//     | 0 | A |
//     +---+---+
vector<vector<set<string>>> dp(11, vector<set<string>>(11, set<string>()));

// Similarily dp2[i][j] is a set which stores all the paths from i to j in the below keypad
//     +---+---+
//     | ^ | A |
// +---+---+---+
// | < | v | > |
// +---+---+---+
// we convert characters '<', '^', 'v', '>', 'A' using map
vector<vector<set<string>>> dp2(5, vector<set<string>>(5, set<string>()));

// map to the characters in the 2nd keypad to integers.
map<char, int> mp;

// Similarily for the first keypad
map<char, int> mp2;

// The function f1, takes the string to be input in the first keypad, 
// and returns a vector of all posible paths the robot can take with the 2nd keypad to input string x 
// in the first keypad.
vector<string> f1(string x){
    vector<string> ans;
    int start = mp2['A'];
    // cout << x << endl;
    for (auto ch: x){
        if ((int)ans.size() != 0){
            vector<string> tans;
            for (auto a : ans){
                for (auto path: dp[start][mp2[ch]]){
                    string temp = a + path;
                    temp += 'A';
                    tans.push_back(temp);
                }
            }
            ans = tans;
            start = mp2[ch];
        }
        else{
            for (auto path: dp[start][mp2[ch]]){
                string temp = path + 'A';
                ans.push_back(temp);
            }
            start = mp2[ch];
        }
    }
    return ans;
}

ll actual_dp[5][5][26];

// Recursion with memoization where actual_dp[i][j][r] stores the number of moves required for the rth robot will have
// to take to press cell j after pressing cell i.
ll from_x_to_y(int x, int y, int r){
    if (actual_dp[x][y][r] != 1e18) return actual_dp[x][y][r];
    ll ans = 1e18;
    for (auto path: dp2[x][y]){
        ll mn = 0;
        string temp = path + 'A';
        if (r == 1){
            ans = min(ans, (ll)temp.size());
            continue;
        }
        for (int i = 0; i<(int)temp.size(); i++){
            if (i == 0){
                mn += from_x_to_y(4, mp[temp[i]], r-1);
            }
            else{
                mn += from_x_to_y(mp[temp[i-1]], mp[temp[i]], r-1);
            }
        }
        ans = min(ans, mn);
    }
    return actual_dp[x][y][r] = ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 

    // Initializing the actual_dp with very high values.
    for (int i = 0; i<5; i++){
        for (int j = 0; j<5; j++){
            for (int k = 0; k<=25; k++){
                actual_dp[i][j][k] = 1e18;
            }
        }
    }

    // Filling the two maps
    mp['<'] = 0;
    mp['>'] = 2;
    mp['v'] = 1;
    mp['^'] = 3;
    mp['A'] = 4;
    for (int i = 0; i<=9; i++){
        mp2[(char)(i + '0')] = i;
    }
    mp2['A'] = 10;
    
    int n = 5; // Input contains 5 strings.
    
    vector<string> v(n);
    for (int i = 0; i<n; i++){
        cin >> v[i];
    }
    
    // Filling the dp array
    // The path to i from i will be empty.
    for (int i = 0; i<=10; i++){
        dp[i][i].insert("");
    }

    // Similarily filling for neighbours manually.
    dp[0][2].insert("^");
    dp[10][3].insert("^");
    dp[1][4].insert("^");
    dp[2][5].insert("^");
    dp[3][6].insert("^");
    dp[4][7].insert("^");
    dp[5][8].insert("^");
    dp[6][9].insert("^");
    dp[7][4].insert("v");
    dp[8][5].insert("v");
    dp[9][6].insert("v");
    dp[4][1].insert("v");
    dp[5][2].insert("v");
    dp[6][3].insert("v");
    dp[2][0].insert("v");
    dp[3][10].insert("v");
    dp[7][8].insert(">");
    dp[8][9].insert(">");
    dp[4][5].insert(">");
    dp[5][6].insert(">");
    dp[1][2].insert(">");
    dp[2][3].insert(">");
    dp[0][10].insert(">");
    dp[8][7].insert("<");
    dp[9][8].insert("<");
    dp[5][4].insert("<");
    dp[6][5].insert("<");
    dp[2][1].insert("<");
    dp[3][2].insert("<");
    dp[10][0].insert("<");

    // Similarily for dp2
    for (int i = 0; i<=4; i++){
        dp2[i][i].insert("");
    }
    dp2[1][3].insert("^");
    dp2[2][4].insert("^");
    dp2[3][1].insert("v");
    dp2[4][2].insert("v");
    dp2[0][1].insert(">");
    dp2[1][2].insert(">");
    dp2[3][4].insert(">");
    dp2[1][0].insert("<");
    dp2[2][1].insert("<");
    dp2[4][3].insert("<");

    // Used a Flloyd Washall inspired approach to fill the dp arrays.
    for (int k = 0; k<=10; k++){
        for (int i = 0; i<=10; i++){
            for (int j = 0; j<=10; j++){
                if (dp[i][k].size() == 0 || dp[k][j].size() == 0) continue;
                for (auto s1: dp[i][k]){
                    for (auto s2: dp[k][j]){
                        string temp = s1 + s2;
                        if (dp[i][j].empty() || (int)temp.size() < (int)(*dp[i][j].begin()).size()){
                            dp[i][j].clear();
                            dp[i][j].insert(temp);
                        }
                        else if ((int)temp.size() == (int)(*dp[i][j].begin()).size()){
                            dp[i][j].insert(temp);
                        }
                    }
                }
            }
        }
    }
    for (int k = 0; k<=4; k++){
        for (int i = 0; i<=4; i++){
            for (int j = 0; j<=4; j++){
                if (dp2[i][k].size() == 0 || dp2[k][j].size() == 0) continue;
                for (auto s1: dp2[i][k]){
                    for (auto s2: dp2[k][j]){
                        string temp = s1 + s2;
                        if (dp2[i][j].empty() || (int)temp.size() < (int)(*dp2[i][j].begin()).size()){
                            dp2[i][j].clear();
                            dp2[i][j].insert(temp);
                        }
                        else if ((int)temp.size() == (int)(*dp2[i][j].begin()).size()){
                            dp2[i][j].insert(temp);
                        }
                    }
                }
            }
        }
    }

    ll ans = 0;

    for (auto x: v){
        vector<string> num = f1(x);
        ll mn = 1e18;
        for (auto x1: num){
            ll curr = 0;
            for (int i = 0; i<(int)x1.size(); i++){
                if (i == 0){
                    curr += from_x_to_y(4, mp[x1[i]], 25);
                }
                else{
                    curr += from_x_to_y(mp[x1[i-1]], mp[x1[i]], 25);
                }
            }
            mn = min(mn, curr);
        }

        ll t = stoll(x.substr(0, 3));
        cout << mn << " " << t << endl;
        ans += t * mn;
    }
    cout << ans << endl;

    return 0;
}
