#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ARRAY_SIZE 7000
#define NUM_THREADS 8

int array[ARRAY_SIZE]; // Global array to store integers from the file
int totalsum = 0;
int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0, sum6 = 0, sum7 = 0, sum8 = 0;

void *threadfunction(void *n) {
    int i;
    for (i = 0; i < 875; i++) {
        sum1 = sum1 + array[i];
    }

}

void *thread2function(void *n) {
    int i;
    for (i = 875; i < 1750; i++) {
        sum2 = sum2 + array[i];
    }

}

void *thread3function(void *n) {
    int i;
    for (i = 1750; i < 2625; i++) {
        sum3 = sum3 + array[i];
    }

}

void *thread4function(void *n) {
    int i;
    for (i = 2625; i < 3500; i++) {
        sum4 = sum4 + array[i];
    }

}

void *thread5function(void *n) {
    int i;
    for (i = 3500; i < 4375; i++) {
        sum5 = sum5 + array[i];
    }
   
}

void *thread6function(void *n) {
    int i;
    for (i = 4375; i < 5250; i++) {
        sum6 = sum6 + array[i];
    }

}

void *thread7function(void *n) {
    int i;
    for (i = 5250; i < 6125; i++) {
        sum7 = sum7 + array[i];
    }
   
}

void *thread8function(void *n) {
    int i;
    for (i = 6125; i < 7000; i++) {
        sum8 = sum8 + array[i];
    }
    
}



void readfile(char* file_name)
{

   char ch;
   
   FILE *fp;
    
    
   fp = fopen(file_name,"r"); // read mode
 
   if( fp == NULL )
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }
   
 
    char line[20]; /* line size */ 

    int i=0;
 
    printf("Reading file: ");    
    fputs(file_name,stdout);
    printf("\n");

    
    while ( fgets ( line, sizeof line, fp) != NULL ) /* read a line */
    {
       if (i < ARRAY_SIZE)
       {
         array[i]=atoi(line);  
       }

        //debug code
        //fputs ( line, stdout ); /* write the line */
      i++;
    }

    
    // debug code 
    //printf("i is : %d \n",i);
 
   fclose(fp);

    printf("Reading file Complete, integers stored in array.\n\n");    

}

 
int main(int argc, char* argv[])
{
   
   if (argc != 2) {
	fprintf(stderr,"usage: a.out <file name>\n");
	/*exit(1);*/
	return -1;
    }

   readfile(argv[1]);







    pthread_t t1, t2, t3, t4, t5, t6, t7, t8;

    pthread_create(&t1, NULL, threadfunction, NULL);
    pthread_create(&t2, NULL, thread2function, NULL);
    pthread_create(&t3, NULL, thread3function, NULL);
    pthread_create(&t4, NULL, thread4function, NULL);
    pthread_create(&t5, NULL, thread5function, NULL);
    pthread_create(&t6, NULL, thread6function, NULL);
    pthread_create(&t7, NULL, thread7function, NULL);
    pthread_create(&t8, NULL, thread8function, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);
    pthread_join(t5, NULL);
    pthread_join(t6, NULL);
    pthread_join(t7, NULL);
    pthread_join(t8, NULL);

    totalsum = sum1 + sum2 + sum3 + sum4 + sum5 + sum6 + sum7 + sum8;

    printf("Thread 1 Sum: %d\n", sum1);
    printf("Thread 2 Sum: %d\n", sum2);
    printf("Thread 3 Sum: %d\n", sum3);
    printf("Thread 4 Sum: %d\n", sum4);
    printf("Thread 5 Sum: %d\n", sum5);
    printf("Thread 6 Sum: %d\n", sum6);
    printf("Thread 7 Sum: %d\n", sum7);
    printf("Thread 8 Sum: %d\n", sum8);
    printf("Total Sum is: %d\n", totalsum);



    return 0;
}

