#include <string>
#include <iostream>
#include <sstream>

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *doubleIt(ListNode *head)
    {
        // each number can be doubled in place that is less than 4
        // if number is greater than 4 than there will be carry over
        // the largest digit (9) will produce only a 1 for carry over when doubled
        // knowing this we can iterate over list and double in place
        ListNode *carry = new ListNode(0, head);
        ListNode *node = carry;
        while (node)
        {
            node->val = (node->val * 2) % 10; // we only want the digit in the ones place
            ListNode *nextnode = node->next;
            if (nextnode && nextnode->val > 4) // there will be carry over from next nodes number
            {
                node->val += 1; // add carry over
            }
            node = nextnode;
        }
        return carry->val ? carry : head;
    }
};

int main()
{
    int number;
    Solution sol;
    ListNode *l = nullptr;
    ListNode *head = nullptr;
    std::string line;
    std::cout << "Enter single digits seperated by whitespace to be represented as link list:" << std::endl;
    std::getline(std::cin, line);
    std::istringstream stream(line);
    while (stream >> number)
    {
        if (number / 10 > 0 )
        {
            std::cout << "Each digit needs to be 0 - 9 and seperated by whitespace" << std::endl;
            return 0;
        }
        ListNode *temp = new ListNode(number);
        if (l)
        {
            l->next = temp;
        }
        else
        {
            head = temp;
        }
        l = temp;
    }
    std::cout << "You entered number: ";
    ListNode *node = head;
    while (node)
    {
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;
    std::cout << "The number doubled is: ";
    node = sol.doubleIt(head);
    while (node)
    {
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;
    return 0;
}