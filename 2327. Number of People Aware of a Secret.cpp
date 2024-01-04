class Solution {
public:
int mod = 1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int>dp(n+1,0);
        dp[1] = 1;

        long long newUser =0;
        for(int i=2;i<=n;i++){
            if(i-delay>=0){
                newUser = newUser + dp[i-delay]; //spread new user
            }if(i-forget>=0){
                newUser = newUser - dp[i-forget]; //remove forgot user
            }
            dp[i] = newUser%mod;
        }
        long long ans =0;
        for(int i=n-forget+1;i<=n;i++){
            ans = (ans+dp[i])%mod;
        }
        return ans; 
    }
};
