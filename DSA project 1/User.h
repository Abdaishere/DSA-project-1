#ifndef DSA_PROJECT_1_USER_H
#define DSA_PROJECT_1_USER_H

#include "bits/stdc++.h"
using namespace std;



/* User relations.
 * ///////// talaat3000,  emadsalem1   (user8, user3)
    ///////// fatoom, olaa100           (user5, user2)
    ///////// olaa100, mony34           (user2, user6)
    ///////// emadsalem1, abdoamr       (user3, user4)
    ///////// emy2000, mony34           (user7, user6)
    ///////// samir22, talaat3000       (user9, user8)
*/


struct treap_Node{
    string node_Key;
    string name;
    int node_Priority;
    treap_Node *left_Node, *right_Node;

};

class User{
private:
    string name;
    string username;
    string email;
    treap_Node* friendsTreap;
public:
    User();
    User(string name, string username, string email, treap_Node* = 0);
    void addFriend(User newFriend);
    void removeFriend(User Friend);
    bool findFriend(User Friend);
    void printFriends();
    string const getName();
    string const getUserName();
    string const getEmail();
    treap_Node* const getFriendsTreap();
    User *getUserByUserName(string username);

};
#endif //DSA_PROJECT_1_USER_H
