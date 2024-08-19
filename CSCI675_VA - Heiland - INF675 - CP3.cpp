/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
       vector<int> answer; //Defines an answer vector, which will hold all of the nodes' values that are greater than current node.
       int currentNodeVal = head->val; //Assigns the head node's value so it can be compared to the other nodes.
       ListNode* currentNodeHead = head; //Assigns the head node so program can keep track of what node is being compared.
       ListNode* nextNode = head->next; //Assigns the head's next node so its value can be compared to the head node's value.
       //cout << head->val;
       //cout << endl << nextNode->val;

       while(currentNodeHead->next != NULL){ //Loops through all the nodes until it reaches the last node.
        if(currentNodeVal < nextNode->val){ //If the current node's value is less than the next node's value.
            answer.push_back(nextNode->val); //The next node's value is added to answer.
            currentNodeHead = currentNodeHead->next; //Sets the current head to the node that is next on the list.
            currentNodeVal = currentNodeHead->val; //Sets the now current head's value to the current node's value.
            nextNode = currentNodeHead->next; //Sets the next node to the current head's next.
        } else { //If the current node's value is greater than the next node's value, then go to the next node.
            if(nextNode->next == NULL){ //If the end of the vector has been reached.
                answer.push_back(0); //0 is pushed to indicate there is no greater node in the list.
                currentNodeHead = currentNodeHead->next; //Sets the current head to the node that is next on the list.
                currentNodeVal = currentNodeHead->val; //Sets the now current head's value to the current node's value.
                nextNode = currentNodeHead->next; //Sets the next node to the current head's next.
            } else { //If the end of the vector has not been reached.
                nextNode = nextNode->next; //Continue going through the vector.
            }
        }
       } 
       //The last node has been reached. Since it is the last, there is no next greater node. 
       answer.push_back(0); //0 is pushed to indicate there is no greater node in the list.

       return answer;
    }
};