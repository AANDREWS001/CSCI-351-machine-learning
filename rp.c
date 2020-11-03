/*
Copyright (c) 2016-2020 Jeremy Iverson

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

/* assert */
#include <assert.h>

/* fabs */
#include <math.h>

/* printf, fopen, fclose, fscanf, scanf */
#include <stdio.h>

/* EXIT_SUCCESS, malloc, calloc, free, qsort */
#include <stdlib.h>

struct distance_metric {
  size_t viewer_id;
  double distance;
};

int
main(int argc, char * argv[])
{
  size_t n, m;

  /* Validate command line arguments. */
  assert(2 == argc);

  /* ... */
  char const * const fn = argv[1];

  /* Validate input. */
  assert(fn);

  /* Open file. */
  FILE * const fp = fopen(fn, "r");
  assert(fp);

  /* Read file. */
  fscanf(fp, "%zu %zu", &n, &m);

  /* Allocate memory. */
  double * const rating = malloc(n * m * sizeof(*rating));

  /* Check for success. */
  assert(rating);

  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      fscanf(fp, "%lf", &rating[i * m + j]);
    }
  }

  /* Close file. */
  int const ret = fclose(fp);
  assert(!ret);

  /* Allocate more memory. */
  double * const urating = malloc(m * sizeof(*urating));

  /* Check for success. */
  assert(urating);

  /* Get user input. */
  for (size_t j = 0; j < m - 1; j++) {
    printf("Enter your rating for movie %zu: ", j + 1);
    scanf("%lf", &urating[j]);
  }

  /* Allocate more memory. */
  //double prob[10] = { 0.0 };
  double prob1[10] = { 0.0 };
  double prob2[10] = { 0.0 };
  double prob3[10] = { 0.0 };
  double prob4[10] = { 0.0 };


/* Compute probabilities */
  /*for (int k = 0; k < 10; k++) {
    for (size_t i = 0; i < n; i++) {
      prob[k] += (rating[i * m + 4] == (k + 1) / 2.0);
    }
  }*/
  
  /* Compute probabilities Part 1 */
  for (int k = 0; k < 10; k++) {
    for (size_t i = 0; i < n; i++) {
      //prob1[k] += (rating[i * m + 0] == (k + 1) / 2.0);
    //prob1[k] = (rating[i * m + 0] == urating[0]);

	if((rating[i * m + 0] == urating[0]) && (rating[i * m + 4] == (k + 1) / 2.0))
	{
		prob1[k] += (rating[i * m + 0] == (k + 1) / 2.0);
		/*prob1[k] /= n;
		printf("Movie 1's ratings: \n prob[%d] = %lf\n", k, prob1[k]);*/
	}
    }
  }
  
  /* Compute probabilities Part 2 */
  for (int k = 0; k < 10; k++) {
    for (size_t i = 0; i < n; i++) {
      //prob2[k] += (rating[i * m + 1] == (k + 1) / 2.0);
    	//prob2[k] = (rating[i * m + 1] == urating[1]);

	if((rating[i * m + 1] == urating[1]) && (rating[i * m + 4] == (k + 1) / 2.0))
	{
		prob2[k] += (rating[i * m + 1] == (k + 1) / 2.0);
		/*prob2[k] /= n;
		printf("Movie 2's ratings: \n prob[%d] = %lf\n", k, prob2[k]);*/
	}
	}

  }


  /* Compute probabilities Part 3 */
  for (int k = 0; k < 10; k++) {
    for (size_t i = 0; i < n; i++) {
      //prob3[k] += (rating[i * m + 2] == (k + 1) / 2.0);
    	//prob3[k] = (rating[i * m + 2] == urating[2]);
	

	if((rating[i * m + 2] == urating[2]) && (rating[i * m + 4] == (k + 1) / 2.0))
	{
		prob3[k] += (rating[i * m + 2] == (k + 1) / 2.0);
		/*prob3[k] /= n;
		printf("Movie 3's ratings: \nprob[%d] = %lf\n", k, prob3[k]);*/
	}
	}
  }

  
  /* Compute probabilities Part 4 */
  for (int k = 0; k < 10; k++) {
    for (size_t i = 0; i < n; i++) {
      //prob4[k] += (rating[i * m + 3] == (k + 1) / 2.0);
    	//prob4[k] = (rating[i * m + 3] == urating[3]);
	

	if((rating[i * m + 3] == urating[3]) && (rating[i * m + 4] == (k + 1) / 2.0))
	{
 		prob4[k] += (rating[i * m + 3] == (k + 1) / 2.0);
		/*prob4[k] /= n;
		printf("Movie 4's ratings: \nprob[%d] = %lf\n", k, prob4[k]);*/
		
	}
		

	}
  }

 
  

  /* Finalize computation of probabilities. */
  for (int k = 0; k < 10; k++) {
    //prob[k] /= n;
    prob1[k] /= n;
    prob2[k] /= n;
    prob3[k] /= n;
    prob4[k] /= n;
  }
