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
        stack<int> st1,st2;
        int sum=0;
        ListNode* p=NULL;
        ListNode* x;
        while(l1){
            st1.push(l1->val);
            l1=l1->next;
        }
        while(l2){
            st2.push(l2->val);
            l2=l2->next;
        }
        while(!st1.empty()||!st2.empty()){
            if(!st1.empty()){
                sum+=st1.top();
                st1.pop();
            }
            if(!st2.empty()){
                sum+=st2.top();
                st2.pop();
            }
            x=new ListNode(sum%10);
            x->next=p;//头插法
            p=x;
            sum/=10;
        }
        if(sum!=0){
            x=new ListNode(sum%10);
            x->next=p;
            p=x;
        }
        return p;
    }
};
