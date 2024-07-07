#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ARRAY_SIZE 400

int array[ARRAY_SIZE];
int sum = 0;
int max = 0;

void *sum_function(void *n) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum += array[i];
    }
    return NULL;
}

void *max_function(void *n) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return NULL;
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

    
    while ( fgets ( line, sizeof line, fp) != NULL ) 
    {
       if (i < ARRAY_SIZE)
       {
         array[i]=atoi(line);  
       }

       
      i++;
    }

    
   
 
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



    pthread_t sum_thread, max_thread;

    pthread_create(&sum_thread, NULL, sum_function, NULL);
    pthread_create(&max_thread, NULL, max_function, NULL);

    pthread_join(sum_thread, NULL);
    pthread_join(max_thread, NULL);

    printf("Sum: %d\n", sum);
    printf("Max: %d\n", max);

    return 0;
}

