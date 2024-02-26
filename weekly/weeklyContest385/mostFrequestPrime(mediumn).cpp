class Solution {
public:
    void getPrimeNumbers(vector<vector<int>>&mat , int i , int j, unordered_map<int,int>&mp){
        // unordered_map<int, int> mp;
        int num = 0 ;
        int x = i ;
        int y = j ;
        while(x>=0 && y>=0){
            num = num*10+mat[x][y];
            if(num>10)
            mp[num]++;
            x--;
            y--;
        }
        x = i ;
        y = j ;
        num  =0 ; 
        while(x>=0){
            num = num*10 + mat[x][y];
            if(num>10)
            mp[num]++;
            x--;
        }
        x = i ;
        y = j ;
        num  =0; 
        while(y>=0){
            num = num*10 + mat[x][y];
            if(num>10){
                mp[num]++;
            }
            y--;
        }
        x = i ;
        y = j ;
        num  =0; 
        while(x<mat.size()){
            num = num*10 + mat[x][y];
            if(num>10){
                mp[num]++;
            }
            x++;
        }
        x = i ;
        y = j ;
        num  =0; 
        while(y<mat[0].size()){
            num = num*10 + mat[x][y];
            if(num>10){
                mp[num]++;
            }
            y++;
        }
        x = i ;
        y = j ;
        num  =0; 
        while(x>=0 && y<mat[0].size()){
            num = num*10 + mat[x][y];
            if(num>10){
                mp[num]++;
            }
            x--;
            y++;
        }
        x = i ;
        y = j ;
        num  =0; 
        while(x<mat.size() && y<mat[0].size()){
            num = num*10 + mat[x][y];
            if(num>10){
                mp[num]++;
            }
            x++;
            y++;
        }
        x = i ;
        y = j ;
        num  =0; 
        while(x<mat.size() && y>=0){
            num = num*10 + mat[x][y];
            if(num>10){
                mp[num]++;
            }
            x++;
            y--;
        }
    }
    bool isPrime(int num){
        int sqrRoot = sqrt(num);
       for(int i =2; i <=sqrRoot;i++){
           if(num%i==0){
               return false;
           }
       }
        return true;
    }
    int mostFrequentPrime(vector<vector<int>>& mat) {
        unordered_map<int,int> mp;
        for(int i =0 ; i < mat.size();i++){
            for(int j = 0 ; j<mat[0].size(); j++){
                getPrimeNumbers(mat, i , j ,mp);
            }
        } 
        priority_queue<pair<int,int>> pq;
        for(auto i: mp){
            if(i.first>10){
                if(isPrime(i.first)==true){
                    pq.push({i.second, i.first});
                }
            }
        }
        
        if(!pq.empty()){
            auto top = pq.top();
            return top.second;
        }   
        return -1;
    }
};
