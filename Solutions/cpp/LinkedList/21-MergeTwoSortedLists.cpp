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
        if(!list1 && !list2)
            return nullptr;
        if(!list1)
            return list2;
        if(!list2)
            return list1;

        ListNode* dummyNode = new ListNode(0);
        ListNode* current = dummyNode;

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
        return dummyNode->next;
    }    
};

//recursive
//Time:O(M+N)
//Space:O(M+N)
class Solution2
{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if(!list1)
            return list2;
        if(!list2)
            return list1;

        ListNode* head;
        if(list1->val > list2->val)
        {
            head = list2;
            head->next = mergeTwoLists(list1, list2->next);
        }
        else
        {
            head = list1;
            head->next = mergeTwoLists(list1->next, list2);
        }
        return head;
    }
};

int main()
{
    vector<int> testVec1 = {};
    vector<int> testVec2 = {1};
    vector<int> testVec3 = {1, 3, 5, 7, 9};
    vector<int> testVec4 = {2, 3, 4, 5, 6};

    ListNode* test1List1 = createLinkedList(testVec1);
    ListNode* test1List2 = createLinkedList(testVec2);
    ListNode* test1List3 = createLinkedList(testVec3);
    ListNode* test1List4 = createLinkedList(testVec4);

    Solution1 solution1;    
    Solution2 solution2;

    //list1 & list1 -> empty
    cout << "before:" << endl;
    printLinkedList(test1List1);
    printLinkedList(test1List1);
    ListNode* sol1Test1 = solution1.mergeTwoLists(test1List1, test1List1);
    cout << "merged: ";
    printLinkedList(sol1Test1);

    //list1 & list2 -> 1
    cout << "before:" << endl;
    printLinkedList(test1List1);
    printLinkedList(test1List2);
    ListNode* sol1Test2 = solution1.mergeTwoLists(test1List1, test1List2);
    cout << "merged: ";
    printLinkedList(sol1Test2);

    //test1list3 & test1list4 -> 1->2->3->3->4->5->5->6->7->9
    cout << "before:" << endl;
    printLinkedList(test1List3);
    printLinkedList(test1List4);
    ListNode* sol1Test3 = solution1.mergeTwoLists(test1List3, test1List4);
    cout << "merged: ";
    printLinkedList(sol1Test3);  

    ListNode* test2List1 = createLinkedList(testVec1);
    ListNode* test2List2 = createLinkedList(testVec2);
    ListNode* test2List3 = createLinkedList(testVec3);
    ListNode* test2List4 = createLinkedList(testVec4);

    //test2list1 & test2list1 -> empty
    cout << "before:" << endl;
    printLinkedList(test2List1);
    printLinkedList(test2List1);
    ListNode* sol2Test1 = solution2.mergeTwoLists(test2List1, test2List1);
    cout << "merged: ";
    printLinkedList(sol2Test1);

    //test2list1 & test2list2 -> 1
    cout << "before:" << endl;
    printLinkedList(test2List1);
    printLinkedList(test2List2);
    ListNode* sol2Test2 = solution2.mergeTwoLists(test2List1, test2List2);
    cout << "merged: ";
    printLinkedList(sol2Test2);

    //test2list3 & test2list4 -> 1->2->3->3->4->5->5->6->7->9
    cout << "before:" << endl;
    printLinkedList(test2List3);
    printLinkedList(test2List4);
    ListNode* sol2Test3 = solution2.mergeTwoLists(test2List3, test2List4);
    cout << "merged: ";
    printLinkedList(sol2Test3);  

    return 0;
}