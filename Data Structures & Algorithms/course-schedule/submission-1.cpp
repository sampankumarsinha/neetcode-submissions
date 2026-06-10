class Solution {
public:
    bool topological(map<int,vector<int>>&adj,vector<int>&indegree,int numCourses){
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
            cnt++;
            for(int &it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    
                    q.push(it);
                }
            }
         }
         if(cnt==numCourses) return true;
         return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        map<int,vector<int>>adj;
        int n=prerequisites.size();
        int m=prerequisites[0].size();
        for(auto &it:prerequisites){
            int a=it[0];
            int b=it[1];
            adj[b].push_back(a);
            indegree[a]++;

        }
        return topological(adj,indegree,numCourses);
        
    }
};
