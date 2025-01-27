#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // Initialize the adjacency matrix
        vector<vector<bool>> isPrerequisite(numCourses, vector<bool>(numCourses, false));
        
        // Fill the direct prerequisites in the matrix
        for (const auto& prereq : prerequisites) {
            isPrerequisite[prereq[0]][prereq[1]] = true;
        }
        
        // Use Floyd-Warshall to compute transitive closure
        for (int k = 0; k < numCourses; ++k) {
            for (int i = 0; i < numCourses; ++i) {
                for (int j = 0; j < numCourses; ++j) {
                    if (isPrerequisite[i][k] && isPrerequisite[k][j]) {
                        isPrerequisite[i][j] = true;
                    }
                }
            }
        }
        
        // Answer the queries
        vector<bool> result;
        for (const auto& query : queries) {
            result.push_back(isPrerequisite[query[0]][query[1]]);
        }
        
        return result;
    }
};
