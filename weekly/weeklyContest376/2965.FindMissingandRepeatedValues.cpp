class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int> mp;
        for(int i =0 ; i <grid.size();i++){
            for(int j= 0 ; j<grid[i].size();j++){
                mp[grid[i][j]]++;
            }
        }
        int num = pow(grid.size(),2);
        int a = -1;
        int b= -1;
        for(int i=1 ; i<=num;i++){
            if(mp.find(i)==mp.end()){
                b= i;
            }else if(mp[i]>1){
                a=i;
            }
        }
        return {a,b};
    }
};
