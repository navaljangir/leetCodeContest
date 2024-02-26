class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int ans =0 ;
        for(int i=0 ; i < nums.size();i++){
            bool breakBetween = false;
            for(int j= 0 ;j<pattern.size();j++){
                if(pattern[j]==1 && i+j+1<nums.size() && nums[i+j+1] >nums[i+j]){
                    continue;
                }else if(pattern[j]==0 &&  i+j+1<nums.size() && nums[i+j+1] ==nums[i+j] ){
                    continue;
                }else if(pattern[j]==-1 &&  i+j+1<nums.size() && nums[i+j+1] <nums[i+j]){
                    continue;
                }else{
                    breakBetween = true;
                    break;
                }
               
            }
             if(breakBetween==false){
                    ans++;
            }
        }
        return ans;
    }
};
