class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
            else{
                if(st.empty()) return false;
                char t=st.top();
                 if ((t == '(' && s[i] == ')') ||
                    (t == '{' && s[i] == '}') ||
                    (t == '[' && s[i] == ']')) {

                    st.pop();
                    
                }else{
                    return false;
                }
          

        }
        }
        if(st.empty()) return true;
        return false;
        
    }
};
