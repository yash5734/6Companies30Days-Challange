class Solution {
public:
    int solve(string &s,unordered_map<string,int>&dict, vector<int>&dp,int ind){
        if(ind==s.size()) return 0;

        if(dp[ind]!=-1) return dp[ind];

        int mini = INT_MAX;
        string temp="";
        for(int i=ind;i<s.size();i++){
            temp+=s[i];
            int v = temp.size();
            if(dict.find(temp)!=dict.end()){
                v =0;
            }

            mini = min(mini, v+solve(s,dict,dp,i+1));
        }
        return dp[ind] = mini;

    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string,int>dict;
        for(auto it:dictionary){
            dict[it]++;
        }
        vector<int>dp(s.size()+1,-1);
        // vector<int>dp;
        return solve(s,dict,dp,0);
    }
};
