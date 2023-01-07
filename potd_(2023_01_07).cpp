class Solution
{
public:
    Node *merge(Node *left, Node *right)
    {

        if (left == NULL)

            return right;

        if (right == NULL)

            return left;

        Node *sortedNode = new Node(-1);

        Node *startNode = sortedNode;

        while (left != NULL && right != NULL)
        {

            if (left->data <= right->data)
            {

                sortedNode->bottom = left;

                sortedNode = left;

                left = left->bottom;
            }

            else
            {

                sortedNode->bottom = right;

                sortedNode = right;

                right = right->bottom;
            }
        }

        while (left != NULL)
        {

            sortedNode->bottom = left;

            sortedNode = left;

            left = left->bottom;
        }

        while (right != NULL)
        {

            sortedNode->bottom = right;

            sortedNode = right;

            right = right->bottom;
        }

        return startNode->bottom;
    }

    Node *flatten(Node *root)

    {

        // Your code here

        if (root == NULL)

            return root;

        Node *flatNode = flatten(root->next);

        Node *temp = root->bottom;

        temp = merge(root, flatNode);

        return temp;
    }
};