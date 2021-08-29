#include <stdlib.h>
#include <stdio.h>


void quicksort(int randArray[],int first,int last){
   int n, j, pivot, temp;

   if(first<last){
      pivot=first;
      n=first;
      j=last;

      while(n<j){
         while(randArray[n]<=randArray[pivot]&&n<last)
		 {
            n++;
        }
         while(randArray[j]>randArray[pivot]){
		 
            j--;
        }
         if(n<j){
            temp=randArray[n];
            randArray[n]=randArray[j];
            randArray[j]=temp;
         }
      }

      temp=randArray[pivot];
      randArray[pivot]=randArray[j];
      randArray[j]=temp;
      quicksort(randArray,first,j-1);
      quicksort(randArray,j+1,last);

   }
}


// Function to print an array
void printArray(int randArray[], int size) {
	int i;
  for ( i = 0; i < size; i++) {
    printf("%d ", randArray[i]);
  }
  printf("\n");
}

void insertionSort(int randArray[], int size) {
	int step;
  for ( step = 1; step < size; step++) {
    int key = randArray[step];
    int j = step - 1;

    /* Compare key with each element on the left of it until an element smaller than
     it is found.*/
    // For descending order, change key<randArray[j] to key>randArray[j].
    while (key < randArray[j] && j >= 0) {
      randArray[j + 1] = randArray[j];
      --j;
    }
    randArray[j + 1] = key;
  }
}






 int randArray[1000];

//generate rondom array from 1000 index

// Driver code
int main() {
	
	//generate rondom array contains 1000 index
    int sz=1000;
   int randArray[sz],i;
   for(i=0;i<sz;i++)
     randArray[i]=rand()%1000;   //Generate number between 0 to 1000
   printf("\nElements of the array::");
   for(i=0;i<sz;i++)
   {
     printf("\nElement number %d::%d",i+1,randArray[i]);
   }
      
      
      
      
 // Insertion Sort
  int size = sizeof(randArray) / sizeof(randArray[0]);
  insertionSort(randArray, size);
  printf("Sorted array in ascending order:\n");
  printArray(randArray, size);
  
  
  //Quick sort
    int s;
    int count =1000;

   quicksort(randArray,0,count-1);

   printf("Order of Sorted elements: ");
   for(s=0;s<count;s++)
      printf(" %d",randArray[s]);
      
      
      
      
      
      float clock_t, start_t, end_t, total_t;
   int b;
   float  CLOCKS_PER_SEC;

   start_t = clock();
   printf("Starting of the program, start_t = %ld\n", start_t);
    
   printf("Going to scan a big loop, start_t = %ld\n", start_t);
   for(b=0; b< 10000000; b++) {
   }
   end_t = clock();
   printf("End of the big loop, end_t = %ld\n", end_t);
   
   total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
   printf("Total time taken by CPU: %f\n", total_t  );
   printf("Exiting of the program...\n");
   
      return 0;

}



//github : https://github.com/MohamedKhaled4455/Task-2.git
