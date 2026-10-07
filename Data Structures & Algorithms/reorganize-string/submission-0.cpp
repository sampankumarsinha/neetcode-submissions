class Solution {
public:
    string reorganizeString(string s) {
        int n=s.length();
        priority_queue<pair<int,char>>pq;
        vector<int>freq(26,0);
        for(char c : s) {
       freq[c - 'a']++;
}

      for(int i = 0; i < 26; i++) {
        if(freq[i]>(n+1)/2) return "";
         if(freq[i] > 0) {

        pq.push({freq[i], char('a' + i)});
    }
      }
      string res="";
    while(pq.size()>=2){
        auto p1=pq.top();
        pq.pop();
        auto p2=pq.top();
        pq.pop();
        res.push_back(p1.second);p1.first--;
        res.push_back(p2.second);p2.first--;
        if(p1.first>0) pq.push(p1);
        if(p2.first>0) pq.push(p2);

    }
    if(!pq.empty()){
        res.push_back(pq.top().second);
    }
    return res;
   

    }

    };