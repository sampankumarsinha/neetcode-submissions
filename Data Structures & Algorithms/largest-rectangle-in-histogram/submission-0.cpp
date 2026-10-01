class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        vector<int>leftSmall(n,0),rightMax(n,0);
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()) leftSmall[i]=0;
            else{
                leftSmall[i]=st.top()+1;
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int j=n-1;j>=0;j--){
            while(!st.empty() && heights[st.top()]>=heights[j]) st.pop();
            if(st.empty()) rightMax[j]=n-1;
            else{
                rightMax[j]=st.top()-1;

            }
            st.push(j);
        }
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,heights[i]*(rightMax[i]-leftSmall[i]+1));
        }
        return maxi;


        
    }
};
