#include <iostream>
using namespace std;

struct LinkNode {
      int val;
      LinkNode *next;
      LinkNode () : val(0), next(nullptr) {}
      LinkNode (int x) : val(x), next(nullptr) {}
      LinkNode (int x, LinkNode *next) : val(x), next(next) {}
 };
 

class KLinkSolution{
public:
    void swap(LinkNode* head,LinkNode* end,int k){
        LinkNode* left=head,right=end;
	int temp=0,i=1,j=1;
	for(;left!=right;)
	{
	    temp=right->val;
	    left->vai=right->val;
	    right->val=temp;
	    left=left->next;
	    while(i!=k-j)
	    {
		++i;    
	        right=head->next;
            }
	    ++j;
	    i=1;
	}
    }
    LinkNode * reverseKGroup(LinkNode * head, int k) {
	LinkNode* temp=head,sp=head;
	int i=1;
	while(temp)
	{
		if((i==k) && temp)
		{
			swap(sp,temp,k);
			i=1;
			sp=temp;
		}
		++i;
		temp=temp->next;
	}

	return head;
    }
    
    void display(LinkNode* head)
    {
	    while(head)
	    {
		    cout<<head->val<<endl;
		    head=head->next;
	    }
    }
};

int main()
{
	int i=1;
	LinkNode* head=new LinkNode;
	LinkNode* temp=head;
	for(;i<11;++i)
	{
		temp->val=i;
		temp->next=new LinkNode;
		temp=temp->next;
	}

	KLinkSolution link;
	link.display(head);
	link.reverseKGroup(head,2);
	link.display(head);

	return 0;
}
