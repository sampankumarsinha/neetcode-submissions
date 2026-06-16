class DSU{
public:
       vector<int>parent;
       vector<int>rank;
       DSU(int n){
         parent.resize(n);
         rank.resize(n);
         for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
         }
       }
       int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x]);
       }
       void Union(int x,int y){
        int u=find(x);
        int v=find(y);
        if(rank[u]>rank[v]){
            parent[v]=u;
        }else if(rank[u]<rank[v]){
            parent[u]=v;
        }else{
            parent[u]=v;
            rank[v]++;
        }
        
       }
       };

class Solution {
public:

vector<int>parent;
vector<int>rank;

    int countComponents(int n, vector<vector<int>>& edges) {
        int res=n;
        DSU ds(n);
        for(auto &it:edges){
            int a=it[0];
            int b=it[1];
            if(ds.find(a)!=ds.find(b)){
                ds.Union(a,b);
                res--;
                
            }
            
           

        }
        return res;
        
            
        


    }
};
