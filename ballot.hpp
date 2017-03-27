//===============================================================
// Name: Ballot Object Representing a Vector of Vote Objects and
//      the Value of the Ballot
// Author: Xin Yan
// File: ballot.hpp
// Copyright: 04/03/2016
// ==============================================================
#ifndef BALLOT_HPP
#define BALLOT_HPP

#include "tools.hpp"
#include "vote.hpp"
#include <vector>
#include <gmpxx.h>

class Ballot {
private:
    vector<Vote*> myVotes;
    mpq_class value;//rational number as value 
    static bool cmpfunc(const Vote* vt1, const Vote* vt2);//define a comparison operator
public:
    Ballot (vector<Vote*> myVt) : myVotes(myVt), value(1) {}//constructor
    ~Ballot ();//destructor 
    
    bool checkOrdinals(unsigned const iball);//sort vote objs and check for validity of ballot
    void findFavor ();//find the favorate candidate 
    void updateValue ();//update the ballot value
    ostream& print(ostream& out) const;//print a ballot object
};

//--------------------------------------------------------------
//inline function defining constructor
inline ostream& operator<<(ostream& out, const Ballot& ball) {
    return ball.print(out);
}

#endif
