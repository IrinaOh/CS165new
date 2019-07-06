###############################################################
# Program:
#     Checkpoint 07b, Pointers and Minecraft
#     Brother Dudey, CS165
# Author:
#     Sandro T
# Summary:
#     Summaries are not necessary for checkpoint assignments.
###############################################################


a.out : voxel.o world.o check07b.o
	g++ voxel.o world.o check07b.o

voxel.o : voxel.cpp voxel.h
	g++ -c voxel.cpp

world.o : worls.cpp world.h
	g++ -c world.cpp

check07b.o : 
world.h check07b.cpp
	g++ -c check07b.cpp

clean :
	rm *.o
	rm a.out
