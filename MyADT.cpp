/*
 * MyADT.cpp
 * 
 * Class Description: A linear data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - This is a value-oriented data collection: the elements are kept in 
 *                     ascending sort order of search key. 
 *                   - Its data structure is not expandable, i.e., resizable. 
 *
 * Author: April Nguyen 301314527 
 * Last modified on: Sept. 29 2023 
 */


#include <iostream>
#include <cctype>
#include "MyADT.h"  // Header file
#include "Profile.h"

using std::cout;
using std::endl;
    
// Default constructor.
MyADT::MyADT() {

   /* Put your code here */
   // no elements are initially present
   for (unsigned int i=0; i<MAX_ALPHA; i++){ 
      elements[i] = new Profile[MAX_ELEMENTS];  // initialize each pointer in elements to an array of MAX_ELEMENTS Profile objects
      if (!elements[i]) {
        exit(1);
      }
      elementCount[i] = 0;                      //initialize to 0 profiles
      for (unsigned int j=0; j<MAX_ELEMENTS; j++){
         elements[i][j] = Profile();          // initialize each profile to default TBD
      }
   }
}  // end default constructor


// Copy constructor - Covered in Lab 3
MyADT::MyADT(const MyADT& rhs) {

   /* Put your code here */
    for (unsigned int i=0; i<MAX_ALPHA; i++){
        elements[i] = new Profile[MAX_ELEMENTS];    // calls the default constructor at each index
        elementCount[i] = rhs.elementCount[i];
        for (unsigned int j=0; j<MAX_ELEMENTS; j++){
            string theUserName = rhs.elements[i][j].getUserName();
            string theName = rhs.elements[i][j].getName();
            string theEmail = rhs.elements[i][j].getEmail();
            string theBirthday = rhs.elements[i][j].getBirthday();
            elements[i][j] = Profile(theUserName, theName, theEmail, theBirthday);
        }
    }

}  // end copy constructor


// Destructor
// Description: Destruct this object, releasing heap-allocated memory.
MyADT::~MyADT() {

   /* Put your code here */
    for (unsigned int i=0; i<MAX_ALPHA; i++) {
        delete[] elements[i];
    }

} // end destructor

// Description: Returns the total element count of elements currently stored in MyADT.
unsigned int MyADT::getElementCount() const {

   /* Put your code here */
   unsigned int total = 0;
   for (unsigned int i=0; i<MAX_ALPHA; i++){
    total += elementCount[i];
   }

   return total;

}  // end getElementCount


// Description: Inserts an element.
// Precondition: newElement must not already be in data collection.  
// Postcondition: newElement inserted and the appropriate elementCount has been incremented.
//                Returns "true" when the insertion is successfull,
//                otherwise "false".
bool MyADT::insert(const Profile& newElement) {

   /* Put your code here */
    string username = newElement.getUserName(); // username we are trying to find
    unsigned int index = newElement.getFirstLetter() - 'A'; // use as index

    // should not be in data collection based on precondition
    if (!search(newElement)){ // if did not find newElement in MyADT, insert into MyADT if there is room
        if (elementCount[index] < MAX_ELEMENTS){
            unsigned int insert = 0;
            // increment to find correct insert position, until newElement username > this username
            while(insert < elementCount[index] && elements[index][insert].getUserName() < username){
                insert++;
            }
            // have the correct insert position
            // shift elements over to make room for newElement
            for (unsigned int i=elementCount[index]; i>insert; i--){ //elementCount[index] is the current number of entries
                elements[index][i] = elements[index][i-1];
            }
            // insert the new element
            elements[index][insert] = newElement;
            elementCount[index]++;
            return true;
        }
    }
    return false;
}  // end insert


// Description: Search for target element. 
//              Returns a pointer to the element if found,
//              otherwise, returns nullptr.
Profile* MyADT::search(const Profile& target) {

   /* Put your code here */
    string username = target.getUserName(); // username we are trying to find
    unsigned int index = target.getFirstLetter() - 'A';

    // go to the index of elements array of Profiles (first letter)
    // check each existing element in array 
    // if found, return element address
    // if not found, return nullptr
    for (unsigned int i=0; i<elementCount[index]; i++){
        if (username == elements[index][i].getUserName()){
            return &elements[index][i];
        }
    }
    return nullptr;
}  // end of search

// Description: Remove an element. 
// Postcondition: toBeRemoved is removed and the appropriate elementCount has been decremented.
//                Returns "true" when the removal is successfull,
//                otherwise "false".
bool MyADT::remove(const Profile& toBeRemoved) {

   /* Put your code here */
   string username = toBeRemoved.getUserName();
   unsigned int index = toBeRemoved.getFirstLetter() - 'A';

    if (search(toBeRemoved)){
        unsigned int remove = 0;
        while(elements[index][remove].getUserName() != username){ // we know it exists since we called search(toBeRemoved)
            remove++;
        }
        // shift over to remove that index
        for (unsigned int j=remove; j<elementCount[index]-1; j++){
                elements[index][j] = elements[index][j+1];
        }
        // decrement elementCount for that letter
        elementCount[index]--;
        return true;
    }
    return false;
}  // end remove


// Description: Remove all elements.
// Postcondition: MyADT goes back to its initialization state.
void MyADT::removeAll() {

   /* Put your code here */
    for (unsigned int i=0; i<MAX_ALPHA; i++){
        if (elementCount[i] != 0){
            for (unsigned int j=0; j<elementCount[i]; j++){
                elements[i][j] = Profile();
            }
        }
        elementCount[i] = 0;
    }
}  // end removeAll


// Description: Prints all elements stored in MyADT by ascending order of search key.
// ***For Testing Purposes - Conceptualy, it is not part of this class.***
void MyADT::print() {

   /* Put your code here */
    for (unsigned int i=0; i<MAX_ALPHA; i++){
        if (elementCount[i] != 0){
            for (unsigned int j=0; j<elementCount[i]; j++){
                    cout << elements[i][j].getUserName() << ", "
                        << elements[i][j].getName() << ", "
                        << elements[i][j].getEmail() << ", "
                        << elements[i][j].getBirthday() << endl;
            }
        }
    }

} // end of print 

//  End of implementation file