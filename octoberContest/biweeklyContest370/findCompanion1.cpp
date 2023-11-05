class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        unordered_map<int,bool> ifStronger;
        // for(int i = 0 ;i <grid.size();i++){
        //     if
        // }
        unordered_map<int,vector<int>> mp;
        for(int i = 0 ; i<grid.size(); i++){
            for(int j = 0;  j<grid[i].size();j++){
                if(grid[i][j]==1 && i!=j){
                    ifStronger[j]=true;
                }else{
                    if(i!=j){
                       ifStronger[i]=true;
                    }
                }
            }
        }
        for(int i =0 ; i <grid.size();i++){
            if(ifStronger.find(i)==ifStronger.end()){
                return i;
            }
        }
        return -1;
    }
};
