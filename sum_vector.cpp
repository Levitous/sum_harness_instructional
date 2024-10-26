#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>
#include <string.h>



void 
setup(int64_t N, uint64_t A[])
{
   printf(" inside sum_vector problem_setup, N=%lld \n", N);

   // Problem definition specifies that A[] must be initialized
   // as an array containing 0 through N-1. We are modifying the
   // array in-place.

   // Since this function is in-place, we must trust that array A
   // has been pre-allocated by the caller.

   // We must also trust that A is at least size N * sizeof(uint64_t),
   // since A appears to be a raw array and has no built in methods
   // to check size before assignments.

   if (A == nullptr)
   {
      printf("Array A has not been pre-allocated by the caller. Exiting.\n");
      exit(1);
   }

   for(int64_t i = 0; i<N; i++)
   {
      A[i] = i;
   }

   return;
}

int64_t
sum(int64_t N, uint64_t A[])
{
   printf(" inside sum_vector perform_sum, N=%lld \n", N);

   // Vector sum will access A once per loop and
   // perform the summing with an accumulator,
   // assuming the compiler makes that choice.

   int64_t sum = 0;
   for(int64_t i = 0; i < N; i++)
   {
      sum += A[i];
   }

   return sum;
}

