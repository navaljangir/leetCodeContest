class Solution {
public:
    string lastNonEmptyString(string s) {
        unordered_map<char,int> mp;
        int maxiOccurence = INT_MIN;
        for(int i = 0 ; i <s.length();i++){
            mp[s[i]]++;
            maxiOccurence = max(maxiOccurence , mp[s[i]]);
        }
        string ans = "";
        unordered_map<char, int> mp2;
        for(int i=0 ; i <s.length();i++){
            mp2[s[i]]++;
            if(mp2[s[i]]==maxiOccurence){
                ans+=s[i];
            }
        }
        return ans;
        
    }
};
