class Solution {
public:
   bool  solve(unordered_map<int,vector<int>>&adj,int node,int parent,vector<int>&vis){
    vis[node]=1;

    for(int it:adj[node]){
        if(it==parent) continue;
        if(vis[it]==1) return false;
        if(!vis[it]){
            vis[it]=1;
            solve(adj,it,node,vis);
    }
    }
    return true;
   }
    bool validTree(int n, vector<vector<int>>& edges) {

    unordered_map<int,vector<int>>adj;
    for(auto it:edges){
        int a=it[0];
        int b=it[1];
        adj[a].push_back(b);
        adj[b].push_back(a);

   }
   vector<int>vis(n,0);
   int parent=-1;
   if(solve(adj,0,parent,vis)==false) return false;

    for(int i=0;i<n;i++){
        if(vis[i]==0) return false;
    }

    return true;
}

  
};
