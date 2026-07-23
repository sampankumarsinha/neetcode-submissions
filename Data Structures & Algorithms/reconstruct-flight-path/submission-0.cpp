class Solution {
public:
    vector<string>res;
    int n;
    bool solve(string fromcity,unordered_map<string,vector<string>>&adj,vector<string>temp){
        temp.push_back(fromcity);
        if(temp.size()==n+1){
            res=temp;
            return true;
        }
        vector<string>&ngbr=adj[fromcity];
        for(int i=0;i<ngbr.size();i++){
            string tocity=ngbr[i];
            ngbr.erase(ngbr.begin()+i);
            if(solve(tocity,adj,temp)) return true;
            ngbr.insert(ngbr.begin()+i,tocity);

        }
        temp.pop_back();
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>>adj;
        n=tickets.size();
        for(auto &it:tickets){
            string u=it[0];
            string v=it[1];
            adj[u].push_back(v);
        }
        for(auto &it:adj){
            sort(it.second.begin(),it.second.end());
        }
        vector<string>temp;
        solve("JFK",adj,temp);
        return res;
        

        
    }
};
