#include <bits/stdc++.h>

using namespace std;

int getWeight(vector<int> curSubset, vector<int> wt) {
    int weight = 0;
    for (auto i: curSubset) {
        weight += wt[i];
    }
    return weight;
}

int getValue(vector<int> curSubset, vector<int> val) {
    int value = 0;
    for (auto i: curSubset) {
        value += val[i];
    }
    return value;
}


void recursive(int W, vector<int>wt, vector<int> val, int n, int index, vector<int> curSubset, int& maxVal) {
    int curValue = getValue(curSubset, val);
    maxVal = max(maxVal, curValue);

    int curWeight = getWeight(curSubset, wt);

    if (index == n) {
        return;
    }

    recursive(W, wt, val, n, index+1, curSubset, maxVal);


    if (curWeight + wt[index] <= W) {
        curSubset.push_back(index);
        recursive(W, wt, val, n, index + 1, curSubset, maxVal);
    }
}


//Function to return max value that can be put in knapsack of capacity W.
int knapSack(int W, vector<int> wt, vector<int> val)
{
   int n = wt.size();
   // Your code here
   int maxValue = INT_MIN;
   vector<int> curSubset;
   recursive(W, wt, val, n, 0, curSubset, maxValue);

   return maxValue;
}
