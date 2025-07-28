class Twitter {
public:
    unordered_map<int, unordered_set<int>>followList;
    unordered_map<int, vector<pair<int,int>>>postList;
    int time;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        postList[userId].push_back({time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>>pq;

        for(auto it : postList[userId]){
            pq.push(it);
        }

        for(auto it : followList[userId]){
            for(auto jt : postList[it]){
                pq.push(jt);
            }
        }

        int cnt = 10;
        vector<int>res;

        while(cnt && !pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
            cnt--;
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followList[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followList[followerId].erase(followeeId);
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