class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        float currAvg = 0;
        int currSum = 0, count = 0;
        int l = 0, r = 0;

        while (r < k) {
            currSum += arr[r];
            r++;
        }
        currAvg = currSum / k;
        if (currAvg >= threshold) {
            count++;
        }

        // cout << count << endl;
        // cout << "this is the sum of the first k elements: " << currSum
        //      << " and their avg: " << currAvg << endl;
        cout << r << endl;
        while (r < arr.size()) {
            currSum += arr[r];
            currSum -= arr[l];
            currAvg = currSum / k;
            // cout << "this is the sum of the " << r - k + 1
            //      << "th iteration: " << currSum << " and their avg: " << currAvg
            //      << " with r = " << r << " and l = " << l << endl;
            if (currAvg >= threshold) {
                count++;
            }
            r++;
            l++;
        }

        return count;
    }
};