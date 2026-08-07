class Twitter {
   public:
    struct Tweet {
        int time;
        int tweetId;
    };

    int count;
    unordered_map<int, unordered_set<int>> followerDb;
    unordered_map <int, vector<Tweet>> followerPosts;

    Twitter() { count = 0; }

    void postTweet(int userId, int tweetId) {
        // storing tweets with increasing timestamps;
        followerPosts[userId].push_back({count++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        struct Node {
            int time;
            int tweetId;
            int userId;
            int idx;
        };

        // we build a max-heap by time
        struct cmp {
            bool operator()(Node a, Node b) { return a.time < b.time; }
        };

        priority_queue<Node, vector<Node>, cmp> pq;

        // this is a helper function that pushes the latest tweets of a user into the heap
        auto pushLatestTweet = [&](int userId) {
            if (!followerPosts[userId].empty()) {
                int lastIdx = followerPosts[userId].size() - 1;
                auto t = followerPosts[userId][lastIdx];
                pq.push({t.time, t.tweetId, userId, lastIdx});
            }
        };

        // pushing user's own latest tweets;
        pushLatestTweet(userId);

        // push the latest tweet form every folowee
        for(int followeeId: followerDb[userId]){
            pushLatestTweet(followeeId);
        }

        vector<int> res;

        while(!pq.empty() && res.size() < 10){
            auto curr = pq.top();
            pq.pop();

            // this is the newest tweet as of now
            res.push_back(curr.tweetId);

            // after using that tweet we must retreive the "next" latest tweet from the same user
            if(curr.idx > 0){
                int nextIdx = curr.idx - 1;
                auto t = followerPosts[curr.userId][nextIdx];
                pq.push({t.time, t.tweetId, curr.userId, nextIdx});
            }
        }

        return res;

    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        followerDb[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        followerDb[followerId].erase(followeeId);
    }
};
