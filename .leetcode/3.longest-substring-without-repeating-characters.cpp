/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
#define INPUT "test_case.txt" // single-input
#define OUTPUT cout, "output.txt" // multi-output

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int outLen = 0;
        string s1 = "";

        for(int i=0; i<s.length(); i++){
            const char c = s[i];
            int j = s1.find(c);
            if( j >= 0){
                s1.erase(0,j+1);
            }
            //注意s[i]返回值是到请求字符的引用。append参数要的是指针
            s1.append(&c,1);
            outLen = max(outLen , (int)s1.size());
        }
        return outLen;
    }
};
// @lc code=end

