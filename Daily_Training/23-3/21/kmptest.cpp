#include <iostream>
#include <string>
#include <vector>
#include <chrono>
using namespace std;
// 暴力匹配算法
int BFMatcher(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();
    for(int i = 0; i <= n - m; i++) {
        int j = 0;
        for(; j < m; j++) {
            if(text[i + j] != pattern[j]) break;
        }
        if(j == m) return i;
    }
    return -1;
}
// KMP算法
int KMPMatcher(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> next(m, 0);
    for(int i = 1, j = 0; i < m; i++) {
        while(j > 0 && pattern[i] != pattern[j]) j = next[j - 1];
        if(pattern[i] == pattern[j]) j++;
        next[i] = j;
    }
    for(int i = 0, j = 0; i < n; i++) {
        while(j > 0 && text[i] != pattern[j]) j = next[j - 1];
        if(text[i] == pattern[j]) j++;
        if(j == m) return i - m + 1;
    }
    return -1;
}
int main() {
    string text = "ababcabcacbab";
    string pattern = "abcac";
    auto start = chrono::steady_clock::now();
    int index1 = BFMatcher(text, pattern);
    auto end = chrono::steady_clock::now();
    auto diff1 = end - start;
    cout << "BF " << chrono::duration <double, milli> (diff1).count() << " ms" << endl;
    start = chrono::steady_clock::now();
    int index2 = KMPMatcher(text, pattern);
    end = chrono::steady_clock::now();
    auto diff2 = end - start;
    cout << "KMP " << chrono::duration <double, milli> (diff2).count() << " ms" << endl;
    if(index1 == index2) {
        cout << " " << index1 << endl;
    } else {
        cout << " " << endl;
    }
    return 0;
}