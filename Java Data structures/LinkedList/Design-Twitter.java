// Design-Twitter.java
// Author: Akshat Sharma
// Description: Design Twitter - Implement basic follow, postTweet, getNewsFeed.

import java.util.*;

class Twitter {
    private static int timeStamp = 0;

    private Map<Integer, User> userMap;

    private class Tweet {
        int id;
        int time;
        Tweet next;
        public Tweet(int id) {
            this.id = id;
            this.time = timeStamp++;
            this.next = null;
        }
    }

    public class User {
        int id;
        Set<Integer> followed;
        Tweet tweetHead;
        public User(int id) {
            this.id = id;
            followed = new HashSet<>();
            follow(id); // follow self
        }
        public void follow(int id) {
            followed.add(id);
        }
        public void unfollow(int id) {
            if (id != this.id)
                followed.remove(id);
        }
        public void post(int id) {
            Tweet t = new Tweet(id);
            t.next = tweetHead;
            tweetHead = t;
        }
    }

    public Twitter() {
        userMap = new HashMap<>();
    }

    public void postTweet(int userId, int tweetId) {
        if (!userMap.containsKey(userId))
            userMap.put(userId, new User(userId));
        userMap.get(userId).post(tweetId);
    }

    public List<Integer> getNewsFeed(int userId) {
        List<Integer> res = new ArrayList<>();
        if (!userMap.containsKey(userId))
            return res;
        Set<Integer> users = userMap.get(userId).followed;
        PriorityQueue<Tweet> pq = new PriorityQueue<>(users.size(), (a, b) -> b.time - a.time);
        for (int user : users) {
            Tweet t = userMap.get(user).tweetHead;
            if (t != null)
                pq.add(t);
        }
        int n = 0;
        while (!pq.isEmpty() && n < 10) {
            Tweet t = pq.poll();
            res.add(t.id);
            n++;
            if (t.next != null)
                pq.add(t.next);
        }
        return res;
    }

    public void follow(int followerId, int followeeId) {
        if (!userMap.containsKey(followerId))
            userMap.put(followerId, new User(followerId));
        if (!userMap.containsKey(followeeId))
            userMap.put(followeeId, new User(followeeId));
        userMap.get(followerId).follow(followeeId);
    }

    public void unfollow(int followerId, int followeeId) {
        if (!userMap.containsKey(followerId) || followerId == followeeId)
            return;
        userMap.get(followerId).unfollow(followeeId);
    }
}
