//approach

//so idea is this if you move around a circle one will run fast and second will slow at one
//point they tend to make 


class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow,*fast;
        while(fast !=NULL || fast->next !=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};