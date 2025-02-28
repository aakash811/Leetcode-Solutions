class Solution {
public:
    int merge(vector<int> &arr, int low, int mid, int high){
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        
        int cnt = 0;
        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                cnt += (mid - left + 1);
                right++;
            }
        }
        
        while(left <= mid){
            temp.push_back(arr[left]);
            left++;
        }
        
        while(right <= high){
            temp.push_back(arr[right]);
            right++;
        }
        
        for(int i = low; i <= high; i++){
            arr[i] = temp[i - low];
        }
        
        return cnt;
    }
    
    int mergeSort(int low, int high, vector<int> &vec){
        int cnt = 0;
        if(low >= high) return cnt;
        int mid = (low + (high - low) / 2);
        
        cnt += mergeSort(low, mid, vec);
        cnt += mergeSort(mid + 1, high, vec);
        cnt += countPairs(vec, low, mid, high);
        merge(vec, low, mid, high);
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

    int reversePairs(vector<int>& nums) {
        return mergeSort(0, nums.size() - 1, nums);
    }
};