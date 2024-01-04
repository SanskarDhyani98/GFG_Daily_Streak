/*

Author : Manas Rawat
Date : 03/01/2024
Problem : Smallest window containing 0, 1 and 2
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/smallest-window-containing-0-1-and-2--170637/1
Video Solution : https://youtu.be/7SVd8dYsq0c

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// class Solution {
//   public:
//     int smallestSubstring(string S) {
//         vector<int> f(3, 0);
//         int l, r;
//         l = r = 0;
//         bool ok = 0;
//         int ans = 1e8;
        
//         while(r < S.size() or l < r){
//             if(!ok and r < S.size()){
//                 ++f[S[r++] - '0'];
                
//                 if(f[0] and f[1] and f[2])
//                     ok = 1;
//                 else
//                     ok = 0;
//             }
//             else if(l < r){
//                 --f[S[l++] - '0'];
                
//                 if(f[0] and f[1] and f[2])
//                     ok = 1;
//                 else
//                     ok = 0;
//             }
            
//             if(ok)
//                 ans = min(ans, r - l);
//         }
        
//         return ans == 1e8 ? -1 : ans;
//     }
// };
class Solution {
public:
    int smallestSubstring(string S) {
        int zero = -1, one = -1, two = -1, res = 100001;

        for (int i = 0; i < S.length(); i++) {
            if (S[i] == '0') zero = i;
            if (S[i] == '1') one = i;
            if (S[i] == '2') two = i;

            if (zero == -1 || one == -1 || two == -1) continue;
            int minimum = min({one, zero, two});
            int maximum = max({one, zero, two});
            res = min(res, maximum - minimum + 1);
        }

        return res == 100001 ? -1 : res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends