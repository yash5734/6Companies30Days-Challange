class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(),ages.end());
        int ans=0;
        for(int i=0;i<ages.size();i++){
            int temp = (ages[i]/2) +7;
            int low_index = upper_bound(ages.begin(),ages.end(), temp)-ages.begin();
            int high_index = upper_bound(ages.begin(),ages.end(), ages[i])-ages.begin();

            ans += max(0,(high_index-low_index-1));
        }
        return ans;
    }
};
