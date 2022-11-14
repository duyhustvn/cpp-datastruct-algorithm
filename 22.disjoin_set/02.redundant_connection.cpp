// https://leetcode.com/problems/redundant-connection/

#include <iostream>
#include <vector>

using namespace std;

class FindRedundantUsingUnionFind {
    // idea: using union-find if 2 vertexs of the added edge has the same root
    // then this must be a cycle

    // Time complexity: O(n)
    // Space complexity: O(n)
    private:
    vector<int> parent;

    int find(int x) {
        int u = x;
        while (parent[u] != -1) {
            u = parent[u];
            parent[x] = u;
        }
        return u;
    }

    public:
    FindRedundantUsingUnionFind(int n) {
        for (int i = 0; i <= n; i++) {
            parent.push_back(-1);
        }
    }

    vector<int> findRedundantConnnection(vector<vector<int>> &edges) {
        for (auto edge: edges) {
            int vertex1 = edge[0]-1, vertex2 = edge[1]-1;

            int root1 = find(vertex1);
            int root2 = find(vertex2);

            // if the same root then this must be a cycle
            if (root1 == root2) {
                return edge;
            } else {
                parent[root2] = root1;
            }
        }

        return {};
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        FindRedundantUsingUnionFind *s = new FindRedundantUsingUnionFind(n);
        return s->findRedundantConnnection(edges);
    }
};
