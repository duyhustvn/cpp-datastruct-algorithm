// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
#include <iostream>

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

    private:
    RSTNode *root;
    int maxLengthBinary; // number of bit of max number in vector

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

    public:
    RST() {
        root = new RSTNode();
    }

    RSTNode* getRootNode() {
        return root;
    }

    void insert(int v) {
        string binaryForm = convertToBinary(v, maxLengthBinary);
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

    int findMaximumXOR(vector<int>& nums) {
        int maxValue = getMaxNumber(nums);
        string maxValueInBinary = convertToBinary(maxValue);
        maxLengthBinary = maxValueInBinary.size();

        for (int i = 0; i < nums.size(); i++) {
            insert(nums[i]);
        }
        return 1;
    }
};