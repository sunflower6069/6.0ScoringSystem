//===============================================================
// Name: Ballot Object Representing a Vector of Vote Objects and
//      the Value of the Ballot
// Author: Xin Yan
// File: ballot.hpp
// Copyright: 04/03/2016
// ==============================================================
#include "ballot.hpp"

//---------------------------------------------------------------
//constructor
//Ballot::
//Ballot (vector<Vote*> myVt) {
//    for (Vote* vt : myVt) {
//        myVotes.push_back(vt);
//    }
//    value (1);
//}

//---------------------------------------------------------------
//define operator < to compare two vote objects
bool Ballot::
cmpfunc (const Vote* vt1, const Vote* vt2) {
    return (vt1->getOrd() < vt2->getOrd());
}

//---------------------------------------------------------------
//destructor
Ballot::
~Ballot () {
    for (Vote* vt : myVotes) {
        delete vt;
    }
}

//---------------------------------------------------------------
// Check the ordinals in a ballot
bool Ballot::
checkOrdinals (unsigned const iball) {
    sort(myVotes.begin(), myVotes.end(), cmpfunc);//sort the vote objs in preference order
    for (unsigned icand=0; icand<myVotes.size(); icand++) {//check for validity of ballot
        if ((myVotes[icand]->getOrd()) != (icand+1)) { 
            cerr << "*** Ballot " << iball << " improperly marked -- IGNORED\n";
            return false;
        }
    }
    return true;
}

//---------------------------------------------------------------
//find the favorate candidate for a ballot object
void Ballot::
findFavor () {
    (*myVotes.begin())->addTally(value); //delegates to function in vote 
}

//---------------------------------------------------------------
// Update the ballot value
void Ballot::
updateValue () {
    StatusType st = (*myVotes.begin())->getStatus(); 
    if (st == ELECTED) { 
        value = value * (1 - (*myVotes.begin())->getAlpha());
    }
    while ( (myVotes.size() >0) && ((*myVotes.begin())->getStatus() != ACTIVE)) {
        myVotes.erase(myVotes.begin());
    }
}

//---------------------------------------------------------------
//print a ballot object
ostream& Ballot::
print (ostream& out) const {
    for (unsigned j=0; j<myVotes.size(); j+=5) {
        for (unsigned i=j; i<j+5; i++) {
            out << *myVotes[i];
        }
    out << "\n";
    }
    return out;
}
