#include <stdio.h>
#include <stdlib.h>
 
/* Grupo - Arthur Ladislau, Lucas Cicutti e Rubens Campos
 * Programa executado na maquina do laboratório
 * Tempo sequencial: 0m2,256s
 * Tempo paralelo sem política: 0m1,409s - Speedup: TempoSeq/TempoParaleloSemPolit = 1,6
 * Tempo paralelo com política: 0m1,199s - Speedup em relação ao sequencial: TempoSeq/TempoParaleloComPolit =  1,88
 *                                         Speedup em relação ao paralelo sem política: TempoParaleloSemPolit/TempoParaleloComPolit = 1,17
 */
int main() 
{

   int i, j, n = 30000; 
 
   // Allocate input, output and position arrays
   int *in = (int*) calloc(n, sizeof(int));
   int *pos = (int*) calloc(n, sizeof(int));   
   int *out = (int*) calloc(n, sizeof(int));   
 
   // Initialize input array in the reverse order
   for(i=0; i < n; i++)
      in[i] = n-i;  
 
   // Print input array
   //   for(i=0; i < n; i++) 
   //      printf("%d ",in[i]);
 
   // Silly sort (you have to make this code parallel)
   #pragma omp parallel for private(j) num_threads(2) schedule(static,173)
   for(i=0; i < n; i++) 
      for(j=0; j < n; j++)
	     if(in[i] > in[j]) 
            pos[i]++;	
 
   // Move elements to final position
   for(i=0; i < n; i++) 
      out[pos[i]] = in[i];
 
   // print output array
   //   for(i=0; i < n; i++) 
   //      printf("%d ",out[i]);
 
   // Check if answer is correct
   for(i=0; i < n; i++)
      if(i+1 != out[i]) 
      {
         printf("test failed\n");
         exit(0);
      }
 
   printf("test passed\n"); 
}  
