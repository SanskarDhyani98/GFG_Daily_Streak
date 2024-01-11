//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // int sum = 0;
	    // unordered_map<int,int> suffix;
	    // suffix[0] = n;
	    
	    // int ans = 0;
	    
	    // for(int i = n - 1; i > -1; i--){
	    //     sum = (sum + (arr[i] % k) + k) % k;
	        
	    //     if(!suffix.count(sum))
	    //         suffix[sum] = i;
	    //     else
	    //         ans = max(ans, suffix[sum] - i);
	    // }
	    
	    // return ans;
         unordered_map<int, int> map;
    int p_sum = 0, ps_rem, ans = 0;

    for (int i = 0; i < n; i++) {
        p_sum += arr[i];
        ps_rem = p_sum % k;

        if (ps_rem == 0)
            ans = max(ans, i + 1);

        if (ps_rem < 0)  // for negative integers
            ps_rem += k;

        if (map.find(ps_rem) != map.end())
            ans = max(ans, i - map[ps_rem]);
        else
            map[ps_rem] = i;
    }

    return ans;
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}
