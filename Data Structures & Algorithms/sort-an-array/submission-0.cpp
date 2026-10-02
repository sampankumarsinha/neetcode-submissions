class Solution {
public:

    
        void merge(vector<int>& nums, int low, int mid, int high) {
        int i = low;
        int j = mid + 1;
        int k = 0;

        vector<int> temp(high - low + 1);


        while(i <= mid && j <= high) {
            if(nums[i] <= nums[j]) {
                temp[k] = nums[i];
                i++;
            }
            else {
                temp[k] = nums[j];
                j++;
            }
            k++;
        }

        
        while(i <= mid) {
            temp[k] = nums[i];
            i++;
            k++;
        }

        
        while(j <= high) {
            temp[k] = nums[j];
            j++;
            k++;
        }

        // Copy temp back to nums
        for(int x = 0; x < temp.size(); x++) {
            nums[low + x] = temp[x];
        }
    }

    void mergesort(vector<int>& nums, int low, int high) {
        if(low < high) {

            int mid = low + (high - low) / 2;

         
            mergesort(nums, low, mid);

          
            mergesort(nums, mid + 1, high);

       
            merge(nums, low, mid, high);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0, nums.size() - 1);
        return nums;
        
    }

};