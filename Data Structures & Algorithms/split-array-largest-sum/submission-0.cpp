class Solution {
public:
    bool canAllocate(vector<int>& arr, int k, long long maxPages) {
        int studentCount = 1;
        long long currSum = arr[0];

        if (arr[0] > maxPages) return false;

        for (int idx = 1; idx < arr.size(); idx++) {
            // this book itself is too large
            if (arr[idx] > maxPages)
                return false;

            if (currSum + arr[idx] <= maxPages) {
                currSum += arr[idx];
            } else {
                // start a new student and assign the current book to this new student
                studentCount++;
                currSum = arr[idx];

                if (studentCount > k) return false;
            }
        }
        return true;
    }

    int splitArray(vector<int>& arr, int k) {
        int n = arr.size();

        if (k > n) return -1;

        long long totalPages = 0;
        int maxi = 0;

        for (int p : arr) {
            totalPages += p;
            maxi = max(maxi, p);
        }

        long long lo = maxi;
        long long hi = totalPages;

        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;

            if (canAllocate(arr, k, mid)) {
                // since mid is feasible we try to find a smaller maximum.
                hi = mid - 1;
            } else {
                // mid is not feasible hence we need more capacity.
                lo = mid + 1;
            }
        }

        return lo;
    }
};