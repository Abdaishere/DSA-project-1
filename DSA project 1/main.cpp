#include <bits/stdc++.h>
#include "User.h"
#include "UserList.h"
using namespace std;
/*
 3- first half of the application
     1 - Login: type “username” to be logged in
     3 - Exit: type “exit”
     4 - Application actions
         1 - Login{

                  1 - List all friends
                  2 - Search by username
                  3 - Add friend
                  4 - Remove friend
                  5 - People you may know
                  6 - logout
                  }

         2 - Exit
 */
int main() {

    string username1 = "soad91";
    string username2 = "olaa100";
    string username3 = "emadsalem1";
    string username4 = "abdoamr";
    string username5 = "fatoom";
    string username6 = "mony34";
    string username7 = "emy2000";
    string username8 = "talaat3000";
    string username9 = "samir22";

    string name1 = "Soad Saber";
    string name2 = "Ola Kamel";
    string name3 = "Emad Salem";
    string name4 = "Abdelkarim Amr";
    string name5 = "Fatma Omar";
    string name6 = "Mona Hamed";
    string name7 = "Iman Kareem";
    string name8 = "Talaat Mahmoud";
    string name9 = "Samir Abdelshakoor";

    string email1 = "soad91@gmail.com";
    string email2 = "olaa100@yahoo.com";
    string email3 = "emadsalem1@gmail.com";
    string email4 = "abdoamr@gmail.com";
    string email5 = "fatoom@yahoo.com";
    string email6 = "mony34@gmail.com";
    string email7 = "emy2000@gmail.com";
    string email8 = "talaat3000@gmail.com";
    string email9 = "samir22@gmail.com";


    treap_Node* friendsTreap1 = nullptr;
    treap_Node* friendsTreap2 = nullptr;
    treap_Node* friendsTreap3 = nullptr;
    treap_Node* friendsTreap4 = nullptr;
    treap_Node* friendsTreap5 = nullptr;
    treap_Node* friendsTreap6 = nullptr;
    treap_Node* friendsTreap7 = nullptr;
    treap_Node* friendsTreap8 = nullptr;
    treap_Node* friendsTreap9 = nullptr;

    User user1(name1, username1, email1);
    User user2(name2, username2, email2);
    User user3(name3, username3, email3);
    User user4(name4, username4, email4);
    User user5(name5, username5, email5);
    User user6(name6, username6, email6);
    User user7(name7, username7, email7);
    User user8(name8, username8, email8);
    User user9(name9, username9, email9);

    User *user1ptr = &user1;
    User *user2ptr = &user2;
    User *user3ptr = &user3;
    User *user4ptr = &user4;
    User *user5ptr = &user5;
    User *user6ptr = &user6;
    User *user7ptr = &user7;
    User *user8ptr = &user8;
    User *user9ptr = &user9;



    user8.addFriend(user3);
    user3.addFriend(user8);

    user5.addFriend(user2);
    user2.addFriend(user5);

    user2.addFriend(user6);
    user6.addFriend(user2);

    user3.addFriend(user4);
    user4.addFriend(user3);

    user7.addFriend(user6);
    user6.addFriend(user7);

    user9.addFriend(user8);
    user8.addFriend(user9);

    listNode user1Node(username1, user1ptr);


    listNode* head_Ptr = &user1Node;

    listNode** ptr_To_Head_Ptr = &head_Ptr;

    UserList users_list(head_Ptr);

    users_list.appendNode(ptr_To_Head_Ptr, user2ptr, username2);
    users_list.appendNode(ptr_To_Head_Ptr, user3ptr, username3);
    users_list.appendNode(ptr_To_Head_Ptr, user4ptr, username4);
    users_list.appendNode(ptr_To_Head_Ptr, user5ptr, username5);
    users_list.appendNode(ptr_To_Head_Ptr, user6ptr, username6);
    users_list.appendNode(ptr_To_Head_Ptr, user7ptr, username7);
    users_list.appendNode(ptr_To_Head_Ptr, user8ptr, username8);
    users_list.appendNode(ptr_To_Head_Ptr, user9ptr, username9);

    users_list.printUserList();
    while(true){
        cout<<"1-LOGIN\n"
              "2-EXIT\n";
        int action1;
        cin>>action1;
        if(action1==1){
            cout<<"input username: ";
            string username;
            cin >> username;
            User *current_user;
                current_user = users_list.getUser(username);
            if (!current_user){
                cout<<"not found\n";
                continue;
            }
            cout << "welcome " << current_user->getName() <<'\n';

            while(true){
                if (!current_user)
                    break;
                int action2;
                cout<<" 1-List all friends\n"
                      " 2-Search by username\n"
                      " 3-Add friend\n"
                      " 4-Remove friend\n"
                      " 5-People you may know\n"
                      " 6-logout\n";
                cin>>action2;
                switch (action2) {
                    case 1: {
                        current_user->printFriends();
                        break;
                    }
                    case 2: {
                        string target;
                        cout << "input the friends username: ";
                        cin >> target;
                        User *targetUser = users_list.getUser(target);
                        if (!targetUser){
                            cout<<"not found\n";
                            continue;
                        }
                        if (current_user->findFriend(*targetUser)) {
                            cout <<targetUser->getUserName()<<", "<< targetUser->getName()<<", "<<targetUser->getEmail()<< '\n';
                        } else {
                            cout << "not found\n";
                        }
                        break;
                    }
                    case 3: {
                        string target;
                        cout << "input the friends username: ";
                        cin >> target;
                        User *targetUser = users_list.getUser(target);
                        if (!targetUser){
                            cout<<"not found\n";
                            continue;
                        }
                        if (current_user->findFriend(*targetUser)) {
                            cout << "You are already friends\n";
                        } else {
                            current_user->addFriend(*targetUser);
                            targetUser->addFriend(*current_user);
                            cout << "You are now friends\n";
                        }
                        break;
                    }
                    case 4: {
                        string target;
                        cout << "input the friends username: ";
                        cin >> target;
                        User *targetUser = users_list.getUser(target);
                        if (!targetUser){
                            cout<<"not found\n";
                            continue;
                        }
                        current_user->removeFriend(*targetUser);
                        cout<<"Done\n";
                        break;
                    }
                    case 5: {
                        users_list.notFriendsTo(current_user);
                        break;
                    }
                    case 6: {
                        current_user = nullptr;
                        break;
                    }
                    default : {
                        cout << "Try Again\n";
                    }
                }
            }

        }
        if(action1==2){ break;}
    }
    return 0;
}
