class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
       string token;
       stack<string>st;
       while(getline(ss,token,'/')){
        if(token==".."){
            if(!st.empty())
            st.pop();
        }else if(token=="." || token==""){
           continue;
        }else{
            st.push(token);
        }
       }
       string res="";
       while(!st.empty()){
        res="/"+st.top()+res;
        st.pop();
       }
       return res.empty()?"/":res;
        
    }
};