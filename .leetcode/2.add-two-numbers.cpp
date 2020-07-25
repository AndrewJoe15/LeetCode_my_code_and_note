/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
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
// @lc code=end

