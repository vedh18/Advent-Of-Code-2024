/*
##################################################################
#                                                                #                       
#     Advent of Code 2024 - Day 5, Part 1                        #                       
#     Problem Link: https://adventofcode.com/2024/day/5          #                       
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
    
    int n = 1176 ; // The number rules in the input.
    map<int, vector<int>> m; // For each key, its value is a vector of elements which should come before the key.
    
    for (int i = 0; i<n; i++){
        string x;
        cin>>x;
        string n1 = "", n2 = "";
        // Each rule is of the form AB|CD
        // A, B, C, D are integers
        
        // n1 = AB
        n1 += x[0]; 
        n1 += x[1];

        // n2 = CD 
        n2 += x[3];  
        n2 += x[4];
        m[stoi(n2)].push_back(stoi(n1));
    }
    

    int m1 = 200; // The number of updates
    int ans = 0; 
    for (int i = 0; i<m1; i++){
        string str;
        cin>>str;
        
        // Creating a vector of integers by splitting the input string at ','
        vector<int> v;
        stringstream ss(str);
        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            v.push_back(stoi(substr));
        }

        bool flag = 1;
        for (int i = 0; i<(int)v.size(); i++){
            // For each element at i, we check all indices j (> i) if they are present if m[v[i]] or not.
            // If present the update is not valid.
            for (int j = i+1; j<(int)v.size(); j++){
                for (auto x: m[v[i]]){
                    if (x == v[j]){
                        flag = 0;
                        break;
                    }
                }
            }
        }
        
        if (flag){
            ans += v[(int)v.size()/2];
        }
    }
    cout << ans << endl;
    return 0;
}
