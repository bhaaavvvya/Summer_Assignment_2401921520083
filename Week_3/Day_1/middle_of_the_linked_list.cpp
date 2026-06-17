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
//First, count the total number of nodes
//present in the linked list.
//
//The middle node position is:
//(cnt / 2) + 1
//
//Traverse the list again
//until the middle position is reached
//and return that node.
//For even-length lists,
//the second middle node is returned.
//Time complexity: O(N)
//Space complexity: O(1)

ListNode* middleNode(ListNode* head)
{
    int cnt = 0;
    ListNode* temp = head;
    while(temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }

    int mid = (cnt / 2) + 1;
    temp = head;

    while(temp != NULL)
    {
        mid--;

        if(mid == 0)
            break;

        temp = temp->next;
    }

    return temp;
}

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* middle = middleNode(head);
    cout << middle->val;
    return 0;
}