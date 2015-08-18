#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;


 //Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* temp = head;
        while(temp)
        {
            temp = temp->next;
            len++;
        }
        //cout<<len<<endl;

        temp = head;
        if(n == len)
        {
            head = head->next;
            delete temp;

            return head;
        }

        int i = 0;
        while(temp)
        {
            if(len - i - 1 == n)
            {            
                ListNode* tobedelte = temp->next;
                temp->next = tobedelte->next;
                delete tobedelte;
                break;
            }
            i++;
            temp = temp->next;
        }

        return head;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    head = s.removeNthFromEnd(head, 1);

    while(head) {
        cout<<head->val<<endl;
        head = head->next;
    }

    return 0;
}