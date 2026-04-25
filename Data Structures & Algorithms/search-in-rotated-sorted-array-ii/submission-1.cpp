class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target)
                return true;
            if(nums[mid] == nums[hi] && nums[mid] == nums[lo]){
                hi--;
                lo++;
                continue;
            }
            if (nums[mid] <= nums[hi]) {
                //  array is right-sorted
                if (target >= nums[mid] && target <= nums[hi]) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            } else {
                //  array is left-sorted
                if (target <= nums[mid] && target >= nums[lo]) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
        }
        return false;
    }
};