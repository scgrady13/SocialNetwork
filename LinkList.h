//SEAN GRADY PROGRAM 5 MAY 3 2020 4817-3168 CS1342


#ifndef PROGRAM5_LINKLIST_H
#define PROGRAM5_LINKLIST_H

#include "Friend.h"
#include <string>
class LinkList {
private:
    //Pointers for the linked list
    Friend* head;
    Friend* tail;
public:
    //constructor
    LinkList();

    //debugging function
    void display_network();
    //function to get the size of the entire linked list
    int getNetworkSize();

    //function to get a recommendation of who a user should be friends with based off how many friends they have in common with others
    Friend* get_recommendations(int);

    //functions for adding information into the linked list and adding friends
    void add_user(Friend);
    void add_friend(int, int);
};


#endif //PROGRAM5_LINKLIST_H
