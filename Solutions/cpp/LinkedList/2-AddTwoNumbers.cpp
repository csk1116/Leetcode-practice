#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

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

//iterate
//Time:O(max(M,N))
//Space:O(1)
class Solution1
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* sumHead = new ListNode(0); //dummy
        ListNode* iter = sumHead;
        int carry = 0;
        while(l1 || l2 || carry)
        {
            int tempSum = 0;
            if(l1)
            {
                tempSum += l1->val;
                l1 = l1->next;
            }
            if(l2)
            {
                tempSum += l2->val;
                l2 = l2->next;
            }
            tempSum += carry;
            carry = tempSum / 10;
            iter->next = new ListNode(tempSum % 10);           
            iter = iter->next;
        }
        return sumHead->next;
    }
};

//
//Time:O()
//Space:O()
class Solution2
{
public:

};


int main()
{
    vector<int> testVec1 = {1};
    vector<int> testVec2 = {9, 9, 9};
    vector<int> testVec3 = {9, 9, 9, 9};

    Solution1 solution1;
    Solution2 solution2;

    //sol1
    cout << "lists: " << endl;
    ListNode* sol1Test11 = createLinkedList(testVec1);
    printLinkedList(sol1Test11);
    ListNode* sol1Test12 = createLinkedList(testVec1);
    printLinkedList(sol1Test12);    
    ListNode* sol1Result1 = solution1.addTwoNumbers(sol1Test11, sol1Test12);
    cout << "sum: " << endl;
    printLinkedList(sol1Result1);

    cout << "lists: " << endl;
    ListNode* sol1Test21 = createLinkedList(testVec1);
    printLinkedList(sol1Test21);
    ListNode* sol1Test22 = createLinkedList(testVec3);
    printLinkedList(sol1Test22);
    ListNode* sol1Result2 = solution1.addTwoNumbers(sol1Test21, sol1Test22);
    cout << "sum: " << endl;
    printLinkedList(sol1Result2);

    cout << "lists: " << endl;
    ListNode* sol1Test31 = createLinkedList(testVec2);
    printLinkedList(sol1Test31);
    ListNode* sol1Test32 = createLinkedList(testVec3);
    printLinkedList(sol1Test32);
    ListNode* sol1Result3 = solution1.addTwoNumbers(sol1Test31, sol1Test32);
    cout << "sum: " << endl;
    printLinkedList(sol1Result3);

    
    return 0;
}