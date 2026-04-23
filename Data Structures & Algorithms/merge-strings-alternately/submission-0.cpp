class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len1 = word1.length();   
        int len2 = word2.length();   
        int l = 0, r = 0;
        string ans = "";

        while(l < len1 && r < len2){
            ans += word1[l++];
            ans += word2[r++];
        }
        while(l < len1){
            ans += word1[l++];
        }
        while(r < len2){
            ans += word2[r++];
        }
        return ans;
    }
};