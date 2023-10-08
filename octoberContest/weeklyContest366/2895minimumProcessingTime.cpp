class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin() , processorTime.end());
        sort(tasks.rbegin(), tasks.rend());
        int k =0;
        int maxi = INT_MIN;
        for(int i = 0 ; i<processorTime.size();i++){
            if(k<tasks.size()){
            maxi = max(maxi ,processorTime[i]+tasks[k]);
            k+=4;
            }else{
                break;
            }
        }
        return maxi;
    }
};
