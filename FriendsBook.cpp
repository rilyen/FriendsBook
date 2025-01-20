/*
 * FriendsBook.cpp - Assignment 1
 * 
 * Class Description: Social network application (partial implementation).
 *
 * In this version, we use our MyADT.
 *
 * ***You cannot remove/change the code provided in this file.***
 *
 * Author: April Nguyen 301314527 
 * Last modified on: Sept. 29, 2023
 */

#include <iostream>
#include <string>
#include <cctype>
#include "Profile.h"
#include "MyADT.h"

using std::cout;
using std::ws;
using std::cin;
using std::endl;


void join(MyADT & theMembers) {

   /* Put your code here */
   string myusername, myname, myemail, mybirthday;
   Profile entry;
      cout << "Enter a username to create your profile (one word starting with a letter): ";
      cin >> myusername; cout << endl;
      entry = Profile(myusername);

   if (theMembers.insert(entry)){
      cout << "Enter your first and last name (Firstname Lastname): ";
      cin.ignore();
      getline(cin,myname); cout << endl;
      cout << "Enter your email address (one word): ";
      cin >> myemail; cout << endl;
      cout << "Enter your birthday (month day year): ";
      cin.ignore();
      getline(cin,mybirthday); cout << endl;
      theMembers.search(entry)->setName(myname);
      theMembers.search(entry)->setEmail(myemail);
      theMembers.search(entry)->setBirthday(mybirthday);
      cout << "Welcome, " << myusername << ", to FriendsBook!" << endl;
   }
   else {
      cout << "Invalid username.\n\n";
      return;
   }
}

void leave(MyADT & theMembers) {

   /* Put your code here */
   cout << "Enter your username (one word starting with a letter): ";
   string username;
   cin >> username; cout << endl;
   Profile toDelete = Profile(username);
   if (theMembers.remove(toDelete)){
      cout << username << " has left FriendsBook." << endl;
   }
   else {
      cout << username << " could not leave FriendsBook." << endl;
   }
}

void search(MyADT & theMembers) {

   /* Put your code here */
   cout << "Enter the username to search for (one word starting with a letter): ";
   string myusername;
   cin >> myusername; cout << endl;
   Profile toSearch(myusername);
   Profile *found = theMembers.search(toSearch);
   if (found){
      cout << "Found " << myusername << " on FriendsBook." << endl;
      cout << "Here are their details: " << endl;
      cout << *found;
   }
   else {
      cout << myusername << " is not on FriendsBook" << endl;
   }

}

void newName(MyADT & theMembers, Profile* found) {
   string myname;
   if (found){
      cout << "Modifying the name of " << found->getUserName() << endl;
      cout << found->getName() << " is the current name." << endl;
      cout << "Enter your new first and last name (Firstname Lastname): ";
      cin.ignore();
      getline(cin,myname); cout << endl;
      found->setName(myname);
      cout << "The name has been updated for " << found->getUserName() << endl;
   }
   else {
      cout << "This profile is not on FriendsBook." << endl;
   }
}

void newEmail(MyADT & theMembers, Profile* found) {
   string myemail;
   if(found){
      cout << "Modying the email of " << found->getUserName() << endl;
      cout << found->getEmail() << " is the current email." << endl;
      cout << "Enter the new email (one word): ";
      cin.ignore();
      getline(cin,myemail); cout << endl;
      found->setEmail(myemail);
      cout << "The email has been updated for " << found->getUserName() << endl;
   }
   else {
      cout << "This profile is not on FriendsBook." << endl;
   }
}

void newBirthday(MyADT & theMembers, Profile* found) {
   string mybirthday;
   if(found){
      cout << found->getUserName() << " is on FriendsBook." << endl;
      cout << found->getBirthday() << " is the current birthday." << endl;
      cout << "Enter the new birthday (month day year): ";
      cin.ignore();
      getline(cin,mybirthday); cout << endl;
      found->setBirthday(mybirthday);
      cout << "The birthday has been updated for " << found->getUserName() << endl;
   }
   else {
      cout << "This profile is not on FriendsBook." << endl;
   }
}

void modify(MyADT & theMembers) {

   /* Put your code here */

   string myusername;
   char input;
   bool done = false;

   cout << "Enter your username (one word starting with a letter): ";
   cin >> myusername;
   Profile* found = theMembers.search(Profile(myusername));
   
   if (found){
      while (not done) {
         cout << "Enter..." << endl;
         cout << "n -> to modify your name" << endl;
         cout << "e -> to modify your email" << endl;
         cout << "b -> to modify your birthday" << endl << endl;
         cout << "x -> to exit modifying your profile." << endl << endl;

         cout << "Your choice: ";
         cin >> input;
         cout << endl;
         input = tolower(input);
         switch(input) {
               case 'n': newName(theMembers, found); break;
               case 'e': newEmail(theMembers, found); break;
               case 'b': newBirthday(theMembers, found); break;
               case 'x': cout << "\n----Bye!\n" << endl; 
                        done = true; break;
               default: cout << "Not sure what you mean! Please, try again!" << endl;
         }
      }
   }
   else {
      cout << myusername << " is not on FriendsBook." << endl;
      cout << "Going back to main menu." << endl;
   }
}

void print(MyADT & theMembers) {

   /* Put your code here */
   theMembers.print();

}

int main() {

    // Variables declaration
    MyADT members = MyADT();  // Object MyADT on the stack, its arrays on the heap
    bool done = false;
    char input = 0;
   
    cout << "*** FYI ***" << endl;
    cout << "Do not enter whitespace at the end of any input." << endl;
    cout << "Usernames may only contain letters and are case sensitive." << endl;
    cout << "Uppercase letters will be considered as coming before lowercase letters alphabetically." << endl;
    cout << "*** End of FYI ***" << endl;
    // Keep going until the user exits
    while (not done) {
        // Print menu to stdout
        cout << "\n----Welcome to FriendsBook!" << endl << endl;
        cout << endl << "Enter ..." << endl;
        cout << "j -> to join FriendsBook by creating a profile." << endl;
        cout << "l -> to leave FriendsBook." << endl;
        cout << "s -> to search for a friend on FriendsBook." << endl;
        cout << "m -> to modify your profile on FriendsBook." << endl;
        cout << "p -> to print all members on FriendsBook." << endl;
        cout << "x -> to exit FriendsBook." << endl << endl;


        cout << "Your choice: ";
        cin >> input;
        cout << endl;
        input = tolower(input);
        switch(input) {
            case 'j': join(members); break;
            case 'l': leave(members); break;
            case 's': search(members); break;
            case 'm': modify(members); break;
            case 'p': print(members); break;
            case 'x': cout << "\n----Bye!\n" << endl; 
                      done = true; break;
            default: cout << "Not sure what you mean! Please, try again!" << endl;
        }
    }
    return 0;
}