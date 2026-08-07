class Twitter {
public:
    int time = 0;

    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>>> tweets;

    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>> pq;

        following[userId].insert(userId);

        for (int user : following[userId]) {
            if (tweets[user].empty()) continue;

            int idx = tweets[user].size() - 1;

            pq.push({
                tweets[user][idx].first,
                tweets[user][idx].second,
                user,
                idx
            });
        }

        vector<int> ans;

        while (!pq.empty() && ans.size() < 10) {

            auto cur = pq.top();
            pq.pop();

            int tweetId = cur[1];
            int user = cur[2];
            int idx = cur[3];

            ans.push_back(tweetId);

            idx--;

            if (idx >= 0) {
                pq.push({
                    tweets[user][idx].first,
                    tweets[user][idx].second,
                    user,
                    idx
                });
            }
        }

        return ans;
    }
};