class Solution {
public:
    string getHint(string secret, string guess) {
        int cow =0;
        int bull =0;
        unordered_map<char,int>mp;
        for(int i=0;i<secret.size();i++){
            mp[secret[i]]++;
        }

        // find number of bulls and cows;

        for(int i=0;i<guess.size();i++){
            if(secret[i]==guess[i]) bull++;            
        }

        for(int i=0;i<guess.size();i++){
            char ch = guess[i];
            if(mp.find(ch)!=mp.end() && mp[ch]!=0){
                cow++;
                mp[ch]--;
            }
        }

        cow = cow-bull;

        string cows = to_string(cow);
        string bulls = to_string(bull);

        string ans = "";
        ans+=bulls;
        ans.push_back('A');    
        ans+=cows;
        ans.push_back('B');

        return ans;    

    }
};
