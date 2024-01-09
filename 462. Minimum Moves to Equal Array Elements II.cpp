class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum = nums[nums.size()/2];
        int ans =0;
        for(auto it:nums){
            ans += abs(sum-it);
        }
        return ans;
    }
};

//Now just think after sorting we need to increase the elements at the left side of the array and decrease the elements at the right side of the array. So lets take the first nums[0] and last element nums[n-1], the element to whom they should be made equal be centre. Hence nums[0] <= centre <= nums[n-1]. If we take any other value as centre then total steps needed will be more . Now if we continue doing the same step for 2nd, 3rd ... ith element we get a general relation nums[i] <= centre <= nums[n-1-i].This ends at the central element of the array if n is odd i.e. nums[n/2] and if n is even it end at the condition nums[n/2 -1] <= centre <= nums[n/2]. So centre will be mid value in case of n is odd and can be any value between the two middle values if n is even.
