###############################################################
# Program:
#     Assignment 05, Order Tracking
#     Brother Dudley, CS165
# Author:
#     Sandro Tamborindegui
# Summary:
#     Put your summary code here... 
###############################################################


# We will learn fancier compilation steps later, but this is
# good enough for now...
a.out : product.h product.cpp address.h address.cpp customer.h customer.cpp order.h order.cpp assign05.cpp
   g++ product.cpp address.cpp customer.cpp order.cpp assign05.cpp
