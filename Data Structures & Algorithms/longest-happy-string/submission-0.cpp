class Solution {
   public:

    string longestDiverseString(int a, int b, int c) {
        // feels similar to task scheduler but with more conditions
        priority_queue <pair<int, char>> maxHeap;
        if(a > 0) maxHeap.push({a, 'a'});
        if(b > 0) maxHeap.push({b, 'b'});
        if(c > 0) maxHeap.push({c, 'c'});
        
        string str = "";

        while(!maxHeap.empty()){
            auto [freq1, char1] = maxHeap.top();
            maxHeap.pop();

            int n = str.length();

            if(n >= 2 && str[n - 1] == char1 && str[n - 2] == char1){
                // now introduce the new character
                if(maxHeap.empty()) break;

                auto [freq2, char2] = maxHeap.top();
                maxHeap.pop();

                str += char2;
                freq2--;

                if(freq2 > 0) maxHeap.push({freq2, char2});
                // put char1 back because we didn't use it
                maxHeap.push({freq1, char1});

            } else {
                str += char1;
                freq1--;

                if(freq1 > 0) maxHeap.push({freq1, char1});
            }
            
        }

        return str;
    }
};