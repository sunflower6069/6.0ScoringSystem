########################
#   CPSC 427 PSet 4    #
#   Xin Yan            #
#   04/10/2016         #
########################

# About the program: 
This program is called Single Transferrable Vote (STV) voting system. 
When run, it takes a command-line argument the name of a CSV-format 
marks file and uses the data in it to construct data structures that 
will be used by the voting algorithm. Then a voting procedure is used
to compute the final elected results according to the STV voting system.

More about the 6.0 Scoring System:
http://www.usfsa.org/programs?id=84139
https://en.wikipedia.org/wiki/6.0_system

# How to use the program:
1) Compile: make
2) Execution: ./stv election.csv
