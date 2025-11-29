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
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr!=NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* getknode(ListNode* temp, int k){
        k--;
        while(temp!=NULL&&k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prevlast = NULL;
        ListNode* temp = head;
        while(temp!=NULL){
            ListNode* kthnode = getknode(temp, k);
            if(kthnode==NULL){
                if(prevlast!=NULL){
                    prevlast->next=temp;
                }
                break;
            }
            ListNode* nextnode = kthnode->next;
            kthnode->next = NULL;
            ListNode* reversehead = reverse(temp);
            if(temp==head){
                head=reversehead;
            }else{
                prevlast->next = reversehead;
            }
            prevlast = temp;
            temp = nextnode;
        }
        return head;
    }
};