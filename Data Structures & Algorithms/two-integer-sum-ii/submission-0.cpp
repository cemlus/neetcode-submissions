class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int l = 0, r = numbers.size() - 1;
        // using the good'ol greedy approach to solve this problem
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum < target) {
                l++;
            } else if (sum > target) {
                r--;
            } else {
                cout << "target found: " << sum << endl;
                ans.push_back(l + 1);
                ans.push_back(r + 1);
                break;
            }
        }
        return ans;
    }
};
