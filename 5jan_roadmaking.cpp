//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
	{   //Calc
	   // dp[i][j]=(i=the current position i am at)(j=whether there is building at previous position)
	   //i==n :: i ahve exhausted all the pssible spaces and have formed a valid config -- return 1
	   // our answer should be stored in dp[0][0]
	   // recursive :
	   //  int helper(int i,int j)
	   //  {  if(i==n) return 1;
	   //    if(dp[i][j]!=-1)
	   //    return dp[i][j];
	   //    if(j==0)--> int make=helper(i+1,1); int nomake=helper(i+1,0); dp[i][j]=(make+nomake)%mod
     	//   else -->  dp[i][j]=helper(i+1,0);
     	
     	// bottom up approach
	    const long long mod = 1e9 + 7;
	    vector<vector<long long>> dp(N + 1, vector<long long> (2, 1));
	    
	    for(int i = N - 1; i > -1; i--){
	        dp[i][1] = dp[i + 1][0];
	        
	        int make, nomake;
	        make = dp[i + 1][1];
	        nomake = dp[i + 1][0];
	        
	        dp[i][0] = (make + nomake) % mod;
	    }
	    
	    return (dp[0][0] * dp[0][0]) % mod;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends