class Solution {
public:
    bool isPalindrome(string s) {
       int n=s.length();
        
        string ans="";
         for (char c : s) {
        if (isalnum(c))
            ans += c;
    }

       transform(ans.begin(), ans.end(), ans.begin(), ::tolower);
       int si=ans.length();
       int i=0;
       int j=si-1;
        while(i<j){
            char ch1=ans[i];
            char ch2=ans[j];            
            
          if(ch1!=ch2) return false;
            i++;
            j--;
        }
    
        return true;
    }
};
