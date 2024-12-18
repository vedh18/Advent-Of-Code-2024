/*
##################################################################
#                                                                #                       
#     Advent of Code 2024 - Day 15, Part 2                       #                       
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

ll rx, ry; // gloabal start coordinates
char a[50][100];

ll can_move_vertically(ll x, ll y, ll dy) {
    if (a[y + dy][x] == '#') return 1; 
    if (a[y + dy][x] == '.') return 0;

    return can_move_vertically(x, y + dy, dy) +
           can_move_vertically(x + (a[y + dy][x] == '[' ? 1 : -1), y + dy, dy);
}

void move_vertically(ll x, ll y, ll dy) {
    if (a[y + dy][x] == '[' || a[y + dy][x] == ']') {
        move_vertically(x + (a[y + dy][x] == '[' ? 1 : -1), y + dy, dy);
        move_vertically(x, y + dy, dy);
    }
    a[y + dy][x] = a[y][x];
    if (a[y][x] == '@') ry = y + dy;
    a[y][x] = '.';
}

void move(ll x, ll y, char c) {
    ll dx = 0, dy = 0, temp_x;
    if (c == '<') {
        dx = -1;
        dy = 0;
    } else if (c == '^') {
        dx = 0;
        dy = -1;
    } else if (c == '>') {
        dx = 1;
        dy = 0;
    } else if (c == 'v') {
        dx = 0;
        dy = 1;
    } else {
        return;
    }

    if (dy == 0) {
        temp_x = x;
        while (a[y][temp_x + dx] == '[' || a[y][temp_x + dx] == ']') temp_x += dx;

        if (a[y][temp_x + dx] == '#') return;

        while (temp_x != x) {
            a[y][temp_x + dx] = a[y][temp_x];
            temp_x -= dx;
        }
        a[y][x + dx] = a[y][x];
        rx = x + dx;
        a[y][x] = '.';
    } else {
        if (can_move_vertically(x, y, dy) == 0)
            move_vertically(x, y, dy);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    
    ll n = 50;
    for (ll i = 0; i<n; i++){
        for (ll j = 0; j<n; j++){
            char ch;
            cin >> ch;
            if (ch == '@'){
                rx = 2*i;
                ry = 2*j;
                a[i][2*j] = '@';
                a[i][2*j+1] = '.';
            }
            else if (ch == 'O'){
                a[i][2*j] = '[';
                a[i][2*j+1] = ']';
            }
            else{
                a[i][2*j] = ch;
                a[i][2*j+1] = ch;
            }
        }
    }
    ll m = 20019;
    vector<char> v(m);
    for (ll i = 0; i<m; i++){
        cin >> v[i];
        move(rx, ry, v[i]);
    }
    ll ans = 0;
    for (ll i = 0; i<n; i++){
        for (ll j = 0; j<2*n; j++){
            if (a[i][j] == '['){
                ans += 100 * (i) + j;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
