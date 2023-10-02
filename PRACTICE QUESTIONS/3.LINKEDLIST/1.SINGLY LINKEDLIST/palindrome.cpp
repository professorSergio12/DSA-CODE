
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    // Function to check whether the list is palindrome.

    Node *reverse(Node *head)
    {
        Node *current = head;
        Node *prev = NULL;
        Node *temp = NULL;

        while (current != NULL)
        {
            temp = current->next;
            current->next = prev;

            prev = current;
            current = temp;
        }
        return prev;
    }
    bool isPalindrome(Node *head)
    {
        if (head == NULL)
            return true;
        Node *slow = head;
        Node *fast = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node *rev = reverse(slow->next);
        Node *curr = head;
        while (rev != NULL)
        {
            if (curr->data != rev->data)
                return false;

            curr = curr->next;
            rev = rev->next;
        }
        return true;
    }
};
