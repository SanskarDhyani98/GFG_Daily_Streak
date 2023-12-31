/*Date : 30/12/2023
Problem : Winner of an election
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names-1587115621/1
Video Solution : https://youtu.be/3C9_r44JVAI

*/


//{ Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        unordered_map<string, int> votes;
        
        for(int i = 0; i < n; i++)
            ++votes[arr[i]];
            
        int best = 0;
        vector<string> ans(2);
        
        for(auto i : votes){
            if(i.second > best){
                best = i.second;
                ans[0] = i.first;
                ans[1] = to_string(best);
            }
            else if(i.second == best and i.first < ans[0]){
                ans[0] = i.first;
            }
        }
        
        return ans;
        //  int i, maxi=0;
        // vector<string> v;
        // unordered_map<string, int> mp;
        // for(i=0;i<n;i++) mp[a[i]]++;
        // for(auto x: mp) {
        //     maxi=max(maxi, x.second);
        // }
        // for(auto x: mp) {
        //     if(x.second==maxi) v.push_back(x.first);
        // }
        // sort(v.begin(), v.end());
        // return {v[0], to_string(maxi)};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}