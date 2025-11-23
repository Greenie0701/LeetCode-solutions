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
    ListNode* getkthNode(ListNode* head, int k){
        k--;
        ListNode* temp = head;
        while(temp!=NULL && k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr!=NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp!=NULL){
            // Determine the Kth Node, if not exist attach Prev chuck to curr temp, end
            ListNode* kthnode = getkthNode(temp, k);
            if(kthnode==NULL){
                if(prev!=NULL){
                    prev->next = temp;
                }
                break;
            }
            // Once you get the kth Node reverse the chunck and make sure to preserve the next node.
            ListNode* next = kthnode->next;
            kthnode->next = NULL;
            ListNode* reversehead = reverse(temp);
            // Check if this the first chunck of given LL
            if(temp==head){
                head = kthnode;
            }
            // Else attach the reversed head to the prev chunck
            else{
                prev->next = reversehead;
            }
            prev = temp;
            temp = next;
        }
        return head;
    }
};