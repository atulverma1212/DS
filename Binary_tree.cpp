#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

void preorder(node *head)
{
    if(head!=NULL)
    {
        cout << head->data << " ";
        preorder(head->left);
        preorder(head->right);
    }
}

void postorder(node *head)
{
    if(head!=NULL)
    {
        postorder(head->left);
        postorder(head->right);
        cout << head->data << " ";
    }
}

void inorder(node *head)
{
    if(head!=NULL)
    {
        inorder(head->left);
        cout << head->data << " ";
        inorder(head->right);
    }
}

int total_nodes(node *temp)
{
    if(temp==NULL)
        return 0;
    return total_nodes(temp->left)+total_nodes(temp->right)+1;
}

int external_nodes(node *temp)
{
    if(temp==NULL)
        return 0;
    else if(temp->left==NULL && temp->right==NULL)
        return 1;
    else
        return external_nodes(temp->left)+external_nodes(temp->right);
}

int internal_nodes(node *temp)
{
    if(temp==NULL)
        return 0;
    else if(temp->left==NULL && temp->right==NULL)
        return 0;
    else
        return internal_nodes(temp->left)+internal_nodes(temp->right)+1;
}

node *min_node(node *temp)
{
    if(temp->left==NULL)
        return temp;
    min_node(temp->left);
}

node* delete_node(node *temp,int n)
{
    if(temp==NULL) return temp;
    if(n<temp->data)
        temp->left = delete_node(temp->left,n);
    else if(n>temp->data)
        temp->right = delete_node(temp->right,n);
    else
    {
        if(temp->left==NULL)
        {
            node *r = temp->right;
            free(temp);
            return r;
        }
        else if(temp->right==NULL)
        {
            node *r = temp->left;
            free(temp);
            return r;
        }
        else
        {
            node *r = min_node(temp->right);
            temp->data = r->data;
            temp->right = delete_node(temp->right,r->data);
        }
    }
    return temp;
}

int Height(node *temp)
{
    int lheight,rheight;
    if(temp==NULL)
        return 0;
    lheight = Height(temp->left);
    rheight = Height(temp->right);
    if(lheight>rheight)
        return lheight+1;
    else
        return rheight+1;
}

void mirror_image(node *tree)
{
    node *r;
    if(tree!=NULL)
    {
        mirror_image(tree->left);
        mirror_image(tree->right);
        r = tree->left;
        tree->left = tree->right;
        tree->right=r;
    }
}



class Tree
{
    node *tree;
public:
    Tree() { tree = NULL; }
    node *create(int d)
    {
        node *temp = new node;
        temp->data = d;
        temp->left = temp->right = NULL;
        return temp;
    }
    void insert(int d)
    {
        node *newnode = create(d);
        node *temp = tree;
        node *parent = NULL;
        if(tree==NULL)
            tree=newnode;
        else
        {
            while(temp!=NULL)
            {
                parent = temp;
                if(d < temp->data)
                    temp=temp->left;
                else
                    temp=temp->right;
            }
            if(d < parent->data)
                parent->left = newnode;
            else
                parent->right = newnode;
        }
    }
    int smallest_element()
    {
        node *temp = tree;
        while(temp->left!=NULL)
            temp=temp->left;
        return temp->data;
    }
    int largest_element()
    {
        node *temp = tree;
        while(temp->right!=NULL)
            temp=temp->right;
        return temp->data;
    }
    void preorder_traversal()
    {
        preorder(tree);
        cout << endl;
    }
    void postorder_traversal()
    {
        postorder(tree);
        cout << endl;
    }
    void inorder_traversal()
    {
        inorder(tree);
        cout << endl;
    }
    node *get() { return tree; }
    void delete_element(int n)
    {
        tree = delete_node(tree,n);
    }
};

int main()
{
    Tree arr;
    int n=1,j,i;
    while(n!=-1)
    {
        cout << "1. Insert Elements \n2. Delete Element \n3. Preorder Traversal \n4. Postorder Traversal \n5. Inorder Traversal \n6. Mirror Image \n7. Number of Nodes \n8. Number of External Nodes \n9. Number of Internal Nodes \n10. Height of tree \n>>Enter a choice: ";
        cin >> n;
        switch(n)
        {
        case 1:
            cin >> i;
            for(int k=0;k<i;k++)
            {
                cin >> j;
                arr.insert(j);
            }
            break;
        case 2:
            cin >> j;
            arr.delete_element(j);
            break;
        case 3:
            cout << "Pre order Traversal: ";
            arr.preorder_traversal();
            break;
        case 4:
            cout << "Post order Traversal: ";
            arr.postorder_traversal();
            break;
        case 5:
            cout << "In order Traversal: ";
            arr.inorder_traversal();
            break;
        case 6:
            mirror_image(arr.get());
            arr.preorder_traversal();
            break;
        case 7:
            cout << "Number of nodes: " << total_nodes(arr.get()) << endl;
            break;
        case 8:
            cout << "Number of external nodes: " << external_nodes(arr.get()) << endl;
            break;
        case 9:
            cout << "Number of internal nodes: " << internal_nodes(arr.get()) << endl;
            break;
        case 10:
            cout << "Height of tree: " << Height(arr.get()) << endl;
            break;
        }
    }

}
