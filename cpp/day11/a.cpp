/*
##################################################################
#                                                                #                       
#     Advent of Code 2024 - Day 11, Part 1                       #                       
#     Problem Link: https://adventofcode.com/2024/day/11         #                       
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
    
    int n = 8; // The number of elements in the input
    
    vector<ll> v(n); // Vector to store the elements
    
    for (int i = 0; i<n; i++){
        cin >> v[i];
    }

    int blinks = 25;
    for (int i = 0; i<blinks; i++){
        // Temp vector to store the elements after a blink
        vector<ll> temp;
        
        for (int j = 0; j<(int)v.size(); j++){
            if (v[j] == 0){
                temp.push_back(1ll);
            }
            else{
                string st = to_string(v[j]);
                if ((int)st.size() % 2 == 0){
                    string st1 = st.substr(0, (int)st.size()/2);
                    string st2 = st.substr((int)st.size()/2, (int)st.size()/2);
                    temp.push_back(stoll(st1));
                    temp.push_back(stoll(st2));
                }   
                else{
                    temp.push_back(v[j] * 2024);
                }
            }
        }
        // Updating the vector to this temp
        v = temp;
    }

    cout << (int)v.size() << endl;

    return 0;
}
