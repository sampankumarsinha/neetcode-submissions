class DSU{
public:
  vector<int>parent;
  vector<int>rank;
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }
    }
   int find(int i){
    if(i==parent[i]){
        return i;
    }
    return parent[i]=find(parent[i]);
   }
   void unionbyrank(int x,int y){
    int x_parent=find(x);
    int y_parent=find(y);
    if(rank[x_parent]>rank[y_parent]){
        parent[y_parent]=x_parent;
    
    }else if(rank[x_parent]>rank[y_parent]){
        parent[x_parent]=y_parent;
    }else{
        parent[x_parent]=y_parent;
        rank[y_parent]++;
    }
   }
};
class Solution {
public:
   
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU ds(n);
        for(auto &it:edges){
            int a=it[0];
            int b=it[1];
            if(ds.find(a)==ds.find(b)) return it;
            ds.unionbyrank(a,b);

        
    }
    return {};
    }
};
