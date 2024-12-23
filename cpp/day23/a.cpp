/*
##################################################################
#                                                                #                       
#     Advent of Code 2024 - Day 23, Part 1                       #                       
#     Problem Link: https://adventofcode.com/2024/day/23         #                       
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

// Adjacency map where each node is mapped to a set of nodes which is adjacent to it
map<string, set<string>> adj;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 

    int n = 3380; // Number of edges/input

    set<string> s; // Set of distinct nodes
    
     // To avoid input parsing, I used {Ctrl-D --> Ctrl-F --> Find all} and replaced the commas with spaces.
    while (n--){
        string x, y;
        cin >> x >> y;

        // Filling the adjacency map and set
        adj[x].insert(y);
        adj[y].insert(x);
        s.insert(x);
        s.insert(y);
    }

    set<vector<string>> ss; // To store cycles of 3 with atleast one node starting with t

    // Brute Force: For every two nodes adjacent to a node with starting character t, 
    // checking if there is an edge between the two nodes
    for (auto x: s){
        if (x[0] == 't'){
            for (auto y: adj[x]){
                for (auto z: adj[x]){
                    if (adj[y].count(z)){
                        vector<string> a{x, y, z};
                        sort(all(a));
                        ss.insert(a);
                    }
                }
            }
        }
    }
    
    cout << (int)ss.size() << endl;

    return 0;
}
