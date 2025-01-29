class Solution {
public:
    vector<int> parent;
    
    int find(int x) {
        if (parent[x] == -1) return x;
        return parent[x] = find(parent[x]); // Path compression
    }
    
    bool unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return false; // Cycle detected
        parent[rootX] = rootY; // Union operation
        return true;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1, -1); // Nodes are 1-based
        
        for (auto& edge : edges) {
            if (!unionSet(edge[0], edge[1])) return edge; // Return the edge causing cycle
        }
        return {};
    }
};
