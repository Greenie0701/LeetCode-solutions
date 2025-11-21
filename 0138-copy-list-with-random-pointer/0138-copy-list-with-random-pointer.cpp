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

    void createrandomnode(Node* head){
        Node* temp = head;
        while(temp!=NULL){
            Node* copy = temp->next;
            if(temp->random==NULL){
                copy->random = NULL;
            }else{
                copy->random = temp->random->next;
            }
            temp = copy->next;
        }
        return;
    }
    void createcopynode(Node* head){
        Node* temp = head;
        Node* nextnode = NULL;
        while(temp!=NULL){
            nextnode = temp->next;
            Node* copy = new Node(temp->val);
            temp->next = copy;
            copy->next = nextnode;
            temp = copy->next;
        } 
        return;
    }
    Node* extractcopynode(Node* head){
        Node* dummy = new Node(-1);
        Node* tail = dummy;
        Node* temp = head;
        while(temp!=NULL){
            tail->next = temp->next;
            temp->next  = temp->next->next;
            temp = temp->next;
            tail = tail->next;
        }
        return dummy->next;
    }
    Node* copyRandomList(Node* head) {
        createcopynode(head);
        createrandomnode(head);
        Node* newhead = extractcopynode(head);
        return newhead;
    }
};