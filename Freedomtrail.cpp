class Solution {
public:

    typedef pair<int, pair<int, int>> P; // {cost, {ring_index, key_index}}

    int findRotateSteps(string ring, string key) {
        int n = ring.size(), m = key.size();
        unordered_map<char, vector<int>> pos;

        // Store all positions of each character
        for (int i = 0; i < n; i++) pos[ring[i]].push_back(i);

        // Min-heap for Dijkstra (cost, {ring_index, key_index})
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0, 0}});

        // Distance table: dist[ring_index][key_index]
        vector<vector<int>> dist(n, vector<int>(m + 1, INT_MAX));
        dist[0][0] = 0;

        while (!pq.empty()) {
            auto [cost, state] = pq.top();
            pq.pop();

            int i = state.first;   // current ring position
            int j = state.second;  // current key index

            // If full key is spelled
            if (j == m) return cost;

            // Already found a better way before
            if (cost > dist[i][j]) continue;

            // Try all next positions for key[j]
            for (int p : pos[key[j]]) {
                int rotate = abs(p - i);
                int step = min(rotate, n - rotate);
                int newCost = cost + step + 1; // +1 for pressing button

                if (newCost < dist[p][j + 1]) {
                    dist[p][j + 1] = newCost;
                    pq.push({newCost, {p, j + 1}});
                }
            }
        }

        return -1; // should never reach here
    }
};
