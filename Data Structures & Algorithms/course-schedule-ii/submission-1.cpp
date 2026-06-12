class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        vector<int>res;
        unordered_map<int,vector<int>>adj;
        for(auto &it:prerequisites){
            int a=it[0];
            int b=it[1];
            
            adj[b].push_back(a);
            indegree[a]++;

        }
        queue<int>q;
        int cnt=0;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            res.push_back(node);
            for(int &it:adj[node]){
               indegree[it]--;
               if(indegree[it]==0){
                
                q.push(it);
                cnt++;
               }
            }
        }
        if(res.size()==numCourses) return res;
        return {};
        
    }
};
