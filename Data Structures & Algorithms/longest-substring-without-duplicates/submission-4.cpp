class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        if(s.length() == 0) return 0;
        // we take advantage of the property of sets which says that an element can only be added ONCE to a set.
        int maxLen = INT_MIN;
        int l = 0;
        for(int r = 0 ; r < s.length() ; r++){
            while(st.find(s[r]) != st.end()){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};
