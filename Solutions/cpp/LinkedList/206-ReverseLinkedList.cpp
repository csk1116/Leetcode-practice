#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}    
};

ListNode* createLinkedList(vector<int>& vec)
{
    if(vec.empty())
        return nullptr;

    ListNode* head = new ListNode(vec[0]);
    ListNode* current = head;
    for(int i = 1; i < vec.size(); i ++)
    {
        current->next = new ListNode(vec[i]);
        current = current->next;
    }
    return head;
}

void printLinkedList(ListNode* head)
{
    if(!head)
    {
        cout << "empty !" << endl;
        return;
    }        

    cout << "[ ";
    while(head)
    {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "nullptr ]" << endl;
}

//Iterative
// Time:O(N)
// Space:O(1)
class Solution1
{
public:
    ListNode* reverseList(ListNode* head)
    {
        if(!head || !(head->next))
            return head;

        ListNode* current = head;
        ListNode* previous = nullptr;

        while(current)
        {
            ListNode* preceding = current->next;
            current->next = previous;
            previous = current;
            current = preceding;
        }

        return previous;
    }
};

//Recursive
// Time:O(N)
// Space:O(N)
class Solution2
{
public:
    ListNode* reverseList(ListNode* head)
    {        
        if(!head || !(head->next))
            return head;

        ListNode* node = reverseList(head->next);
        head->next->next = head; // 1->2, 1->next->next = 1: 1->next = 2, 1->next->next = 2->next => 2->next = 1
        head->next = nullptr;
        return node;
    }
};

int main()
{

    Solution1 solution1;
    Solution2 solution2;

    vector<int> testVec1 = {};
    vector<int> testVec2 = {1};
    vector<int> testVec3 = {1, 2, 3, 4, 5, 6};

    ListNode* sol1Test1 = createLinkedList(testVec1);
    ListNode* sol1Test2 = createLinkedList(testVec2);
    ListNode* sol1Test3 = createLinkedList(testVec3);

    //sol 1
    
    cout << "origin: ";
    printLinkedList(sol1Test1);
    ListNode* sol1Result1 = solution1.reverseList(sol1Test1);
    cout << "reversed: ";
    printLinkedList(sol1Result1);
    
    cout << "origin: ";
    printLinkedList(sol1Test2);
    ListNode* sol1Result2 = solution1.reverseList(sol1Test2);
    cout << "reversed: ";
    printLinkedList(sol1Result2);
    
    cout << "origin: ";
    printLinkedList(sol1Test3);
    ListNode* sol1Result3 = solution1.reverseList(sol1Test3);
    cout << "reversed: ";
    printLinkedList(sol1Result3);

    ListNode* sol2Test1 = createLinkedList(testVec1);
    ListNode* sol2Test2 = createLinkedList(testVec2);
    ListNode* sol2Test3 = createLinkedList(testVec3);

    //sol2
    cout << "origin: ";
    printLinkedList(sol2Test1);
    ListNode* sol2Result1 = solution2.reverseList(sol2Test1);
    cout << "reversed: ";
    printLinkedList(sol2Result1);

    cout << "origin: ";
    printLinkedList(sol2Test2);
    ListNode* sol2Result2 = solution2.reverseList(sol2Test2);
    cout << "reversed: ";
    printLinkedList(sol2Result2);

    cout << "origin: ";
    printLinkedList(sol2Test3);
    ListNode* sol2Result3 = solution2.reverseList(sol2Test3);
    cout << "reversed: ";
    printLinkedList(sol2Result3);

    return 0;
}