class Twitter {
public:
    unordered_map<int, vector<pair<int, int>>>posts;
    unordered_map<int, unordered_set<int>>follows;
    int time;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>>pq;

        for(auto it : posts[userId]){
            pq.push(it);
        }

        for(auto it : follows[userId]){
            for(auto jt : posts[it]){
                pq.push(jt);
            }
        }
        
        vector<int>news;
        int cnt = 10;
        while(!pq.empty() && cnt){
            news.push_back(pq.top().second);
            pq.pop();
            cnt--;
        }
        return news;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */