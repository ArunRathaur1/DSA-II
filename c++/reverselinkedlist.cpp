#include<bits/stdc++.h>
using namespace std;
struct Listnode{
    int val;
    Listnode* node;
};
Listnode* addelement(int val){
    Listnode* head=new Listnode();
    head->val=val;
    return head;
}
Listnode* createList(vector<int>values){
    int n=values.size();
    Listnode* head=new Listnode();
    head->node=NULL;
    if(n==0)return  head;
    head->val=values[0];
    Listnode* x=head;
    for(int i=1;i<n;i++){
        Listnode* tem=addelement(values[i]);
        head->node=tem;
        head=tem;
    }
    return x;
}
Listnode* reverselist(Listnode* head){
    if(head==NULL||head->node==NULL)return head;
    Listnode* prev=NULL;
    Listnode* curr=head;
    while(curr!=NULL){
        Listnode* next=curr->node;
        curr->node=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
void printlist(Listnode* head){
    while(!head==NULL){
        cout<<head->val<<' ';
        head=head->node;
    }
}
int main(){
    vector<int>values={1,2,3,4,5};
    Listnode* head=createList(values);
    printlist(head);
    cout<<endl;
    Listnode* newhead=reverselist(head);
    printlist(newhead);
}