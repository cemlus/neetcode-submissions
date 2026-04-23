class Solution {
public:
    int characterReplacement(string s, int k) {
        // 'A' = 65
        unordered_map<char, int> freq;
        int maxFreq = 0, maxLen = 0;
        int l = 0;
        for(int r = 0 ; r < s.length() ; r++){
            freq[s[r]]++;
            maxFreq = max(maxFreq, freq[s[r]]);

            // If (window_size - maxFreq) > k, it's invalid
            if((r - l + 1) - maxFreq > k){
                // hence trim it down;
                freq[s[l]]--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};
