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

//2 pointer + extra space
//Time:O(N)
//Space:O(N)
class Solution1
{
public:
    void reorderList(ListNode* head)
    {
        if(!head || !head->next)
            return;

        vector<ListNode*> vec;
        while(head)
        {
            vec.push_back(head);
            head = head->next;
        }

        int left = 0;
        int right = vec.size() - 1;        
        ListNode* newHead = vec[left];        

        while(left < right)
        {            
            newHead->next = vec[right];
            newHead = newHead->next;
            left ++;
            newHead->next = vec[left];
            right --;
            newHead = newHead->next;
        }
        newHead->next = nullptr;
    }
};

//in-place
//Time:O(N)
//Space:O(1)
class Solution2
{
public:
    void reorderList(ListNode* head)
    {
        if(!head || !head->next)
            return;

        ListNode* mid = middleNode(head);     
        //reverse right half, right will be shorter than left   
        ListNode* right = reverseList(mid->next);
        //break into 2 half
        mid->next = nullptr;

        //merge
        ListNode* left = head;
        while(right)
        {
            ListNode* rightPtr = right->next;
            ListNode* leftPtr = left->next;

            left->next = right;
            right->next = leftPtr;

            left = leftPtr;
            right = rightPtr;
        }
    }
private:
    ListNode* middleNode(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverseList(ListNode* head)
    {
        ListNode* previous = nullptr;
        ListNode* current = head;
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


int main()
{
    vector<int> testVec1 = {};
    vector<int> testVec2 = {1};
    vector<int> testVec3 = {1, 2, 3, 4, 5, 6};

    Solution1 solution1;
    Solution2 solution2;
    
    //sol1
    ListNode* sol1Test1 = createLinkedList(testVec1);
    ListNode* sol1Test2 = createLinkedList(testVec2);
    ListNode* sol1Test3 = createLinkedList(testVec3);
    //test1
    cout << "before:" << endl;
    printLinkedList(sol1Test1);
    solution1.reorderList(sol1Test1);
    cout << "reordered:" << endl;
    printLinkedList(sol1Test1);

    //test2
    cout << "before:" << endl;
    printLinkedList(sol1Test2);
    solution1.reorderList(sol1Test2);
    cout << "reordered:" << endl;
    printLinkedList(sol1Test2);

    //test3
    cout << "before:" << endl;
    printLinkedList(sol1Test3);
    solution1.reorderList(sol1Test3);
    cout << "reordered:" << endl;
    printLinkedList(sol1Test3);

    //sol2
    ListNode* sol2Test1 = createLinkedList(testVec1);
    ListNode* sol2Test2 = createLinkedList(testVec2);
    ListNode* sol2Test3 = createLinkedList(testVec3);
    //test1
    cout << "before:" << endl;
    printLinkedList(sol2Test1);
    solution2.reorderList(sol2Test1);
    cout << "reordered:" << endl;
    printLinkedList(sol2Test1);

    //test2
    cout << "before:" << endl;
    printLinkedList(sol2Test2);
    solution2.reorderList(sol2Test2);
    cout << "reordered:" << endl;
    printLinkedList(sol2Test2);

    //test3
    cout << "before:" << endl;
    printLinkedList(sol2Test3);
    solution2.reorderList(sol2Test3);
    cout << "reordered:" << endl;
    printLinkedList(sol2Test3);
    
    return 0;
}