#include<stdio.h>
main(){
    int n, a=3, b=7, c=7, mod=1e8+7; scanf("%d",&n);
    int dp[n+1];
    dp[1] = 3;
    dp[2] = 7;
    for(int i=3;i<=n;i++){
        dp[i] = (((2*dp[i-1])%mod)+dp[i-2])%mod;
    }
    printf("%d",dp[n]);
}