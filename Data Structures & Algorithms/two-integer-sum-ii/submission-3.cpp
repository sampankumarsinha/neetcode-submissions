class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

       int n=numbers.size();
       int i=0;
       int j=n-1;
       int sum=0;
       
       int mini=0,minij=0;
       while(i<j){
        sum=numbers[i]+numbers[j];
      
        if(sum>target){
             j--;
       
        }else if(sum<target){ 
            i++;
      
        }else{
            
            break;
            
            
        }
       }
       return {i+1,j+1};
        
    }
};
