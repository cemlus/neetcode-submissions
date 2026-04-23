class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            // to find the number of subarrays with sum = k, we need to find the number of subarrays with 
            // sum = k - currSum
            int n = nums.size();
            unordered_map<int, int> mpp;
            int currSum = 0;
            int count = 0;
            for(int i = 0 ; i < n ; i++){
                currSum += nums[i];
                if(currSum == k) count++;
                // check if 'prefix-sum' exists in the map
                if(mpp.find(currSum - k) != mpp.end()){
                    // we add the count/frequency of the prefix sum
                    count += mpp[currSum - k];
                }
                mpp[currSum]++;
            }
            return count;
        }
};