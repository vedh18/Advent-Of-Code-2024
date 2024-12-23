/*
##################################################################
#                                                                #                       
#     Advent of Code 2024 - Day 17, Part 2                       #                       
#     Problem Link: https://adventofcode.com/2024/day/17         #                       
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

ll a,b,c; // Global Variables to store the value of the registers.

// Function which returns the combo operant of x
ll combo(ll x){
    if (x>=0 && x<=3){
        return x;
    }
    else if (x == 4){
        return a;
    }
    else if (x == 5){
        return b;
    }
    else if (x == 6){
        return c;
    }
}

// Function which returns the first value to be output with the current value of a, b, c
ll print_one(vector<int>& v){
    int n = (int)v.size();
    for (int i = 0; i<n-1; i+=2){
        ll n = v[i];
        ll m = v[i+1];
        if (n == 0){
            a = a/(1<<combo(m));
        }
        else if (n == 1){
            b = b ^ m;
        }
        else if (n == 2){
            b = combo(m) % 8;
        }
        else if (n == 3){
            if (a==0)continue;
            i = m;
            i -= 2;
        }
        else if (n == 4){
            b = b ^ c;
        }
        else if (n == 5){
            return combo(m) % 8; // We return at the first time the opcode reads 5
        }
        else if (n == 6){
            b = a/(1<<combo(m));
        }
        else{
            c = a/(1<<combo(m));
        }
    }
}

// The overall procedure described by MY INPUT can be broken down into steps as follows:

// Step 1 --> b = a % 8 => Extract last three bits of a and then give it to b
// Step 2 --> b = b ^ 2 => flip the 2nd bit of b
// Step 3 --> c = a >> b => Shift a to b[0 - 8] times towards the right.
// Step 4 --> b = b ^ 3 => Flip the 1st bit and 2nd bit of b
// Step 5 --> b = b ^ c
// Step 6 --> PRINT b % 8
// Step 7 --> if (a == 0) end else jump back to step 1.

// Key observation: The output of one striaght sequence of steps from (1 - 6)
// only depends on the last three bits of a. 

// So, to reverse engineer this starting from the end of the desiered array, we iterate
// through the possible values of the last three bits of a i.e, from 0 - 7 and check if
// it produces the desired value, whenever it does, we shift a 3 bits to the left and move
// one index to the left of the desired array. We repeat this process untill we reach the 
// -1th index of the array.
void find_smallest_a(int idx, ll curr_a, vector<int>& v){
    int n = (int)v.size();
    if (idx == -1){
        cout << curr_a/8 << endl;
        return;
    }
    for (int i = 0; i<8; i++){
        a = curr_a + i;
        if (v[idx] == print_one(v)){
            find_smallest_a(idx-1, (curr_a+i)*8, v);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 

    // To avoid input parsing, I removed all non integer characters
    // (was easier as there weren't many)

    cin >> a >> b >> c;

    ll n = 16; // The number of instructions in the input
    
    vector<int> v(n);
    for (int i = 0; i<n; i++){
        cin >> v[i];
    }

    find_smallest_a(n-1, 0, v);
    
    return 0;
}
