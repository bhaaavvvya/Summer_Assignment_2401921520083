//adding required header files
#include<iostream>
using namespace std;

//definition for singly-linked list
struct ListNode
{
    int val;
    ListNode* next;

    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

//APPROACH:
//Use a dummy node to handle edge cases
//such as removing the head node.
//
//Maintain two pointers:
//first and second.
//
//Move second pointer (n + 1) steps ahead.
//Then move both pointers together
//until second reaches NULL.
//
//Now first points to the node just before
//the node to be deleted.
//Remove the target node and return the head.
//Time complexity: O(N)
//Space complexity: O(1)

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode dummy(0);
    dummy.next = head;
    ListNode* first = &dummy;
    ListNode* second = &dummy;
    for(int i = 0; i <= n; i++)
        second = second->next;
    while(second != NULL)
    {
        first = first->next;
        second = second->next;
    }
    first->next = first->next->next;
    return dummy.next;
}

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    head = removeNthFromEnd(head, 2);

    while(head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}