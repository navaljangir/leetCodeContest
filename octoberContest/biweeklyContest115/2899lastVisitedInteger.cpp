class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<string> v;
        vector<int> ans;
        for(int i =0 ; i<words.size();i++){
            int j= i;
            
            while(j<words.size() && words[j]!="prev"){
                v.push_back(words[j]);
                j++;
            }
            int count= 0 ;
            while(j<words.size() && words[j]=="prev"){
                 count++;
                if(count>v.size()){
                ans.push_back(-1);
                }else{
                string str = v[v.size()-count];
                ans.push_back(stoi(str));
            }
               
                j++;
            }
            
            i = j-1;
            
        }
        return ans;
    }
};
