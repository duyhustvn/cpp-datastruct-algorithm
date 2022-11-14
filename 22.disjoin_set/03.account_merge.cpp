#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class AccountsMergeUsingUnionFind {
    private:
    int numsOfAccount;
    vector<int> parent;

    int find(int x) {
        int u = x;
        while (parent[u] != -1) {
            u = parent[u];
            parent[x] =u;
        }
        return u;
    }


    public:
    AccountsMergeUsingUnionFind(int n) {
        numsOfAccount = n;
        for (int i = 0; i < n; i++) {
            parent.push_back(-1);
        }
    }


    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> result;

        unordered_map<string, int> groupMail;


        for (int i = 0; i < accounts.size(); i++) {

            for (int j = 1; j < accounts[i].size(); j++) {
                // not found in map
                if (groupMail.find(accounts[i][j]) == groupMail.end() ) {
                    groupMail[accounts[i][j]] = i;
                } else {
                    int curGroup = groupMail[accounts[i][j]];
                    // in case an account has duplicated email
                    // ["John", "John@gmail.com", "John@gmail.com", "John1@gmail.com"]
                    if (curGroup == i) {
                        continue;
                    }
                    int rootGroup = find(curGroup);
                    int rootI = find(i);

                    if (rootGroup == rootI) {
                        continue;
                    }

                    // union i with curGroup
                    parent[rootI] = rootGroup;
                }
            }
        }

        unordered_map<int, vector<string>> mapGroupToEmails;
        for (auto e: groupMail) { // e stand for element
            string email = e.first;
            int rootGroup = find(e.second);

            mapGroupToEmails[rootGroup].push_back(email);
        }

        for (auto e: mapGroupToEmails) {
            vector<string> listEmail = e.second;
            sort(listEmail.begin(), listEmail.end());
            string accountName = accounts[e.first][0];
            listEmail.insert(listEmail.begin(), accountName);
            result.push_back(listEmail);
        }

        return result;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        AccountsMergeUsingUnionFind *s = new AccountsMergeUsingUnionFind(accounts.size());
        vector<vector<string>> result = s->accountsMerge(accounts);
        return result;
    }
};
