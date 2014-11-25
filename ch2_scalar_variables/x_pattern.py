#!/usr/bin/env python

"""
x_pattern.py

Author: Patrick Rummage (patrickbrummage@gmail.com)

Objective:
    Write a program that prints out an 'X' pattern in 
    hashes, using one output statement each for hashes,
    spaces, and newlines.

#            #
 ##        ##
  ###    ###
   ########
   ########
  ###    ###
 ##        ##
#            #
"""
import sys 

rowLength = 15 

for row in range(1, 9):
    #caluculate values
    indent = int(4 - abs(4.5 - row))
    numHashes = 2 * (indent + 1)
    triangleLeft = (numHashes / 2) + indent
    triangleRight = rowLength - numHashes
    #print line
    for pos in range(1, rowLength - indent):
        if pos > indent and (pos <= triangleLeft or pos > triangleRight):
           sys.stdout.write("#")
        else:
            sys.stdout.write(" ")
    sys.stdout.write("\n")

