class Twitter {
public:
    
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if (_userMap.find(userId) == _userMap.end()) {
            User *u = new User(userId);
            _userMap[userId] = u;
        }
        User *u = _userMap[userId];
        u->post(tweetId, _TimeStamp);
        _TimeStamp++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        if (_userMap.find(userId) == _userMap.end()) {
            return res;
        }
        priority_queue<Tweet*, vector<Tweet*>, Tweet::cmp> pq;
        for (int uId : _userMap[userId]->follower) {
            User* u = _userMap[uId];
            if (u->tweet_head != NULL) {
                pq.push(u->tweet_head);
            }
        }
        int n = 0;
        while (!pq.empty() && n < 10) {
            Tweet* t = pq.top();
            pq.pop();
            res.push_back(t->tweetID);
            if (t->next != NULL) {
                pq.push(t->next);
            }
            ++n;
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (_userMap.find(followerId) == _userMap.end()) {
            _userMap[followerId] = new User(followerId);
        }
        if (_userMap.find(followeeId) == _userMap.end()) {
            _userMap[followeeId] = new User(followeeId);
        }
        _userMap[followerId]->follow(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId)   return;
        if (_userMap.find(followerId) == _userMap.end()) {
            _userMap[followerId] = new User(followerId);
        }
        if (_userMap.find(followeeId) == _userMap.end()) {
            _userMap[followeeId] = new User(followeeId);
        }
        _userMap[followerId]->unfollow(followeeId);
    }
private:
    int _TimeStamp = 0;
    class Tweet {
    public:
        int tweetID;
        int time;
        Tweet* next;
        Tweet(int tweetid, int t): tweetID(tweetid), time(t), next(NULL) {}
        class cmp{
        public:
            bool operator()(Tweet* a, Tweet* b) {
                return a->time < b->time;
            }
        };
    };
    class User {
    public:
        int ID;
        unordered_set<int> follower;
        Tweet* tweet_head;
        User(int id) {
            this->ID = id;
            follow(id);
            tweet_head = NULL;
        }
        void post(int tweetid, int time) {
            Tweet* newT = new Tweet(tweetid, time);
            newT->next = tweet_head;
            tweet_head = newT;
        }
        void follow(int userid) {
            follower.insert(userid);
        }
        void unfollow(int userid) {
            follower.erase(userid);
        }
    };
    unordered_map<int, User*> _userMap;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */