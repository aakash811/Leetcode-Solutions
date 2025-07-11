class Solution {
public:
    void solve(vector<int>&nums,int s,int mid,int e){
        
        int i=s;
        int j=mid+1;
        
        vector<int>ans;
        while(i<=mid && j<=e){
            if(nums[i]<=nums[j]){
                ans.push_back(nums[i]); 
                i++; 
            }
            else{
                ans.push_back(nums[j]);
                j++;
            }
        }
        
        while(i<=mid){
            ans.push_back(nums[i]);
            i++;
        }
        while(j<=e){
            ans.push_back(nums[j]);
            j++;
        }
        
        for(int k=s;k<=e;k++){
            nums[k]=ans[k-s];
        }
    }
    
    void mergeSort(vector<int>&nums,int s,int e){
        if(s < e){
              int mid=s+(e-s)/2;
              mergeSort(nums,s,mid);
              mergeSort(nums,mid+1,e);
              solve(nums,s,mid,e);
        }
    }
    
    void sortColors(vector<int>& nums) {
     
        int n=nums.size();
        return mergeSort(nums,0,n-1);
    }
};