class Solution {
public:
    static bool cmp(pair<int,int>&a, pair<int,int>&b){
        return a.first<b.first;
    }
    static bool cmp2(pair<int,int>&a, pair<int,int>&b){
        return a.second<b.second;
    }
    vector<int> maxSubsequence(vector<int>& arr, int k) {
        vector<pair<int,int>>nums;
        for(int i=0;i<arr.size();i++){
            nums.push_back({arr[i],i});
        }
        vector<pair<int,int>>ans;

        sort(nums.begin(),nums.end(),cmp);

        for(int i=arr.size()-k;i<arr.size();i++){
            ans.push_back(nums[i]);
        }

        sort(ans.begin(),ans.end(),cmp2);

        vector<int>result;
        for(auto &it:ans){
            result.push_back(it.first);
        }

        return result;
        
    }
};
