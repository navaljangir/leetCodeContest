class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
       int maxi = INT_MIN;
        long long ans =0 ;
        int K = 1e5;
        cout<<K<<" ";
        for(int i = 0;  i<nums.size();i++){
            maxi = max(maxi, nums[i]);
        }
        int i =0 ;
         int j =0 ; 
        int maxiCount =0 ;
        while(j<nums.size()){
            if(nums[j]==maxi){
                maxiCount++;
            }
            if(maxiCount>=k){
                while(maxiCount>=k){
                    ans +=(nums.size()-j);
                    if(nums[i]==maxi){
                        maxiCount--;
                    }
                    i++;
                }
            }
            
            j++;
        }
        return ans;
    }
};
