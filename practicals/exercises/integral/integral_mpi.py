#!/usr/bin/env python

from mpi4py import MPI

import math
import numpy

import integral

def main (comm):
    """Compute a definite integral using the trapezium rule"""


#    if rank == 0:
#    	fh =  open( "results_mpi_{:d}.txt".format(size), "w" ) 

    # compute Pi (as a definite integral)

# root process writes result
#        if rank == 0:
#            fh.write("{:d} {:6.4e}\n".format(N, wt))
#	     print "MPI({:d}) N={:9d} Time={:6.4e} Error={:12.8e}".format( size, N, wt, e1 )


#    if rank ==0:
#        fh.close()

if __name__ == "__main__":
    """Run with a large number of points"""
    main (MPI.COMM_WORLD)
