#include<iostream>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
        {
            return head;
        } 
        else
        {
            int temp = head->val;
            head->val = head->next->val;
            head->next->val = temp;
        }
        
        ListNode* p = swapPairs(head->next->next);

        head->next->next = p;

        return head;
    }

   
};

int main(int argc, char const *argv[])
{
    Solution s;
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);

    s.swapPairs(l1);

    while(l1) {
        cout<<l1->val<<endl;
        l1 = l1->next;
    }

    return 0;
}