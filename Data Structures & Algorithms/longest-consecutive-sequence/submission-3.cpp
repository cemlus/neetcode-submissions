class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxLen = 0, maxi = 0;
        if(nums.size() == 0) return 0;
        unordered_set<int> st(nums.begin(), nums.end());
        for (int ele : st) {
            if (st.find(ele - 1) == st.end()) {
                // THE FIX: Only start counting if 'ele' is the start of a
                // sequence
                // If st contains ele - 1, then 'ele' is in the middle of a
                // sequence
                int currEle = ele;
                int currLen = 0;
                while (st.find(currEle) != st.end()) {
                    // Count how long this specific sequence goes
                    currLen++;
                    currEle++;
                }
                maxLen = max(maxLen, currLen);
            }
        }
        return maxLen;
    }
};
