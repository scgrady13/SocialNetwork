//SEAN GRADY PROGRAM 5 MAY 3 2020 4817-3168 CS1342

#include <iostream>
#include "Friend.h"
#include "LinkList.h"
#include <string>
using namespace std;
//Constructor to create linkedlist with nullptr head and tail
LinkList::LinkList(){head = nullptr; tail = nullptr;}

int LinkList::getNetworkSize(){

    int networkSize = 0;
    //pointer that is used to iterate over the entire linked list
    Friend* getSize;
    getSize = head;
    //while loop continues until the list hits a nullptr at the tail
    while(getSize != nullptr){
        networkSize++;
        getSize = getSize->nextFriend;
    }
    //returns the final networksize
    return networkSize;
}
Friend* LinkList::get_recommendations(int search){
    //variables to assist in recommendations
    //holds the amount for the most friends that were the same as the user recommendation
    int mostFriendsFound = 0;
    //used in a loop to hold how many friends the current user being tested has in common
    int currentFriendsFound;
    //creates a pointer to pointer to users that are being tested
    Friend *testUser;
    testUser = head;
    //creates a pointer that is then left pointing to the person the recommendation is being made to
    Friend *currentUser;
    currentUser = head;
    //final pointer that is set after a user with more friends in common is found and is returned at the end
    Friend *suggestedFriend = nullptr;

    //while loop that iterates until the pointer is pointing to the friend
    //that the user wants to recommend a friend for
    while(currentUser != nullptr) {
        if (currentUser->getID() == search) {
            break;
        }
        else currentUser = currentUser->nextFriend;
    }
    //copies vector from the friend the currentUser is pointing to
    vector<int> current = currentUser->getFriendsList();
    vector<int> suggested;
    //while loop to find which friend has the most friends in common
    while(testUser != nullptr) {
        //copies vector from friend testUser is pointing to
        suggested = testUser->getFriendsList();
        //tracks how many friends the current friend that testUser is pointing to has in common
        currentFriendsFound = 0;
        //iterates over the friend that the recommendation is being made for
        for (int i : current){
            //iterates over the friend that the testUser pointer is currently pointing at
            for (int j : suggested){
                //checks to see if it is a friend in common, if it is the currentFriendsFound integar is increased
                if(i == j) {
                    currentFriendsFound++;
                }
            }
        }
        //checks to see if more current friends are found then the most already found
        //if so mostfriends will be changed to currentfriends found
        //lastly the suggestedfriend pointer will be changed to the user who now has the most friends in common
        if (currentFriendsFound >= mostFriendsFound && testUser->getID() != search) {
            mostFriendsFound = currentFriendsFound;
            suggestedFriend = testUser;
        }
        //increases the testUser pointer to the next user
        testUser = testUser->nextFriend;
    }
    //returns the final suggest user with the most friends in common
    return suggestedFriend;
}
//function to add users to the linked list
void LinkList::add_user(Friend add_user){
    string name = add_user.getName();
    int id = add_user.getID();
    //creates a new node in the linked list of a friend
    //friend in node is initialized with no data held
    auto *newFriend = new Friend;
    //fills in the data for name from the Friend object that was passed in
    newFriend->setName(name);
    //fills in the data for id from the Friend object that was passed in
    newFriend->setID(id);

    newFriend->nextFriend = nullptr;

    if(head != nullptr){
        tail->nextFriend = newFriend;
        tail = newFriend;
    }
    else {
        head = newFriend;
        tail = newFriend;
    }

}
//function to add friends to each user
void LinkList::add_friend(int u, int v){
    //creates a pointer for the linkedlist
    //pointer is used to search through the network for the friend
    Friend *searchNetwork;
    searchNetwork = head;
    //iterates over the linkedlist until the user is found corresponding to the 'U' variable
    while(searchNetwork != nullptr){
        //checks if the ID of the pointer matches the 'U' value
        if(searchNetwork->getID() == u){
            //if it matches adds the 'V' value as a friend
            searchNetwork->addFriend(v);
            //once found function returns
            return;
        }

        //goes to the next node if the friendID did not match 'U' value
        searchNetwork = searchNetwork->nextFriend;
    }
}
//Used for debugging, not needed anymore
void LinkList::display_network(){
    Friend* iterateNetwork;
    iterateNetwork = head;
    string name;
    int id;
    while(iterateNetwork != nullptr){
        name = iterateNetwork->getName();
        id = iterateNetwork->getID();
        vector<int> friends = iterateNetwork->getFriendsList();
        cout << id;
        cout << " (";
        cout << name;
        cout << ") [";
        for(int i : friends) {
            cout << i << " ";
        }
        cout << "]";
        iterateNetwork = iterateNetwork->nextFriend;
        cout << endl;
    }
}
