## 题目描述

给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

**示例:**

>输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)  
输出：7 -> 0 -> 8  
原因：342 + 465 = 807  

链接：https://leetcode-cn.com/problems/add-two-numbers/  


## 直接法

```C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
                    
        ListNode* l1_currentNode = l1;
        ListNode* l2_currentNode = l2;        
        ListNode* out_currentNode = new ListNode(0);        
        ListNode* outHead = out_currentNode;
        
        int l1_currentValue;
        int l2_currentValue;    
        
        int carry = 0;   

        //其中一个为空 
        //l1 l2 若有为空的，则直接跳过while 返回空列表
        //否则一直执行到l1 l2当前节点均到达列表末尾
        while(l1_currentNode!=NULL || l2_currentNode!=NULL){

            //l1和l2可能一长一短，短的到达末尾后面值记为0
            l1_currentValue = (l1_currentNode == NULL) ? 0 : l1_currentNode->val;            
            l2_currentValue = (l2_currentNode == NULL) ? 0 : l2_currentNode->val;

            int currentSum = l1_currentValue + l2_currentValue + carry;
            
            out_currentNode->next = new ListNode(currentSum%10);
            out_currentNode = out_currentNode->next;
            carry = currentSum/10;
            
            if(l1_currentNode != NULL) l1_currentNode = l1_currentNode->next;
            if(l2_currentNode != NULL) l2_currentNode = l2_currentNode->next;  

        }
        //加和到最后若还有进位 则追加到结果列表末尾
        if(carry!=0){
            out_currentNode->next = new ListNode(carry);
        }

        return outHead->next;
    }
};
```

> 注：需要特别注意的几种情况：
> > l1和l2一长一短
> > 其中一个为空 
> > 加和最后还有进位
>
> 收获: 通过创建哑节点`ListNode* out_currentNode = new ListNode(0);`可以避免许多判断操作（输出列表是否为空）。

### 复杂度分析：

时间复杂度：

空间复杂度：

### 结果：

|运行时间|内存消耗|
| --- | --- |
| 36 ms| 9.5 MB|
|在所有 C++ 提交中击败了56.69%的用户|在所有 C++ 提交中击败了100.00%的用户|
