class Solution {
public:

    vector<string>ans;
    int n;
    void solve(int idx,string &s,string &temp,unordered_map<char,string>&mpp){
        if(idx>=n){
            ans.push_back(temp);
            return;
        }
        char ch=s[idx];
        string str=mpp[ch];
        for(int i=0;i<str.length();i++){
            temp.push_back(str[i]);
            solve(idx+1,s,temp,mpp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
    
     unordered_map<char,string>mpp;
     n=digits.length();
     mpp['2'] = "abc";
     mpp['3'] = "def";
     mpp['4'] = "ghi";
      mpp['5'] = "jkl";
       mpp['6'] = "mno";
      mpp['7'] = "pqrs";
       mpp['8'] = "tuv";
       mpp['9'] = "wxyz";
       string temp="";
       if(n==0){
        return {};
       }
       solve(0,digits,temp,mpp);
       return ans;
    }
};
