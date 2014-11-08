#include<iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};


ListNode *sortList(ListNode *head) {

    if(head==NULL || head->next==NULL)
        return head;

    ListNode *current=head->next;
    ListNode *prev=head;
    bool flag=false;
    while(current!=NULL){
        ListNode *next=current->next; 
        if(current->val < head->val) {
            prev->next=current->next;
            current->next=head;
            head=current;
            prev=current->next;
            flag=true;
        }
        else {
            ListNode *node=head;;
            while(node->next!=current){
                if(current->val < node->next->val){
                    prev->next=current->next;
                    current->next=node->next;
                    node->next=current;
                    flag=true;
                    break;
                }
                node=node->next;
            }
        }
        if(flag==false)prev=current;
        flag=false;
        current=next;
    }
    return head;                
}

int main(){
    ListNode *node=new ListNode(8);
    node->next=new ListNode(4);
    node->next->next=new ListNode(6);
    node->next->next->next=new ListNode(1);
    node->next->next->next->next=new ListNode(5);
    node = sortList(node);
    while(node->next!=NULL){
        cout<<node->val;
    }

}
