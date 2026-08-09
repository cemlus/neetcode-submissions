class Solution {
   public:
    string reorganizeString(string s) {
        unordered_map<char, int> mpp;
        for (char c : s) {
            mpp[c]++;
        }

        priority_queue<pair<int, char>> pq;
        for (auto it : mpp) {
            pq.push({it.second, it.first});
        }

        string str;

        while (!pq.empty()) {
            int n = str.length();
            auto [freq1, char1] = pq.top();
            pq.pop();

            if(n >= 1 && str[n - 1] == char1){
                // if top is same as the character before, then only go for the next element from the top in the heap
                if(pq.empty()){
                    return "";
                }
                auto [freq2, char2] = pq.top();
                pq.pop();

                freq2--;
                str.push_back(char2);

                if(freq2 > 0) pq.push({freq2, char2});

                // pushing char1 back inside since it wasn't used
                pq.push({freq1, char1});
            } else {
                str.push_back(char1);
                freq1--;

                if(freq1 > 0) pq.push({freq1, char1});
            }
        }
        return str;
    }
};