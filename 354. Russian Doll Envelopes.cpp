class Solution {
public:
    static bool cmp(vector<int>v1,vector<int>v2){
        if(v1[0]==v2[0]) return v1[1]>v2[1];
        return v1[0]<v2[0];
    }

    int maxEnvelopes(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        int n = nums.size();
        vector<int>dp;
        dp.push_back(nums[0][1]);

        for(int i=1;i<n;i++){
            int index = lower_bound(dp.begin(),dp.end(),nums[i][1])-dp.begin();
            if(nums[i][1]>dp.back()){
                dp.push_back(nums[i][1]);
            }else{
                dp[index] = nums[i][1];
            }
        }
        
       return dp.size();
    }
};
