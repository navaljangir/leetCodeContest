//BruteForce
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans =0 ; 
        for(int i =0 ; i <nums.size();i++){
            unordered_map<int,bool> mp;
            int count=0; 
            for(int j = i; j<nums.size();j++){
                if(mp.find(nums[j])==mp.end()){
                    count++;
                    mp[nums[j]]=true;
                }
                ans =ans + count*count;
            }
        }
        return ans;
    }
};
