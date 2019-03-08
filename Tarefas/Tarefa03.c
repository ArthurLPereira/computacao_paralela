/********** TIMES************
*****PARALELO******
    1054154@PMG34INFLL20713:~/Documentos$ time ./sieve 
    5761455

    real	0m1,029s
    user	0m3,947s
    sys	0m0,036s
*****SEQUENCIAL*********
    1054154@PMG34INFLL20713:~/Documentos$ time ./sieve 
    5761455

    real	0m1,710s
    user	0m1,678s
    sys	0m0,032s

*****SPEEDUP=1.66****/



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
 
int sieveOfEratosthenes(int n)
{
   // Create a boolean array "prime[0..n]" and initialize
   // all entries it as true. A value in prime[i] will
   // finally be false if i is Not a prime, else true.
   int primes = 0; 
   bool *prime = (bool*) malloc((n+1)*sizeof(bool));
   int sqrt_n = sqrt(n);

    
 
   memset(prime, true,(n+1)*sizeof(bool));
 
   //#pragma omp parallel for
   for (int p=2; p <= sqrt_n; p++)
   {
       // If prime[p] is not changed, then it is a prime
       if (prime[p] == true)
       {
           // Update all multiples of p
           #pragma omp parallel for 
           for (int i=p*2; i<=n; i += p)
           prime[i] = false;
        }
    }
 
    // count prime numbers
    #pragma omp parallel for reduction(+:primes)
    for (int p=2; p<=n; p++)
       if (prime[p])
         primes++;
 
    return(primes);
}
 
int main()
{
   int n = 100000000;
   printf("%d\n",sieveOfEratosthenes(n));
   return 0;
} 
