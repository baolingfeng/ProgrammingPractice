#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
        {
            return NULL;
        }
        else if(lists.size() == 1)
        {
            return lists[0];
        }
        
        vector<ListNode*>::iterator it = lists.begin() + lists.size() / 2;
        vector<ListNode*> list1(lists.begin(), it);
        vector<ListNode*> list2(it, lists.end());
        
        ListNode* l1 = mergeKLists(list1);
        ListNode* l2 = mergeKLists(list2);

        return mergeTwoLists(l1, l2);
    }

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
    /* code */
    return 0;
}