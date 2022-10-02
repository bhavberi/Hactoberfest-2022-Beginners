// Author: Ishaan Kulkarni
// Date: 2-10-2022


/*

To find the mid point of LL, we use a fast and slow pointer. Fast pointer moves as speex = 2 * slow pointer.

When the LL reaches the end, of LL, slow pointer is at the mid of LL.

10->20->30->40
The mid point of above LL is 20/30. We take it to be 20 cuz it helps in merge sort.
s=10, f=10
s=20, f=30
Stop when fast->next=NULL || fast->next->next=NULL


*/







class node {
public:
	int data;
	node*next;

	node(int d) {
		data = d;
		next = NULL;
	}
};








node* midPoint(node* head){

    if(head==NULL || head->next==NULL){
        return head;
    }

    node* fast = head;
    node* slow = head;

    while(fast->next!=NULL && fast->next->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;

}



