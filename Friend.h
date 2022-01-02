//SEAN GRADY PROGRAM 5 MAY 3 2020 4817-3168 CS1342


#ifndef PROGRAM5_FRIEND_H
#define PROGRAM5_FRIEND_H
#include <string>
#include <vector>
using namespace std;
class Friend {
private:
    string name;
    int id;
    vector<int> friendsList;
public:
    //pointer used to iterate over the friends list
    Friend* nextFriend;
    //setters
    void setName(string);
    void setID(int);
    //getters
    vector<int> getFriendsList();
    string getName();
    int getID();

    //used for debugging
//    void displayFriends();
    //function to add friends into the vector of each user
    void addFriend(int);


    void displayFriends();
};


#endif //PROGRAM5_FRIEND_H
