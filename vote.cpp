//===============================================================
// Name: Vote Object Representing a Candidate and an Ordinal NO.
// Author: Xin Yan
// File: vote.cpp
// Copyright: 04/03/2016
// ==============================================================
#include "vote.hpp"
#include <iomanip>

//---------------------------------------------------------------
//add value to the candidate's total tally
void Vote::
addTally (mpq_class value) {
    cand->tally = cand->tally + value;
}

//---------------------------------------------------------------
//print a human-readable representation of vote object
ostream& Vote::
print (ostream& out) const {
    out << right << setw(4) << ordinal << ": "; 
    out << left << setw(16) << cand->name;
    return out;
}

