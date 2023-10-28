class Solution {
public:
    int solve(vector<int>&nums , int index, int sum , int&target,vector<vector<int>>&dp){
        if(sum>target){
            return -1e9;
        }
        if(target==sum){
            return 0;
        }
        if(index>=nums.size()){
            return -1e9;
        }
        if(dp[index][sum]!=-1){
            return dp[index][sum];
        }
        int inc = 1+ solve(nums, index+1 , sum+nums[index], target,dp);
        int exc = solve(nums,index+1, sum , target,dp);
        return dp[index][sum]=max(inc , exc);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(), vector<int>(target , -1));
        int ans = solve(nums, 0 , 0 ,target,dp);
        if(ans <0){
            return -1;
        }
        return ans;
    }
};
