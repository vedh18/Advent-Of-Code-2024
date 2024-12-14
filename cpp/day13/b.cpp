/*
##################################################################
#                                                                #                       
#     Advent of Code 2024 - Day 13, Part 2                       #                       
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
   
    ll fans = 0; // To store the final answer
    int n = 320; // The input contained 320 button, target combinations
    for (int i = 0; i<n; i++){
        if (i != 0){
            string temp;
            getline(cin, temp);
            // After each button and target there was an empty line as well.
        }

        // Button A
        string str;
        getline(cin, str);
        string s1 = str.substr(12, 2);
        string s2 = str.substr(18, 2);
        int ax = stoi(s1);
        int ay = stoi(s2);

        // Button B
        getline(cin, str);
        s1 = str.substr(12, 2);
        s2 = str.substr(18, 2);
        int bx = stoi(s1);
        int by = stoi(s2);

        // Target
        getline(cin, str);
        string s;
        stringstream ss(str);
        vector<string> v;
        while (getline(ss, s, ' ')) {     
            v.push_back(s);
        }
        v[1].pop_back();
        s1 = v[1].substr(2, (int)v[1].size()  -2);
        s2 = v[2].substr(2, (int)v[2].size()  -2);
        ll tx = stoll(s1) + 10000000000000;
        ll ty = stoll(s2) + 10000000000000;

        // Matrix Inversion
        if (ax * by - ay * bx != 0){
            ll aa = by * tx -  bx * ty;
            ll bb = -ay*tx + ax*ty;
            if (aa % (ax * by - ay * bx) == 0 && bb % (ax * by - ay * bx) == 0){
                fans += 3 * aa/(ax * by - ay * bx) + bb/(ax * by - ay * bx);
            }
        }
    }
  
    cout << fans << endl;
  
    return 0;
}
