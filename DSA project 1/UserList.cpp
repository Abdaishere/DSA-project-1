#include "UserList.h"
using namespace std;


listNode::listNode(){
    this->username = "";
    this->user = nullptr;
    this->next = nullptr;
    this->prev = nullptr;
}

listNode::listNode(string username, User *user){
    this->username = username;
    this->user = user;
    this->prev = nullptr;
    this->next = nullptr;
}

void push(listNode** head, User *newUser){

    listNode* new_Node = (listNode*)malloc(sizeof(listNode));
    new_Node->user = newUser;
    new_Node->next = (*head);
    new_Node->prev = nullptr;

    if ((*head) != nullptr){ (*head)->prev = new_Node; }

    (*head) = new_Node;
}

void insertAfter( listNode* prev_Node, User *newUser){
    if (prev_Node == nullptr) {
        cout<<"the node to be inserted after cannot be NULL";
        return;
    }

    listNode* new_Node = (listNode*)malloc(sizeof(listNode));
    new_Node->user = newUser;
    new_Node->next = prev_Node->next;
    prev_Node->next = new_Node;
    new_Node->prev = prev_Node;

    if (new_Node->next != nullptr){new_Node->next->prev = new_Node;}

}

void append( listNode** head_ref, User *newUser, string username1){
//    listNode* new_node = (listNode*)malloc(sizeof(listNode));
    listNode *new_node= new listNode(newUser->getUserName(), newUser);
    listNode* last = *head_ref;
    new_node->next = nullptr;

    if (*head_ref == nullptr) {
        new_node->prev = nullptr;
        *head_ref = new_node;
        return;
    }

    while (last->next != nullptr) {last = last->next;}

    last->next = new_node;
    new_node->prev = last;
}

void printList(listNode* head_Node){

    listNode* last_Node = nullptr;

    while (head_Node != nullptr){
        cout<<head_Node->user->getUserName()<<", "<<head_Node->user->getName()<<" \n";
        last_Node = head_Node;
        head_Node = head_Node->next;
    }
}

UserList::UserList(){
    listHead = nullptr;
    listTail = nullptr;
}

UserList::UserList(listNode *listHead){ this->listHead = listHead;}




void UserList::appendNode(listNode **head_ref, User *newUser, string username) {
    append(head_ref, newUser, username);
}

void UserList::printUserList() {printList(this->listHead);}

User *UserList::getUser(string username) {
    listNode *ptr = this->listHead;
    while (ptr && ptr->username!= username){
        ptr = ptr->next;
    }
    if (ptr)
        return ptr->user;
    return nullptr;
}

void UserList::notFriendsTo(User *person) {
    listNode *ptr=this->listHead;
    short count=0;
    while (count <5 && ptr){
        if (!person->findFriend(*(ptr->user)) && ptr->username != person->getUserName()) {
            cout<<ptr->user->getUserName()<<", "<<ptr->user->getName()<<'\n';
            count++;
        }
        ptr = ptr->next;
    }
}