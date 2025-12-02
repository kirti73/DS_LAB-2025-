#include  <stdio.h>
#include <stdlib.h>
typedef struct {
    int data;
    struct node *left;
    struct node *right;}node;
node *create (int value)
{   node * new;
    new=(node *)malloc(sizeof(node *));
    new->data=value;
    new->left=NULL;
    new->right=NULL;
    return new;
}
void insert(node *root,node *temp)
{
    if(temp->data<root->data)
    {
        if(root->left!=NULL)
            insert(root->left,temp);
        else{
            root->left=temp;
        }
    }
    if(temp->data>=root->data)
    {
        if(root->right!=NULL)
            insert(root->right,temp);
        else{
            root->right=temp;
        }
    }
}
void inorder(node *root)
{

    if(root!=NULL)
    {

        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void preorder(node *root)
{

    if(root!=NULL)
    {

        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    node *root=NULL;
    int c, v, p;
    do {
        printf("\n1.insert\n2.inorder\n3. preorder\n4. exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &c);

        switch (c) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &v);
                node * new;
                new=(node *)malloc(sizeof(node *));
                new=create(v);
                if (root==NULL)
                    root=new;
                else
                    insert(root,new);
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                preorder(root);
                break;

        }
    } while (c != 4);

    return 0;
}

