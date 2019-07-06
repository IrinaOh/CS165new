###############################################################
# Program:
#     Checkpoint 07a, Static
#     Brother Dudley, CS165
# Author:
#     Sandro
# Summary:
#     Summaries are not necessary for checkpoint assignments.
###############################################################

# Rule for a.out
a.out : icecream.o check07a.cpp
	g++ icecream.o check07a.o

# rule for icecream.o
icecream.o : icecream.h icecream.cpp
	g++ -c icecream.cpp

# Rule for check07a.o
check07a.o : icecream.h check07a.cpp
	g++ -c check07a.cpp


clean :
	rm *.o
	rm a.out
