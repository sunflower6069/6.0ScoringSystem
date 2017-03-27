/*
***********************************************
*  CPSC427 Object Oriented Programming        *
*     PSet 4: Single Transferrable Vote (STV) *      
*             Voting Program                  *      
*     Author: Xin Yan                         *
*     Date:  04/03/2016                       *
*     Credit: Part of the code was adopted    *
*     from Alice & Michael Fischer            *
***********************************************
*/
#include "tools.hpp"
#include "election.hpp"
using namespace std;

//-------------------------------------------------------------------
//main function for aboutme program that executes the program and 
//handles exceptions
//
int main(int argc, char* argv[]) {
    void run(int argc, char* argv[]);
    banner();
    try {
        run(argc, argv);
    }
    catch(Fatal& e) {
        cerr << "Catching Fatal exception\n" << e.what() << endl;
    }
    catch(...) {
        cerr << "Uncaught exception" << endl;
    }
    bye();
}

//--------------------------------------------------------------------
//read name & year of birth, output age 
//
void run(int argc, char* argv[]) {
    if (argc != 2) 
        throw Fatal("Wrong number of arguments. Usage: '%s' file.csv", argv[0]);
    //ofstream outfl("output.out");
    Election elect = Election(argv[1], cout);
    elect.import();
    elect.electSequence();
    //outfl << soh; 
    //outfl.close();
}

