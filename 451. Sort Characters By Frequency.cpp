class Solution {
public:

static bool cmp(pair<int,char>&a, pair<int,char>&b){
    return a.first>b.first;

}
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(auto it:s){
            mp[it]++;
        }
        vector<pair<int,char>>temp;
        for(auto it:mp){
            temp.push_back({it.second,it.first});
        }
        sort(temp.begin(),temp.end(),cmp);

        string ans ="";
        for(auto it:temp){
            int num = it.first;
            char ch = it.second;
            while(num--){
                ans+=ch;
            }
        }
        return ans;
    }
};
