#include <iostream>
#include <vector>
#include <utility> //pair
#include <unordered_map>
using namespace std;

//Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;    
    Node(int _val) 
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

typedef pair<int, int> listNode;

Node *createLinkedList(vector<listNode>& vec)
{
    if (vec.empty())
        return nullptr;

    Node *head = new Node(0);
    Node *iter = head;
    vector<Node*> tempVec;
    for (int i = 0; i < vec.size(); i++)
    {
        iter->next = new Node(vec[i].first);
        tempVec.push_back(iter->next);
        iter = iter->next;
    }

    iter = head->next;
    for(int i = 0; i < vec.size(); i++)
    {
        int index = vec[i].second;
        if(index != -1)
            iter->random = tempVec[index];
        else
            iter->random = nullptr;
        iter = iter->next;
    }
    return head->next;
}

void printLinkedList(Node *head)
{
    if (!head)
    {
        cout << "empty !" << endl;
        return;
    }

    Node* iter = head;
    unordered_map<Node*, int> map;
    int index = 0;
    while(iter)
    {
        map[iter] = index;
        iter = iter->next;
        index ++;        
    }

    cout << "[ ";
    while (head)
    {        
        cout << "[" << head->val << "," ;
        if(map.find(head->random) != map.end())
            cout << map[head->random] << "], ";
        else
            cout << "null" << "], ";
        head = head->next;
    }
    cout << "nullptr ]" << endl;
}

//hash map<origin node*, copy node*>, two pass
//Time:O(N)
//Space:O(N)
class Solution1
{
public:
    Node* copyRandomList(Node* head)
    {
        unordered_map<Node*, Node*> map {{nullptr, nullptr}}; //<origin, copy>
        Node* iter = head;
        while(iter)
        {
            map[iter] = new Node(iter->val);
            iter = iter->next;
        }

        iter = head;
        while(iter)
        {
            Node* copy = map[iter];
            copy->next = map[iter->next];
            copy->random = map[iter->random];
            iter = iter->next;
        }
        return map[head];
    }
};

// https://leetcode.com/problems/copy-list-with-random-pointer/discuss/1059181/C%2B%2B-or-Three-Pass-or-O(n)-0ms-Beats-100-or-Explanation-(with-example)
//three pass method
//Time:O(N)
//Space:O(1)
class Solution2
{
public:
    Node* copyRandomList(Node* head)
    {
        // [[1, 3], [2, 0], [3, null], [4, 1]]
        //first pass, create copy node next to origin node
        // [[1, 3], [1', null], [2, 0], [2', null], [3, null], [3', null], [4, 1], [4', null]]
        Node* iter = head;
        while(iter)
        {
            Node* temp = iter->next;
            iter->next = new Node(iter->val);
            iter->next->next = temp;
            iter = temp; 
        } 

        //second pass, link copy node's random node
        // [[1, 3], [1', 3'], [2, 0], [2', 0'], [3, null], [3', null], [4, 1], [4', 1']]
        iter = head;
        while(iter)
        {
            if(iter->random)
                iter->next->random = iter->random->next;
            iter = iter->next->next;
        }
        
        //third pass, link copy list
        //copy [[1', 3'], [2', 0'], [3', null], [4', 1']]        
        Node* copy = new Node(0); //dummy
        iter = copy;
        while(head)
        {
            iter->next = head->next;
            iter = iter->next;

            head->next = head->next->next;
            head = head->next;
        } 
        
        return copy->next;
    }
};


int main()
{
    vector<listNode> testVec1 = {};
    vector<listNode> testVec2 = {listNode(1,0)};
    vector<listNode> testVec3 = {listNode(1,3), listNode(2,1), listNode(4,-1), listNode(5, 0)};
    Node* testList1 = createLinkedList(testVec1);
    Node* testList2 = createLinkedList(testVec2);
    Node* testList3 = createLinkedList(testVec3);
    cout << "origin: " << endl;
    printLinkedList(testList1);
    printLinkedList(testList2);
    printLinkedList(testList3);

    Solution1 solution1;
    Solution2 solution2;

    //sol1
    cout << "sol1 copy: " << endl;
    Node* sol1Result1 = solution1.copyRandomList(testList1);
    Node* sol1Result2 = solution1.copyRandomList(testList2);
    Node* sol1Result3 = solution1.copyRandomList(testList3);
    printLinkedList(sol1Result1);
    printLinkedList(sol1Result2);
    printLinkedList(sol1Result3);

    //sol2
    cout << "sol2 copy: " << endl;
    Node* sol2Result1 = solution2.copyRandomList(testList1);
    Node* sol2Result2 = solution2.copyRandomList(testList2);
    Node* sol2Result3 = solution2.copyRandomList(testList3);
    printLinkedList(sol2Result1);
    printLinkedList(sol2Result2);
    printLinkedList(sol2Result3);
    
    return 0;
}