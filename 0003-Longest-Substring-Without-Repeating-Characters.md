## 题目描述

Given a string, find the length of the longest substring without repeating characters.

### 示例

> **Example 1:**
> > Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
>
> **Example 2:**
>>Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
>
>**Example 3:**
>>Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/

### 思考

#### 想法I： 字符串(可行)

> 1. 遍历字符串s，新建字符串s1，若s[i]在s1中不存在，把字符s[i]依次放到s1中
> 2. 若s[i]在s1中已存在（s1[j]），则s1保留s1[j]后面的字符，再把s[i]依次放到s1末尾
> 3. 更新最长列表值
> 4. 遍历结束后，返回最长列表值

#### 想法II：类似哈希表 （不可行）

（单纯解题，只能求出最长子串长度，不知道是哪个子串）
> 最长子串长度out，当前子串长度temp。初始均为0。
>
> 1. 建立一个数组，所有元素一次对应所有ASCII字符
> 2. 遍历字符串，对于当前字符，若在数组对应位置元素为0，则置为1，表示已有这个字母，并将temp++
> 3. 若在数组对应位置元素为1，则令out=max[out,temp], temp=0，数组元素除当前字符外全部置0，temp=1
> 4. 重复2和3知道遍历结束

问题：步骤3的操作会丢失掉重复字符之间字符的计数。
对于简单测试用例：abcbb，可以通过
但是对于测试用例：asjvgapa 这种，遍历到第二个a，out=5。而实际上最长子串是 sjvgap， out=6。

## Solution

### 字符串法

```C++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int outLen = 0;
        string s1 = "";

        for(int i=0; i<s.length(); i++){
            const char c = s[i];
            int j = s1.find(c);
            if( j >= 0){
                s1 = s1.substr(j+1);
            }
            //注意s[i]返回值是到请求字符的引用。append参数要的是指针
            s1.append(&c,1);
            outLen = max(outLen , (int)s1.size());
        }
        return outLen;
    }
};
```

> 注：
> 对于`s1.append(&s[i],1);`, `string::append(const char *__s, std::size_t __n)`第一个参数为指针，而s[i]为引用，故需用`&s[i]`传入地址；第二个参数不要省略，否则会乱码。

#### 复杂度分析

时间复杂度：O(N)，其中 N 是字符串的长度。遍历字符串一次。
            另外`int j = s1.find(c);`会花费一些时间。用boyer_moore_searcher应该会快一些， 见下面代码（输处错误，待验证）
空间复杂度：O(k)，其中k=min(m,n)是子串s1的长度。m是字符集的元素个数，n是字符串s的长度。
            **值得注意的是**，`s1 = s1.substr(j+1);`操作会产生临时变量，占用内存空间，改成`s1.erase(0,j+1);`会好很多（见下面结果）。

#### 结果

`s1 = s1.substr(j+1);`
|运行时间|内存消耗|
| :----: | :----: |
| 36 ms| 20.8 MB|
|在所有 C++ 提交中击败了 59.65 % 的用户|在所有 C++ 提交中击败了 7.48 % 的用户|

`s1.erase(0,j+1);`
|运行时间|内存消耗|
| :----: | :----: |
| 20 ms | 6.9 MB|
|在所有 C++ 提交中击败了 77.67 % 的用户|在所有 C++ 提交中击败了 90.55 % 的用户|

```C++
#include <bits/stdc++.h>
#include <functional>
using namespace std;
// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int outLen = 0;
        string s1 = "";

        for(int i=0; i<s.length(); ++i){           
            
            string c = s.substr(i,i);
            auto it = search(s1.begin(), s1.end(),
                            boyer_moore_searcher(c.begin(), c.end()));
            if(it != s1.end())
                s1 = s1.substr(it-s1.begin()+1); 
            //注意s[i]返回值是到请求字符的引用。append参数要的是指针
            s1.append(c); 
            outLen = max(outLen , (int)s1.size());      
        }
        return outLen;
    }
};
```

### 官网方法 优化的滑动窗口

```Java
//Java代码
public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length(), ans = 0;
        Map<Character, Integer> map = new HashMap<>(); // current index of character
        // try to extend the range [i, j]
        for (int j = 0, i = 0; j < n; j++) {
            if (map.containsKey(s.charAt(j))) {
                i = Math.max(map.get(s.charAt(j)), i);
            }
            ans = Math.max(ans, j - i + 1);
            map.put(s.charAt(j), j + 1);
        }
        return ans;
    }
}
```

> 注：
> 和我的方法本质是一样的，我的代码中s1即充当了滑动窗口的作用，这里的滑动窗口是map。
