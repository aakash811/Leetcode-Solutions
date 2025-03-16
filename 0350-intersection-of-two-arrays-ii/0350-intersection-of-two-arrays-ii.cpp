class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end()) ;
        sort(nums2.begin(), nums2.end()) ;
        vector<int> arr ;

        for(int i=0;i<nums1.size(); i++){
            int target = nums1[i] ;
            
            int low = 0 , high = nums2.size()-1 ;
            while(low<=high){
                int mid = low + (high-low)/2 ;
                if(nums2[mid]==target){
                    nums2.erase(nums2.begin()+mid) ;
                    arr.push_back(target) ;
                    break ;
                }
                else if(target>nums2[mid]){
                    low = mid+1 ;
                }
                else{
                    high = mid-1 ;
                }
 
            }

        }

        return arr ;

    }
};