class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int start = 0;
        int end =0;
        int ans =0;

        while(start<nums.size() && end<nums.size()){
            mp[nums[end]]++;

            if(mp[nums[end]]<=k){
                ans = max(ans,end-start+1);
                
            }else{
                while(mp[nums[end]]>k ){
                   mp[nums[start]]--;
                    start++;
                }
            }
            end++;
        }  
        return ans; 

    }
};
