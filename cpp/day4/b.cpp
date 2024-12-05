#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define ll long long int
#define all(v) (v).begin(), (v).end()
#define printvec(vec) {for(int i = 0; i<vec.size(); i++) cout << vec[i] << " "; cout << endl;} 

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
            
            // Ensuring we don't go out of bounds
            if (j + 2 >= n || i + 2 >= n) continue; // Skip if out of bounds
            
            // Check the center of the pattern
            if (a[i + 1][j + 1] == 'A') { 
                // Check the diagonals of the "X-pattern"
                if (
                    // Top-left to bottom-right diagonal should be MAS or SAM
                    ((a[i][j] == 'M' && a[i + 2][j + 2] == 'S') || (a[i][j] == 'S' && a[i + 2][j + 2] == 'M')) &&
                    // Bottom-left to top-right diagonal should be MAS or SAM
                    ((a[i + 2][j] == 'M' && a[i][j + 2] == 'S') || (a[i + 2][j] == 'S' && a[i][j + 2] == 'M'))
                ) {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
    
    return 0; 
}
