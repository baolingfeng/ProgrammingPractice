#include<iostream>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* p = head;

        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val < l2->val)
            {
                p->next = l1;
                p = l1;

                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                p = l2;
                l2 = l2->next;
            }
        }

        ListNode* l = (l1 != NULL ? l1 : l2);

        while(l)
        {
            p->next = l;
            p = l;
            l = l->next;
        }

        return head->next;
    }

    
};

int main(int argc, char const *argv[])
{
    Solution s;
    ListNode* l1 = new ListNode(0);
    ListNode* l2 = new ListNode(3);
    l2->next = new ListNode(7);
    l1->next = new ListNode(4);

    ListNode* sum = s.mergeTwoLists(l1, l2);

    while(sum != NULL)
    {
        cout<<sum->val<<endl;
        sum = sum->next;
    }
    

    return 0;
}