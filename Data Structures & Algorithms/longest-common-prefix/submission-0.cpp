class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string str=strs[0];
        string ans="";
        for(int i=1;i<n;i++){
            string comp=strs[i];
            int j=0;
            while(j<comp.length() && j<str.length() && str[j]==comp[j]){
                j++;
            }
            str=str.substr(0,j);
        }
        return str;
        
        
        
    }

    };
