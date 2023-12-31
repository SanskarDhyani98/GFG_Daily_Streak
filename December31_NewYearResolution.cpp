/*
Date : 31/12/2023
Problem : New Year Resolution
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/good-by-2023/1
Video Solution : https://youtu.be/xqq5tVLOz3A
*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

// class Solution {

//     public:
//     int isPossible(int N , int coins[]) 
//     {
//         vector<vector<int>> dp(N + 1, vector<int> (2025, 0));

//         for(int i = 20; i < 2025; i += 20)
//             dp[N][i] = 1;
//         for(int i = 24; i < 2025; i += 24)
//             dp[N][i] = 1;
//         dp[N][2024] = 1;

//         for(int i = N - 1; i > -1; i--){
//             for(int j = 0; j < 2025; j++){
//                 int take, notake;
//                 take = notake = 0;

//                 notake = dp[i + 1][j];

//                 if(coins[i] + j < 2025)
//                     take = dp[i + 1][j + coins[i]];

//                 dp[i][j] = max(take, notake);
//             }
//         }

//         return dp[0][0];
//     }

// };
class Solution {
    public:
    int solve(int i,int N,int coins[],int sum,vector<vector<int>> &dp){
        if(sum==2024) return 1;
        if(sum!=0 and (sum%20==0 || sum%24==0)){
            return 1;
        }
        if(i>=N){
            return 0;
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        int take   = solve(i+1,N,coins,sum+coins[i],dp);
        int notake = solve(i+1,N,coins,sum,dp);
        return dp[i][sum]=take || notake;
    }
    int isPossible(int N , int coins[]) 
    {
        int sum=0;
        for(int i=0;i<N;i++) sum+=coins[i];
        vector<vector<int>> dp(N,vector<int>(sum+1,-1));
        return solve(0,N,coins,0,dp);
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;
        int coins[N];
        for(int i=0 ; i<N ; i++)
            cin>>coins[i];

        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }
    return 0;
}
// } Driver Code Ends