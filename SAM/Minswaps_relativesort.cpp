int minSwap(vector<int>& a, vector<int>& b){
    int inf = (int)(1e9);
    int n=a.size();
    int dp[n][2];
    dp[0][0]=0;
    dp[0][1]=1;
    for(int i=1;i<n;i++)
        dp[i][0]=dp[i][1]=inf;
    for(int i=1;i<n;i++){
        if(a[i-1]<a[i]&&b[i-1]<b[i]){
            dp[i][0]=dp[i-1][0];
            dp[i][1]=dp[i-1][1]+1;
        }
        if(a[i-1]<b[i]&&b[i-1]<a[i]){
            dp[i][0]=min(dp[i][0],dp[i-1][1]);
            dp[i][1]=min(dp[i][1],dp[i-1][0]+1);
        }
    }
    return min(dp[n-1][0],dp[n-1][1]);
}
