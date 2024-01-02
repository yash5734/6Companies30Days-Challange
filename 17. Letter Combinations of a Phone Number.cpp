class Solution {
    private:
    void solve(int ind,string ds, vector<string>&ans,string map[], string &digits){

        if(ind>=digits.length()){
            ans.push_back(ds);
            return;
        }

        int num = digits[ind] - '0';
        string value = map[num];

        for(int i=0;i<value.length();i++){
            ds.push_back(value[i]);
            solve(ind+1,ds,ans,map,digits);
            ds.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.length()==0) return ans;

        string ds = "";
        string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        solve(0,ds,ans,mapping,digits);
        return ans;
    }
};
