class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
            map<int, int> mp;
            mp[0]=1;
            int sum = 0;
            int ans = 0;
            for (int i = 0; i < nums.size(); i++) {
                sum += nums[i];
                int target = sum-k;
                if (mp.find(target) != mp.end()) {
                    ans += mp[target];
                }
                mp[sum]++;
            }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        // using preix sum --> use the logic of subaaray sum equals to k

        vector<int>temp;
        for(auto it:nums){
            if(it%2!=0){
                temp.push_back(1);
            }else temp.push_back(0);
        }

        return subarraySum(temp,k);

    }
};
