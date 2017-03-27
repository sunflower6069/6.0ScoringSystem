//===============================================================
// Name: Election Object that Maintains All Information Describing
//      the Election
// Author: Xin Yan
// File: election.cpp
// Copyright: 04/03/2016
//===============================================================
#include "election.hpp"

//---------------------------------------------------------------
//import and parse CSV file, store data in appropriate variables
void Election::
import() {
    ifstream fin(infile);
    if(!fin) throw Fatal("Error opening file %s. Aborting.", &infile);

    //read the number of seats
    string ln;
    string fld;
    getline(fin, ln);
    if(!fin.good()) throw Fatal("I/O error while reading %s. Aborting.", &infile);
    istringstream sin;
    sin.str(ln); 
    getline(sin, fld, ',');//check if the 1st field of 1st line contains 'Seats'
    if(fld.find("Seats") == std::string::npos)
        throw Fatal("The first line does not contain 'Seats'. Aborting.");
    sin >> vacancy;
    if(!sin.good()) throw Fatal("Error while reading number of seats. Aborting");
    //read the number of candidates
    getline(fin, ln);
    if(!fin.good()) throw Fatal("I/O error while reading %s. Aborting.", &infile);
    sin.str(ln); 
    getline(sin, fld, ',');//check if the 1st field of 2nd line contains 'Candidates'
    if(fld.find("Candidates") == std::string::npos)
        throw Fatal("The 2nd line does not contain 'Candidates'. Aborting.");
    sin >> nactive;
    if(!sin.good()) throw Fatal("Error while reading number of candidates. Aborting");
    //read the names of candidates
    getline(fin, ln);
    if(!fin.good()) throw Fatal("I/O error while reading %s. Aborting.", &infile);
    sin.str(ln);
    unsigned icand = 0;
    do {
        getline(sin, fld, ',');
        if(!sin.fail()) {
            Candidate* cand = new Candidate(fld);
            myCands.push_back(cand);
            icand++;
        }
    } while(sin.good());
    if(!sin.eof()) throw Fatal("I/O error while reading candidate names.");
    if(icand != nactive) throw Fatal("Wrong number of candidate names.");
    //read ballots 
    unsigned ordinal;
    char c1;
    unsigned iball = 0;
    vector<unsigned> goodball;//vector to keep track of bad ballots
    do {//for each ballot
        vector<Vote*> myVotes;
        getline(fin, ln);
        if(!fin.fail()) {
            iball++;
            istringstream sin(ln);
            icand = 0;
            do {//for each vote
                sin >> ordinal;
                if (!sin.fail()) {
                    Vote* vt = new Vote(myCands[icand], ordinal);
                    myVotes.push_back(vt);
                    icand++;
                }
                sin >> c1;//read one char after the ordinal
                if(c1 != ',') break;
            } while(sin.good());
            //check for validity of ballot
            if(!sin.eof() || (icand != nactive)) { 
                cerr << "*** Ballot " << iball << " improperly marked -- IGNORED\n";
                continue;//read the next ballot
            }
            //construct a Ballot obj
            Ballot* ball = new Ballot(myVotes);
            if (ball->checkOrdinals(iball)) { 
                myBalls.push_back(ball); 
                goodball.push_back(iball);
            }
            else { 
                delete ball; 
            }
        }
    } while(fin.good());
    if(!fin.eof()) throw Fatal ("I/O error while reading ballots.");
    fin.close();
    //set quota
    quota = myBalls.size()/(vacancy + 1) + 1;
    //print imported data
    out << "Number of seats=" << vacancy << "\n";
    out << "Number of candidates=" << nactive << "\n";
    out << "Number of ballots=" << myBalls.size() << "\n";
    out << "Quota=" << quota << "\n";
    //print the initial ballot
    for (iball=0; iball<myBalls.size(); iball++) { 
        out << "Ballot #" << goodball[iball] << ":\n";
        out << (*myBalls[iball]);
    }
    out << endl;
    out << "--------------------\n";
    out << "Counting the Ballots\n";
    out << "--------------------\n";
}

//--------------------------------------------------------------
// Function to Perform One Round of Election
void Election::
electRound (unsigned const iround) {
    out << "Round " << iround << ": numSeats=" << vacancy << \
        ", numActive=" << nactive << "\n";
    // counting the total tally for each candidate
    for (Candidate* cand : myCands) { cand->unsetTally(); };
    for (Ballot* ball : myBalls) { ball->findFavor(); }
    // determine the status of each candidate
    mpq_class mintally (myBalls.size());//initialize mintally as the largest total tally 
    //that a candidate can get
    StatusType st;
    unsigned id = 0;//first candidate with the smallest total tally
    bool elected = false;//any candidate being elected
    for (unsigned icand=0; icand < myCands.size(); icand++) {
        st = myCands[icand]->updateStatus(iround, quota, mintally);
        if (st == ELECTED) {//cand is elected
            vacancy--;
            nactive--;
            elected = true;
            myCands[icand]->print1(out);
        }
        else if (st == DROPPED) {
            id = icand;
        }
    }
    if (!elected) {//if no candidate have been elected
        myCands[id]->drop(iround);//drop the first candidate with the smallest tally
        nactive--;
        myCands[id]->print1(out);
    }
    // Update values of ballots
    for (Ballot* ball : myBalls) { ball->updateValue(); }
}

//--------------------------------------------------------------
// Function to perform a sequence of elections
void Election::
electSequence () {
    printBall();
    unsigned iround = 0;
    while ((vacancy != 0) && (nactive != 0)) {
        iround++;
        electRound(iround);
    }
    printFinal();
}

//--------------------------------------------------------------
// Function to print the election results
void Election::
printBall () const {
}

void Election::
printFinal () {
    out << "\n------------------\n";
    out << "Elected Candidates\n";
    out << "------------------\n";
    for (Candidate* cand : myCands) { cand->print2(out); }
}
