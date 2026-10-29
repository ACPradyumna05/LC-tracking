class Twitter {
    int timestamp;

    unordered_map<int, unordered_set<int>> followMap;

    unordered_map<int, vector<pair<int, int>>> tweetsMap;

public:
    Twitter() {
        timestamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweetsMap[userId].push_back({timestamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> feed;

        priority_queue<vector<int>> maxHeap;

        unordered_set<int> users = followMap[userId];
        users.insert(userId); 
        for (int uId : users) {
            if (tweetsMap.count(uId) && !tweetsMap[uId].empty()) {
                int lastIdx = tweetsMap[uId].size() - 1;
                auto& [time, tweetId] = tweetsMap[uId][lastIdx];
                maxHeap.push({time, tweetId, uId, lastIdx});
            }
        }

        while (!maxHeap.empty() && feed.size() < 10) {
            auto top = maxHeap.top();
            maxHeap.pop();

            int tweetId = top[1];
            int uId = top[2];
            int idx = top[3];

            feed.push_back(tweetId);

            if (idx > 0) {
                auto& [prevTime, prevTweetId] = tweetsMap[uId][idx - 1];
                maxHeap.push({prevTime, prevTweetId, uId, idx - 1});
            }
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followMap[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followMap[followerId].erase(followeeId);
        }
    }
};