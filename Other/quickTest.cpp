#include <iostream>
using namespace std;

int findSum(TreeNode * root, int depth)
{
    if(root != NULL)
    {
        int rightSum = findSum(root->right, depth + 1);
        int leftSum = findSum(root->left, depth + 1);
        cout << root->key;
        if (depth != 0)
        {
            cout << " ";
        }
        return rightSum + leftSum + root->key;
    }
    else
       return 0;
}

int main()
{
	cout << "Hello World" << endl;

}