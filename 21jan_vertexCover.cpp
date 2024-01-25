#include <bits/stdc++.h>
using namespace std;
// class Solution{
//     public:
//         int vertexCover(int n, vector<pair<int, int>> &edges) {
//                 // code here
//                 int ans=20;
//                 for(int i=0;i<(1<<n);i++)
//                 {
//                     int m=edges.size();
//                     for(auto edge:edges)
//                     {
//                         int x=edge.first;
//                         int y=edge.second;
//                         x--; y--;
//                         if(((i>>x)&1) or ((i>>y)&1))
//                         m--;
//                     }
//                     if(m==0)
//                     ans=min(ans,__builtin_popcount(i));
//                 }
//                 return ans;
//             }       
// };

class Solution{
    public:
     int next(int x){
        unsigned smallest, ripple, new_smallest, ones;

        if (x == 0) return 0;
        smallest     = (x & -x);
        ripple       = x + smallest;
        new_smallest = (ripple & -ripple);
        ones         = ((new_smallest/smallest) >> 1) - 1;
        return ripple | ones;
    }
        bool check(int bits,int n,vector<pair<int, int>> &edges)
        {
            int cur = (1 << bits) - 1;
            
            while(cur < (1 << n)){
                int m = edges.size();
                
                for(auto edge : edges){
                    int x, y;
                    tie(x, y) = edge;
                    --x; --y;
                    
                    if(((cur >> x) & 1) or ((cur >> y) & 1))
                        --m;
                }
                
                if(m == 0)
                    return 1;
                    
                cur = next(cur);
        }
        return 0;
        }
        int vertexCover(int n, vector<pair<int, int>> &edges) {
       
        int low = 0;
        int high = n;
        
        while(low < high - 1){
            int mid = low + (high - low) / 2;
            
            if(check(mid,n,edges))
                high = mid;
            else
                low = mid;
        }
        
        return high;
            }
            
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> edges;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            edges.push_back({a,b});
        }
        Solution s;
        cout<<s.vertexCover(n,edges)<<endl;
    }
    return 0;
}
