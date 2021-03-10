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
    ListNode* middleNode(ListNode* head) {
        ListNode* x=head;
        int size=0;
        while(x!=NULL)
        {
            size++;
            x=x->next;
        }
        int k=-1;
        x=head;
        while(x!=NULL)
        {
            k++;
            if(k==size/2)
                return x;
            x=x->next;
        }
        return NULL;
    }
};