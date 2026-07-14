#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <unordered_set>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> mpp;
        ListNode* temp = head;

        while(temp != NULL){
            if(mpp.find(temp) != mpp.end()) return true;

            mpp.insert(temp);

            temp = temp->next;
        }
        return false;
    }


};


void printLinkedList(ListNode* head) {
    ListNode* temp = head;
    // Traverse the linked list and print each node's value
    while (temp != nullptr) { 
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);
    ListNode* fifth = new ListNode(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    // Create a loop
    fifth->next = third; 

    Solution sol;
    // Check if there is a loop 
    // In the linked list
    if (sol.hasCycle(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }

    // Clean up memory (free the allocated nodes)
    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}