printf("Movie 1's rating probabilities\n");
  for (int k = 0; k < 10; k++) {
    //printf("prob[%d] = %lf\n", k, prob[k]);
    printf("prob[%d] = %lf\n", k, prob1[k]);
  }
printf("Movie 2's rating probabilities\n");
  for (int k = 0; k < 10; k++) {
    //printf("prob[%d] = %lf\n", k, prob[k]);
    printf("prob[%d] = %lf\n", k, prob2[k]);
  }
printf("Movie 3's rating probabilities\n");
  for (int k = 0; k < 10; k++) {
    //printf("prob[%d] = %lf\n", k, prob[k]);
    printf("prob[%d] = %lf\n", k, prob3[k]);

  }
printf("Movie 4's rating probabilities\n");
  for (int k = 0; k < 10; k++) {
    //printf("prob[%d] = %lf\n", k, prob[k]);
    printf("prob[%d] = %lf\n", k, prob4[k]);
  }

  /* Output prediction. */
<<<<<<< HEAD
//double max, max1, max2, max3, max4, maxEquation;
/*I have a feeling this isnt what exactly what you asked for
for (int k = 0; k < 10; k++){
for(size_t i=0; i<n; i++){

=======
double max1, max2, max3, max4, maxEquation;
for (int k = 0; k < 10; k++){
>>>>>>> 7c2c7237f2d27c9b4c6b4ffa519b9ab348043e43
max1 = 0.0;
 if(prob1[k] > max1){
    max1 = prob1[k];
}
}

for (int k = 0; k < 10; k++){
max2 = 0.0;
 if(prob2[k] > max2){
    max2 = prob2[k];
}
}

for (int k = 0; k < 10; k++){
max3 = 0.0;
 if(prob3[k] > max3){
    max3 = prob3[k];
}
}

for (int k = 0; k < 10; k++){
max4 = 0.0;
 if(prob4[k] > max4){
    max4 = prob4[k];
}
}
<<<<<<< HEAD
=======

if(max1 < max2){
maxEquation = max2;
}
if(max1 < max2){
maxEquation = max2;
}
if(max2 < max3){
maxEquation = max3;
}
if(max3 < max4){
maxEquation = max4;
<<<<<<< HEAD
}*/

double max, max1, max2, max3, max4, maxEquation;

for (int k = 0; k < 10;k++){
for(size_t i = 0; i < n; i++){
max1 = ((rating[i * m + 4]  == ((k+1) / 2.0)) * (rating[i * m + 0] == urating[0]) && (rating[i * m + 4] ==  (k+1) / 2.0));

max2 = (rating[i * m + 1] == urating[1]) && (rating[i * m + 4] ==  (k+1) / 2.0);

max3 = (rating[i * m + 2] == urating[2]) && (rating[i * m + 4] ==  (k+1) / 2.0);

max4 = (rating[i * m + 3] == urating[3]) && (rating[i * m + 4] ==  (k+1) / 2.0);

maxEquation = max1 * max2 * max3 * max4;

if(maxEquation > max){
max = maxEquation;
}
}
}

printf("The predicted rating for movie five is %.1lf.\n", max);
=======
}

/*for (int k = 0; k<10;k++){
for(size_t i = 0; i < n; i++){
equation = ((rating[i * m + 4] == prob[k]) * (rating[i * m + 0] == urating[0] && rating[i * m + 4] == prob1[k]) * (rating[i * m + 1] == urating[1] && rating[i * m + 4] == prob2[k]) * (rating[i * m + 2] == urating[2] && rating[i * m + 4] == prob3[k]) * (rating[i * m + 3] == urating[3] && rating[i * m + 4] == prob4[k]));
}
}
*/



  /* Deallocate memory. */
  free(rating);
  free(urating);

  return EXIT_SUCCESS;
}



