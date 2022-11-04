#include <iostream>
#include <vector>

using namespace std;

class KMP {
    friend class KMPTest;
    FRIEND_TEST(KMPTest, MethodComputeLPSArray);

    private:
    vector<int> computeLPSArrayBruteForce(string pat) {
        vector<int> lsp;

        lsp.push_back(0);

        string sub;
        string purPrefix;
        string suffix;
        bool found;
        for (int i = 1; i < pat.size(); i++) {
            found = false;
            sub = pat.substr(0, i+1);
            
            for (int j = 1; j < sub.size(); j++) {
                purPrefix = sub.substr(0, sub.size()-j);
                suffix = sub.substr(j);
                if (purPrefix == suffix) {
                    found = true;
                    lsp.push_back(purPrefix.size());
                    break;
                }
            }
            if (!found) {
                lsp.push_back(0);
            }
        }
        
        return lsp;
    }

    vector<int> computeLPSArray(string pat) {
        int n = pat.size();
        int i = 1, len = 0;
        vector<int> lps{0};

        while (i < n) {
            if (pat[i] == pat[len]) {
                lps.push_back(len+1);
                len++;
                i++;
            } else {
                if (len == 0) {
                    lps.push_back(0);
                    i++;
                } else {
                    len = lps[len-1];
                }
            }
        }

        return lps;
    }

    public: 
    // find the index of pat in txt
    vector<int> find(string txt, string pat) {
        int N=txt.size();
        int M=pat.size();
        vector<int> result;
    
        vector<int> lps = computeLPSArray(pat);
    
        int i=0,j=0;
        while(i<N){
            if(pat[j]==txt[i]){i++;j++;}

            if (j == M) { 
                // printf("Found pattern at index %d ", i - j);
                result.push_back(i-j);
                j = lps[j - 1]; 
            } 
            else if (i < N && pat[j] != txt[i]) { 
                if (j == 0) 
                    i++;
                else
                    j = lps[j - 1];  
            }
        }
        return result;
    }
};