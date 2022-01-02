//SEAN GRADY PROGRAM 5 MAY 3 2020 4817-3168 CS1342

#include <iostream>
#include "Friend.h"
using namespace std;
//setters
void Friend::setName(string namein){
    name = namein;
}
void Friend::setID(int idin){
    id = idin;
}
//getters
string Friend::getName(){return name;}
int Friend::getID(){return id;}
//used for debugging
void Friend::displayFriends(){
    for (int i = 0; i < friendsList.size();i++){
        cout << friendsList[i] << " ";
    }
}
//function to add friends to the friendsList vector
void Friend::addFriend(int v) {
    friendsList.push_back(v);
}
//getter
vector<int> Friend::getFriendsList(){
    return friendsList;
}
