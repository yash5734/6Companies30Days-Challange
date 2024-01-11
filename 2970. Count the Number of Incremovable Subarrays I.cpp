class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
            int maxi = INT_MIN;
            bool flag = true;
                for(int k=0;k<nums.size();k++){
                    if(k>=i && k<=j) continue;
                    if(maxi>=nums[k]){
                        flag = false;
                        break;
                    }
                    maxi = nums[k];
                }
                if(flag) ans++;
            }
        }
        return ans;
    }
};
