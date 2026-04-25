class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        // array is RIGHT rotated
        while (lo <= hi) {
            int mid = lo + ((hi - lo) / 2);
            if(nums[mid] == target) return mid;
            if(nums[mid] <= nums[hi]){
                // it is RIGHT SORTED
                if(target >= nums[mid] && target <= nums[hi]){
                    // it exists in the 2nd half of the array i.e. the right sorted one
                    lo = mid + 1;
                } else {
                    // it exists in the 1st half of the array i.e. the unsorted left one
                    hi = mid - 1;
                }
            } else {
                // it is LEFT SORTED
                if(target >= nums[lo] && target <= nums[mid]){
                    // it exists within the left sorted array's first half
                    hi = mid - 1;
                } else {
                    // it exists within the left sorted array's second half
                    lo = mid + 1;
                }
            }
        }
        return -1;
    }
};
