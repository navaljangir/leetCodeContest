class Solution {
public:
    long long solve(vector<int>&nums , int k , int i, vector<long long>&dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        long long ans1 = LONG_MAX;
        long long ans2= LONG_MAX;
        long long ans3 = LONG_MAX;
        if(nums[i]<k){
                ans1 =(k-nums[i]) + solve(nums, k , i+1 ,dp);
        }else{
            ans1=solve(nums, k , i+1 , dp);
        }
        if(i+1<nums.size()){
            if(nums[i+1]<k){
                ans2 = (k-nums[i+1])+solve(nums, k , i+2,dp);
            }else{
                ans2= min(ans2,solve(nums, k , i+2, dp));
            }
        }else{
            ans2=0;
        }
        if(i+2<nums.size()){
            if(nums[i+2]<k){
                ans3 = (k-nums[i+2])+solve(nums, k , i+3,dp);
            }else{
                ans3= min(ans3,solve(nums, k , i+3, dp));
            }
        }else{
            ans3=0;
        }
        return dp[i] =min(ans1, min(ans2, ans3));
    }
    long long minIncrementOperations(vector<int>& nums, int k) {
        vector<long long> dp(nums.size(),-1);
        long long ans =solve(nums, k , 0,dp);
        
        return ans;
    }
};
