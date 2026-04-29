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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> critical;
        ListNode* curr = head->next;
        ListNode* prev = head;
        ListNode* next = NULL;
        int index = 1;
        while(curr->next){
            next = curr->next;
            if((curr->val>prev->val&&curr->val>next->val)||(curr->val<prev->val&&curr->val<next->val)){
                critical.push_back(index);
            }
            index++;
            prev=curr;
            curr = next;
            
        }
        if(critical.size()<2)return {-1, -1};
        int n = critical.size();
        int mini = critical[n-1]-critical[0];
        vector<int> result;
        for(int i=1; i<n; i++){
            if(critical[i]-critical[i-1]<mini)mini=critical[i]-critical[i-1];
        }
        result.push_back(mini);
        result.push_back(critical[n-1]-critical[0]);
        return result;
    }
};