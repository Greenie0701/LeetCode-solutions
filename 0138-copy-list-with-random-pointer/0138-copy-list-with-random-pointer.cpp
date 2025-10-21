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
    void insertcopynode(Node* head){
        Node* temp = head;
        while(temp!=NULL){
            Node* nextnode = temp->next;
            Node* copy = new Node(temp->val);
            temp->next = copy;
            copy->next = nextnode;
            temp = nextnode;
        }
    }
    void linkrandompointers(Node* head){
        Node* temp = head;
        while(temp!=NULL){
            Node* copy = temp->next;
            if(temp->random!=NULL){
                copy->random = temp->random->next;
            }else{
                copy->random = nullptr;
            }
            temp = temp->next->next;
        }
    }
    Node* extractcopyhead(Node* head){
        Node* temp = head;
        Node* dummyhead = new Node(-1);
        Node* res = dummyhead;
        while(temp!=NULL){
            res->next = temp->next;
            res = res->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummyhead->next;
    }
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        insertcopynode(head);
        linkrandompointers(head);
        Node* copyhead = extractcopyhead(head);
        return copyhead;
    }
};