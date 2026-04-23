class Solution {
public:
    vector<int> returnFreqArr(string str1) {
        vector<int> arr(26, 0);
        for (int i = 0; i < str1.length(); i++) {
            arr[str1[i] - 97]++;
        }
        return arr;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mpp;
        for (int i = 0; i < strs.size(); i++) {
            vector<int> freqArr = returnFreqArr(strs[i]);
            mpp[freqArr].push_back(strs[i]);
        }
        
        vector<vector<string>> ans;
        for (const auto& pair : mpp) {
            ans.push_back(pair.second);
        }
        return ans;
    }
};
