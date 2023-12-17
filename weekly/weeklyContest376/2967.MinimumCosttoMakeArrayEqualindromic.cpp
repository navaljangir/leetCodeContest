class Solution {
public:
    bool isPalindrome(int num){
        string s = to_string(num);
        int i= 0; 
        int j = s.length()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    long long minimumCost(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        long long median = -1;
        if(nums.size()%2!=0){
            median = nums[nums.size()/2];
        }else{
            median = (nums[nums.size()/2] + nums[(nums.size()/2)-1])/2;
        }
        long long minNearestPalindrome = median;
        while(!isPalindrome(minNearestPalindrome)){
            minNearestPalindrome--;
        }
        long long maxNearestPalindrome = median;
        while(!isPalindrome(maxNearestPalindrome)){
            maxNearestPalindrome++;
        }
        long long minAns = 0;
        long long maxAns =0 ; 
        for(auto i : nums){
            minAns +=abs(i-minNearestPalindrome);
            maxAns +=abs(i-maxNearestPalindrome);
        }
        return min(minAns , maxAns);
    }
};
