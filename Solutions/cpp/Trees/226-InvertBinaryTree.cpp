#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* createTree(vector<int>& vec)
{
    TreeNode* root = new TreeNode(0);
    return root;
}

void printTree(TreeNode* root)
{

}

//
// Time:O()
// Space:O()
class Solution1
{
public:
};

//
// Time:O()
// Space:O()
class Solution2
{
public:
};

int main()
{

    Solution1 solution1;
    Solution2 solution2;

    return 0;
}