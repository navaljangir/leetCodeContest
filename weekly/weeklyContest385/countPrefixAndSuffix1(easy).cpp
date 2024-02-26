class Solution {
public:
    bool isPrefixSuffix(string str1 , string str2){
        if(str1.size()<str2.size()){
            int size = str1.size();
            int index = str2.size() - size;
            if(str2.substr(0 , size)==str1 && str2.substr(index , size)==str1){
                return true;
            }
        }else if(str1.size()==str2.size()){
            return str1==str2;
        }
        return false;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans =0 ;
        for(int i  =   0 ; i <words.size() ; i++){
            for(int j = i+1 ; j <words.size();j++){
                if(isPrefixSuffix(words[i] , words[j])){
                    ans++;
                }
            }
        }
        return ans;
    }
};
