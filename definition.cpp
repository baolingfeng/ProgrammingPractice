#include "definition.h"

void init_stack(MyStack &s)
{
    s.top = -1;
    s.a = new int[MAX_STACK_SIZE];
}

int stack_pop(MyStack &s)
{
    if(s.top < 0)
    {
        cout<<"empty stack!!!"<<endl;
    }

    return s.a[s.top--];
}

void stack_push(MyStack &s, int value)
{
    if(s.top>=MAX_STACK_SIZE-1)
    {
        cout<<"full stack!!!"<<endl;
    }

    s.a[++s.top] = value;
}

int main(int argc, char const *argv[])
{
    MyStack s;
    init_stack(s);

    stack_push(s, 1);
    stack_push(s, 2);
    stack_push(s, 3);
    stack_push(s, 4);
    stack_push(s, 5);

    cout<<stack_pop(s)<<endl;
    cout<<stack_pop(s)<<endl;
    cout<<stack_pop(s)<<endl;
    cout<<stack_pop(s)<<endl;
    cout<<stack_pop(s)<<endl;
    return 0;
}