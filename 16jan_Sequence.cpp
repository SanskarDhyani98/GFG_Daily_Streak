//i is denoting my current position
//j is denoting my current position value
//dp[i][j] -> total no. of ways if I am at he ith position and the current element is j
//base case
//.. i==n-1   and j<=m and j>=0  --> i have found a valid way --> return 1
//answer
// sum(dp[0][1]........dp[0][m])


//int helper(int i,int j)
//    if(i==n-1)
//return 1;
//  if(dp[i][j]!=-1) return dp[i][j]
//  dp[i][j]=0;
//for(int k=2*j:k<=m;k++)
// {
//     dp[i][j]+=helper(i+1,k);
// }
// return dp[i][j];

/*
Date : 16/01/2024
Problem : Sequence of Sequence
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/sequence-of-sequence1155/1
Video Solution : https://youtu.be/7HV6gnbJPJ0

*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
 int help(int i, int j, int n, int m){
        if(j==n)    return 1;
        if(i>m)     return 0;
        
        int pick= help(i*2, j+1, n, m);
        int not_pick=help(i+1, j, n, m);

        return pick+not_pick;
    }
    int numberSequence(int m, int n){
        return help(1,0,n,m);
    }
    // int numberSequence(int m, int n){
    //     // code here
    //     vector<vector<int>> dp(n,vector<int>(m+1,0));
    //     for(int i=1;i<=m;i++)
    //     {  dp[n-1][i]=1;    //base case
    //     }
    //         for(int i=n-2;i>=0;i--)
    //         {
    //             for(int j=1;j<=m;j++)
    //             {
    //                 for(int k=2*j;k<=m;k++)
    //                 dp[i][j]+=dp[i+1][k];
    //             }
    //         }
    //         return accumulate(dp[0].begin(),dp[0].end(),0);
    // }
};