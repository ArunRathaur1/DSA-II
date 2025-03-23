#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* x;
};
node* addnode(int value){
    node* y=new node();
    y->val=value;
    y->x=NULL;
    return y;
}
node* generatelist(vector<int>ar){// take vector as input genrate a list from it
    if(ar.size()==0)return NULL;
    node* head=addnode(ar[0]);
    node* forward=head;
    int k=ar.size();
    for(int i=1;i<k;i++){
        node* tem=addnode(ar[i]);
        forward->x=tem;
        forward=tem;
    }
    return head;
}
node* unionlist(list l1,list l2){
    node* head1=l1;
    node* head2=l2;
    node* dummyhead=new node();
    node* forwardhead=dummyhead;
    while(l1!=NULL&& l2!=NULL){
        //case1 when values are differnet
        if(l1->value>l2->value){
            node* tem=new node(l2->value);
            forwardhead->next = tem;
            forwardhead=tem;
            l2=l2->next;
        }
        else(l2->value>l1->value){
            node *tem = new node(l1->value);
            forwardhead->next = tem;
            forwardhead = tem;
            l1=l1->next;
        }
        else{
            node *tem = new node(l1->value);
            forwardhead->next = tem;
            forwardhead = tem;
            l1=l1->next;
            l2=l2->next;
        }
    }
    while(l1!=NULL){
        node *tem = new node(l1->value);
        forwardhead->next = tem;
        forwardhead = tem;
        l1 = l1->next;
    }
    while(l2!=NULL){
        node *tem = new node(l2->value);
        forwardhead->next = tem;
        forwardhead = tem;
        l2 = l2->next;
    }
    return dummyhead->next;
}
/*
l1->1->2->3->4->5->nullptr
                     .

l2->3->5->nullptr
           .


dummy->3->5
         forward

*/
node *intersection(list l1, list l2)
{
    node *head1 = l1;
    node *head2 = l2;
    node *dummyhead = new node();
    node *forwardhead = dummyhead;
    while (l1 != NULL && l2 != NULL)
    {

        if (l1->value == l2->value)
        {
        
            node *tem = new node();
            tem->val=l1->val
            tem->next=NULL;
            forwardhead->next = tem;
            forwardhead = tem;
            l1 = l1->next;
            l2 = l2->next;
        }
        else{
            if (l1->value > l2->value)
            {
                l2 = l2->next;
            }
            else{
                    l1 = l1->next;
                }
        }
    }
    return dummyhead->next;
}
