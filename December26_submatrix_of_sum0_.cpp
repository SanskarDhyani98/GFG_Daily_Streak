/*

Date : 26/12/2023
Problem : Largest rectangular sub-matrix whose sum is 0
(Given a matrix mat[][] of size N x M. The task is to find the largest rectangular sub-matrix by area whose sum is 0.

If there are multiple solutions return the rectangle which starts from minimum column index. If you still have multiple solutions return the one starting from minimum row index. If you still have multiple solutions return the one having greatest row number. If no such matrix is present return a zero (0) size matrix.

Example 1:

Input: N = 3, M = 3
mat[][] =  1, 2, 3
          -3,-2,-1
           1, 7, 5

Output:  1, 2, 3
        -3,-2,-1

Explanation: This is the largest sub-matrix,
whose sum is 0.
Example 2:

Input: N = 4, M = 4
mat[][] = 9, 7, 16, 5
          1,-6,-7, 3
          1, 8, 7, 9
          7, -2, 0, 10

 Output: -6,-7
          8, 7
         -2, 0 
Your Task:
You don't need to read input or print anything. You just have to complete the function sumZeroMatrix() which takes a 2D matrix mat[][], its dimensions N and M as inputs and returns a largest sub-matrix, whose sum is 0.

Expected Time Complexity: O(N*M*M).
Expected Auxiliary Space: O(N*M).
)

Difficulty : Hard
Problem Link : https://www.geeksforgeeks.org/problems/largest-rectangular-sub-matrix-whose-sum-is-0/1
Video Solution Referred : Manas Rawat (cpwithcpp) https://youtu.be/UQADCH6nx8w

*/


//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  vector<vector<int>> sumZeroMatrix(vector<vector<int>> a){
        int n = a.size();
        int m = a[0].size();
        
        vector<vector<int>> rowPrefix(n + 1, vector<int> (m + 1, 0));
        
        for(int i = 1; i < n + 1; i++){
          for(int j = 1; j < m + 1; j++)
            rowPrefix[i][j] += rowPrefix[i][j - 1] + a[i - 1][j - 1];
        }
        
        int best = 0;
        int sx, sy, ex, ey;
        
        
        // starting column
        for(int i = 1; i < m + 1; i++){
            // ending column
          for(int j = i; j < m + 1; j++){
              map<int,int> pre;
              pre[0] = 0;
              
              int csum = 0;
              
              // through the rows
              for(int k = 1; k < n + 1; k++){
                  csum += rowPrefix[k][j] - rowPrefix[k][i - 1];
                  
                  if(pre.count(csum)){
                      int area = (j - i + 1) * (k - pre[csum]);
                      
                      if(area > best){
                          best = area;
                          
                          sx = pre[csum] + 1;
                          sy = i;
                          
                          ex = k;
                          ey = j;
                      }
                  }
                  else{
                      pre[csum] = k;
                  }
              }
          }
        }
      
        vector<vector<int>> ans;
      
        if(best == 0)
            return ans;
        
        for(int i = sx; i < ex + 1; i++){
            vector<int> curRow;
            
            for(int j = sy; j < ey + 1; j++)
                curRow.push_back(a[i - 1][j - 1]);
            
            ans.push_back(curRow);//.emplace_back
        }
        
        return ans;
  }
};


//{ Driver Code Starts.




int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        
        vector<vector<int>> a(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> ans = ob.sumZeroMatrix(a);
        if(ans.size() == 0){
            cout<<-1<<endl;
        }
        else{
            for(int i=0;i<ans.size();i++){
                for(int j=0;j<ans[0].size();j++){
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends