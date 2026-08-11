/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        map<int, int> events;
        for(auto it: intervals){
            int start = it.start;
            int end = it.end;

            events[start] += 1;
            events[end] -= 1;
        }
        int sum = 0;
        for(auto it: events){
            sum += it.second;
            if(sum > 1) return false;
        }
        return true;
    }
};
