class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> answer = matrix;
        unordered_map<int,int> maxAtColumn ;
        for(int i =0 ; i <matrix.size();i++){
            for(int j = 0 ; j <matrix[0].size();j++){
                if(matrix[i][j]==-1){
                    if(maxAtColumn.find(j)==maxAtColumn.end()){
                        int maxi = INT_MIN;
                    for(int k = 0 ; k<matrix.size();k++){
                        maxi = max(maxi , matrix[k][j]);
                    }
                    answer[i][j] = maxi;
                    }else{
                        answer[i][j] = maxAtColumn[j];
                    }
                }
            }
        }
        return answer;
    }
};
