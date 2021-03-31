cycle find_cycle(elem* head) {
   cycle ans;
   ans.len = -1;
   ans.start = 0;
   elem* fast = head;
   elem* slow = head;
   while (fast) {
        if (fast->next==NULL) {
            ans.start=(ans.start)*2+1;
            break;
        }
        fast = fast->next->next;
        slow = slow->next;
        if(fast==slow) {
            ans.len=1;
            fast = fast->next;
            while(fast!=slow) {
                fast = fast->next;
                ans.len++;
            }
            slow = head;
            ans.start=0;
            while(fast!=slow) {
                slow=slow->next;
                fast=fast->next;
                ans.start++;
            }
            break;

        }
        ans.start++;
   }
   if(fast==NULL) {
      ans.start*=2;
   }


   return ans;

}