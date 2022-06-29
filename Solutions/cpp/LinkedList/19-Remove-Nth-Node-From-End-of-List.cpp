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

ListNode *createLinkedList(vector<int> &vec)
{
    if (vec.empty())
        return nullptr;

    ListNode *head = new ListNode(vec[0]);
    ListNode *current = head;
    for (int i = 1; i < vec.size(); i++)
    {
        current->next = new ListNode(vec[i]);
        current = current->next;
    }
    return head;
}

void printLinkedList(ListNode *head)
{
    if (!head)
    {
        cout << "empty !" << endl;
        return;
    }

    cout << "[ ";
    while (head)
    {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "nullptr ]" << endl;
}

// one pointer: two pass
// Time:O(N)
// Space:O(1)
class Solution1
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode* iter1 = head;
        int length = 0;
        while(iter1)
        {
            iter1 = iter1->next;
            length ++;
        }

        if(length == n) //means delete head
        {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        int previousToRemove = length - n - 1;
        ListNode* iter2 = head;
        for(int i = 0; i < previousToRemove; i++)
        {
            iter2 = iter2->next;
        }
        ListNode* removeNode = iter2->next;
        iter2->next = iter2->next->next;
        delete removeNode;

        return head;
    }
};

// slow-fast pointer: one pass
// Time:O(N)
// Space:O(1)
class Solution2
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *fast = head;
        ListNode *slow = head;

        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }

        if (!fast) //means delete head
        {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        } 
            

        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode *removeNode = slow->next;
        slow->next = slow->next->next;
        delete removeNode;

        return head;
    }
};

int main()
{

    vector<int> testVec1 = {1};
    vector<int> testVec2 = {1, 2, 3, 4, 5, 6}; //n = 1, 6, 3

    Solution1 solution1;
    Solution2 solution2;

    //sol1
    ListNode* sol1Test1 = createLinkedList(testVec1); //n = 1
    ListNode* sol1Test2 = createLinkedList(testVec2); //n = 1
    ListNode* sol1Test3 = createLinkedList(testVec2); //n = 6
    ListNode* sol1Test4 = createLinkedList(testVec2); //n = 3

    cout << "before:" << endl;
    printLinkedList(sol1Test1);
    ListNode* sol1Result1 = solution1.removeNthFromEnd(sol1Test1, 1); //empty
    cout << "removed:" <<endl;
    printLinkedList(sol1Result1);

    cout << "before:" << endl;
    printLinkedList(sol1Test2);
    ListNode* sol1Result2 = solution1.removeNthFromEnd(sol1Test2, 1); //1,2,3,4,5
    cout << "removed:" <<endl;
    printLinkedList(sol1Result2);

    cout << "before:" << endl;
    printLinkedList(sol1Test3);
    ListNode* sol1Result3 = solution1.removeNthFromEnd(sol1Test3, 6); //2,3,4,5
    cout << "removed:" <<endl;
    printLinkedList(sol1Result3);

    cout << "before:" << endl;
    printLinkedList(sol1Test4);
    ListNode* sol1Result4 = solution1.removeNthFromEnd(sol1Test4, 3); //1,2,3,5,6
    cout << "removed:" <<endl;
    printLinkedList(sol1Result4);



    //sol2
    ListNode* sol2Test1 = createLinkedList(testVec1); //n = 1
    ListNode* sol2Test2 = createLinkedList(testVec2); //n = 1
    ListNode* sol2Test3 = createLinkedList(testVec2); //n = 6
    ListNode* sol2Test4 = createLinkedList(testVec2); //n = 3

    cout << "before:" << endl;
    printLinkedList(sol2Test1);
    ListNode* sol2Result1 = solution2.removeNthFromEnd(sol2Test1, 1); //empty
    cout << "removed:" <<endl;
    printLinkedList(sol2Result1);

    cout << "before:" << endl;
    printLinkedList(sol2Test2);
    ListNode* sol2Result2 = solution2.removeNthFromEnd(sol2Test2, 1); //1,2,3,4,5
    cout << "removed:" <<endl;
    printLinkedList(sol2Result2);

    cout << "before:" << endl;
    printLinkedList(sol2Test3);
    ListNode* sol2Result3 = solution2.removeNthFromEnd(sol2Test3, 6); //2,3,4,5
    cout << "removed:" <<endl;
    printLinkedList(sol2Result3);

    cout << "before:" << endl;
    printLinkedList(sol2Test4);
    ListNode* sol2Result4 = solution2.removeNthFromEnd(sol2Test4, 3); //1,2,3,5,6
    cout << "removed:" <<endl;
    printLinkedList(sol2Result4);

    return 0;
}