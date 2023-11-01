class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 =0 ; 
        long long sum2= 0 ;
        long long zeroCount= 0;
        long long zeroCount2=0;
        for(int i =0 ; i<nums1.size(); i++){
            if(nums1[i]==0){
                zeroCount++;
            }
            sum1+=nums1[i];
        }
        for(int i= 0; i<nums2.size();i++){
            if(nums2[i]==0){
                zeroCount2++;
            }
            sum2+=nums2[i];
        }
        sum1+=zeroCount;
        sum2+=zeroCount2;
        if(sum1>sum2){
            if(zeroCount2==0){
                return -1;
            }
            return sum1;
        }else if(sum1<sum2){
            if(zeroCount==0){
                return -1;
            }
            return sum2;
        }else{
            return sum1;
        }
        return -1;
    }
};
