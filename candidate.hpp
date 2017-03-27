//===============================================================
// Name: Candidate Object Representing a Single Candidate
// Author: Xin Yan
// File: candidate.hpp
// Copyright: 04/03/2016
//===============================================================
#ifndef CANDIDATE_HPP
#define CANDIDATE_HPP

#include "tools.hpp"
#include <string>
#include <gmpxx.h>

enum StatusType {ACTIVE, ELECTED, DROPPED};

class Candidate {
    friend class Vote;
private:
    string name;
    StatusType status;
    unsigned roundno;//round no. at which the candidate is chosen/dropped
    mpq_class tally; //rational number as total tally
    mpq_class alpha;
public:
    //constructor
    Candidate (string nm) : name(nm), status(ACTIVE), tally(0), alpha() {}
    ~Candidate () {} //destructor

    //set tally to zero for each round before counting total tally
    void unsetTally() { tally = 0; }
    //update status of the candidate
    StatusType updateStatus
        (unsigned const iround, mpq_class quota, mpq_class& mintally);
    //drop the candidate
    void drop(unsigned const iround);
    //print a candidate object, ptally==true:print tally, o/w print roundno
    ostream& print1(ostream& out) const; 
    ostream& print2(ostream& out) const; 
};

#endif
