class Solution {
public:
    long long minimumSteps(string s) {
        long long ans= 0 ;
        int oneCount =0 ;
        for(int i =s.length()-1;i>=0;i--){
            int j =i;
            if(s[i]=='0'){
                while(j>=0){
                    if(s[j]=='1'){
                        ans+=i-j-oneCount;
                        oneCount++;
                    }
                    j--;
                }
            }
            i=j;
        }
        return ans;
    }
};
