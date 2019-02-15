#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int val):val(val),next(nullptr){}
};

Node *mergeTwoSortedList(Node *n1, Node *n2){
    Node *head = new Node(-1);
    Node *cur = head;
    while (n1 && n2) {
        if(n1->val <= n2->val){
            cur->next = n1;
            n1 = n1->next;
        }else {
            cur->next = n2;
            n2 = n2->next;
        }
        cur = cur->next;
    }
    cur->next = n1 != nullptr ? n1 : n2;
    cur = head;
    head = head->next;
    delete cur;
    cur = nullptr;
    return head;
}
void printList(Node* head){
    Node *cur = head;
    for(Node *cur=head; cur!=nullptr; cur=cur->next)cout<<cur->val<<",";
    cout<<endl;
}

int main(){
    Node *n1 = new Node(1);
    n1->next = new Node(3);
    n1->next->next = new Node(5);

    Node *n2 = new Node(2);
    n2->next = new Node(4);
    n2->next->next = new Node(6);

    printList(mergeTwoSortedList(n1, n2));

    return 0;
}
