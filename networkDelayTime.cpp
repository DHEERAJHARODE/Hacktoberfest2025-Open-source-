class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        queue<pair<int, int>> q;

        vector<vector<pair<int, int>>> adj(n+1);

        for(int i = 0; i< times.size(); i++){
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        q.push({k, 0});
        vector<int> dis(n+1, INT_MAX);
        dis[k] = 0;

        while(!q.empty()){

            int node = q.front().first;
            int time = q.front().second;

            q.pop();

            for(auto it: adj[node]){
                int total_time = time+it.second;

                if(dis[it.first] > total_time){
                    dis[it.first] = total_time;
                    q.push({it.first, total_time});
                }
            }
        }
        int maxTime =0;

        for(int i = 1; i<= n; i++){
            if(dis[i] == INT_MAX) return -1;// this will check if any node is unvisited
            maxTime = max(dis[i], maxTime);
        }
        return maxTime;
    }
};
