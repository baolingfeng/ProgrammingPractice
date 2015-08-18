#include "definition.h"

void print_linklink(PtrLNode p)
{
    while(p != NULL)
    {
        cout<<p->value<<" ";
        p = p->next;
    }
    cout<<endl;
}

PtrLNode reverse_link_recur(PtrLNode head)
{
    if(head == NULL) return NULL;
    if(head->next == NULL) return head;

    PtrLNode p = reverse_link_recur(head->next);
    head->next->next = head;
    head->next = NULL;

    return p;
}

PtrLNode reverse_link(PtrLNode head)
{
    PtrLNode previous = NULL;
    PtrLNode p = head;
    PtrLNode next; 

    while(p != NULL)
    {
        next = p->next;
        p->next = previous;
        previous = p;
        p = next;
    }
    return previous;
}

int main()
{
    PtrLNode head = new LNode; head->value = 1; 
    PtrLNode p1 = new LNode; p1->value = 2;
    PtrLNode p2 = new LNode; p2->value = 3;
    PtrLNode p3 = new LNode; p3->value = 4;
    PtrLNode p4 = new LNode; p4->value = 5;

    head->next = p1; p1->next = p2; p2->next = p3; p3->next = p4; p4->next = NULL;

    PtrLNode revserse = reverse_link(head);
    print_linklink(revserse);
    return 0;
}