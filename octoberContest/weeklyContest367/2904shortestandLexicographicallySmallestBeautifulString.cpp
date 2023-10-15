class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = s;
        for(int i = 0 ; i<s.length(); i++){
            int count =0 ; 
            if(s[i]=='1'){
                count++;
            }
            string str= "";
            str+=s[i];
            if(count==k){
                return str;
            }
            for(int j = i+1 ; j<s.length();j++){
                
                if(s[j]=='1'){
                    count++;
                }
                str+=s[j];
                if(count==k){
                    break;
                }
                
                
            }
            if(count==k){
             if(ans.size()>str.size()){
                 ans = str;
             }else if(ans.length()==str.length()){
                 if(str<ans){
                     ans= str;
                 }
             }
            }
        }
         if(ans ==s){
            int count =0 ;
            for(auto i : s){
                if(i=='1'){
                    count++;
                }
            }
             if(count==k)
             return s;
        }
          if(ans==s){
            return "";
        }
        return ans;
    }
};
