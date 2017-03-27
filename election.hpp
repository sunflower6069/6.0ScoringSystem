//===============================================================
// Name: Election Object that Maintains All Information Describing
//      the Election
// Author: Xin Yan
// File: election.hpp
// Copyright: 04/03/2016
//===============================================================
#ifndef ELECTION_HPP
#define ELECTION_HPP

#include "tools.hpp"
#include "vote.hpp"
#include "ballot.hpp"
#include "candidate.hpp"
#include <vector>
#include <string>
#include <gmpxx.h>

class Election {
private:
    string infile;
    ostream& out;
    unsigned vacancy;
    unsigned nactive;
    vector<Candidate*> myCands;
    vector<Ballot*> myBalls;
    unsigned quota;
    
    void printBall () const;//print initial ballots
    void printFinal (); //print final election results
public:
    Election (const string& infl, ostream& outfl) ://constructor
        infile(infl), out(outfl) {}
    ~Election();//destructor

    void import ();//read the election data
    void electRound (unsigned const iround); //perform one round of election 
    void electSequence (); //perform a sequence of elections
};

inline Election:: 
~Election () {
    for (Candidate* cand : myCands) {
        delete cand;
    }
    for (Ballot* ball : myBalls) {
        delete ball;
    }
}

#endif
