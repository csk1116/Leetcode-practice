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

//iterative
//Time:O(M+N)
//Space:O(1)
class Solution1
{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* result = new ListNode(0);
        ListNode* current = result;

        while(list1 && list2)
        {
            if(list1->val > list2->val)
            {
                current->next = list2;
                list2 = list2->next;
            }
            else
            {
                current->next = list1;
                list1 = list1->next;
            }   
            current = current->next;         
        }
        current->next = list1 ? list1 : list2;
        return result->next;
    }    
};

//recursive
//Time:O(M+N)
//Space:O(M+N)
class Solution2
{
public:

};

int main()
{
    vector<int> testVec1 = {};
    vector<int> testVec2 = {1};
    vector<int> testVec3 = {1, 3, 5, 7, 9};
    vector<int> testVec4 = {2, 3, 4, 5, 6};

    ListNode* list1 = createLinkedList(testVec1);
    ListNode* list2 = createLinkedList(testVec2);
    ListNode* list3 = createLinkedList(testVec3);
    ListNode* list4 = createLinkedList(testVec4);

    Solution1 solution1;    

    //test1 list1 & list1 -> empty
    cout << "before:" << endl;
    printLinkedList(list1);
    printLinkedList(list1);
    ListNode* test1 = solution1.mergeTwoLists(list1, list1);
    cout << "merged: ";
    printLinkedList(test1);

    //test2 list1 & list2 -> 1
    cout << "before:" << endl;
    printLinkedList(list1);
    printLinkedList(list2);
    ListNode* test2 = solution1.mergeTwoLists(list1, list2);
    cout << "merged: ";
    printLinkedList(test2);

    //test3 list3 & list4 -> 1->2->3->3->4->5->5->6->7->9
    cout << "before:" << endl;
    printLinkedList(list3);
    printLinkedList(list4);
    ListNode* test3 = solution1.mergeTwoLists(list3, list4);
    cout << "merged: ";
    printLinkedList(test3);  

    return 0;
}