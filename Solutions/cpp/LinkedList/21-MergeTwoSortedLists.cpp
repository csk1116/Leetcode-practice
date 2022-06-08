#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution1
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode* mergeList = new ListNode;
        ListNode* temp = mergeList;

        while(l1 != nullptr && l2 != nullptr)
        {
            if(l1->val > l2->val)
            {
                temp->next = l2;
                l2 = l2->next;
                temp = temp->next;
            }
            else
            {
                temp->next = l1;
                l1 = l1->next;
                temp = temp->next;
            }            
        }

        if(l1) temp->next = l1;
        if(l2) temp->next = l2;

        return mergeList->next;
    }
    void printList(ListNode* head)
    {
        while(head->next != nullptr)
        {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
};

int main()
{
    ListNode l1(1);
    ListNode l2(0);

    ListNode* head1 = &l1;
    ListNode* temp1 = head1;
    ListNode* head2 = &l2;
    ListNode* temp2 = head2;

    for(int i = 2; i < 10; i++)
    {
        temp1->next = new ListNode(i);
        temp1 = temp1->next;
    } 

    for(int i = 0; i < 15; i = i+2)
    {
        temp2->next = new ListNode(i);
        temp2 = temp2->next;
    } 

    Solution1 solution1;    
    solution1.printList(head1);
    solution1.printList(head2);
    ListNode* mergedListHead = solution1.mergeTwoLists(head1, head2);
    solution1.printList(mergedListHead);   

    return 0;
}