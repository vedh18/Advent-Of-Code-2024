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
    
    int n = 6; // Number of lines to process
    int ans = 0; // To store the cumulative result of multiplication operations
    bool flag = 1; // Flag to store weather mul will be counted or not.

    for (int i = 0; i<6; i++){
        string input;
        getline(cin, input);
        for (int i = 0; i<(int)input.size(); i++){
            // Extract a substring of length 7 starting at the current index
            string y = input.substr(i, 7);
            
            // If the substring is don't(), set flag to 0 and skip further checks
            if (y == "don't()") {
                flag = 0;
                continue;
            }
            
            // Extract a substring of length 4 starting at the current index
            string z = input.substr(i, 4);
            
            // If the substring is do(), set flag to 1 and continue processing
            if (z == "do()") {
                flag = 1;
                continue;
            }
            
            // If `flag` is true and the substring is "mul(", process it
            if (flag && z == "mul("){
                string y = ""; // To store the parameters inside mul()
                bool flag = 0; // Flag to check if the contents inside mul() are valid
                
                // Extract up to 8 characters after mul(
                for (int j = i + 4; j < i + 4 + 8; j++) {
                    y += input[j];
                    if (input[j] == ')') { 
                        flag = 1;
                        break;
                    }
                }
                
                if (!flag) continue; // Skip if no closing parenthesis is found
                
                string num1 = ""; // To store the first number
                int id = 0;
                // Extract the first number
                while (id < (int)y.size() && y[id] - '0' >= 0 && y[id] - '0' <= 9) {
                    num1 += y[id];
                    id++;
                }
                
                // Validate the first number
                if (id == (int)y.size() || y[id] != ',' || (int)num1.size() > 3 || (int)num1.size() < 1) 
                    continue;
                
                int n1 = stoi(num1); // Convert the first number to an integer
                id++;
                
                string num2 = ""; // To store the second number
                // Extract the second number
                while (id < (int)y.size() && y[id] - '0' >= 0 && y[id] - '0' <= 9) {
                    num2 += y[id];
                    id++;
                }
                
                // Validate the second number
                if (id == (int)y.size() || y[id] != ')' || (int)num2.size() > 3 || (int)num2.size() < 1) 
                    continue;
                
                int n2 = stoi(num2); // Convert the second number to an integer
                ans += n1 * n2; // Add the product of n1 and n2 to the result

            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}   
