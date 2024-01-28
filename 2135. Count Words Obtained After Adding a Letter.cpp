class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        int ans =0;
        unordered_map<string,int>mp;
        for(int i=0;i<startWords.size();i++){
            for(char ch = 'a';ch<='z';ch++){
                string target = startWords[i];
                target+=ch;
                sort(target.begin(),target.end());
                mp[target]++;
            }
        }
        for(int i=0;i<targetWords.size();i++){
            sort(targetWords[i].begin(),targetWords[i].end());
            if(mp[targetWords[i]]>0) ans++;
        }
        return ans;
    }
};
