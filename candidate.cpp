//===============================================================
// Name: Candidate Object Representing a Single Candidate
// Author: Xin Yan
// File: candidate.hpp
// Copyright: 04/03/2016
//===============================================================
#include "candidate.hpp"
#include <iomanip>

//---------------------------------------------------------------
// Update status of the candidate
StatusType Candidate:://1-elected; 2-mintally; 0-others
updateStatus 
(unsigned const iround, mpq_class quota, mpq_class& mintally) {
    if (status == ACTIVE) {
        if (tally >= quota) {
            status = ELECTED;
            roundno = iround;
            alpha = quota / tally;
            return ELECTED;
        }
        else {
            if (tally < mintally) {
                mintally = tally;
                return DROPPED;
            }
            return ACTIVE;
        }
    }
    else { return ACTIVE; }
}

//---------------------------------------------------------------
// Drop the candidate
void Candidate::
drop (unsigned const iround) {
    status = DROPPED;
    roundno = iround;
}

//---------------------------------------------------------------
// Printing the results of a candidate with tally number
ostream& Candidate::
print1 (ostream& out) const {
    if (status == ELECTED) { out << "   [ELECTED] "; }
    else if (status == DROPPED) { out << "   [DROPPED] "; }
    out << setw(17) << std::left << name;
    out << "with tally (" << fixed << setprecision(6) << tally.get_d() 
        << " = " << tally.get_num();
    mpz_class den (tally.get_den());
    if (cmp(den,1) != 0) {
        out << "/" << tally.get_den(); 
    }
    out << ")\n";
    return out;
}

//---------------------------------------------------------------
// Printing the final results of the election
ostream& Candidate::
print2 (ostream& out) const {
    if (status == ELECTED) { 
        out << " [ELECTED] " << setw(17) << name << "in round " << roundno << "\n";
    }
    return out;
}
