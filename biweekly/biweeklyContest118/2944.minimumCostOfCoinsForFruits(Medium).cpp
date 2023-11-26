class Solution {
public:
    int solve(vector<int>&prices , int index ,int freeIndex ,vector<vector<int>>&dp){
        if(index>=prices.size()){
            return 0;
        }
        if(freeIndex>=prices.size()){
            return 0;
        }
        if(dp[index][freeIndex]!=-1){
            return dp[index][freeIndex];
        }
        int notTake = INT_MAX;
        int take = INT_MAX;
        if(freeIndex==0 || index>freeIndex){
            take = prices[index] + solve(prices, index+1 ,index+index+1,dp);
        }else{
            take = prices[index]+ solve(prices , index+1 , index+index+1,dp);
            notTake =solve(prices , index+1 , freeIndex,dp);
        }
        return dp[index][freeIndex] = min(take , notTake);
    }
    int minimumCoins(vector<int>& prices) {
        vector<vector<int>> dp(prices.size() , vector<int>(prices.size()+prices.size()+1 , -1));
        return solve(prices , 0 , 0 ,dp);
    }
};
