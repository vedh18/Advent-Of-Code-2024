#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define ll long long int
#define all(v) (v).begin(), (v).end()
#define printvec(vec) {for(int i = 0; i<vec.size(); i++) cout << vec[i] << " "; cout << endl;} 

// Function to split the input string based on spaces.
vector<string> split_sentence(string sen) {
    stringstream ss(sen);
    string word;
    vector<string> words;
    
    while (ss >> word) {
        words.push_back(word);
    }
    
    return words;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n = 1000; // Total number of input reports
    int ans = 0; // Counter for valid reports
    
    for (int i = 0; i<n; i++){
        // Read a single line of input representing one report
        string input;
        getline(cin, input);
        
        // Split the input string into individual words
        vector<string> v = split_sentence(input);
        
        // Changing each element in vector to string.
        // vi represents the report with each element being a level.
        vector<int> vi;
        for (auto x: v){
            vi.push_back(stoi(x));
        }
        
        bool increasing = (vi[0] < vi[1]); // increasing is 1 when series is strictly incresing and 0 when strictly decreasing.
        
        bool valid = 1; // If the current report is invalid this is changed to 0
        
        for (int i = 1; i<(int)vi.size(); i++){
            if (increasing){
                if (!(vi[i] - vi[i-1] == 1 || vi[i] - vi[i-1] == 2 || vi[i] - vi[i-1] == 3)){
                    valid = 0;
                    break;
                }
            }
            else{
                if (!(vi[i] - vi[i-1] == -1 || vi[i] - vi[i-1] == -2 || vi[i] - vi[i-1] == -3)){
                    valid = 0;
                    break;
                }
            }
        }
        
        if (valid) ans++; // If current report is valid global counter increases by 1.
    }
    
    cout << ans << endl;

    return 0;
}   
