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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode* ans = new ListNode(0);
        priority_queue <pair<int,ListNode*>, vector<pair<int,ListNode*>>,               greater<pair<int,ListNode*>>> pq;
        
        int len = lists.size();
        
        for(int i = 0; i < len; i++){
            if(lists[i])pq.push({lists[i]->val, lists[i]});
        }
        
        ListNode* res = ans;
        
        while(pq.size()){
            auto x = pq.top();
            pq.pop();
            ListNode *curr = new ListNode(x.first);
            ans->next = curr;
            ans = ans->next;
            if(x.second->next){
                pq.push({x.second->next->val, x.second->next});
            }
        }
        
        return res->next;
    }
};