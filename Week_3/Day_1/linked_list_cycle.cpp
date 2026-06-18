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
//We use Floyd's Cycle Detection Algorithm.
//Maintain two pointers:
//slow -> moves one step at a time
//fast -> moves two steps at a time
//
//If a cycle exists,
//both pointers will eventually meet.
//If fast reaches NULL,
//the linked list does not contain a cycle.
//Time complexity: O(N)
//Space complexity: O(1)

bool hasCycle(ListNode *head)
{
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        //cycle detected
        if(slow == fast)
            return true;
    }

    return false;
}

int main()
{
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    //creating a cycle
    head->next->next->next->next = head->next;

    cout << (hasCycle(head) ? "true" : "false");
    return 0;
}