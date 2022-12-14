// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
#include <iostream>
#include <unordered_map>

using namespace std;

struct RSTNode {
    int val; // only left node has value
    RSTNode* child[2]; // child is array of RSTNode* with length equals 2

    RSTNode() {
        child[0] = NULL;
        child[1] = NULL;
    }
};

class RST {
    friend class RSTTest;
    FRIEND_TEST(RSTTest, MethodConvertToBinary);
    FRIEND_TEST(RSTTest, MethodInsert);
    FRIEND_TEST(RSTTest, MethodGetMaxXOR);
    FRIEND_TEST(RSTTest, MethodFindMaximumXOR);

    private:
    RSTNode *root;
    int maxLengthBinary; // number of bit of max number in vector
    unordered_map<int, string> mapNumToBinary;

    void setMaxLengthBinary(int v) {
        maxLengthBinary = v;
    }

    int getMaxNumber(vector<int>& nums) {
        int maxNumber = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxNumber) {
                maxNumber = nums[i];
            } 
        }
        return maxNumber;
    }

    string convertToBinary(int v) {
        string result = "";
        while (v != 0) {
            int remainder = v%2;
            result = to_string(remainder) + result;
            v = v / 2;
        }
        return result;
    }

    string convertToBinary(int v, int length) {
        string result = "";
        while (v != 0) {
            int remainder = v%2;
            result = to_string(remainder) + result;
            v = v / 2;
        }
        int resultSize = result.size();
        // invalid value of length
        if (resultSize > length) {
            return "-1";
        }

        while (resultSize < length) {
            result = "0" + result;
            length--;
        }
        return result;
    }

    RSTNode* getRootNode() {
        return root;
    }

    public:
    RST() {
        root = new RSTNode();
    }

    void insert(int v) {
        string binaryForm = convertToBinary(v, maxLengthBinary);
        mapNumToBinary[v] = binaryForm;
        RSTNode *cur = root;
        for (int i = 0; i < binaryForm.size(); i++) {
            int index = binaryForm[i] - '0';
            if (cur->child[index] == NULL) {
                RSTNode* newNode = new RSTNode();
                cur->child[index] = newNode;
            }
            cur = cur->child[index];
        }
        cur->val = v;
    }

    int getMaxXOR(int v) {
        RSTNode *cur = root;
        string binaryForm = mapNumToBinary[v];
        for (int i = 0; i < binaryForm.size(); i++) {
            int index = binaryForm[i] - '0';
            int expectedIndex = 1 - index;
            if (cur->child[expectedIndex] != NULL) {
                cur = cur->child[expectedIndex];
            } else if (cur->child[index] != NULL) {
                cur = cur->child[index];
            } else {
                return cur->val;
            }
        }
        if (cur != NULL) {
            return cur->val;
        }
        return -1;
    }    

    int findMaximumXOR(vector<int>& nums) {
        int maxValue = getMaxNumber(nums);
        string maxValueInBinary = convertToBinary(maxValue);
        maxLengthBinary = maxValueInBinary.size();

        for (int i = 0; i < nums.size(); i++) {
            insert(nums[i]);
        }

        int maxXor = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int foundNumber = getMaxXOR(nums[i]);
            maxXor = max(foundNumber ^ nums[i], maxXor);
        }
        return maxXor;
    }
};

class Solution {
    private:
    RSTNode *root;
    public:
    Solution() {
        root = new RSTNode();
    }

    // it is the same with insert but optimization version
    void insert(int v) {
        RSTNode *cur = root;

        RSTNode *newNode;
        for (int i = 31; i >= 0; i--) {
            int bit = (v >> i) & 1;
            if (cur->child[bit] == NULL) {
                newNode = new RSTNode();
                cur->child[bit] = newNode;
            }
            cur = cur->child[bit];
        }
        cur->val = v;
    } 

    int getMaxXOR(int v) {
        RSTNode *cur = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (v >> i) & 1;
            int expectedIndex = 1 - bit;
            if (cur->child[expectedIndex] != NULL) {
                cur = cur->child[expectedIndex];
            } else if (cur->child[bit] != NULL) {
                cur = cur->child[bit];
            } else {
                return cur->val;
            }
        }
        if (cur != NULL) {
            return cur->val;
        }
        return -1;
    }

    int findMaximumXOR(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            insert(nums[i]);
        }

        int maxXor = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int foundNumber = getMaxXOR(nums[i]);
            maxXor = max(foundNumber ^ nums[i], maxXor);
        }
        return maxXor;
    }
};