/**
 *  * Definition for singly-linked list.
 *   * struct ListNode {
 *    *     int val;
 *     *     ListNode *next;
 *      *     ListNode(int x) : val(x), next(NULL) {}
 *       * };
 *        */
class Solution {
public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            int ex,tag=0;
            ListNode *p1 = l1;
            ListNode *p2 = l2;
            ListNode *tp1,*tp2;
            while(p1!=nullptr && p2!=nullptr)
            {
                ex = p1->val+p2->val+tag;
                if(ex>9)
                {
                    p1->val = ex%10;
                    tag = ex/10;
                }
                else
                {
                    p1->val = ex;
                    tag = 0;
                }
                tp1 = p1;
                tp2 = p2;
                p1 = p1->next;
                p2 = p2->next;
            }
            while(p1!=nullptr)
            {
                ex = p1->val + tag;
                if(ex>9)
                {
                    p1->val = ex%10;
                    tag = ex/10;
                }
                else
                {
                    p1->val = ex;
                    tag = 0;
                }
                tp1 = p1;
                p1 = p1->next;
            }
            if(p1==nullptr && p2==nullptr && tag!=0)
            {
                ListNode *tmp = new ListNode(tag);
                tp1->next = tmp;
                tag = 0;
            }
            if(p2!=nullptr)
                tp1->next = p2;
            while(p2!=nullptr)
            {
                ex = p2->val + tag;
                if(ex>9)
                {
                    p2->val = ex%10;
                    tag = ex/10;
                }
                else
                {
                    p2->val = ex;
                    tag = 0;
                }
                tp2 = p2;
                p2 = p2->next;
            }
            if(p1==nullptr && p2==nullptr && tag!=0)
            {
                ListNode *tmp = new ListNode(tag);
                tp2->next = tmp;
            }

            return l1;
        }
};
