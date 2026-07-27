class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
               int n=gas.size();
               int maxele=0;
               int maxidx=-1;
               for(int i=0;i<n;i++){
                if(gas[i]<cost[i]) continue;
                int j=(i+1)%n;
                int currgas=gas[i]-cost[i]+gas[j];
                int costi=cost[i];
                while(j!=i){
                    if(currgas<cost[j]) break;
                     int costi=cost[j];
                    j=(j+1)%n;
                  currgas=(currgas-costi+gas[j]);
                    
                }
                if(j==i) return i;
               }
               return -1;
    }              
};

