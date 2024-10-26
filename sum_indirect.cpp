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
   printf(" inside sum_indirect problem_setup, N=%lld \n", N);

   // Problem definition specifies that A[] must be initialized
   // as an array containing random numbers in the range 0 to N.
   // We will be modifying the array in-place.

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

   // First make sure the array has all unique values from 0 to N-1:
   for (int64_t i = 0; i<N; i++)
   {
      A[i] = i;
   }

   // Then prep/seed the random number generator in the assignment doc
   srand48(time(nullptr));

   // Then shuffle the values. I'll be using the Fisher-Yates shuffle,
   // which produces a random permutation of an array of values. I'm not
   // sure if there is a more efficient way to produce a unique, collision
   // free, randomly arranged array. This has O(N) time complexity and
   // O(1) space complexity, so I'll use it until I find something better.

   for (int64_t i = N-1; i > 0; i--)
   {
      // Since i is counting down from N, we can get a random number
      // (j) between 0 and i. Then we can swap the value at A[i] with
      // the value at A[j]..provided they aren't the same index.
      int64_t j = lrand48() % (i+1);

      // If they aren't the same index, XOR swap the values.
      if (i != j)
      {
         A[i] = A[i] ^ A[j];
         A[j] = A[i] ^ A[j];
         A[i] = A[i] ^ A[j];
      }
   }

   // Now A[] should be initialized with unique values 0 through N-1,
   // arranged in a random permutation. I chose to make all values
   // unique because Professor Bethel mentioned the possibility of
   // entering an accessing loop which would artificially reduce the
   // durations in our tests.

   return;
}

int64_t
sum(int64_t N, uint64_t A[])
{
   printf(" inside sum_indirect perform_sum, N=%lld \n", N);

   // Indirect sum will access A once per loop and
   // perform the summing with an accumulator,
   // assuming the compiler makes that choice.

   int64_t sum = 0;
   int64_t idx = A[0];

   for(int64_t i = 0; i < N; i++)
   {
      sum += A[idx];
      idx = A[idx];
   }

   return sum;
}
