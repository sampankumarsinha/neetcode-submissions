class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto &it:times){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
        }
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        while(!pq.empty()){
            int u=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            for(auto [v,wt]:adj[u]){
                if(dist[u]+wt<dist[v]){
                    dist[v]=wt+dist[u];
                    pq.push({dist[v],v});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            ans=max(ans,dist[i]);
        }
        return ans==INT_MAX?-1:ans;
    
    
    
    
    
    
    }
};