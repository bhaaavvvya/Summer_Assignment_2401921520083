//adding required header files
#include<iostream>
using namespace std;

//definition for singly-linked list
struct ListNode
{
    int val;
    ListNode* next;

    ListNode()
    {
        val = 0;
        next = NULL;
    }

    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

//APPROACH:
//Use a dummy node to simplify merging.
//Maintain a tail pointer that always points
//to the last node of the merged list.
//
//Compare nodes from both lists and attach
//the smaller node to the merged list.
//Move the corresponding pointer forward.
//
//After one list ends,
//attach the remaining nodes of the other list.
//Time complexity: O(N + M)
//Space complexity: O(1)

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
    ListNode test;
    ListNode* tail = &test;
    while(list1 != NULL && list2 != NULL)
    {
        if(list1->val <= list2->val)
        {
            tail->next = list1;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    tail->next = (list1 != NULL) ? list1 : list2;
    return test.next;
}

int main()
{
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* head = mergeTwoLists(list1, list2);

    while(head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}