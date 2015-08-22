#include<iostream>

using namespace std;


struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* lastNode;
        //ListNode* kNode;
        ListNode* nkNode;

        if(head == NULL) return head;
        
        ListNode* p = head;
        int len = 0;

        while(p != NULL)
        {
            len++;
           
            if(p->next == NULL)
            {
                lastNode = p;
            }
            p = p->next;
        }

        if(k >= len)
        {
            k = k % len;
        }
        if(k == 0) return head;

        int i = 0;
        p = head;
        while(p != NULL)
        {
            
            if(len-i-1 == k)
            {
                nkNode = p;
            }
            i++;

            p = p->next;
        }

        lastNode->next = head;
        //kNode->next = NULL;
        p = nkNode->next;
        nkNode->next = NULL;

        return p;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    head = s.rotateRight(head, 4);

    while(head) {
        cout<<head->val<<endl;
        head = head->next;
    }
    return 0;
}