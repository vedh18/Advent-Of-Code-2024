/*
##################################################################
#                                                                #                       
#     Advent of Code 2024 - Day 23, Part 2                       #                       
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

set<string> largest; // Set to store the largest clique.

// Dfs where the next node is added to the set only if it has edges to all the current nodes in the set
void dfs(string node, set<string>& current){
    for (auto nextNode: adj[node]){
        if (!current.count(nextNode)){
            bool flag = 1;
            for (auto curr: current){
                if (!adj[curr].count(nextNode)){
                    flag = 0;
                    break;
                }
            }
            if (flag){
                current.insert(nextNode);
                dfs(nextNode, current);
            }
        }
    }
}
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

    for (auto x: s){
        set<string> current;
        
        dfs(x, current);

        // If the size of the current set is more than that of the global maximum, the largest set is updated
        if ((int)current.size() > (int)largest.size()){
            largest = current;
        }
    }

    // Already sorted so only have to print
    for (auto x: largest){
        cout << x << ",";
    }
    cout << endl;

    // Removed last comma while entering the answer

    return 0;
}
