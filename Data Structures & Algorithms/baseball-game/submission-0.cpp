class Solution {
public:
    int calPoints(vector<string>& s) {
        stack<string>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=="+"){
                if(!st.empty()){
                    int x=stoi(st.top());
                    st.pop();
                    int y=stoi(st.top());
                    
                    st.push(to_string(x));
                    st.push(to_string(x+y));
                }
                }else if(s[i]=="C"){
                    
                        st.pop();
                    }
                else if(s[i]=="D"){
                    int x=stoi(st.top());
                    
                    st.push(to_string(2*x));
                }else{
                st.push(s[i]);
            }
    }
            int sum=0;
            while(!st.empty()){
                sum+=stoi(st.top());
                st.pop();
            }
            return sum;

        
        
    }
};