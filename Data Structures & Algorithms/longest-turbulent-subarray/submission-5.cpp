class Solution {
   public:
    int maxTurbulenceSize(vector<int>& arr) {
        if (arr.size() == 1) return 1;

        string str = "";

        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] > arr[i + 1])
                str += '>';
            else if (arr[i] < arr[i + 1])
                str += '<';
            else
                str += '=';
        }

        int count = 1;
        int maxi = 1;

        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '=') {
                // Current comparison is '='
                count = 1;
            }

            else if (i == 0 || str[i] == str[i - 1]) {
                // First comparison OR current comparison can start a new pair
                count = 2;
            }

            else {
                // Comparisons alternate
                count++;
            }

            maxi = max(maxi, count);
        }

        return maxi;
    }
};