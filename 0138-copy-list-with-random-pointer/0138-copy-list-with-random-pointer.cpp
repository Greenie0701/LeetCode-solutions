/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    void createcopynode(Node* head){
        Node* temp = head;
        while(temp!=NULL){
            Node* next = temp->next;
            Node* copy = new Node(temp->val);
            temp->next = copy;
            copy->next = next;
            temp = next;
        }
    }

    void linkrandompointer(Node* head){
        Node* temp = head;
        while(temp!=NULL){
            if(temp->random==NULL){
                temp->next->random==NULL;
            }
            else{
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }
    }

    Node* extractcopynode(Node* head){
        Node* dummy = new Node(-1);
        Node* tail = dummy;
        Node* temp = head;
        while(temp!=NULL){
            Node* copy = temp->next;
            tail->next = copy;
            temp->next = copy->next;
            temp = temp->next;
            tail = tail->next;
        }
        return dummy->next;
    }

    Node* copyRandomList(Node* head) {
        createcopynode(head);
        linkrandompointer(head);
        Node* newhead = extractcopynode(head);
        return newhead;
    }
};