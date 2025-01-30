#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 1);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> color(n + 1, 0);
        vector<vector<int>> components;
        
        // Step 1: Check for bipartiteness and find connected components
        for (int i = 1; i <= n; ++i) {
            if (color[i] == 0) {
                queue<int> q;
                vector<int> component;
                q.push(i);
                color[i] = 1;
                
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    component.push_back(node);
                    
                    for (int neighbor : adj[node]) {
                        if (color[neighbor] == 0) {
                            color[neighbor] = -color[node];
                            q.push(neighbor);
                        } else if (color[neighbor] == color[node]) {
                            return -1; // Odd cycle detected
                        }
                    }
                }
                components.push_back(component);
            }
        }
        
        // Step 2: Find the maximum BFS depth for each component
        auto bfsMaxDepth = [&](int start) -> int {
            queue<int> q;
            unordered_map<int, int> depth;
            q.push(start);
            depth[start] = 1;
            int maxDepth = 1;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : adj[node]) {
                    if (!depth.count(neighbor)) {
                        depth[neighbor] = depth[node] + 1;
                        maxDepth = max(maxDepth, depth[neighbor]);
                        q.push(neighbor);
                    }
                }
            }
            return maxDepth;
        };

        int maxGroups = 0;
        for (auto& component : components) {
            int localMax = 0;
            for (int node : component) {
                localMax = max(localMax, bfsMaxDepth(node));
            }
            maxGroups += localMax;
        }

        return maxGroups;
    }
};
