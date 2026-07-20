class Solution {
public:
vector<char>temp;
  int n;
  int m;
  int l;
  vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  bool solve(int i,int j,vector<vector<char>>& board,string word,int idx){
    if(idx>=l) return true;
    if(i<0 || i>=n || j<0 || j>=m) return false;
     if (board[i][j] != word[idx])
        return false;

    char temp = board[i][j];
    board[i][j] = '#';
    
    for(auto &it:directions){
        int nrow=i+it[0];
        int ncol=j+it[1];
        if(solve(nrow,ncol,board,word,idx+1)) return true;
    }
    board[i][j]=temp;
    return false;
    
  } 
 
    
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        l=word.length();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] && solve(i,j,board,word,0)) return true;
            }
        }
        return false;
        
        
    }
};
