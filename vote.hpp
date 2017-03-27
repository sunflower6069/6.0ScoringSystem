//===============================================================
// Name: Vote Object Representing a Candidate and an Ordinal NO.
// Author: Xin Yan
// File: vote.hpp
// Copyright: 04/03/2016
// ==============================================================
#ifndef VOTE_HPP
#define VOTE_HPP

#include "tools.hpp"
#include "candidate.hpp"
#include <string>
#include <gmpxx.h>

class Vote {
private:
    Candidate* cand;
    unsigned ordinal;
public:
    Vote(Candidate* c, unsigned ord) : cand(c), ordinal(ord) {} //constructor
    ~Vote() { cand = nullptr; } //destructor

    unsigned getOrd() const { return ordinal; } //getter function of ordinal
    void addTally(mpq_class value);//add value to the candidate total tally
    StatusType getStatus() const { return cand->status; }//getter function for status
    mpq_class getAlpha() const { return cand->alpha; }//getter function for alpha value
    ostream& print(ostream& out) const;//print a vote object
};

//--------------------------------------------------------------
//inline function defining output operator
inline ostream& operator<<(ostream& out, const Vote& vt) {
    return vt.print(out);
}

#endif
