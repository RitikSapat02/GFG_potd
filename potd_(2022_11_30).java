class Solution
{
    //function to reverse the linked list
    Node reverse(Node head)
    {
        if(head==null)
        {
            return head;
        }
        
        Node prev=null;
        Node h=head;
        while(h!=null)
        {
            Node temp=h.next;
            h.next=prev;
            prev=h;
            h=temp;
        }
        return prev;
    }
    
    
    Node reorderlist(Node head)
    {
        if(head==null || head.next==null)
        {
            return head;
        }
        
        Node slow=head;
        Node fast=head;
        Node prevSlow=null;
        
        while(fast!=null && fast.next!=null)
        {
            prevSlow=slow;
            slow=slow.next;
            fast=fast.next.next;
        }
        
        Node reverseHead=reverse(slow);
        prevSlow.next=null;
        
        fast=head;
        slow=reverseHead;
        
        while(fast!=null)
        {
            Node tempFast=fast.next;
            Node tempSlow=slow.next;
            fast.next=slow;
            if(tempSlow!=null && tempFast!=null)
            {
                slow.next=tempFast;
            }
            fast=tempFast;
            slow=tempSlow;
        }
        
        return head;   
    }
}