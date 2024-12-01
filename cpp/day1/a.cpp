#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define ll long long int
#define all(v) (v).begin(), (v).end()
#define printvec(vec) {for(int i = 0; i<vec.size(); i++) cout << vec[i] << " "; cout << endl;} 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n = 1000; // The number of lines in the input
    
    vector<ll> v1, v2;
    
    for (int i = 0; i<n; i++){
        ll x, y;
        cin >> x >> y;
        v1.push_back(x);
        v2.push_back(y);
    }
    
    sort(all(v1));
    sort(all(v2));
    
    ll ans = 0;
    
    for (int i = 0; i<n; i++){
        ans += abs(v1[i] - v2[i]);
    }
    
    cout << ans << endl;

    return 0;
}   
