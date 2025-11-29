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
            Node* copynode = new Node(temp->val);
            Node* nextnode = temp->next;
            temp->next = copynode;
            copynode->next = nextnode;
            temp = nextnode;
        }
    }

    void linkrandomnode(Node* head){
        Node* temp = head;
        while(temp!=NULL){
            Node* copynode = temp->next;
            if(temp->random==NULL){
                copynode->random = NULL;
            }else{
                copynode->random = temp->random->next;
            }
            temp = copynode->next;
        }
    }

    Node* extracthead(Node* head){
        Node* dummy = new Node(-1);
        Node* tail = dummy;
        Node* temp = head;
        while(temp!=NULL){
            tail->next = temp->next;
            temp->next = temp->next->next;
            temp = temp->next;
            tail = tail->next;
        }
        return dummy->next;
    }

    Node* copyRandomList(Node* head) {
        createcopynode(head);
        linkrandomnode(head);
        Node* newhead = extracthead(head);
        return newhead;
    }
};