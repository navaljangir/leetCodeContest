class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int s1length=s1.length();
        int s2length = s2.length();
        int s3length = s3.length();
        int minLen = min(s1length , min(s2length , s3length));
        int ops = 0;
        while(s1.length()>minLen){
            ops++;
            s1.pop_back();
        }
        while(s2.length()>minLen){
            ops++;
            s2.pop_back();
        }
        cout<<ops<<" ";
        while(s3.length()>minLen){
            ops++;
            s3.pop_back();
        }
        cout<<ops<<" ";
        if(s1.length()==0){
            return -1;
        }
        for(int i= 0 ; i<s1.length();i++){
            if(s1[i]==s2[i] && s2[i]==s3[i]){
                continue;
            }else{
                if(i>=1){
                    ops = ops + (s1.length()-i)*3;
                    break;
                }else{
                    return -1;
                }
            }
        }
        return ops;
    }
};
