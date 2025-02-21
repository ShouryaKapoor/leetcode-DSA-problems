class Twitter {
private:
    struct Tweet {
        int id;
        int time;
        Tweet(int tweetId, int timestamp) : id(tweetId), time(timestamp) {}
    };
    
    unordered_map<int, vector<Tweet>> tweets; // Stores tweets of each user
    unordered_map<int, unordered_set<int>> followers; // Stores user follow relationships
    int timestamp; // Global timestamp for ordering tweets
    
public:
    Twitter() {
        timestamp = 0; // Initialize timestamp to track order of tweets
    }
    
    // User posts a new tweet
    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(tweetId, timestamp++);
    }
    
    // Retrieve the 10 most recent tweet IDs in the user's news feed
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> maxHeap; // Max-heap to store tweets based on time
        
        // Include the user's own tweets
        for (const auto& tweet : tweets[userId]) {
            maxHeap.emplace(tweet.time, tweet.id);
        }
        
        // Include tweets from followed users
        for (int followeeId : followers[userId]) {
            for (const auto& tweet : tweets[followeeId]) {
                maxHeap.emplace(tweet.time, tweet.id);
            }
        }
        
        vector<int> feed;
        for (int i = 0; i < 10 && !maxHeap.empty(); i++) {
            feed.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        
        return feed;
    }
    
    // Follower follows a followee
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) { // A user cannot follow themselves
            followers[followerId].insert(followeeId);
        }
    }
    
    // Follower unfollows a followee
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};
