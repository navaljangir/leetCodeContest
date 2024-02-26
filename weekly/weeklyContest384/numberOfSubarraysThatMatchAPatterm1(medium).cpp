class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int ans =0 ;
        for(int i=0 ; i < nums.size();i++){
            bool breakBetween = false;
            for(int j= 0 ;j<pattern.size();j++){
                if(pattern[j]==1 && i+j+1<nums.size() && nums[i+j+1] >nums[i+j]){
                    continue;
                }else if(pattern[j]==0 &&  i+j+1<nums.size() && nums[i+j+1] ==nums[i+j] ){
                    continue;
                }else if(pattern[j]==-1 &&  i+j+1<nums.size() && nums[i+j+1] <nums[i+j]){
                    continue;
                }else{
                    breakBetween = true;
                    break;
                }
               
            }
             if(breakBetween==false){
                    ans++;
            }
        }
        return ans;
    }
};




//Method 2 : string substr

class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        string str1 = "";
        for(int i = 0; i < nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                str1+=('1');
            }else if(nums[i]==nums[i+1]){
                str1+=('0');
            }else if(nums[i]>nums[i+1]){
                str1+=('2');
            }
        }
        string str2 = "";
        for(int i= 0 ; i <pattern.size();i++){
            if(pattern[i]==-1){
                str2+=('2');
            }else{
                str2+=(pattern[i]+'0');
            }
        }
        int size = pattern.size();
        int ans =0 ; 
        string s = str1.substr(0 , size);
        if(s==str2){
            ans++;
        } 
        for(int i= size; i <str1.length();i++){
            s = s.substr(1);
            s+=str1[i];
            if(s==str2){
                ans++;
            }
        }
        return ans;
    }
};

