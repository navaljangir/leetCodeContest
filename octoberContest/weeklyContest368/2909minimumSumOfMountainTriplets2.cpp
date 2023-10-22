class Solution {
public:
    int minimumSum(vector<int>& nums) {
        vector<int> v1(nums.size());
        vector<int> v2(nums.size());
        int mini = nums[0];
        for(int i= 0 ; i<nums.size();i++){
            mini = min(mini , nums[i]);
            v1[i]=mini;
        }
        mini = nums[nums.size()-1];
        for(int i = nums.size()-1;i>=0 ;i--){
            mini = min(mini , nums[i]);
            v2[i] = mini;
        }
        mini = -1;
        for(int i = 1 ; i<nums.size()-1;i++){
            if(nums[i]>v1[i-1] && nums[i]>v2[i+1]){
                if(mini==-1){
                    mini = nums[i]+v1[i-1]+v2[i+1];
                }else{
                    mini = min(mini, nums[i]+v1[i-1]+v2[i+1]);
                }
            }
        }
        return mini;
    }
};
