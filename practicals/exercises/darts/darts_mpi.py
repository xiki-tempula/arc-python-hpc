"""
   Exercise: use Monte-Carlo integration on the unit circle to compute Pi
   Notes:    this version uses Send()/Recv() and numpy arrays
"""

import darts
import math
import numpy
from mpi4py import MPI


def main (comm):
    """Compute Pi using Monte-Carlo integration"""

    # compute Pi with different number of points

#    if rank == 0:
#    	fh =  open( "results_mpi_{:d}.txt".format(size), "w" ) 

#        if rank == 0:
#            pi  = 4.0 * float (numHits[0]) / float (numPoints)
#            err = math.fabs (pi - math.pi)
#            fh.write("{:d} {:6.4e}\n".format(numPoints, wt))
#	     print "MPI({:d}) N={:9d} Time={:6.4e} Error={:12.8e}".format( size, numPoints, wt, err )

#    if rank ==0:
#        fh.close()



if __name__ == "__main__":
    """Run with a large number of points"""
    main (MPI.COMM_WORLD)
