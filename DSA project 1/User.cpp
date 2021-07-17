#include "User.h"
#include "bits/stdc++.h"
using namespace std;

treap_Node *right_Rotation(treap_Node *m)
{
    treap_Node *n = m->left_Node,  *T2 = n->right_Node;

    // Perform rotation
    n->right_Node = m;
    m->left_Node = T2;

    // Return new root
    return n;
}

treap_Node *left_Rotation(treap_Node *m){

    treap_Node *n = m->right_Node, *T2 = n->left_Node;

    // Perform rotation
    n->left_Node = m;
    m->right_Node = T2;

    // Return new root
    return n;
}

treap_Node* new_Node(string KEY, string name){

    treap_Node* TMP = new treap_Node;
    TMP->node_Key = KEY;
    TMP->node_Priority = rand()%100;
    TMP->name = name;
    TMP->left_Node = TMP->right_Node = nullptr;
    return TMP;
}


treap_Node* find(treap_Node* treap_Root, string KEY){

    // Base Cases: root is null or key is present at root
    if (treap_Root == nullptr || treap_Root->node_Key == KEY){
        return treap_Root;
    }

    // Key is greater than root's key
    if (treap_Root->node_Key < KEY){
        return find(treap_Root->right_Node, KEY);
    }


    // Key is smaller than root's key
    return find(treap_Root->left_Node, KEY);
}


treap_Node* insert(treap_Node* treap_Root, string KEY, string name){

    // if no tree exists, create a node and return one.
    if (!treap_Root){
        return new_Node(KEY, name);
    }
    // If key is smaller than root
    if (KEY <= treap_Root->node_Key){

        // Insert in left subtree
        treap_Root->left_Node = insert(treap_Root->left_Node, KEY, name);

        // restore Heap property if violated
        if (treap_Root->left_Node->node_Priority > treap_Root->node_Priority)
            treap_Root = right_Rotation(treap_Root);
    }

    else{ // If key is greater

        // Insert in right subtree
        treap_Root->right_Node = insert(treap_Root->right_Node, KEY, name);

        // restore Heap property if violated
        if (treap_Root->right_Node->node_Priority > treap_Root->node_Priority){
            treap_Root = left_Rotation(treap_Root);

        }
    }
    return treap_Root;
}

/* Recursive implementation of node Deletion function */
treap_Node* deleteNode(treap_Node* treap_Root, string KEY){

    if (treap_Root == nullptr){
        return treap_Root;
    }

    if (KEY < treap_Root->node_Key){
        treap_Root->left_Node = deleteNode(treap_Root->left_Node, KEY);
    }

    else if (KEY > treap_Root->node_Key){
        treap_Root->right_Node = deleteNode(treap_Root->right_Node, KEY);

    }

    // IF KEY IS AT ROOT

        // If left node is nullptr
    else if (treap_Root->left_Node == nullptr){
        treap_Node *temp = treap_Root->right_Node;
        delete(treap_Root);
        treap_Root = temp;  // Make right child as root
    }

        // If Right node is nullptr
    else if (treap_Root->right_Node == nullptr){
        treap_Node *temp = treap_Root->left_Node;
        delete(treap_Root);
        treap_Root = temp;  // Make left child as root
    }

        // If at root and both left node and right node are not nullptr
    else if (treap_Root->left_Node->node_Priority < treap_Root->right_Node->node_Priority){
        treap_Root = left_Rotation(treap_Root);
        treap_Root->left_Node = deleteNode(treap_Root->left_Node, KEY);
    }

    else{
        treap_Root = right_Rotation(treap_Root);
        treap_Root->right_Node = deleteNode(treap_Root->right_Node, KEY);
    }

    return treap_Root;
}

void printInOrder(treap_Node* treap_Root){
    if (treap_Root){
        //  Username, name
        printInOrder(treap_Root->left_Node);
        cout << treap_Root->node_Key<<", "<< treap_Root->name<<'\n';
        printInOrder(treap_Root->right_Node);

    }
}
User::User() {
   this->name = " ";
   this->username = " ";
   this->email = " ";
   this->friendsTreap = nullptr;
}

User::User(string name, string username, string email, treap_Node *friendsTreap) {

    this->name = name;
    this->username = username ;
    this->email = email;
    this->friendsTreap = friendsTreap;

}

void User::addFriend(User newFriend) {
    this->friendsTreap = insert(this->friendsTreap, newFriend.username, newFriend.name);
}

void User::removeFriend(User Friend) {
    this->friendsTreap = deleteNode(this->friendsTreap, Friend.username);
}

bool User::findFriend(User Friend) {
    return  find(this->friendsTreap,Friend.username)? 1:0;
}

void User::printFriends() {
    printInOrder(this->friendsTreap);
}

string const User::getName(){ return this->name;}
string const User::getUserName(){ return this->username;}
string const User::getEmail(){ return this->email;}
treap_Node* const User::getFriendsTreap(){ return this->friendsTreap;}
User *User::getUserByUserName(string username) {
    if(username == this->username){
        return this;
    }
    else
        return nullptr;
}