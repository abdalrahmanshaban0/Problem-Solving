/*
Problem Name : 19. Remove Nth Node From End of List 
Author: Abdalrahman Shaban
Date: 03/03/2024 18:33:30
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int sz = 0;
        while(temp != nullptr){
            sz++;
            temp = temp->next;
        }

        if(sz == 1 && n == 1) return NULL;
        if(n == sz) return head->next;

        temp = head;
        ListNode* ans = head;
        for(int i = 0; i < sz-n; i++){
            temp = temp->next;
            if(i < sz-n-1){
                head = head->next;
            }
        }
        
        head->next = temp->next;
        return ans;
    }
};
