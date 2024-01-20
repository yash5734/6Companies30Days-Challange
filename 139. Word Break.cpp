class Solution {
private:
    bool f(string s,unordered_map<string,int>&dict,unordered_map<string,bool>&dp){
        if(s.length()==0) return true;

        if(dp.find(s)!=dp.end()) return dp[s];

        for(int i=0;i<s.length();i++){
            string sub = s.substr(0,i+1);
            if(dict.find(sub)!=dict.end()){
                if(f(s.substr(i+1),dict,dp)) return dp[s] = true;
            }
        }
        return dp[s]=false;
    }
    bool tabu(string s,unordered_set<string>st)
    {
        vector<bool>dp(s.size()+1,false);
        dp[0]=true;
        for(int i=1;i<=s.length();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
               if(dp[j])
               {
                    string temp=s.substr(j,i-j);
                if(st.find(temp)!=st.end())
                {
                    dp[i]=true;
                    break;
                }
               }
            }
        }
        return dp[s.size()];
    }
 
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool>dp;
        unordered_map<string,int>dict;

        for(auto &it: wordDict){
            dict[it]++;
        }

        return f(s,dict,dp);

    }
};
