class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {

        map<string,vector<int>>mp;
        vector<string>ans;
        for(int i=0;i<access_times.size();i++){
            mp[access_times[i][0]].push_back(stoi(access_times[i][1]));
        }
        for(auto &it:mp){
            sort(it.second.begin(),it.second.end());
        }
        for(auto &it:mp){
            vector<int>temp = it.second;
            for(int i=2;i<temp.size();i++){
                if(temp[i]-temp[i-2]<100){  // we see first elem and third elem and check if diff is less then 100 then good to go, since it is sorted middle elem i.e second will also less then third. so we only check first and third.
                    ans.push_back(it.first);
                    break;
                }
            }
        }
    return ans;

    }
};
