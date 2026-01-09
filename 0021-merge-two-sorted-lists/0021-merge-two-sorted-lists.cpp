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
    struct comp {
        bool operator()(ListNode* a, ListNode* b) const {
            return a->val > b->val;  // min-heap
        }
    };
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)return list2;
        if(!list2)return list1;
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        ListNode* dummynode = new ListNode(-1);
        ListNode* tail = dummynode;
        while(l1){
            pq.push(l1);
            l1 = l1->next;
        }
        while(l2){
            pq.push(l2);
            l2 = l2->next;
        }
        while(!pq.empty()){
            tail->next = pq.top();
            pq.pop();
            tail = tail->next;
        }
        tail->next = nullptr; 
        return dummynode->next;
    }
};