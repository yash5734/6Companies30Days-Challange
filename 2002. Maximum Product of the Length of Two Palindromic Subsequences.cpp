class Solution {
public:

    void subsequence(int ind, int n, string s, vector<int> ds, vector<vector<int>>&ans){
       
        if(ind>=n){
            if(isPallindrome(s,ds))
            ans.push_back(ds);
            return;
        }
        

        // take
        ds.push_back(ind);
        subsequence(ind+1,n,s,ds,ans);

        // not take
        ds.pop_back();
        subsequence(ind+1,n,s,ds,ans);
    }
    bool isPallindrome(string str,vector<int>ans){
        int n = ans.size();
        int start = 0;
        int end = n-1;
        while(start<end){
            if(str[ans[start]]!=str[ans[end]]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    bool check(vector<int>&a,vector<int>&b){
        for(int i=0;i<a.size();i++){
            for(int j=0;j<b.size();j++){
                if(a[i]==b[j]) return false;
            }
        }
        return true;
    }
    int maxProduct(string s) {
        int n = s.size();
        vector<int> temp;
        vector<vector<int>>ans;
        subsequence(0,n,s,temp,ans);

        int result =0;
        for(int i=0;i<ans.size()-1;i++){
            for(int j=i+1;j<ans.size();j++){
                int sum =(int)ans[i].size() * ans[j].size();
                if(result<sum && check(ans[i],ans[j])){
                    result = sum;
                }
            }
        }
        return result;
    }
};
