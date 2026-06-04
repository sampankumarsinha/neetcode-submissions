class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int minutes=0;
        int freshcount=0;
        int n=grid.size();
        int m=grid[0].size();
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                freshcount++;
            }else if(grid[i][j]==2){
                q.push({i,j});
            }
        }
       }
       int drow[]={-1,0,1,0};
       int dcol[]={0,1,0,-1};
       while(!q.empty() && freshcount>0){
        int s=q.size();
        while(s--){
          int i=q.front().first;
          int j=q.front().second;
          q.pop();
        for(int k=0;k<4;k++){
            int nrow=i+drow[k];
            int ncol=j+dcol[k];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 ){
            grid[nrow][ncol]=2;
            freshcount--;
            q.push({nrow,ncol});
       }
        }
       
                
            
        }
        minutes++;
        

       }
       if(freshcount==0){
        return minutes;
       }
       return -1;
 
        
    }
};
