class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int mini = INT_MAX;
        
        // the key idea here is to know that kadane's algo helps us to find max subarray
        // also total sum = (min subarray + max subarray)
        // therefore (total sum - min subarray) = max subarray 

        int total = 0;
        for(int n: nums){
            total += n;
        }

        int l = 0; 
        int r = 0;
        int sum = 0;
        while(r < nums.size()){
            sum += nums[r];
            mini = min(sum, mini);

            if(sum > 0){
                sum = 0;
                l = r;
            }
            r++;
        }

        cout << mini << endl;
        // finding the global minimum => would help us in getting the wrapped around max subarray
        // but what if the max subarray isn't wrapped, what if it's in the middle like a normal subarray and therefore we also calculate the maximum normal subarray using kadane
        
        int maxi = INT_MIN;
        r = 0;
        l = 0;
        sum = 0;
        while(r < nums.size()){
            sum += nums[r];
            maxi = max(sum, maxi);

            if(sum < 0){
                sum = 0;
                l = r;
            }
            r++;
        }

        // in case this is an entirely negative array then maxi must have the maximum subarray
        if(maxi < 0) return maxi;

        return max(maxi, total - mini);

    }
};