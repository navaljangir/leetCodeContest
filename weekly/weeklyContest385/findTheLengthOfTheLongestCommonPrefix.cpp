class TrieNode{
public:
  TrieNode* children[10];
    char data ;
    bool isTerminal; 
    TrieNode(char d){
    for(int i =0 ; i <10;i++){
        children[i] = NULL;
    }
    this->isTerminal = false;
    this->data = d;
    }
};
class Solution {
public:
    void insertInTrie(TrieNode* root , string str){
        if(str.size()==0){
            root->isTerminal =true;
            return;
        }
        TrieNode* child;
        int index = str[0]-'0';
        char ch = str[0];
        if(root->children[index]!=NULL){
            child = root->children[index];
        }else{
            child = new TrieNode(ch);
            root->children[index] = child;
            child = root->children[index];
        }
        insertInTrie(child , str.substr(1));
    }
    int solve(TrieNode* root , string str){
        if(str.size()==0){
            return 0;
        }
        int ans= 0; 
        int index = str[0]-'0';
        if(root->children[index]!=NULL){
            ans = 1+ solve(root->children[index] , str.substr(1));
        }   
        return ans;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode* root = new TrieNode('-');
        for(int i =0 ; i <arr1.size();i++){
            string str = to_string(arr1[i]);
            insertInTrie(root , str);
        }
        int ans = INT_MIN;
        for(int i =0 ; i <arr2.size();i++){
            string str = to_string(arr2[i]);
            ans = max(ans , solve(root, str));
        }
        return ans;
    }
};
