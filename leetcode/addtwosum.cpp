#include<iostream>

using namespace std;


struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* p = head;
        
        int overflow = 0;
        while(l1 != NULL && l2 != NULL)
        {
            int temp = l1->val + l2->val + overflow;
            if(temp >= 10)
            {
                overflow = 1;
                temp -= 10;
            }
            else
            {
                overflow = 0;
            }
            
            p->next = new ListNode(temp);
            p = p->next;
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1 != NULL)
        {
            int temp = l1->val + overflow;
            if(temp >= 10)
            {
                overflow = 1;
                temp -= 10;
            }
            else
            {
                overflow = 0;
            }

            p->next = new ListNode(temp);
            p = p->next;
            
            l1 = l1->next;
        }
        
        while(l2 != NULL)
        {
            int temp = l2->val + overflow;
            if(temp >= 10)
            {
                overflow = 1;
                temp -= 10;
            }
            else
            {
                overflow = 0;
            }

            p->next = new ListNode(temp);
            p = p->next;
            
            l2 = l2->next;
        }

        if(overflow)
        {
            p->next = new ListNode(overflow);
        }
        
        return head->next;
    }
};

int main()
{
    Solution s;
    ListNode* l1 = new ListNode(0);
    ListNode* l2 = new ListNode(7);
    l2->next = new ListNode(3);

    ListNode* sum = s.addTwoNumbers(l1, l2);

    while(sum != NULL)
    {
        cout<<sum->val<<endl;
        sum = sum->next;
    }
    

    return 0;
}