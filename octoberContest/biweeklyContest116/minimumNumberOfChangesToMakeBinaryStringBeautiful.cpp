class Solution {
public:
    int minChanges(string s) {
        int count =0 ; 
        for(int i = 0 ; i<s.length();i++){
            if(i+1<s.length() && (s[i]==s[i+1])){
                cout<<i;
                i=i+1;
            }else{
                count++;
                i=i+1;
            }
        }
        return count;
    }
};
