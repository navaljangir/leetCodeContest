class Solution {
public:
    int countTestedDevices(vector<int>& arr) {
        int tested= 0;
        for(int i = 0; i <arr.size();i++){
            if(arr[i]>0){
                tested++;
                for(int j = i+1; j<arr.size();j++){
                    arr[j] = max(0, arr[j] - 1);
                }
            }
        }
        return tested;
    }
};
