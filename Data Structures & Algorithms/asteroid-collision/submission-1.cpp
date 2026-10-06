class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int i=0;i<asteroids.size();i++){
            int curr=asteroids[i];
            if(curr>0) st.push(curr);
            else{
                while(!st.empty() && st.top()>0 && abs(curr)>st.top()){
                  st.pop();
               
            }
                 if(st.empty() || st.top()<0){
                    st.push(curr);
                 }
                 else if(abs(curr)==st.top()) st.pop();
                 else{
                    continue;
                 }
            }

           
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
       reverse(ans.begin(),ans.end());
       return ans;
        
        
    }
};