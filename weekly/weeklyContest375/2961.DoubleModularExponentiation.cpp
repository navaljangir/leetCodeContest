class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ans;
        for(int i =0 ; i <variables.size();i++){
            int a = variables[i][0];
            int b=  variables[i][1];
            int c = variables[i][2];
            int m = variables[i][3];
            int num = 1;
            int b1 = b;
            int a1 = a;
            int bitr= 0 ;
            int citr=0;
            while(bitr<b){
                num = (num*a)%10;
                bitr++;
            }
            int num1 =1;
            while(citr<c){
                num1 = (num1*num)%m;
                citr++;
            }
            if(num1==target){
                ans.push_back(i);
            }
        }   
        return ans;
    }
};
