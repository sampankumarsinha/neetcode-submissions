class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mpp;
        for(char i:s){
            mpp[i]++;
        }
         bool ans=false;
        for(int i=0;i<t.length();i++){
            char ch=t[i];
            if(mpp.find(ch)==mpp.end()){
            return false;
            }
            mpp[ch]--;
            if(mpp[ch]==0) mpp.erase(ch);
            
        }
        if(mpp.empty()) return true;
        return false;
        
        
        
    }
};
