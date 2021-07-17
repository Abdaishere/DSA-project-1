#ifndef DSA_PROJECT_1_USERLIST_H
#define DSA_PROJECT_1_USERLIST_H

#include <iostream>
#include "User.h"
using namespace std;

struct listNode{
    string username;
    User *user;
    listNode *next;
    listNode *prev;
    listNode();
    listNode(string username, User *user);
};
class UserList{
private:
    listNode *listHead;
    listNode *listTail;
public:
    UserList();
    UserList(listNode *listHead);
    void notFriendsTo(User*);
    void printUserList();
    void appendNode(listNode** head_ref, User *newUser, string);
    User *getUser(string username);

};

#endif //DSA_PROJECT_1_USERLIST_H
