
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node *NODE;

// Function to create BST
NODE create_bst(NODE root, int item)
{
    NODE temp, prev, cur;

    temp = (NODE)malloc(sizeof(struct node));

    if (temp == NULL)
    {
        printf("Memory allocation failed!");
        exit(1);
    }

    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;

    if (root == NULL)
        return temp;

    prev = NULL;
    cur = root;

    while (cur != NULL)
    {
        prev = cur;

        if (item < cur->data)
            cur = cur->left;
        else
            cur = cur->right;
    }

    if (item < prev->data)
        prev->left = temp;
    else
        prev->right = temp;

    return root;
}

// Preorder traversal
void preorder(NODE root)
{
    if (root != NULL)
    {
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder traversal
void inorder(NODE root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

// Postorder traversal
void postorder(NODE root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}

// Main function
int main()
{
    NODE root = NULL;
    int ch, item;

    for (;;)
    {
        printf("\n1. Insert");
        printf("\n2. Preorder");
        printf("\n3. Inorder");
        printf("\n4. Postorder");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("\nEnter element to be inserted: ");
                scanf("%d", &item);
                root = create_bst(root, item);
                break;

            case 2:
                printf("\nPreorder traversal is:\n");
                preorder(root);
                printf("\n");
                break;

            case 3:
                printf("\nInorder traversal is:\n");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("\nPostorder traversal is:\n");
                postorder(root);
                printf("\n");
                break;

            case 5:
                exit(0);

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}

