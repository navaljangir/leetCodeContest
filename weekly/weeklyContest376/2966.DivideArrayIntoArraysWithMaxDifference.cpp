class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i =0 ; i <nums.size();i++){
            int count =0; 
            int sum = 0;
            int j = i;
            vector<int> v;
            while(j<nums.size() && count<3){
                if(v.size()==0 || nums[j] - v[0]<=k){
                    v.push_back(nums[j]);
                }else{
                    return {};
                }
                count++;
                j++;
            }
            ans.push_back(v);
            i = j-1;
        }
        return ans;
    }
};
