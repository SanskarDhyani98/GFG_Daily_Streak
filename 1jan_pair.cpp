/*

Author : Manas Rawat
Date : 01/01/2024
Problem : Array Pair Sum Divisibility Problem
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1
Video Solution : https://youtu.be/ETYGE6QcI1U

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// class Solution {
//   public:
//     bool canPair(vector<int> nums, int k) {
//         map<int,int> f;
        
//         for(int i = 0; i < nums.size(); i++){
//             int cur = nums[i] % k;
//             int need = (k - cur) % k;
            
//             if(f.count(need)){
//                 --f[need];
                
//                 if(f[need] == 0)
//                     f.erase(need);
//             }
//             else{
//                 ++f[cur];
//             }
//         }
        
//         return f.size() == 0;
//     }
// };
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
      int n = nums.size();
        if(n % 2) return false;
        vector<int> mp(k + 1, 0); 
        for(auto x : nums){
            x %= k;
            mp[x]++;
            mp[k-x]--;
        } 
        for(int i = 1; i < k; i++) if(mp[i]>0) return false;
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends