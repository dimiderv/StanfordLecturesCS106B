/*
 * File: KarelGoesHome.cpp
 * -----------------------
 * Solution to the KarelGoesHome problem.  This problem turns out to be exactly
 * the same as the combinations problem from the last assignment.
 */

#include <iostream>
#include <iomanip>
#include "console.h"
/* Function prototypes */
#include"simpio.h"
int countPaths(int street, int avenue);

/* Main program */

int main() {
 int street=getInteger("give me the street number");
 int avenue=getInteger(" now give avenue ");
 int nPaths = countPaths(street, avenue);
std::cout<<"The number of paths available are "<<nPaths;
   return 0;
}

/*
 * Function: countPaths
 * Usage: int nPaths = countPaths(street, avenue);
 * -----------------------------------------------
 * Counts the paths from a particular street/avenue position in
 * Karel's world to the origin, subject to the restriction that
 * Karel can move only west and south.  The number of paths to
 * any given position is the number of paths from the corner to
 * the left plus the number of paths from the corner to the south.
 */

int countPaths(int street, int avenue) {
   if (street == 1 || avenue == 1) {
      return 1;
   } else {
      return countPaths(street - 1, avenue) + countPaths(street, avenue - 1);
   }
}