/*
---------------------------------------------------------------
 Example output 1 with election.csv as input:
---------------------------------------------------------------

---------------------------------------------------------------
    Xin Yan
    CPSC 427a/527a
    Sun Apr 10 2016 18:05:45
---------------------------------------------------------------
Number of seats=6
Number of candidates=20
Number of ballots=20
Quota=3
Ballot #1:
   1: Shirley Kindel     2: Ignacio Mccree     3: Loyce Mcdorman     4: Minna Wardle       5: Gregory Risser  
   6: Natacha August     7: Maren Spake        8: Keisha Jansen      9: Richard Periera   10: Rosaline Recker 
  11: Rosetta Mcinnis   12: Raleigh Blais     13: Cordelia Power    14: Youlanda Sera     15: Elva Alfonso    
  16: Katherin Mchenry  17: Elke Beckford     18: Tressa Hessler    19: Juliana Lalonde   20: Wyatt Ferrigno  
Ballot #2:
   1: Ignacio Mccree     2: Minna Wardle       3: Natacha August     4: Raleigh Blais      5: Loyce Mcdorman  
   6: Rosetta Mcinnis    7: Cordelia Power     8: Juliana Lalonde    9: Richard Periera   10: Shirley Kindel  
  11: Keisha Jansen     12: Maren Spake       13: Katherin Mchenry  14: Youlanda Sera     15: Tressa Hessler  
  16: Rosaline Recker   17: Elke Beckford     18: Wyatt Ferrigno    19: Gregory Risser    20: Elva Alfonso    
Ballot #3:
   1: Loyce Mcdorman     2: Shirley Kindel     3: Natacha August     4: Ignacio Mccree     5: Rosetta Mcinnis 
   6: Minna Wardle       7: Maren Spake        8: Richard Periera    9: Keisha Jansen     10: Cordelia Power  
  11: Elke Beckford     12: Raleigh Blais     13: Juliana Lalonde   14: Wyatt Ferrigno    15: Gregory Risser  
  16: Youlanda Sera     17: Tressa Hessler    18: Elva Alfonso      19: Rosaline Recker   20: Katherin Mchenry
Ballot #4:
   1: Minna Wardle       2: Ignacio Mccree     3: Loyce Mcdorman     4: Gregory Risser     5: Rosetta Mcinnis 
   6: Cordelia Power     7: Natacha August     8: Richard Periera    9: Shirley Kindel    10: Maren Spake     
  11: Youlanda Sera     12: Raleigh Blais     13: Rosaline Recker   14: Elke Beckford     15: Keisha Jansen   
  16: Wyatt Ferrigno    17: Tressa Hessler    18: Katherin Mchenry  19: Juliana Lalonde   20: Elva Alfonso    
Ballot #5:
   1: Ignacio Mccree     2: Minna Wardle       3: Loyce Mcdorman     4: Rosetta Mcinnis    5: Maren Spake     
   6: Elke Beckford      7: Keisha Jansen      8: Natacha August     9: Cordelia Power    10: Rosaline Recker 
  11: Tressa Hessler    12: Youlanda Sera     13: Shirley Kindel    14: Wyatt Ferrigno    15: Richard Periera 
  16: Gregory Risser    17: Juliana Lalonde   18: Katherin Mchenry  19: Raleigh Blais     20: Elva Alfonso    
Ballot #6:
   1: Cordelia Power     2: Maren Spake        3: Natacha August     4: Ignacio Mccree     5: Minna Wardle    
   6: Shirley Kindel     7: Loyce Mcdorman     8: Gregory Risser     9: Rosetta Mcinnis   10: Richard Periera 
  11: Keisha Jansen     12: Youlanda Sera     13: Juliana Lalonde   14: Raleigh Blais     15: Elva Alfonso    
  16: Rosaline Recker   17: Elke Beckford     18: Tressa Hessler    19: Katherin Mchenry  20: Wyatt Ferrigno  
Ballot #7:
   1: Maren Spake        2: Loyce Mcdorman     3: Shirley Kindel     4: Natacha August     5: Gregory Risser  
   6: Minna Wardle       7: Elke Beckford      8: Cordelia Power     9: Keisha Jansen     10: Rosetta Mcinnis 
  11: Ignacio Mccree    12: Youlanda Sera     13: Richard Periera   14: Rosaline Recker   15: Raleigh Blais   
  16: Katherin Mchenry  17: Juliana Lalonde   18: Elva Alfonso      19: Wyatt Ferrigno    20: Tressa Hessler  
Ballot #8:
   1: Natacha August     2: Loyce Mcdorman     3: Ignacio Mccree     4: Rosetta Mcinnis    5: Keisha Jansen   
   6: Minna Wardle       7: Maren Spake        8: Shirley Kindel     9: Cordelia Power    10: Gregory Risser  
  11: Youlanda Sera     12: Juliana Lalonde   13: Raleigh Blais     14: Richard Periera   15: Wyatt Ferrigno  
  16: Elva Alfonso      17: Elke Beckford     18: Katherin Mchenry  19: Tressa Hessler    20: Rosaline Recker 
Ballot #9:
   1: Shirley Kindel     2: Minna Wardle       3: Rosetta Mcinnis    4: Cordelia Power     5: Loyce Mcdorman  
   6: Ignacio Mccree     7: Keisha Jansen      8: Gregory Risser     9: Raleigh Blais     10: Maren Spake     
  11: Natacha August    12: Richard Periera   13: Youlanda Sera     14: Rosaline Recker   15: Juliana Lalonde 
  16: Elva Alfonso      17: Elke Beckford     18: Wyatt Ferrigno    19: Katherin Mchenry  20: Tressa Hessler  
Ballot #10:
   1: Shirley Kindel     2: Natacha August     3: Minna Wardle       4: Ignacio Mccree     5: Loyce Mcdorman  
   6: Keisha Jansen      7: Youlanda Sera      8: Maren Spake        9: Cordelia Power    10: Gregory Risser  
  11: Richard Periera   12: Elke Beckford     13: Wyatt Ferrigno    14: Tressa Hessler    15: Rosetta Mcinnis 
  16: Rosaline Recker   17: Juliana Lalonde   18: Raleigh Blais     19: Katherin Mchenry  20: Elva Alfonso    
Ballot #11:
   1: Minna Wardle       2: Ignacio Mccree     3: Loyce Mcdorman     4: Richard Periera    5: Natacha August  
   6: Shirley Kindel     7: Elke Beckford      8: Maren Spake        9: Youlanda Sera     10: Cordelia Power  
  11: Keisha Jansen     12: Raleigh Blais     13: Gregory Risser    14: Rosaline Recker   15: Rosetta Mcinnis 
  16: Tressa Hessler    17: Juliana Lalonde   18: Katherin Mchenry  19: Wyatt Ferrigno    20: Elva Alfonso    
Ballot #12:
   1: Minna Wardle       2: Loyce Mcdorman     3: Rosetta Mcinnis    4: Natacha August     5: Ignacio Mccree  
   6: Shirley Kindel     7: Maren Spake        8: Youlanda Sera      9: Richard Periera   10: Gregory Risser  
  11: Elva Alfonso      12: Juliana Lalonde   13: Katherin Mchenry  14: Keisha Jansen     15: Cordelia Power  
  16: Wyatt Ferrigno    17: Raleigh Blais     18: Rosaline Recker   19: Elke Beckford     20: Tressa Hessler  
Ballot #13:
   1: Minna Wardle       2: Loyce Mcdorman     3: Cordelia Power     4: Natacha August     5: Rosetta Mcinnis 
   6: Keisha Jansen      7: Richard Periera    8: Youlanda Sera      9: Maren Spake       10: Ignacio Mccree  
  11: Shirley Kindel    12: Raleigh Blais     13: Juliana Lalonde   14: Elke Beckford     15: Wyatt Ferrigno  
  16: Katherin Mchenry  17: Gregory Risser    18: Rosaline Recker   19: Tressa Hessler    20: Elva Alfonso    
Ballot #14:
   1: Natacha August     2: Cordelia Power     3: Ignacio Mccree     4: Maren Spake        5: Shirley Kindel  
   6: Loyce Mcdorman     7: Minna Wardle       8: Gregory Risser     9: Elva Alfonso      10: Keisha Jansen   
  11: Rosaline Recker   12: Rosetta Mcinnis   13: Raleigh Blais     14: Richard Periera   15: Wyatt Ferrigno  
  16: Juliana Lalonde   17: Youlanda Sera     18: Katherin Mchenry  19: Elke Beckford     20: Tressa Hessler  
Ballot #15:
   1: Minna Wardle       2: Ignacio Mccree     3: Loyce Mcdorman     4: Natacha August     5: Shirley Kindel  
   6: Maren Spake        7: Keisha Jansen      8: Raleigh Blais      9: Youlanda Sera     10: Richard Periera 
  11: Gregory Risser    12: Juliana Lalonde   13: Elke Beckford     14: Rosetta Mcinnis   15: Cordelia Power  
  16: Katherin Mchenry  17: Rosaline Recker   18: Wyatt Ferrigno    19: Elva Alfonso      20: Tressa Hessler  
Ballot #16:
   1: Shirley Kindel     2: Ignacio Mccree     3: Loyce Mcdorman     4: Youlanda Sera      5: Natacha August  
   6: Raleigh Blais      7: Keisha Jansen      8: Cordelia Power     9: Richard Periera   10: Minna Wardle    
  11: Maren Spake       12: Rosaline Recker   13: Rosetta Mcinnis   14: Wyatt Ferrigno    15: Elke Beckford   
  16: Gregory Risser    17: Elva Alfonso      18: Juliana Lalonde   19: Tressa Hessler    20: Katherin Mchenry
Ballot #17:
   1: Loyce Mcdorman     2: Minna Wardle       3: Natacha August     4: Ignacio Mccree     5: Shirley Kindel  
   6: Cordelia Power     7: Keisha Jansen      8: Rosetta Mcinnis    9: Maren Spake       10: Richard Periera 
  11: Raleigh Blais     12: Elke Beckford     13: Gregory Risser    14: Youlanda Sera     15: Juliana Lalonde 
  16: Rosaline Recker   17: Elva Alfonso      18: Wyatt Ferrigno    19: Tressa Hessler    20: Katherin Mchenry
Ballot #18:
   1: Minna Wardle       2: Natacha August     3: Rosetta Mcinnis    4: Maren Spake        5: Shirley Kindel  
   6: Ignacio Mccree     7: Gregory Risser     8: Loyce Mcdorman     9: Richard Periera   10: Cordelia Power  
  11: Raleigh Blais     12: Keisha Jansen     13: Katherin Mchenry  14: Rosaline Recker   15: Elke Beckford   
  16: Tressa Hessler    17: Youlanda Sera     18: Elva Alfonso      19: Wyatt Ferrigno    20: Juliana Lalonde 
Ballot #19:
   1: Ignacio Mccree     2: Natacha August     3: Keisha Jansen      4: Minna Wardle       5: Loyce Mcdorman  
   6: Raleigh Blais      7: Cordelia Power     8: Gregory Risser     9: Rosetta Mcinnis   10: Shirley Kindel  
  11: Maren Spake       12: Richard Periera   13: Juliana Lalonde   14: Katherin Mchenry  15: Tressa Hessler  
  16: Youlanda Sera     17: Wyatt Ferrigno    18: Elke Beckford     19: Elva Alfonso      20: Rosaline Recker 
Ballot #20:
   1: Ignacio Mccree     2: Rosetta Mcinnis    3: Loyce Mcdorman     4: Shirley Kindel     5: Maren Spake     
   6: Minna Wardle       7: Rosaline Recker    8: Keisha Jansen      9: Cordelia Power    10: Natacha August  
  11: Elke Beckford     12: Richard Periera   13: Raleigh Blais     14: Katherin Mchenry  15: Tressa Hessler  
  16: Gregory Risser    17: Juliana Lalonde   18: Wyatt Ferrigno    19: Youlanda Sera     20: Elva Alfonso    

--------------------
Counting the Ballots
--------------------
Round 1: numSeats=6, numActive=20
   [ELECTED] Ignacio Mccree   with tally (4.000000 = 4)
   [ELECTED] Minna Wardle     with tally (6.000000 = 6)
   [ELECTED] Shirley Kindel   with tally (4.000000 = 4)
Round 2: numSeats=3, numActive=17
   [ELECTED] Loyce Mcdorman   with tally (5.250000 = 21/4)
   [ELECTED] Natacha August   with tally (3.250000 = 13/4)
Round 3: numSeats=1, numActive=15
   [DROPPED] Elke Beckford    with tally (0.000000 = 0)
Round 4: numSeats=1, numActive=14
   [DROPPED] Elva Alfonso     with tally (0.000000 = 0)
Round 5: numSeats=1, numActive=13
   [DROPPED] Juliana Lalonde  with tally (0.000000 = 0)
Round 6: numSeats=1, numActive=12
   [DROPPED] Katherin Mchenry with tally (0.000000 = 0)
Round 7: numSeats=1, numActive=11
   [DROPPED] Rosaline Recker  with tally (0.000000 = 0)
Round 8: numSeats=1, numActive=10
   [DROPPED] Tressa Hessler   with tally (0.000000 = 0)
Round 9: numSeats=1, numActive=9
   [DROPPED] Wyatt Ferrigno   with tally (0.000000 = 0)
Round 10: numSeats=1, numActive=8
   [DROPPED] Raleigh Blais    with tally (0.019231 = 1/52)
Round 11: numSeats=1, numActive=7
   [DROPPED] Keisha Jansen    with tally (0.038462 = 1/26)
Round 12: numSeats=1, numActive=6
   [DROPPED] Youlanda Sera    with tally (0.126374 = 23/182)
Round 13: numSeats=1, numActive=5
   [DROPPED] Richard Periera  with tally (0.214286 = 3/14)
Round 14: numSeats=1, numActive=4
   [DROPPED] Gregory Risser   with tally (0.321429 = 9/28)
Round 15: numSeats=1, numActive=3
   [DROPPED] Maren Spake      with tally (1.554945 = 283/182)
Round 16: numSeats=1, numActive=2
   [ELECTED] Cordelia Power   with tally (3.079670 = 1121/364)

------------------
Elected Candidates
------------------
 [ELECTED] Cordelia Power   in round 16
 [ELECTED] Ignacio Mccree   in round 1
 [ELECTED] Loyce Mcdorman   in round 2
 [ELECTED] Minna Wardle     in round 1
 [ELECTED] Natacha August   in round 2
 [ELECTED] Shirley Kindel   in round 1

---------------------------------------------------------------
Normal termination.


---------------------------------------------------------------
 Example output 2 with election2.csv as input:
---------------------------------------------------------------

---------------------------------------------------------------
    Xin Yan
    CPSC 427a/527a
    Sun Apr 10 2016 18:07:24
---------------------------------------------------------------
*** Ballot 42 improperly marked -- IGNORED
Number of seats=6
Number of candidates=20
Number of ballots=49
Quota=8
Ballot #1:
   1: Loyce Mcdorman     2: Natacha August     3: Minna Wardle       4: Rosetta Mcinnis    5: Ignacio Mccree  
   6: Cordelia Power     7: Youlanda Sera      8: Shirley Kindel     9: Raleigh Blais     10: Keisha Jansen   
  11: Richard Periera   12: Elva Alfonso      13: Gregory Risser    14: Maren Spake       15: Katherin Mchenry
  16: Elke Beckford     17: Wyatt Ferrigno    18: Tressa Hessler    19: Rosaline Recker   20: Juliana Lalonde 
Ballot #2:
   1: Loyce Mcdorman     2: Minna Wardle       3: Gregory Risser     4: Shirley Kindel     5: Rosetta Mcinnis 
   6: Ignacio Mccree     7: Natacha August     8: Keisha Jansen      9: Youlanda Sera     10: Richard Periera 
  11: Maren Spake       12: Raleigh Blais     13: Cordelia Power    14: Elva Alfonso      15: Elke Beckford   
  16: Rosaline Recker   17: Tressa Hessler    18: Juliana Lalonde   19: Wyatt Ferrigno    20: Katherin Mchenry
Ballot #3:
   1: Loyce Mcdorman     2: Minna Wardle       3: Richard Periera    4: Shirley Kindel     5: Natacha August  
   6: Gregory Risser     7: Keisha Jansen      8: Maren Spake        9: Youlanda Sera     10: Ignacio Mccree  
  11: Tressa Hessler    12: Raleigh Blais     13: Rosetta Mcinnis   14: Cordelia Power    15: Rosaline Recker 
  16: Elva Alfonso      17: Elke Beckford     18: Katherin Mchenry  19: Wyatt Ferrigno    20: Juliana Lalonde 
Ballot #4:
   1: Loyce Mcdorman     2: Shirley Kindel     3: Minna Wardle       4: Maren Spake        5: Cordelia Power  
   6: Gregory Risser     7: Ignacio Mccree     8: Elva Alfonso       9: Rosetta Mcinnis   10: Natacha August  
  11: Richard Periera   12: Keisha Jansen     13: Youlanda Sera     14: Rosaline Recker   15: Tressa Hessler  
  16: Juliana Lalonde   17: Raleigh Blais     18: Elke Beckford     19: Katherin Mchenry  20: Wyatt Ferrigno  
Ballot #5:
   1: Minna Wardle       2: Shirley Kindel     3: Ignacio Mccree     4: Richard Periera    5: Loyce Mcdorman  
   6: Keisha Jansen      7: Rosetta Mcinnis    8: Raleigh Blais      9: Maren Spake       10: Katherin Mchenry
  11: Natacha August    12: Cordelia Power    13: Elke Beckford     14: Youlanda Sera     15: Juliana Lalonde 
  16: Gregory Risser    17: Elva Alfonso      18: Rosaline Recker   19: Tressa Hessler    20: Wyatt Ferrigno  
Ballot #6:
   1: Minna Wardle       2: Natacha August     3: Shirley Kindel     4: Ignacio Mccree     5: Cordelia Power  
   6: Loyce Mcdorman     7: Richard Periera    8: Rosetta Mcinnis    9: Rosaline Recker   10: Youlanda Sera   
  11: Maren Spake       12: Juliana Lalonde   13: Keisha Jansen     14: Elva Alfonso      15: Raleigh Blais   
  16: Tressa Hessler    17: Gregory Risser    18: Katherin Mchenry  19: Wyatt Ferrigno    20: Elke Beckford   
Ballot #7:
   1: Minna Wardle       2: Loyce Mcdorman     3: Natacha August     4: Ignacio Mccree     5: Rosetta Mcinnis 
   6: Shirley Kindel     7: Cordelia Power     8: Keisha Jansen      9: Richard Periera   10: Maren Spake     
  11: Youlanda Sera     12: Elke Beckford     13: Rosaline Recker   14: Juliana Lalonde   15: Elva Alfonso    
  16: Gregory Risser    17: Raleigh Blais     18: Tressa Hessler    19: Katherin Mchenry  20: Wyatt Ferrigno  
Ballot #8:
   1: Ignacio Mccree     2: Minna Wardle       3: Maren Spake        4: Keisha Jansen      5: Cordelia Power  
   6: Natacha August     7: Shirley Kindel     8: Rosetta Mcinnis    9: Richard Periera   10: Loyce Mcdorman  
  11: Raleigh Blais     12: Rosaline Recker   13: Youlanda Sera     14: Elke Beckford     15: Wyatt Ferrigno  
  16: Gregory Risser    17: Elva Alfonso      18: Katherin Mchenry  19: Juliana Lalonde   20: Tressa Hessler  
Ballot #9:
   1: Minna Wardle       2: Ignacio Mccree     3: Loyce Mcdorman     4: Natacha August     5: Youlanda Sera   
   6: Maren Spake        7: Richard Periera    8: Keisha Jansen      9: Rosetta Mcinnis   10: Shirley Kindel  
  11: Tressa Hessler    12: Wyatt Ferrigno    13: Elke Beckford     14: Raleigh Blais     15: Cordelia Power  
  16: Katherin Mchenry  17: Gregory Risser    18: Rosaline Recker   19: Juliana Lalonde   20: Elva Alfonso    
Ballot #10:
   1: Loyce Mcdorman     2: Ignacio Mccree     3: Minna Wardle       4: Natacha August     5: Maren Spake     
   6: Rosetta Mcinnis    7: Youlanda Sera      8: Keisha Jansen      9: Gregory Risser    10: Shirley Kindel  
  11: Cordelia Power    12: Elke Beckford     13: Richard Periera   14: Raleigh Blais     15: Tressa Hessler  
  16: Katherin Mchenry  17: Rosaline Recker   18: Wyatt Ferrigno    19: Juliana Lalonde   20: Elva Alfonso    
Ballot #11:
   1: Ignacio Mccree     2: Loyce Mcdorman     3: Minna Wardle       4: Cordelia Power     5: Keisha Jansen   
   6: Rosetta Mcinnis    7: Shirley Kindel     8: Elke Beckford      9: Youlanda Sera     10: Richard Periera 
  11: Natacha August    12: Gregory Risser    13: Juliana Lalonde   14: Rosaline Recker   15: Maren Spake     
  16: Elva Alfonso      17: Tressa Hessler    18: Raleigh Blais     19: Katherin Mchenry  20: Wyatt Ferrigno  
Ballot #12:
   1: Shirley Kindel     2: Minna Wardle       3: Maren Spake        4: Cordelia Power     5: Natacha August  
   6: Loyce Mcdorman     7: Ignacio Mccree     8: Richard Periera    9: Rosetta Mcinnis   10: Youlanda Sera   
  11: Elke Beckford     12: Keisha Jansen     13: Rosaline Recker   14: Raleigh Blais     15: Tressa Hessler  
  16: Juliana Lalonde   17: Wyatt Ferrigno    18: Gregory Risser    19: Elva Alfonso      20: Katherin Mchenry
Ballot #13:
   1: Rosetta Mcinnis    2: Minna Wardle       3: Ignacio Mccree     4: Shirley Kindel     5: Natacha August  
   6: Loyce Mcdorman     7: Keisha Jansen      8: Youlanda Sera      9: Maren Spake       10: Rosaline Recker 
  11: Cordelia Power    12: Richard Periera   13: Raleigh Blais     14: Katherin Mchenry  15: Gregory Risser  
  16: Elke Beckford     17: Wyatt Ferrigno    18: Tressa Hessler    19: Elva Alfonso      20: Juliana Lalonde 
Ballot #14:
   1: Minna Wardle       2: Loyce Mcdorman     3: Cordelia Power     4: Richard Periera    5: Keisha Jansen   
   6: Maren Spake        7: Ignacio Mccree     8: Natacha August     9: Rosetta Mcinnis   10: Elke Beckford   
  11: Raleigh Blais     12: Shirley Kindel    13: Gregory Risser    14: Youlanda Sera     15: Juliana Lalonde 
  16: Elva Alfonso      17: Rosaline Recker   18: Katherin Mchenry  19: Tressa Hessler    20: Wyatt Ferrigno  
Ballot #15:
   1: Shirley Kindel     2: Minna Wardle       3: Ignacio Mccree     4: Loyce Mcdorman     5: Maren Spake     
   6: Cordelia Power     7: Natacha August     8: Elke Beckford      9: Richard Periera   10: Rosetta Mcinnis 
  11: Keisha Jansen     12: Youlanda Sera     13: Rosaline Recker   14: Gregory Risser    15: Wyatt Ferrigno  
  16: Katherin Mchenry  17: Elva Alfonso      18: Raleigh Blais     19: Juliana Lalonde   20: Tressa Hessler  
Ballot #16:
   1: Minna Wardle       2: Shirley Kindel     3: Keisha Jansen      4: Ignacio Mccree     5: Elke Beckford   
   6: Natacha August     7: Maren Spake        8: Cordelia Power     9: Gregory Risser    10: Raleigh Blais   
  11: Loyce Mcdorman    12: Youlanda Sera     13: Rosaline Recker   14: Rosetta Mcinnis   15: Tressa Hessler  
  16: Richard Periera   17: Wyatt Ferrigno    18: Katherin Mchenry  19: Elva Alfonso      20: Juliana Lalonde 
Ballot #17:
   1: Loyce Mcdorman     2: Ignacio Mccree     3: Minna Wardle       4: Rosetta Mcinnis    5: Maren Spake     
   6: Natacha August     7: Shirley Kindel     8: Gregory Risser     9: Keisha Jansen     10: Richard Periera 
  11: Wyatt Ferrigno    12: Cordelia Power    13: Juliana Lalonde   14: Raleigh Blais     15: Rosaline Recker 
  16: Youlanda Sera     17: Elva Alfonso      18: Katherin Mchenry  19: Tressa Hessler    20: Elke Beckford   
Ballot #18:
   1: Ignacio Mccree     2: Youlanda Sera      3: Minna Wardle       4: Shirley Kindel     5: Cordelia Power  
   6: Natacha August     7: Loyce Mcdorman     8: Rosetta Mcinnis    9: Gregory Risser    10: Richard Periera 
  11: Rosaline Recker   12: Maren Spake       13: Elva Alfonso      14: Elke Beckford     15: Tressa Hessler  
  16: Juliana Lalonde   17: Keisha Jansen     18: Wyatt Ferrigno    19: Katherin Mchenry  20: Raleigh Blais   
Ballot #19:
   1: Loyce Mcdorman     2: Ignacio Mccree     3: Shirley Kindel     4: Minna Wardle       5: Youlanda Sera   
   6: Maren Spake        7: Cordelia Power     8: Keisha Jansen      9: Natacha August    10: Raleigh Blais   
  11: Rosetta Mcinnis   12: Rosaline Recker   13: Elke Beckford     14: Elva Alfonso      15: Richard Periera 
  16: Katherin Mchenry  17: Gregory Risser    18: Juliana Lalonde   19: Tressa Hessler    20: Wyatt Ferrigno  
Ballot #20:
   1: Ignacio Mccree     2: Loyce Mcdorman     3: Elke Beckford      4: Youlanda Sera      5: Natacha August  
   6: Minna Wardle       7: Rosetta Mcinnis    8: Keisha Jansen      9: Richard Periera   10: Shirley Kindel  
  11: Rosaline Recker   12: Juliana Lalonde   13: Cordelia Power    14: Maren Spake       15: Katherin Mchenry
  16: Elva Alfonso      17: Tressa Hessler    18: Raleigh Blais     19: Gregory Risser    20: Wyatt Ferrigno  
Ballot #21:
   1: Loyce Mcdorman     2: Natacha August     3: Maren Spake        4: Rosetta Mcinnis    5: Ignacio Mccree  
   6: Youlanda Sera      7: Minna Wardle       8: Elva Alfonso       9: Richard Periera   10: Shirley Kindel  
  11: Cordelia Power    12: Gregory Risser    13: Katherin Mchenry  14: Juliana Lalonde   15: Elke Beckford   
  16: Rosaline Recker   17: Raleigh Blais     18: Keisha Jansen     19: Wyatt Ferrigno    20: Tressa Hessler  
Ballot #22:
   1: Ignacio Mccree     2: Loyce Mcdorman     3: Natacha August     4: Keisha Jansen      5: Shirley Kindel  
   6: Minna Wardle       7: Cordelia Power     8: Rosetta Mcinnis    9: Richard Periera   10: Youlanda Sera   
  11: Maren Spake       12: Rosaline Recker   13: Elke Beckford     14: Raleigh Blais     15: Katherin Mchenry
  16: Gregory Risser    17: Tressa Hessler    18: Elva Alfonso      19: Wyatt Ferrigno    20: Juliana Lalonde 
Ballot #23:
   1: Minna Wardle       2: Ignacio Mccree     3: Rosetta Mcinnis    4: Natacha August     5: Maren Spake     
   6: Cordelia Power     7: Loyce Mcdorman     8: Gregory Risser     9: Shirley Kindel    10: Youlanda Sera   
  11: Rosaline Recker   12: Raleigh Blais     13: Tressa Hessler    14: Katherin Mchenry  15: Elva Alfonso    
  16: Richard Periera   17: Keisha Jansen     18: Juliana Lalonde   19: Elke Beckford     20: Wyatt Ferrigno  
Ballot #24:
   1: Minna Wardle       2: Ignacio Mccree     3: Loyce Mcdorman     4: Rosetta Mcinnis    5: Natacha August  
   6: Maren Spake        7: Elke Beckford      8: Shirley Kindel     9: Keisha Jansen     10: Gregory Risser  
  11: Richard Periera   12: Youlanda Sera     13: Cordelia Power    14: Raleigh Blais     15: Tressa Hessler  
  16: Juliana Lalonde   17: Katherin Mchenry  18: Rosaline Recker   19: Elva Alfonso      20: Wyatt Ferrigno  
Ballot #25:
   1: Minna Wardle       2: Natacha August     3: Ignacio Mccree     4: Gregory Risser     5: Loyce Mcdorman  
   6: Shirley Kindel     7: Raleigh Blais      8: Elva Alfonso       9: Cordelia Power    10: Elke Beckford   
  11: Rosaline Recker   12: Richard Periera   13: Keisha Jansen     14: Rosetta Mcinnis   15: Youlanda Sera   
  16: Maren Spake       17: Juliana Lalonde   18: Katherin Mchenry  19: Tressa Hessler    20: Wyatt Ferrigno  
Ballot #26:
   1: Minna Wardle       2: Shirley Kindel     3: Ignacio Mccree     4: Natacha August     5: Youlanda Sera   
   6: Rosetta Mcinnis    7: Maren Spake        8: Cordelia Power     9: Gregory Risser    10: Elva Alfonso    
  11: Loyce Mcdorman    12: Rosaline Recker   13: Raleigh Blais     14: Elke Beckford     15: Keisha Jansen   
  16: Katherin Mchenry  17: Richard Periera   18: Tressa Hessler    19: Wyatt Ferrigno    20: Juliana Lalonde 
Ballot #27:
   1: Minna Wardle       2: Loyce Mcdorman     3: Natacha August     4: Keisha Jansen      5: Ignacio Mccree  
   6: Richard Periera    7: Shirley Kindel     8: Maren Spake        9: Youlanda Sera     10: Cordelia Power  
  11: Rosetta Mcinnis   12: Elke Beckford     13: Raleigh Blais     14: Rosaline Recker   15: Tressa Hessler  
  16: Gregory Risser    17: Wyatt Ferrigno    18: Juliana Lalonde   19: Katherin Mchenry  20: Elva Alfonso    
Ballot #28:
   1: Loyce Mcdorman     2: Natacha August     3: Rosetta Mcinnis    4: Shirley Kindel     5: Minna Wardle    
   6: Ignacio Mccree     7: Elva Alfonso       8: Cordelia Power     9: Wyatt Ferrigno    10: Gregory Risser  
  11: Maren Spake       12: Rosaline Recker   13: Richard Periera   14: Keisha Jansen     15: Raleigh Blais   
  16: Elke Beckford     17: Youlanda Sera     18: Juliana Lalonde   19: Katherin Mchenry  20: Tressa Hessler  
Ballot #29:
   1: Minna Wardle       2: Natacha August     3: Maren Spake        4: Ignacio Mccree     5: Loyce Mcdorman  
   6: Rosetta Mcinnis    7: Cordelia Power     8: Youlanda Sera      9: Raleigh Blais     10: Keisha Jansen   
  11: Richard Periera   12: Gregory Risser    13: Elke Beckford     14: Tressa Hessler    15: Rosaline Recker 
  16: Shirley Kindel    17: Juliana Lalonde   18: Elva Alfonso      19: Katherin Mchenry  20: Wyatt Ferrigno  
Ballot #30:
   1: Loyce Mcdorman     2: Minna Wardle       3: Shirley Kindel     4: Rosetta Mcinnis    5: Youlanda Sera   
   6: Natacha August     7: Juliana Lalonde    8: Ignacio Mccree     9: Cordelia Power    10: Keisha Jansen   
  11: Rosaline Recker   12: Maren Spake       13: Raleigh Blais     14: Richard Periera   15: Gregory Risser  
  16: Katherin Mchenry  17: Wyatt Ferrigno    18: Elva Alfonso      19: Elke Beckford     20: Tressa Hessler  
Ballot #31:
   1: Rosetta Mcinnis    2: Shirley Kindel     3: Cordelia Power     4: Minna Wardle       5: Natacha August  
   6: Gregory Risser     7: Keisha Jansen      8: Ignacio Mccree     9: Richard Periera   10: Loyce Mcdorman  
  11: Elke Beckford     12: Youlanda Sera     13: Maren Spake       14: Tressa Hessler    15: Rosaline Recker 
  16: Raleigh Blais     17: Juliana Lalonde   18: Katherin Mchenry  19: Elva Alfonso      20: Wyatt Ferrigno  
Ballot #32:
   1: Loyce Mcdorman     2: Shirley Kindel     3: Rosetta Mcinnis    4: Cordelia Power     5: Minna Wardle    
   6: Keisha Jansen      7: Youlanda Sera      8: Raleigh Blais      9: Natacha August    10: Richard Periera 
  11: Tressa Hessler    12: Ignacio Mccree    13: Juliana Lalonde   14: Maren Spake       15: Elke Beckford   
  16: Elva Alfonso      17: Gregory Risser    18: Wyatt Ferrigno    19: Rosaline Recker   20: Katherin Mchenry
Ballot #33:
   1: Loyce Mcdorman     2: Ignacio Mccree     3: Shirley Kindel     4: Natacha August     5: Maren Spake     
   6: Elke Beckford      7: Richard Periera    8: Minna Wardle       9: Rosetta Mcinnis   10: Cordelia Power  
  11: Youlanda Sera     12: Raleigh Blais     13: Elva Alfonso      14: Rosaline Recker   15: Gregory Risser  
  16: Keisha Jansen     17: Wyatt Ferrigno    18: Juliana Lalonde   19: Tressa Hessler    20: Katherin Mchenry
Ballot #34:
   1: Natacha August     2: Rosetta Mcinnis    3: Minna Wardle       4: Loyce Mcdorman     5: Maren Spake     
   6: Gregory Risser     7: Ignacio Mccree     8: Raleigh Blais      9: Youlanda Sera     10: Shirley Kindel  
  11: Rosaline Recker   12: Elke Beckford     13: Keisha Jansen     14: Richard Periera   15: Cordelia Power  
  16: Elva Alfonso      17: Katherin Mchenry  18: Tressa Hessler    19: Juliana Lalonde   20: Wyatt Ferrigno  
Ballot #35:
   1: Rosetta Mcinnis    2: Loyce Mcdorman     3: Minna Wardle       4: Natacha August     5: Shirley Kindel  
   6: Youlanda Sera      7: Gregory Risser     8: Maren Spake        9: Keisha Jansen     10: Ignacio Mccree  
  11: Raleigh Blais     12: Rosaline Recker   13: Cordelia Power    14: Richard Periera   15: Elke Beckford   
  16: Tressa Hessler    17: Juliana Lalonde   18: Elva Alfonso      19: Katherin Mchenry  20: Wyatt Ferrigno  
Ballot #36:
   1: Minna Wardle       2: Ignacio Mccree     3: Loyce Mcdorman     4: Cordelia Power     5: Keisha Jansen   
   6: Maren Spake        7: Natacha August     8: Rosetta Mcinnis    9: Raleigh Blais     10: Shirley Kindel  
  11: Youlanda Sera     12: Rosaline Recker   13: Richard Periera   14: Elke Beckford     15: Juliana Lalonde 
  16: Tressa Hessler    17: Gregory Risser    18: Elva Alfonso      19: Wyatt Ferrigno    20: Katherin Mchenry
Ballot #37:
   1: Loyce Mcdorman     2: Shirley Kindel     3: Ignacio Mccree     4: Raleigh Blais      5: Cordelia Power  
   6: Natacha August     7: Elke Beckford      8: Keisha Jansen      9: Minna Wardle      10: Youlanda Sera   
  11: Tressa Hessler    12: Richard Periera   13: Gregory Risser    14: Elva Alfonso      15: Rosetta Mcinnis 
  16: Rosaline Recker   17: Juliana Lalonde   18: Katherin Mchenry  19: Maren Spake       20: Wyatt Ferrigno  
Ballot #38:
   1: Natacha August     2: Minna Wardle       3: Loyce Mcdorman     4: Keisha Jansen      5: Cordelia Power  
   6: Ignacio Mccree     7: Youlanda Sera      8: Rosetta Mcinnis    9: Shirley Kindel    10: Juliana Lalonde 
  11: Raleigh Blais     12: Maren Spake       13: Gregory Risser    14: Richard Periera   15: Elva Alfonso    
  16: Rosaline Recker   17: Tressa Hessler    18: Elke Beckford     19: Wyatt Ferrigno    20: Katherin Mchenry
Ballot #39:
   1: Loyce Mcdorman     2: Minna Wardle       3: Ignacio Mccree     4: Gregory Risser     5: Rosetta Mcinnis 
   6: Shirley Kindel     7: Maren Spake        8: Natacha August     9: Cordelia Power    10: Juliana Lalonde 
  11: Elke Beckford     12: Keisha Jansen     13: Katherin Mchenry  14: Raleigh Blais     15: Elva Alfonso    
  16: Richard Periera   17: Youlanda Sera     18: Rosaline Recker   19: Tressa Hessler    20: Wyatt Ferrigno  
Ballot #40:
   1: Natacha August     2: Ignacio Mccree     3: Cordelia Power     4: Maren Spake        5: Loyce Mcdorman  
   6: Minna Wardle       7: Shirley Kindel     8: Raleigh Blais      9: Gregory Risser    10: Keisha Jansen   
  11: Rosetta Mcinnis   12: Richard Periera   13: Elke Beckford     14: Rosaline Recker   15: Youlanda Sera   
  16: Juliana Lalonde   17: Wyatt Ferrigno    18: Katherin Mchenry  19: Tressa Hessler    20: Elva Alfonso    
Ballot #41:
   1: Ignacio Mccree     2: Natacha August     3: Minna Wardle       4: Shirley Kindel     5: Rosetta Mcinnis 
   6: Cordelia Power     7: Keisha Jansen      8: Elke Beckford      9: Loyce Mcdorman    10: Maren Spake     
  11: Elva Alfonso      12: Raleigh Blais     13: Richard Periera   14: Youlanda Sera     15: Gregory Risser  
  16: Rosaline Recker   17: Juliana Lalonde   18: Wyatt Ferrigno    19: Katherin Mchenry  20: Tressa Hessler  
Ballot #43:
   1: Loyce Mcdorman     2: Shirley Kindel     3: Ignacio Mccree     4: Cordelia Power     5: Rosetta Mcinnis 
   6: Minna Wardle       7: Natacha August     8: Youlanda Sera      9: Maren Spake       10: Raleigh Blais   
  11: Rosaline Recker   12: Richard Periera   13: Elva Alfonso      14: Elke Beckford     15: Gregory Risser  
  16: Katherin Mchenry  17: Keisha Jansen     18: Tressa Hessler    19: Juliana Lalonde   20: Wyatt Ferrigno  
Ballot #44:
   1: Ignacio Mccree     2: Loyce Mcdorman     3: Natacha August     4: Minna Wardle       5: Keisha Jansen   
   6: Richard Periera    7: Rosetta Mcinnis    8: Raleigh Blais      9: Cordelia Power    10: Shirley Kindel  
  11: Maren Spake       12: Juliana Lalonde   13: Rosaline Recker   14: Katherin Mchenry  15: Elva Alfonso    
  16: Youlanda Sera     17: Tressa Hessler    18: Gregory Risser    19: Wyatt Ferrigno    20: Elke Beckford   
Ballot #45:
   1: Minna Wardle       2: Natacha August     3: Rosetta Mcinnis    4: Cordelia Power     5: Shirley Kindel  
   6: Ignacio Mccree     7: Loyce Mcdorman     8: Gregory Risser     9: Richard Periera   10: Raleigh Blais   
  11: Maren Spake       12: Tressa Hessler    13: Keisha Jansen     14: Youlanda Sera     15: Juliana Lalonde 
  16: Elva Alfonso      17: Elke Beckford     18: Wyatt Ferrigno    19: Rosaline Recker   20: Katherin Mchenry
Ballot #46:
   1: Rosetta Mcinnis    2: Loyce Mcdorman     3: Natacha August     4: Minna Wardle       5: Ignacio Mccree  
   6: Cordelia Power     7: Richard Periera    8: Shirley Kindel     9: Raleigh Blais     10: Youlanda Sera   
  11: Gregory Risser    12: Keisha Jansen     13: Elke Beckford     14: Maren Spake       15: Wyatt Ferrigno  
  16: Katherin Mchenry  17: Tressa Hessler    18: Rosaline Recker   19: Juliana Lalonde   20: Elva Alfonso    
Ballot #47:
   1: Minna Wardle       2: Youlanda Sera      3: Natacha August     4: Richard Periera    5: Ignacio Mccree  
   6: Rosetta Mcinnis    7: Gregory Risser     8: Loyce Mcdorman     9: Maren Spake       10: Shirley Kindel  
  11: Cordelia Power    12: Raleigh Blais     13: Elva Alfonso      14: Keisha Jansen     15: Katherin Mchenry
  16: Elke Beckford     17: Rosaline Recker   18: Juliana Lalonde   19: Wyatt Ferrigno    20: Tressa Hessler  
Ballot #48:
   1: Loyce Mcdorman     2: Minna Wardle       3: Maren Spake        4: Ignacio Mccree     5: Shirley Kindel  
   6: Natacha August     7: Rosetta Mcinnis    8: Gregory Risser     9: Elke Beckford     10: Keisha Jansen   
  11: Richard Periera   12: Rosaline Recker   13: Raleigh Blais     14: Katherin Mchenry  15: Youlanda Sera   
  16: Cordelia Power    17: Wyatt Ferrigno    18: Elva Alfonso      19: Juliana Lalonde   20: Tressa Hessler  
Ballot #49:
   1: Minna Wardle       2: Loyce Mcdorman     3: Shirley Kindel     4: Rosetta Mcinnis    5: Natacha August  
   6: Youlanda Sera      7: Ignacio Mccree     8: Keisha Jansen      9: Maren Spake       10: Cordelia Power  
  11: Raleigh Blais     12: Juliana Lalonde   13: Rosaline Recker   14: Richard Periera   15: Elke Beckford   
  16: Katherin Mchenry  17: Gregory Risser    18: Elva Alfonso      19: Wyatt Ferrigno    20: Tressa Hessler  
Ballot #50:
   1: Minna Wardle       2: Rosetta Mcinnis    3: Shirley Kindel     4: Ignacio Mccree     5: Youlanda Sera   
   6: Richard Periera    7: Gregory Risser     8: Loyce Mcdorman     9: Natacha August    10: Elva Alfonso    
  11: Cordelia Power    12: Maren Spake       13: Keisha Jansen     14: Rosaline Recker   15: Wyatt Ferrigno  
  16: Raleigh Blais     17: Elke Beckford     18: Katherin Mchenry  19: Tressa Hessler    20: Juliana Lalonde 

--------------------
Counting the Ballots
--------------------
Round 1: numSeats=6, numActive=20
   [ELECTED] Loyce Mcdorman   with tally (16.000000 = 16)
   [ELECTED] Minna Wardle     with tally (17.000000 = 17)
Round 2: numSeats=4, numActive=18
   [ELECTED] Ignacio Mccree   with tally (11.617647 = 395/34)
Round 3: numSeats=3, numActive=17
   [ELECTED] Natacha August   with tally (8.931199 = 59973/6715)
Round 4: numSeats=2, numActive=16
   [DROPPED] Elva Alfonso     with tally (0.000000 = 0)
Round 5: numSeats=2, numActive=15
   [DROPPED] Juliana Lalonde  with tally (0.000000 = 0)
Round 6: numSeats=2, numActive=14
   [DROPPED] Katherin Mchenry with tally (0.000000 = 0)
Round 7: numSeats=2, numActive=13
   [DROPPED] Raleigh Blais    with tally (0.000000 = 0)
Round 8: numSeats=2, numActive=12
   [DROPPED] Rosaline Recker  with tally (0.000000 = 0)
Round 9: numSeats=2, numActive=11
   [DROPPED] Tressa Hessler   with tally (0.000000 = 0)
Round 10: numSeats=2, numActive=10
   [DROPPED] Wyatt Ferrigno   with tally (0.000000 = 0)
Round 11: numSeats=2, numActive=9
   [DROPPED] Keisha Jansen    with tally (0.224396 = 90368356/402718695)
Round 12: numSeats=2, numActive=8
   [DROPPED] Elke Beckford    with tally (0.311392 = 123/395)
Round 13: numSeats=2, numActive=7
   [DROPPED] Richard Periera  with tally (0.587665 = 157775857/268479130)
Round 14: numSeats=2, numActive=6
   [DROPPED] Gregory Risser   with tally (0.710895 = 95430178/134239565)
Round 15: numSeats=2, numActive=5
   [ELECTED] Shirley Kindel   with tally (8.159568 = 2190673811/268479130)
Round 16: numSeats=1, numActive=4
   [DROPPED] Maren Spake      with tally (1.008101 = 889372525510428901/882225298336596645)
Round 17: numSeats=1, numActive=3
   [DROPPED] Youlanda Sera    with tally (1.193640 = 351019899407005257/294075099445532215)
Round 18: numSeats=1, numActive=2
   [DROPPED] Cordelia Power   with tally (1.922688 = 1696244111546748472/882225298336596645)
Round 19: numSeats=1, numActive=1
   [ELECTED] Rosetta Mcinnis  with tally (9.000000 = 9)

------------------
Elected Candidates
------------------
 [ELECTED] Ignacio Mccree   in round 2
 [ELECTED] Loyce Mcdorman   in round 1
 [ELECTED] Minna Wardle     in round 1
 [ELECTED] Natacha August   in round 3
 [ELECTED] Rosetta Mcinnis  in round 19
 [ELECTED] Shirley Kindel   in round 15

---------------------------------------------------------------
Normal termination.
*/
