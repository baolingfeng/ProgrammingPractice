#include "definition.h"
#include <stack>
#include <queue>

typedef struct _NextTreeNode
{
    int value;
    struct _NextTreeNode* left;
    struct _NextTreeNode* right;
    struct _NextTreeNode* next;
}NextTreeNode, *PtrNextTreeNode;


PtrTreeNode contruct_tree(int a[], int l, int r)
{
    if(r <= l)
    {
        return NULL;
    }

    int middle = (l + r) / 2;
    PtrTreeNode node = new TreeNode;
    node->value = a[middle];
    
    PtrTreeNode left = contruct_tree(a, l, middle);
    PtrTreeNode right = contruct_tree(a, middle+1, r);

    node->left = left;
    node->right = right;

    return node;
}

PtrNextTreeNode contruct_next_tree(int a[], int l, int r)
{
    if(r <= l)
    {
        return NULL;
    }

    int middle = (l + r) / 2;
    PtrNextTreeNode node = new NextTreeNode;
    node->value = a[middle];
    
    PtrNextTreeNode left = contruct_next_tree(a, l, middle);
    PtrNextTreeNode right = contruct_next_tree(a, middle+1, r);

    node->left = left;
    node->right = right;
    node->next = NULL;

    return node;
}

int tree_height(PtrTreeNode root)
{
    if(root == NULL)
    {
        return 0;
    }

    int leftHeight = tree_height(root->left);
    int rightHeight = tree_height(root->right);

    return leftHeight>rightHeight ? leftHeight+1 : rightHeight + 1;
}

void pre_order(PtrTreeNode root)
{
    if(root == NULL)
    {
        return ;
    }

    cout<<root->value<<" ";

    pre_order(root->left);
    pre_order(root->right);
}

void mid_order(PtrTreeNode root)
{
    if(root == NULL)
    {
        return ;
    }

    mid_order(root->left);
    cout<<root->value<<" ";
    mid_order(root->right);
}

void post_order(PtrTreeNode root)
{
    if(root == NULL)
    {
        return ;
    }

    post_order(root->left);
    post_order(root->right);
    cout<<root->value<<" ";
}

void pre_order_nonre(PtrTreeNode root)
{
    stack<PtrTreeNode> s;
    s.push(root);
    while(!s.empty())
    {
        PtrTreeNode node = s.top();
        s.pop();

        cout<<node->value<<" ";

        if(node->right) s.push(node->right);
        if(node->left) s.push(node->left); 
    }
}

void mid_order_nonre(PtrTreeNode root)
{
    PtrTreeNode node = root;
    stack<PtrTreeNode> s;

    while(node!=NULL || !s.empty())
    {
        if(node != NULL)
        {
            s.push(node);
            node = node->left;
        }
        else
        {
            node = s.top();
            cout<<node->value<<" ";

            s.pop();

            node = node->right;
        }
    }
}

void post_order_nonre(PtrTreeNode root)
{
    stack<PtrTreeNode> s1;
    stack<PtrTreeNode> s2;

    s1.push(root);
    while(!s1.empty())
    {
        PtrTreeNode node = s1.top();
        s1.pop();

        s2.push(node);

        if(node->left) s1.push(node->left);
        if(node->right) s1.push(node->right);
    }

    while(!s2.empty())
    {
        cout<<s2.top()->value<<" ";
        s2.pop();
    }
}

void level_order(PtrTreeNode root)
{
    queue<PtrTreeNode> q;
    q.push(root);

    while(!q.empty())
    {
        PtrTreeNode node = q.front();
        q.pop();

        cout<<node->value<<endl;

        if(node->left) q.push(node->left); 
        if(node->right) q.push(node->right);
    }
}

void add_next_tree(PtrNextTreeNode root)
{
    queue<PtrNextTreeNode> q;
    q.push(root);

    while(!q.empty())
    {
        vector<PtrNextTreeNode> list;
        while(!q.empty())
        {
            PtrNextTreeNode node = q.front();
            q.pop();

            list.push_back(node);
        }

        for(int i=0; i<list.size(); i++)
        {
            PtrNextTreeNode node = list[i];
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);

            if(i<list.size()-1)
            {
                node->next = list[i+1];
            }
            else
            {
                node->next = NULL;
            }
        }    
    }
}

void print_next_tree(PtrNextTreeNode root)
{
    PtrNextTreeNode node = root;
    while(node!=NULL)
    {
        PtrNextTreeNode node2 = node;
        while(node2 != NULL)
        {
            cout<<node2->value<<" ";
            node2 = node2->next;
        }
        cout<<endl;
        node = node->left;
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len = sizeof(a) / sizeof(int);

    PtrNextTreeNode root = contruct_next_tree(a, 0, len);
    add_next_tree(root);
    print_next_tree(root);
    //PtrTreeNode root = contruct_tree(a, 0, len);
    //cout<<"height: "<<tree_height(root)<<endl;

    //post_order_nonre(root);
    //cout<<endl;
    //post_order(root);
    return 0;
}