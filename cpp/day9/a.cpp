/*
##################################################################
#                                                                #                       
#     Advent of Code 2024 - Day 9, Part 1                        #                       
#     Problem Link: https://adventofcode.com/2024/day/9          #                       
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
    
    string x;
    cin >> x;

    // Finding the sum of numbers to find the size of layout in which files and empty spaces exist.
    int sum = 0;
    for (auto ch: x){
        sum += (ch - '0');
    }

    int a[sum]; // Integer array to store the files
    
    int idx = 0; // Current index to tract the postion in array a
    
    int curr_id = 0; // The current id of the file we are processing 

    // Filling the array A accoding to the disk map (string x) provided.
    for (int i = 0; i<(int)x.size(); i++){
        if (i%2 == 0){
            for (int j = 0; j<x[i]-'0'; j++){
                a[idx++] = curr_id;
            }
            curr_id++;
        }
        else{
            // Representing empty spaces as -1
            for (int j = 0; j<x[i]-'0'; j++){
                a[idx++] = -1;
            }
        }
    }

    // Two pointers.
    int j = sum-1;
    int i = 0;
   
    while (i < j){
        // i represents the left most index with an empty space (-1).
        while (i<=sum-1 && a[i] != -1){
            i++;
        }
        // To count the number of empty spaces in continuation
        int c = 0;
        for (int k = i; k<=sum-1; k++){
            if (a[k] == -1) c++;
            else break;
        }

        // j is the right most index with a file
        while (j>=0 && a[j] == -1){
            j--;
        }

        // Checking if i and j are valid for swap
        if (i > sum-1 || j < 0 || j <= i+c-1) break;
        
        swap(a[i], a[j]);
        i++;
        j--;
    }

    // Calculating the final score based on the modified array a
    ll ans = 0;
    for (int i = 0; i<=sum-1; i++){
        if (a[i] == -1) break;
        ans += i * a[i];
    }

    cout << ans << endl;

    return 0;
}
