#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    char c;
    int end;
    node* ar[26];
    node(char c){
        this->c=c;
        for(int i=0;i<26;i++){
            ar[i]=NULL;
        }
        end=0;
    }
};
class Trie {
    public:
    node* head=new node('1');
    Trie() {
    }
    node* helperadd(char ch,node* head){
        node* newnode=new node(ch);
        head->ar[ch-'a']=newnode;
        return newnode;
    }
    void insert(string word) {
        node* tem=head;
        for(int i=0;i<word.length();i++){
            int ch=word[i];
            node* newnode=helperadd(ch,tem);
            tem=newnode;
        }
    }
    
    bool search(string word) {
        node* tem=head;
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            if(tem->ar[ch-'a']!=NULL){
                tem=tem->ar[ch-'a'];
            }
            else{
                return false;
            }
        }
        for(int i=0;i<26;i++){
            if(tem->ar[i]!=NULL){
                return false;
            }
        }
        return true;
    }
    
    bool startsWith(string word) {
         node* tem=head;
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            if(tem->ar[ch-'a']!=NULL){
                tem=tem->ar[ch-'a'];
            }
            else{
                return false;
            }
        }
        return true;
        
    }
    void print(){
        int p=-1;
        queue<node*>q;
        q.push(head);
        while(!q.empty()){
            node* t=q.front();
            q.pop();
            if(t==NULL){
                cout<<endl;
                  continue;
            }
            
            cout<<t->c;
            for(int i=0;i<26;i++){
                if(t->ar[i]!=NULL){
                    q.push(t->ar[i]);
                }
            }
            q.push(NULL);
        }
    }
    
};
int main(){
      Trie* ob=new Trie();
    ob->insert("hello");
    ob->insert("apple");
    cout<<ob->search("apple")<<endl;
    }
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */