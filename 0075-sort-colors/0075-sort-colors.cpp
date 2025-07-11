class Solution {
public:
    
    
    // void insertion(vector<int>nums){
        
    //     int n=nums.size();
    //     for(int i=0;i<n;i++){
            
    //         int key=0;
    //         for(int j=i;j>i;i--){
                
    //         }
            
    //     }
        
        
        
    // }
    
    void bubbleSort(vector<int>& nums){
        int n = nums.size();
        
        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j <= i - 1; j++){
                if(nums[j] > nums[j + 1]){
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
        
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n-i-1;j++){
        //         if(nums[j]>nums[j+1]){
        //             swap(nums[j],nums[j+1]);
        //         }
        //     }
        // }
    }
    
        void sortColors(vector<int>& nums) {
            
            bubbleSort(nums);
        }
   
};