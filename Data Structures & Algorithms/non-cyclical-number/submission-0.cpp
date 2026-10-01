class Solution {
public:
  int helper(int n){
    int ans=0;
    while(n>0){
        int sum=n%10;
         ans+=sum*sum;
        n/=10;

    }
    return ans;
  }
    bool isHappy(int n) {
        
        unordered_set<int>st;
      
           while (n != 1) {

        if (st.find(n) != st.end())
            return false;

        st.insert(n);

        n = helper(n);
    }
    return true;
    }


        
    
};
