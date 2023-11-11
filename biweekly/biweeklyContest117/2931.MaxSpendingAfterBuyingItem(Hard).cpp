class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        long long days = 1; 
        long long ans =0 ;
        int zeroCount = values.size();
        while(zeroCount>0){
            long long mini = INT_MAX;
            int minIndex = -1;
            for(int i= 0 ; i <values.size();i++){
                if(values[i].size()>0){
                    if(mini > values[i][values[i].size()-1]){
                        mini = values[i][values[i].size()-1];
                        minIndex= i;
                    }
                }
            }
            if(mini!=INT_MAX)
            ans += mini * days;
            days++;
            if(minIndex>=0){
            values[minIndex].pop_back();
            if(values[minIndex].size()==0){
                zeroCount--;
            }
            }
        }
        return ans;
    }
};
