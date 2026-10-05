class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        int n=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++){
            pq.push({abs(x-nums[i]),i});
        }
        vector<int>ans;
        while(k--){
            int idx=pq.top().second;
            pq.pop();
            ans.push_back(nums[idx]);

        }
        sort(ans.begin(),ans.end());
      return ans;

        
    }
};