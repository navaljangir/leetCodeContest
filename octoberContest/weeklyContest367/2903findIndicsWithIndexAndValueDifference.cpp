class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        vector<int> v;
        for(int i = 0; i <nums.size(); i++){
            for(int j  = 0 ; j <nums.size();j++){
                if(abs(i-j)>=indexDifference && abs(nums[i]-nums[j])>=valueDifference){
                    v.push_back(i);
                    v.push_back(j);
                    break;
                }
                
            }
            if(v.size()!=0){
                    break;
                }
        }
        if(v.size()==0){
            v.push_back(-1);
            v.push_back(-1);
        }
        return v;
    }
};
