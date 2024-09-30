#include<bits/stdc++.h>
using namespace std;
    
    int main(){

        int n;
        cin>>n;
        vector<int> demand(n),setup_cost(n),inv_cost(n),prodn_cost(n);
        for(auto &k:demand)cin>>k;
        for(auto &k:setup_cost)cin>>k;
        for(auto &k:inv_cost)cin>>k;
        for(auto &k:prodn_cost)cin>>k;
        vector<int> dp(n+1,1e9);
        dp[0]=0;
        for(int i=1;i<n+1;i++){
            int prod=0,ext=0;
            for(int j=i;j>=1;j--){
                dp[i]=min(dp[i],dp[j-1]+setup_cost[j-1]+prodn_cost[j-1]*(prod+demand[j-1])+prod*inv_cost[j-1]+ext);
                ext+=inv_cost[j-1]*prod;
                prod+=demand[j-1];
            }
        }
        cout<<dp[n]<<endl;
        return 0;
    }

// Time Complexity O(N^2)
// Space Complexity O(N)
