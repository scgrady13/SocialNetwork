//SEAN GRADY PROGRAM 5 MAY 3 2020 4817-3168 CS1342


#include <fstream>
#include <iostream>
#include "LinkList.h"
using namespace std;
//function prototypes
ifstream& open_file();
LinkList* read_file(ifstream&);
int recommend_user(LinkList *network,int);
string toUpper(string);
int main(){
    LinkList *network;
    string userChoice;
    cout << "WELCOME TO THE SOCIAL NETWORK!" << endl << endl;
    //opens the file then reads it into the linked list to fill data in
    network = read_file(open_file());
    //finds the network size
    int networkSize = network->getNetworkSize();
    //recommends a user before entering the loop
    cout << recommend_user(network, networkSize);
    while(userChoice != "NO"){
        //prompts user to continue
        cout << endl << "CONTINUE? (YES/NO)? ";
        cin >> userChoice;
        //converts user entered string to uppercase
        userChoice = toUpper(userChoice);
        //if yes allows user to reccomend another friend
        if(userChoice == "YES"){
            cout << recommend_user(network, networkSize);
        }
            //if not terminates program
        else if(userChoice == "NO") {
            cout << "THANK YOU FOR USING THE SOCIAL NETWORK" << endl;
            cout << "SOCIAL NETWORK TERMINATING";
            break;
        }
            //checks if user entered invalid responce
        else {
            cout << "INVALID FIELD, PLEASE RETRY" << endl;
        }
    }
    return 0;
}
//opens file to be read and returns the reference of it
ifstream& open_file(){
    auto* networkFile = new ifstream();
    networkFile->open("facebook_1000_data.txt");
//    networkFile->open("small_network_data.txt");
    if(!networkFile->is_open()) {
        cout <<"File not found" << endl << "Exiting Program";
        exit(0);
    }
    return *networkFile;
}
//function to read in the file for the social network
LinkList* read_file(ifstream& networkFile){
    //creates a reference to network
    auto *network = new LinkList();

    //temp string used to read the file
    string fileString;
    //holds the size of the network for the forloop to use to iterate over all the pople inside of the network
    int networkSize;

    //reads in the size of the network
    getline(networkFile,fileString);
    networkSize = stoi(fileString);
    cout << "READING IN THE NETWORK FILE..." << endl << endl;


    //iterates text file until it reads in all the friends based off the size of the network
    for(int i = 0;i < networkSize; i++){

        //creates a temp person object
        auto* person = new Friend;

        //reads in the name of the person
        getline(networkFile, fileString);
        //fills in the information on the person that will be used to fill it in inside of hte linked list;
        person->setID(i);
        person->setName(fileString);
        //passes the person to the linked list
        network->add_user(*person);
    }

    int u,v;
    while(!networkFile.eof()){
        //reads the lines of the function to get the user value and the value of who they are friends with
        getline(networkFile, fileString, ' ');
        //error needed to be avoided of file that caused a invalid_argument error
        if (fileString.empty()) break;
        u = stoi(fileString);
        getline(networkFile, fileString);
        v = stoi(fileString);
        //uses the add_friend function in the linked list to add the friends for each user
        network->add_friend(u, v);
        network->add_friend(v, u);
    }
    cout << "SUCCESSFULLY READ IN THE NETWORK FILE!" << endl << endl;
    return network;
}
//converts user entered strings into uppercase
string toUpper(string userChoice) {
    for (char & i : userChoice) {
        if (i >= 'a' && i <= 'z') {
            i -= 32;
        }
    }
    return userChoice;
}
//function to recommend the user
int recommend_user(LinkList *network,int networkSize){
    string search;
    int recommendation;
    cout << "SELECT USER TO SUGGEST FRIEND TO" << endl;
    cout << "SELECT A USER BETWEEN 0 AND " << networkSize - 1 << endl;
    cin >> search;
    int temp;

    while(search != "EXIT") {
        //checks if user entered a string
        for(char i : search) {
            if(i >= '0' && i <= '9'){
                temp++;
            }
        }

        //checks if only digits entered
        if (temp >= search.length()) {
            //checks if user entered a number in range
            if (stoi(search) < networkSize && stoi(search) >= 0) {
                //calls the getRecommendation function with the user enterd number
                Friend *suggestFriend = network->get_recommendations(stoi(search));
                recommendation = suggestFriend->getID();
                cout << "SUGGESTED FRIEND FOR " << search << " IS ";
                return recommendation;
            }
        }
        //called if the user does not enter a valid number
        cout << "SELECT A USER BETWEEN 0 AND " << networkSize << endl;
        cin >> search;
    }
}
