class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>bank(wordList.begin(),wordList.end());
        unordered_set<string>vis;
        queue<string>q;
        q.push(beginWord);
        vis.insert(beginWord);
        int level=1;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                string s=q.front();
                q.pop();
                if(s==endWord) return level;
                for(char ch='a';ch<='z';ch++){
                    for(int i=0;i<s.length();i++){
                        string nhbr=s;
                        nhbr[i]=ch;
                        if(vis.find(nhbr)==vis.end()&& bank.find(nhbr)!=bank.end()){

                            vis.insert(nhbr);
                            q.push(nhbr);
                        }
                    }

                }
            }
            level++;
        }
        return 0;
        
        
    }
};
