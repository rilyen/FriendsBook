/*
 * MyADTTestDriver.cpp - Assignment 1
 *
 * Class Description: Test ADT class.
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
using std::endl;

int main(){
    // Variables declaration
    cout << "*** Testing default constructor MyADT():" << endl;
    MyADT * members = new MyADT();
    cout << "memory adress of members is " << &members << endl;
    cout << "memory address stored in members is " << members << endl;
    cout << endl;

    // Constructor Test for Profile("username")
    cout << "Just created MyADT members. Expected to have 0 elements." << endl;
    cout << "MyADT members has " << members->getElementCount() << " elements." << endl;
    cout << endl;
    cout << "Here is what MyADT members contains: " << endl;
    members->print();
    cout << endl;
    cout << endl;

    cout << "Creating 3 Profile arrays using parameterized constructor Profile(string aUserName);:" << endl;
    cout << "Alice, Andrew, Ava, Alexander, Amelia." << endl;
    cout << "Michael, Megan, Matthew, Madison, Michelle." << endl;
    cout << "Zachary, Zoe, Zara, Zeke, Zane." << endl;
    cout << endl;
    cout << endl;
    Profile theMemberA[] = {Profile("Alice"),Profile("Andrew"),Profile("Ava"),Profile("Alexander"),Profile("Amelia")};
    Profile theMemberM[] = {Profile("Michael"),Profile("Megan"),Profile("Matthew"),Profile("Madison"),Profile("Michelle")};
    Profile theMemberZ[] = {Profile("Zachary"),Profile("Zoe"),Profile("Zara"),Profile("Zeke"),Profile("Zane")};

    // Insert test
    ///// insert the first profile in theMember_[] into MyADT members
    cout << "*** Testing insert() of MyADT:" << endl;
    cout << "Inserting 1 element from each of the 3 profile arrays theMember_[]." << endl;
    for (unsigned int i = 0; i<1; i++) {
        if (!members->insert(theMemberA[i])){
            cout << "Insert failed for theMemberA[" << i << "] " << theMemberA[i].getUserName();
        }
        if (!members->insert(theMemberM[i])){
            cout << "Insert failed for theMemberM[" << i << "] " << theMemberM[i].getUserName();
        }
        if (!members->insert(theMemberZ[i])){
            cout << "Insert failed for theMemberZ[" << i << "] " << theMemberZ[i].getUserName();
        }
    }

    cout << "My ADT members is expected to have 3 elements: Alice, Michael, and Zachary" << endl;
    cout << "My ADT members has " << members->getElementCount() << " elements. " << endl;
    cout << endl;
    cout << "Here is what MyADT members contains: " << endl;
    members->print();
    cout << endl;
    cout << endl;

    ///// insert the rest of the profiles in theMember_[] into MyADT members
    cout << "*** Testing insert() of MyADT:" << endl;
    cout << "Inserting all remaining elements from the 3 Profile arrays theMember_[]" << endl;
    for (unsigned int i = 1; i < 5; i++) {
        if (!members->insert(theMemberA[i])){
            cout << "Insert failed for theMemberA[" << i << "] " << theMemberA[i].getUserName();
        }
        if (!members->insert(theMemberM[i])){
            cout << "Insert failed for theMemberM[" << i << "] " << theMemberM[i].getUserName();
        }
        if (!members->insert(theMemberZ[i])){
            cout << "Insert failed for theMemberZ[" << i << "] " << theMemberZ[i].getUserName();
        }
    }
    cout << "My ADT members is expected to have 15 elements." << endl;
    cout << "My ADT members has " << members->getElementCount() << " elements. " << endl;
    cout << endl;
    cout << "Here is what MyADT members contains: " << endl;
    members->print();
    cout << endl;
    cout << endl;

    cout << "*** Testing insert() of MyADT: " << endl;
    cout << "Testing insert() Profile(Ashley) - not there - A is full." << endl;
    cout << "Insert is expected to fail." << endl;
    if (!members->insert(Profile("Ashley"))){
        cout << "Insert failed for Ashley." << endl;
    }
    cout << endl;
    cout << "My ADT members is expected to have 15 elements." << endl;
    cout << "My ADT members has " << members->getElementCount() << " elements. " << endl;
    cout << "Here is what MyADT members contains: " << endl;
    members->print();
    cout << endl;
    cout << endl;

    cout << "*** Testing insert() of MyADT: " << endl;
    cout << "testing insert() Profile(Emily, Emily Rodriguez, emily.rodriguez@gmail.com, October 15 1990)" << endl;
    if (!members->insert(Profile("Emily", "Emily Rodriguez", "emily.rodriguez@gmail.com", "October 15 1990"))){
        cout << "Insert failed for Emily." << endl;
    }
    cout << endl;
    cout << "My ADT members is expected to have 16 elements." << endl;
    cout << "My ADT members has " << members->getElementCount() << " elements. " << endl;
    cout << "Here is what MyADT members contains: " << endl;
    members->print();
    cout << endl;
    cout << endl;

    cout << "*** Testing remove() of MyADT:" << endl;
    cout << "Testing remove(Megan) - already there - middle." << endl;
    if (!members->remove(Profile("Megan"))){
        cout << "Remove failed for Megan." << endl;
    }
    cout << "My ADT members is expected to have 15 elements." << endl;
    cout << "My ADT members has " << members->getElementCount() << " elements. " << endl;
    cout << endl;
    cout << "Here is what MyADT members contains: " << endl;
    members->print();
    cout << endl;

    cout << "*** Testing remove() of MyADT:" << endl;
    cout << "Testing remove(Zoe) - already there - last." << endl;
    if (!members->remove(Profile("Zoe"))){
        cout << "Remove failed for Zoe." << endl;
    }
    cout << "My ADT members is expected to have 14 elements." << endl;
    cout << "My ADT members has " << members->getElementCount() << " elements. " << endl;
    cout << endl;
    cout << "Here is what MyADT members contains: " << endl;
    members->print();
    cout << endl;
    cout << endl;

    cout << "*** Testing remove() of MyADT:" << endl;
    cout << "Testing remove(Alexander) - already there - first." << endl;
    if (!members->remove(Profile("Alexander"))){
        cout << "Remove failed for Alexander." << endl;
    }
    cout << "My ADT members is expected to have 13 elements." << endl;
    cout << "My ADT members has " << members->getElementCount() << " elements. " << endl;
    cout << endl;
    cout << "Here is what MyADT members contains: " << endl;
    members->print();
    cout << endl;
    cout << endl;

    cout << "*** Testing remove() of MyADT:" << endl;
    cout << "Testing remove(Melissa) - not there - M has 4/5 elements." << endl;
    cout << "Remove is expected to fail." << endl;
    if (!members->remove(Profile("Melissa"))){
        cout << "Remove failed for Melissa." << endl;
    }
    cout << "My ADT members is expected to have 13 elements." << endl;
    cout << "My ADT members has " << members->getElementCount() << " elements. " << endl;
    cout << endl;
    cout << "Here is what MyADT members contains: " << endl;
    members->print();
    cout << endl;
    cout << endl;

    cout << "*** Testing remove() of MyADT:" << endl;
    cout << "Testing remove(Gabriel) - not there - G has no elements" << endl;
    cout << "Remove is expected to fail." << endl;
    if (!members->remove(Profile("Gabriel"))){
        cout << "Remove failed for Gabriel." << endl;
    }
    cout << "My ADT members is expected to have 13 elements." << endl;
    cout << "My ADT members has " << members->getElementCount() << " elements. " << endl;
    cout << endl;
    cout << "Here is what MyADT members contains: " << endl;
    members->print();
    cout << endl;
    cout << endl;

    cout << "*** Testing search: " << endl;
    cout << endl;

    cout << "Testing search and << for Profile(Alice) - already there - first." << endl;
    for (unsigned int i=0; i<1; i++){
        Profile * found = members->search(Profile("Alice"));
        if (!found){
            cout << "Alice not found." << endl;
        }
        else {
            cout << *found << endl;
        }
    }
    cout << endl;

    cout << "Testing search and getters for Profile(Matthew) - already there" << endl;
    for (unsigned int i=0; i<1; i++){
        Profile * found = members->search(Profile("Matthew"));
        if (!found){
            cout << "Matthew not found." << endl;
        }
        else {
            cout << "Username is " << found->getUserName() << endl;
            cout << "Name is "     << found->getName()     << endl;
            cout << "Email is "    << found->getEmail()    << endl;
            cout << "Birthday is " << found->getBirthday() << endl;
        }
    }
    cout << endl;

    cout << "Testing search Profile(Alexander) - was there but not anymore." << endl;
    for (unsigned int i=0; i<1; i++){
        Profile * found = members->search(Profile("Alexander"));
        if (!found){
            cout << "Alexander not found." << endl;
        }
        else {
            cout << found << endl;
        }
    }
    cout << endl;

    cout << "Testing search Profile(Liam) - not there." << endl;
    for (unsigned int i=0; i<1; i++){
        Profile * found = members->search(Profile("Liam"));
        if (!found){
            cout << "Liam not found." << endl;
        }
        else {
            cout << found << endl;
        }
    }
    cout << endl;
    
    cout << "Testing search and setters for Profile(Madison) - already there" << endl;
    for (unsigned int i=0; i<1; i++){
        Profile * found = members->search(Profile("Madison"));
        if (!found){
            cout << "Madison not found." << endl;
        }
        else {
            cout << "Current information for Madison: " << endl;
            cout << *found << endl;
            cout << "Set Madison's name to Anderson." << endl;
            found->setName("Madison Anderson");
            cout << "Set Madison's email to madison.anderson@email.com" << endl;
            found->setEmail("madison.anderson@email.com");
            cout << "Set Madison's birthday to March 8 1995." << endl;
            found->setBirthday("March 8 1995");
            cout << "Updated information for Madison: " << endl;
            cout << *found << endl;
        }
    }
    cout << endl;

    cout << "My ADT members is expected to have 13 elements." << endl;
    cout << "My ADT members has " << members->getElementCount() << " elements. " << endl;
    cout << endl;
    cout << "Here is what MyADT members contains: " << endl;
    members->print();
    cout << endl;

    cout << "*** Testing removeAll() of MyADT:" << endl;
    cout << "MyADT is expected to go back to initialization state." << endl;
    members->removeAll();
    cout << "My ADT members is expected to have 0 elements." << endl;
    cout << "My ADT members has " << members->getElementCount() << " elements. " << endl;
    cout << "Here is what MyADT members contains: " << endl;
    members->print();
    cout << endl;
    cout << endl;

    cout << "*** Testing destructor ~MyADT():" << endl;
    cout << "Calling delete members." << endl;
    delete members;
}