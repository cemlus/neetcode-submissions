class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int r = 0; // Pointer for the position of the next valid element
        for (int l = 0; l < nums.size(); l++) {
            // If the current element is NOT the value we want to remove...
            if (nums[l] != val) {
                // ...copy it to the 'r' position
                nums[r] = nums[l];
                // Move the r forward
                r++;
            }
        }

        // 'r' now represents the count of valid elements
        return r; 
    }
};