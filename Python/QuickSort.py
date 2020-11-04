 #-------------------------------------------------------------------------
 #  QuickSort.py - QuickSort an array of N floating point numbers
 #  Version:	$Name$
 #  Module:	
 #
 #  Purpose:	
 #  See:	
 #
 #  Author:	Hema A Murthy (hema@localhost.localdomain)
 #
 #  Created:        Sat 10-Mar-2001 19:36:25
 #  Last modified:  Fri 12-Apr-2019 17:56:19 by hema
 #  $Id$
 #
 #  Bugs:	
 #
 #  Change Log:	<Date> <Author>
 #  		<Changes>
 #-------------------------------------------------------------------------#/


#-------------------------------------------------------------------------
 #  Swap -- Swaps two float elements
 #    Args:	int, int
 #    Returns:	int
 #    Throws:	
 #    See:	
 #    Bugs:	
 #-------------------------------------------------------------------------#/
def Swap (a, b):
    a, b = b, a
  
	#  End of Swap		End of Swap   #/

#-------------------------------------------------------------------------
 #  QuickSort -- Recursive sort using CAR Hoare's Algorithm
 #    Args:	floa#, int, int
 #    Returns:	Nothing
 #    Throws:	
 #    See:	
 #    Bugs:	
 #-------------------------------------------------------------------------#/

def QuickSort(v, left, right):
    i = left
    j = right
    print (left, right, v[left:right])
    x = v[int((left+right)/2)]
    while True:
        while (v[i] < x):
            i = i + 1
        while (x < v[j]):
            j = j - 1
        if (i <= j):
            v[i],v[j] = v[j], v[i]
            i = i + 1
            j = j - 1
        if ( i >= j):
            break

    if (left < j): 
        QuickSort(v,left,j)
    if (i < right):
        QuickSort(v,i,right)
                
	#  End of QuickSort		End of QuickSort   #/
lines = list (map (int, input().split()))
print ("before sorting", lines, "\n")
QuickSort(lines, 0, len(lines) - 1)
print ("after sorting", lines, "\n")

#-------------------------------------------------------------------------
 # $Log$
 #
 # Local Variables:
 # time-stamp-active: t
 # time-stamp-line-limit: 20
 # time-stamp-start: "Last modified:[ 	]+"
 # time-stamp-format: "%3a %02d-%3b-%:y %02H:%02M:%02S by %u"
 # time-stamp-end: "$"
 # End:
 #                        End of QuickSort.py
 #-------------------------------------------------------------------------#/







