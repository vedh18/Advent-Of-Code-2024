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
    
    // The input was observed to be a square gird of n * n dimensions.
    int n = 140; 
    char a[n][n];
     
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    ll ans = 0; 
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            string x = ""; // Temporary string to store the current sequence
            
            // Check horizontally (left to right, or right to left)
            if (j >= 3) { // Ensure we have enough space to look backwards
                for (int k = j; k >= j - 3; k--) { // Traverse the previous 4 characters
                    x += a[i][k]; 
                }
                if (x == "XMAS" || x == "SAMX") ans++; // Check for "XMAS" or "SAMX"
            }
            
            x = ""; // Reset the string
            
            // Check vertically (top to bottom)
            if (i + 3 <= n - 1) { /
                for (int k = i; k <= i + 3; k++) { // Traverse the next 4 characters in the column
                    x += a[k][j]; 
                }
                if (x == "XMAS" || x == "SAMX") ans++; 
            }
            
            x = ""; 
            
            // Check diagonally (top-left to bottom-right)
            for (int k = 0; k <= 3; k++) {
                if (i + k >= n || j + k >= n) break; // Ensure we stay within bounds
                else {
                    x += a[i + k][j + k]; 
                }
            }
            if (x == "XMAS" || x == "SAMX") ans++; 
            
            x = "";
            
            // Check diagonally (top-right to bottom-left)
            for (int k = 0; k <= 3; k++) {
                if (i + k >= n || j - k < 0) break; 
                else {
                    x += a[i + k][j - k]; 
                }
            }
            if (x == "XMAS" || x == "SAMX") ans++; 
        }
    }

    cout << ans << endl;
    
    return 0;
}
