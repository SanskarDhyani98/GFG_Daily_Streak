/*

Author : Manas Rawat
Date : 11/01/2024
Problem : Remove K Digits
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/remove-k-digits/1
Video Solution : https://youtu.be/fYopLz9nmes

*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string S, int K) {
        // pair<int, int> last = {0, K};
        // int n = S.size();
        // int index = 0;
        
        // while(index < n){
        //     if(S[index] != '0'){
        //         if(K)
        //             --K;
        //         else
        //             break;
                    
        //         ++index;
        //     }
        //     else{
        //         while(index < n and S[index] == '0'){
        //             ++index;
        //         }
                
        //         last = {index, K};
        //     }
        // }
        
        // stack<int> num;
        // int start = last.first;
        // K = last.second;
        
        // for(int i = start; i < n; i++){
        //     while(num.size() and num.top() > (S[i] - '0') and K){
        //         --K;
        //         num.pop();
        //     }
            
        //     num.push(S[i] - '0');
        // }
        
        // while(num.size() and K--){
        //     num.pop();
        // }
        
        // string ans = "";
        
        // while(num.size()){
        //     ans += to_string(num.top());
        //     num.pop();
        // }
        
        // reverse(ans.begin(), ans.end());
        
        // if(ans == "")
        //     ans = "0";
        
        // return ans;
         int n=S.size();
        stack<char> num;
        for(int i=0;i<n;i++)
        {
            while(!num.empty()&&num.top() > S[i]&&K)
            {
                num.pop();//  stack  in ascending order
                K--;        // number of deletion remaining
            }
             // if (!stack.isEmpty()) {//push c irres of its 0 or not 
            //      stack.push(c);
            // } 
            // if(stack.isEmpty() && c!='0')
            // stack.push(c);
             
            //  if(stack.isEmpty() && c=='0') // no leading zeros
            //  continue;
            if(!num.empty()||S[i]!='0')
            num.push(S[i]);
        }
         // number of deletion remaining >0
        while (!num.empty() && K > 0) {
            num.pop();
            K--;
        } 

        if (num.empty()) {
            return "0";
        }

        string sb="" ;
        // Appends characters one by one
       while(!num.empty())
       {
           sb+=num.top();
           num.pop();
       }
       reverse(sb.begin(),sb.end());

        return sb;

         //3
        //  string result;

        // for (int i = 0; i < S.length(); i++) {
        //     char c = S[i];

        //     while (!result.empty() && result.back() > c && K > 0) {
        //         result.pop_back(); // make sure characters in result are in ascending order
        //         K--;               // remove one char
        //     }

        //     if (!result.empty() || c != '0') {
        //         result.push_back(c);
        //     } // can't have leading '0'
        // }

        // // remove remaining characters if needed
        // while (!result.empty() && K-- > 0) {
        //     result.pop_back();
        // }

        // return (result.empty()) ? "0" : result;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends