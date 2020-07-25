/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
#include <bits/stdc++.h>
using namespace std;
#define INPUT "test_case.txt" // single-input
#define OUTPUT cout, "output.txt" // multi-output
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        /*
        vector<int> out;
        for(int i = 0; i<nums.size(); i++){
            for(int j = i+1; j<nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    out.push_back(i);
                    out.push_back(j);
                    return out;
                }
            }
        }
        return out;*/

        //哈希表 一次遍历
        unordered_map<int,int> hash;
        vector<int> out;

        for(int i = 0; i<nums.size(); i++){
            if(hash[target - nums[i]]){
                out.push_back(hash[ target - nums[i] ]-1);
                out.push_back(i);
                return out;
            }
            hash[nums[i]] = i+1;            
        }        
        return out;
    }
};
// @lc code=end

