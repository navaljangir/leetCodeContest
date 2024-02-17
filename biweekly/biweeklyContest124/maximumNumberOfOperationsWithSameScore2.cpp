class Solution {
public:
    int solve(int i , int j ,int prevScore ,  vector<int>&nums , vector<vector<int>>&dp){
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans = 0 ; 
            int score1 = nums[i] + nums[j];
            int score2 = nums[i] + nums[i+1];
            int score3 = nums[j] + nums[j-1];
            if(prevScore ==score1){
                ans = max(ans , 1 + solve(i + 1 , j-1 , score1 , nums ,dp));
            }
            if(prevScore==score2){
                ans = max(ans , 1 + solve(i+2 , j , prevScore , nums ,dp));
            }
            if(prevScore ==score3){
                ans = max(ans , 1+solve(i , j -2, prevScore , nums ,dp));
            }
        return dp[i][j] = ans;
    }
    int maxOperations(vector<int>& nums) {
        int i = 0; 
        int j = nums.size()-1;
        vector<vector<int>> dp(nums.size()+1 , vector<int>(nums.size()+1, - 1));
        vector<vector<int>> emptyArr = dp;
        int score1 = nums[0] + nums[j];
        int score2 = nums[0] + nums[1];
        int score3 = nums[j] + nums[j-1];
        int ans1 = 1 + solve(1 , j-1 , score1 , nums , dp);
        dp = emptyArr;
        int ans2 = 1+solve(2 , j , score2 , nums, dp);
        dp=  emptyArr;
        int ans3 = 1 + solve( 0 , j -2,score3 ,  nums , dp);
        return max({ans1 , ans2 , ans3});
    }
};
