#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int singleElement(int arr[] ,int N) {
        vector<int> f(32, 0);
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < 32; j++){
                f[j] += (arr[i] >> j) & 1;
            }
        }
        
        int ans = 0;
        
        for(int i = 0; i < 32; i++)
            ans += (f[i] % 3) << i;
            
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.singleElement(arr,N);
        cout<<"\n";
    }
    return 0;
}
// class Solution {
//   public:
//     int singleElement(int arr[] ,int N) {
//         // code here
//         int res = 0;
//         for (int i = 0; i < 32; i++) {
//             int setbit = 0;
//             for (int j = 0; j < N; j++) {
//                 if ((arr[j] & (1 << i)) != 0) {
//                     setbit++;
//                 }
//             }
//             if (setbit % 3 == 1) {
//                 res = res | (1 << i);
//             }
//         }
//         return res;
//     }
// };