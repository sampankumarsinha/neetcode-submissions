class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      string ans="";
      int l=0;
      int r=0;
      vector<int>freq1(26,0),freq(26,0);
      for(char c:s1){
        freq1[c-'a']++;
      }
      int n=s2.length();
      while(r<n){
        freq[s2[r]-'a']++;
        if((r-l+1)==s1.length() && freq1==freq){
         return true;
        }
        while(r-l+1>=s1.length()){
           freq[s2[l]-'a']--;
           l++;
          
        }
        r++;

      }
      return false;
      
        
    }
};
