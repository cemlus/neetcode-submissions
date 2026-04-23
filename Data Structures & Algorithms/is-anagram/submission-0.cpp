class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        vector<int> arr (26,0);
        for(int i = 0 ; i < s.length() ; i++){
            // 97 start
            arr[s[i] - 97]++;
        }
        for(int j = 0 ; j < t.length() ; j++){
            arr[t[j] - 97]--;
        }
        for(int k = 0 ; k < 26 ; k++){
            if(arr[k] < 0 || arr[k] > 0){
                return false;
            }
        }
        return true;
    }
};
