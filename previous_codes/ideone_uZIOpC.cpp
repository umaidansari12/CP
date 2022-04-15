#include<bits/stdc++.h>
using namespace std;
#define int long long 
int solve(int n,int k){
    int dp[n+1][k+1];
    memset(dp,sizeof(dp),0);
    dp[0][0]=1;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=min(i-1,k);j++){
            dp[i][0]+=dp[i-1][j]*21;
        }
        for(int j=1;j<=min(i,k);j++){
            dp[i][j]=dp[i-1][j-1]*5;
        }
    }
    int ans=0;
    for(int j=0;j<=k;j++) {
    	ans+=dp[n][j];
    }
    for(int i=0; i<=n; i++) {
    	for(int j=0; j<=min(i,k);j++){
    		cout<<dp[i][j];
    		cout<<" | ";
    	}
    	cout <<"\n";
    }
    
    return ans;
}
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        cout<<solve(5,2)<<endl;
    }
}
