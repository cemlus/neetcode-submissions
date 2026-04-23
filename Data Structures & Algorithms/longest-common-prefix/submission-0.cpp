class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string str = strs[0];
        for(int i = 1 ; i < n ; i++){
            string temp = "";
            for(int j = 0; j < str.length() ; j++){
                if(str[j] == strs[i][j]){
                    // the character is common
                    temp += strs[i][j];
                } else {
                    break;
                }
            }
            str = temp;
        }
        return str;
    }
};