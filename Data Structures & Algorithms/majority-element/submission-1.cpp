class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mpp;
        if(nums.size() == 1) return nums[0];
        for(int i = 0 ; i < nums.size() ; i++){
            if(mpp.find(nums[i]) != mpp.end()){
                mpp[nums[i]]++;
                if(mpp[nums[i]] > (nums.size()/2)){
                    return nums[i];
                }
            } else {
                mpp[nums[i]] = 1;
            }
        }
    }
};