class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        if (n == 1) return 0;
        vector<bool> visited(n, false);
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++)
            adj[edges[i][0]].push_back(i);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        // Structure: {time, node}
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();
            if (visited[node])
                continue;
            if (node == n - 1)
                return time;
            visited[node] = true;
            for (int it : adj[node]) {
                if (!visited[edges[it][1]] && time <= edges[it][3]) {
                    pq.push({max(time, edges[it][2]) + 1, edges[it][1]});
                }
            }
        }
        return -1;
    }
};