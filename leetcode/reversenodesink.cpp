#include<iostream>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return NULL;

        ListNode* p = head;
        int num = 0;
        while(p)
        {
            if(num >= k) break;

            p = p->next;

            num++;
        }

        if(num<k)
        {
            return head;
        }
        

        int i = 0;
        ListNode* previous = NULL;
        ListNode* current = head;
        ListNode* after;
        while(i<num && current != p)
        {
            after = current->next;
            current->next = previous;
            previous = current;
            current = after;

            i++;
        }
        
       // cout<<previous->val<<endl;
        //cout<<head->val<<endl;

        head->next = reverseKGroup(p, k);

       

        return previous;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    //l1->next->next = new ListNode(3);
    //l1->next->next->next = new ListNode(4);

    ListNode* l2 = s.reverseKGroup(l1, 3);

    while(l2) {
        cout<<l2->val<<endl;
        l2 = l2->next;
    }

    return 0;
}