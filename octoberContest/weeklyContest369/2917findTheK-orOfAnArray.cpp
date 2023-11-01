class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        vector<int> v;
        int i=  0 ; 
        while(i<32){
            int count=0;
            for(int j = 0 ; j <nums.size();j++){
                if((nums[j] & (1<<i))!=0){
                    count++;
                }
            }
            if(count>=k){
                v.push_back(i);
            }
            i++;
        }
        int ans =0 ; 
        for(int k = 0; k<v.size();k++){
            ans+=pow(2,v[k]);
        }
        return ans;
    }
};
