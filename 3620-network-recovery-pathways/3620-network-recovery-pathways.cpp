class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges,
                         vector<bool>& online,
                         long long k) {

        int n = online.size();

        vector<vector<pair<int,int>>> adj(n);
        vector<int> indeg(n,0);

        int maxCost = 0;

        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int c = e[2];

            adj[u].push_back({v,c});
            indeg[v]++;

            maxCost = max(maxCost,c);
        }

        vector<int> topo;
        queue<int> q;

        vector<int> indegCopy = indeg;

        for(int i=0;i<n;i++) {
            if(indegCopy[i]==0)
                q.push(i);
        }

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            topo.push_back(u);

            for(auto &[v,c]:adj[u]) {
                if(--indegCopy[v]==0)
                    q.push(v);
            }
        }

        auto feasible = [&](int score)->bool {

            const long long INF = 4e18;

            vector<long long> dist(n,INF);
            dist[0] = 0;

            for(int u : topo) {

                if(dist[u]==INF) continue;

                if(u!=0 && u!=n-1 && !online[u])
                    continue;

                for(auto &[v,c] : adj[u]) {

                    if(c < score)
                        continue;

                    if(v!=n-1 && !online[v])
                        continue;

                    if(dist[u] + c < dist[v]) {
                        dist[v] = dist[u] + c;
                    }
                }
            }

            return dist[n-1] <= k;
        };

        int lo = 0;
        int hi = maxCost;
        int ans = -1;

        while(lo <= hi) {

            int mid = lo + (hi-lo)/2;

            if(feasible(mid)) {
                ans = mid;
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};