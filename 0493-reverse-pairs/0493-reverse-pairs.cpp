class Solution {
public:
    int merge(vector<int>& nums, int lo, int mid, int hi){
        int i = lo;
        int j = mid + 1;
        vector<int>temp;
        int cnt = 0;

        while(i <= mid && j <= hi){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                cnt += (mid - i + 1);
                j++;
            }
        }

        while(i <= mid){
            temp.push_back(nums[i]);
            i++;
        }

        while(j <= hi){
            temp.push_back(nums[j]);
            j++;
        }

        for(int i = lo; i <= hi; i++){
            nums[i] = temp[i - lo];
        }

        return cnt;
    }

    int countPairs(vector<int> &vec, int low, int mid, int high){
        int right = mid + 1;
        int cnt = 0;

        for(int i = low; i <= mid; i++)
        {
            while(right <= high && vec[i] > 1LL* 2 * vec[right])
            {
                right++;
            }
            cnt += (right - (mid + 1));
        }
        return cnt;
    }

    int mergeSort(vector<int>& nums, int lo, int hi){
        int cnt = 0;
        if(lo >= hi){
            return cnt;
        }
        int mid = lo + (hi - lo) / 2;

        cnt += mergeSort(nums, lo, mid);
        cnt += mergeSort(nums, mid + 1, hi);
        cnt += countPairs(nums, lo, mid, hi);
        merge(nums, lo, mid, hi);
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n - 1);
    }
};