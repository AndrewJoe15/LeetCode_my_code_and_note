## 题目描述

给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。 

**示例:**

> 给定 nums = [2, 7, 11, 15], target = 9
>
> 因为 nums[0] + nums[1] = 2 + 7 = 9  
> 所以返回 [0, 1]

链接：https://leetcode-cn.com/problems/two-sum

## 暴力法

```C++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
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
        return out;
    }
};
```

> 注：if的判断中`hash[ target - nums[j] ]`没有机会为0，因为总是从nums的第0个元素开始判断，如果后面有符合条件的，那在j=0时就返回结果了。因此在用map给元素编号时没必要从1开始，

### 复杂度分析：

时间复杂度：O(n)，
我们把包含有 n 个元素的列表遍历两次。由于哈希表将查找时间缩短到 O(1) ，所以时间复杂度为 O(n)。

空间复杂度：O(n)，
所需的额外空间取决于哈希表中存储的元素数量，该表中存储了 n 个元素。

### 结果：

|运行时间|内存消耗|
| --- | --- |
|16 ms|9.1 MB|

## 哈希表 一次遍历

```C++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
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
```

> 注：if的判断中`hash[ target - nums[j] ]`有可能为0，是因为if()中判断的是数组nums中i之前的元素是否有元素target - nums[i]已在map中。故而与上个方法不同，这里编号从1开始(i+1)。

### 复杂度分析：

时间复杂度：O(n)，
我们只遍历了包含有 n 个元素的列表一次。在表中进行的每次查找只花费 O(1) 的时间。

空间复杂度：O(n)，
所需的额外空间取决于哈希表中存储的元素数量，该表最多需要存储 n 个元素。

### 结果：

|运行时间|内存消耗|
| --- | --- |
|12 ms|8.9 MB|