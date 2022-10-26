#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here

int helper(Node * root)
{
    int temp;
    if(root->left == NULL && root ->right == NULL)
    {
        return 1;
    }
    else if(root->left == NULL)
    {
        temp = helper(root->right);
        if(temp == -1)
            return -1;
        else
            return 1 + temp;
    }
    else if(root->right == NULL)
    {
        temp = helper(root->left);
        if(temp == -1)
            return -1;
        else
            return 1 + temp;
    }
    else        //left and right exist
    {
        int temp = helper(root->left);
        if(temp == helper(root->right))
        {
            return 1 + temp;
        }
        else
        {
            return -1;
        }
    }
}

bool equalPaths(Node * root)
{
    if(root == NULL)
    {
        return true;
    }
    else if(root->left == NULL && root->right == NULL)
    {
        return true;
    }
    else if(root->left == NULL)
    {
        if(helper(root->right) == -1)
            return false;
        else
            return true;
    }
    else if(root->right == NULL)
    {
        if(helper(root->left) == -1)
            return false;
        else
            return true;
    }
    else
    {
        int left = helper(root->left);
        int right = helper(root->right);
        if((left != right) || left == -1 || right == -1)
        {
            return false;
        }
        else
            return true;
    }

}

