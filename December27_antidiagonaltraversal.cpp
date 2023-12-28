#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        // Code here
        //  int n = matrix.size(), k = 0, x = 0;
        // vector<int> arr(n * n);

        // for (int i = 0; i < n; i++) {
        //     k = 0;
        //     for (int j = i; j >= 0; j--) arr[x++] = matrix[k++][j];
        // }

        // for (int i = 1; i < n; i++) {
        //     k = i;
        //     for (int j = n - 1; j >= i; j--) arr[x++] = matrix[k++][j];
        // }

        // return arr;
        int n=matrix.size();
        vector<int> ans;
        //Traversing anti diagonal elements of top row
        for(int i=0;i<n;i++)
        {  int row=0;int column=i;
            while(row<n&&column>=0)
            {
                ans.push_back(matrix[row][column]);
                row++;
                column--;
            }
        }
        //Traversing anti diagonal elements of second half of matrix
        for(int i=1;i<n;i++)
        {
            int column=n-1;
            int row=i;
            while(row<n&&column>=0)
            {
                ans.push_back(matrix[row][column]);
                row++;
                column--;
            }
        }
        return ans;
    }
};
int main()
{   vector<vector<int>> matrix={{3, 2, 3},{4, 5, 1},{7, 8, 9}};
    Solution ob;
    vector<int> ans=ob.antiDiagonalPattern(matrix);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}