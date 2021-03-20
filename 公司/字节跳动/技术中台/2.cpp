class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ret;
        ListNode* curNode=new ListNode();
        ListNode* pre=new ListNode();
        ret = curNode;
        while(l1!=NULL&&l2!=NULL)
        {
            int temp=l1->val+l2->val+curNode->val;
            pre = curNode;
            if(temp>=10)
            {
                curNode->val=temp-10;
                ListNode* next=new ListNode(1);
                curNode->next=next;
                curNode=next;
            }
            else
            {
                ListNode* next=new ListNode();
                curNode->val=temp;
                curNode->next=next;
                curNode=next;
            }
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL)
        {
            pre = curNode;
            int temp = l1->val + curNode->val;
            if(temp>=10)
            {
                curNode->val=temp-10;
                ListNode* next =  new ListNode(1);
                curNode->next=next;
                curNode=next;
            }
            else
            {
                ListNode* next =  new ListNode();
                curNode->val=temp;
                curNode->next=next;
                curNode=next;
            }
            l1=l1->next;
        }
        while(l2!=NULL)
        {
            pre = curNode;
            int temp = l2->val + curNode->val;
            if(temp>=10)
            {
                curNode->val=temp-10;
                ListNode* next = new ListNode(1);
                curNode->next=next;
                curNode=next;
            }
            else
            {
                ListNode* next = new ListNode();
                curNode->val=temp;
                curNode->next=next;
                curNode=next;
            }
            l2=l2->next;
        }
        if(curNode->val==0)
        {
            pre->next=NULL;
        }
        return ret;
    }
};