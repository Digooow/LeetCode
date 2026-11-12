#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

class Solution {
public:
    bool canFinish(int numCourses, const std::vector<std::vector<int>>& prerequisites) {
        std::vector<std::vector<int>> adj(numCourses);
        std::vector<int> inDegree(numCourses, 0);

        for (const auto& edge : prerequisites) {
            int course = edge[0];
            int prereq = edge[1];
            adj[prereq].push_back(course);
            ++inDegree[course];
        }

        std::queue<int> ready;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                ready.push(i);
            }
        }

        int completed = 0;
        while (!ready.empty()) {
            int curr = ready.front();
            ready.pop();
            ++completed;

            for (int nextCourse : adj[curr]) {
                if (--inDegree[nextCourse] == 0) {
                    ready.push(nextCourse);
                }
            }
        }

        return completed == numCourses;
    }
};

int main() {
    Solution solver;

    assert(solver.canFinish(2, {{1, 0}}) == true);
    assert(solver.canFinish(2, {{1, 0}, {0, 1}}) == false);

    std::cout << "[OK] 0207 - Course Schedule: todos os testes passaram.\n";
    return 0;
}
