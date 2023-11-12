class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        vector<string> ans;
        map<string , vector<int>> mp;
        for(int i = 0 ; i <access_times.size();i++){
            string str= access_times[i][0];
            int num = stoi(access_times[i][1]);
            mp[str].push_back(num);
        }
        for(auto &i : mp){
            vector<int> v = i.second;
            // int ans = 0;
            bool inHour = false;
            for(int i = 0 ; i<v.size();i++){
                int count = 0;
                for(int j = 0 ; j <v.size();j++){
                    if(v[j]==0){
                        if(2400-v[i]<=99){
                            count++;
                        }
                    }else {
                        if(v[j] - v[i]>=0 && v[j]-v[i]<=99){
                            count++;
                        }
                    }
                }
                if(count>=3){
                    inHour=true;
                    break;
                }
                
            }
            if(inHour){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};
