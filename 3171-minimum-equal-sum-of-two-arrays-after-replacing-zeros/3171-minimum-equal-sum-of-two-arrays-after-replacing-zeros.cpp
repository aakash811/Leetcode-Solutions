class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long n = nums1.size();
        long long m = nums2.size();

        long long sum1 = 0;
        long long sum2 = 0;
        long long cnt1 = 0;
        long long cnt2 = 0;

        for(long long i = 0; i < n; i++){
            if(nums1[i] == 0){
                cnt1++;
            }
            sum1 += nums1[i];
        }

        for(long long i = 0; i < m; i++){
            if(nums2[i] == 0){
                cnt2++;
            }
            sum2 += nums2[i];
        }

        cout<<sum1<<" "<<sum2<<endl;
        cout<<cnt1<< " "<< cnt2<<endl;

        if(cnt1 == 0 && cnt2 == 0){
            if(sum1 == sum2){
                return sum1;
            }
            else{
                return -1;
            }
        }

        if(sum2 > sum1){
            if(cnt1 != 0 && cnt2 == 0){
                long long diff = sum2 - sum1;
                if(cnt1 > diff){
                    return -1;
                }
                return sum2;
            }
            else if(cnt1 != 0 && cnt2 != 0){
                long long maxi = max(sum2 + cnt2, sum1 + cnt1);
                return maxi;
            }
            else if(cnt1 == 0){
                return -1;
            }
        }
        else if(sum2 < sum1){
            if(cnt2 != 0 && cnt1 == 0){
                long long diff = sum1 - sum2;
                if(cnt2 > diff){
                    return -1;
                }
                return sum1;
            }
            else if(cnt2 != 0 && cnt1 != 0){
                long long maxi = max(sum2 + cnt2, sum1 + cnt1);
                return maxi;
            }
            else if(cnt2 == 0){
                return -1;
            }
        }
        else if(sum2 == sum1){
            if(cnt2 != 0 && cnt1 == 0){
                return -1;
            }
            else if(cnt2 == 0 && cnt1 != 0){
                return -1;
            }
            else if(cnt2 != 0 && cnt1 != 0){
                return max(sum2 + cnt2, sum1 + cnt1);
            }
        }
        return -1;
    }
};