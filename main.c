#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


///////////////////////////////////////////////////////////printing functions
void print_heap(int a[],int s){int k=6;
    int i;
for(i=0;i<s;i++){
        printf("%d  ",a[i]);
    if(i==0||i==2){
        printf("\n");
    }
    else if(i==k){
        printf("\n");
        k=2*k+1;
    }

}
}

void print_arr(int a[],int length){
    char op;

    printf("\n\t\tWould you Like To print the Sorted array? y/n\n");
    scanf(" %c",&op);
    if(op=='y'||op=='Y'){

for(int i=0;i<length;i++){

    printf("%d ",a[i]);
}}

else if(op!='n'&&op!='N'){
    printf("\t\tEnter A Valid Letter\n");
    print_arr(a,length);
}

}


/////////////////////////////////////////////////////////create random array
void CreateRandArr(int a[],int length){
srand(time(NULL));//to make a new seed every time we run the code

for(int i=0;i<length;i++){
a[i]=(rand()%1000)+1;//creating random values for each cell where the max value can be 100
}
 printf("\t\twe created a random array for you\n");
printf("\n\n\t\tWould you like to print it before sorting ? y/n\n\t\t");
char op;
scanf(" %c",&op);
if(op=='Y'||op=='y'){
printf("\n\n\t\tThe array before sorting:\n");
for(int i=0;i<length;i++){

printf("%d ",a[i]);
}
}
}

/////////////////////////////////////////////////////////QuickSort
void swap (int*x,int*y){
int temp=*x;
*x=*y;
*y=temp;
/*this function is to swap the between two pointers in the array under a certain condition*/
}

void QuickSort(int arr[],int length){
QuickSort_Recursion(arr,0,length-1);
/*this is just a wrapper function to make it easier to send only the length at first*/
}

void QuickSort_Recursion(int arr[],int low,int high){

if(low<high){
int pivloc=partition(arr,low,high);//gets the new pivot
QuickSort_Recursion(arr,low,pivloc-1);//the left side of the pivot
QuickSort_Recursion(arr,pivloc+1,high);//the right side of the pivot
}
}

int partition(int arr[] , int low , int high){
int piv_val=arr[high];//choosing the pivot randomly so we chose to be the right most one in array
int i=low;
for(int j=low;j<high;j++){
    if(arr[j]<=piv_val){

        swap(&arr[i],&arr[j]);
        i++;
    }

}
 swap(&arr[i],&arr[high]);

return i;
}

/////////////////////////////////////////////////////////////////////MergeSort

void Merge_Sort(int a[],int length){
Merge_Sort_Recursion(a,0,length-1);//this is a wrapper function to send the left and right index to the
                                   //Recursive function
}

void Merge_Sort_Recursion(int a[],int low,int high){//a:[5 4 3 2 1] low=0 high =5-1=4
//0<4 true

    if(low<high){
int mid=low+(high-low)/2;//mid=0+4/2=2 mid=2
Merge_Sort_Recursion(a,low,mid);//sends the array recursivly with low=0,mid->high=2::::[5 4 3]
                                //then[5 4 3] has mid=0+2/2=1 mid=1 sends the array,low=0,mid->high=1:::[5 4]
                                //[5 4]has mid=0+1/2=0 mid=0 ,sends the array , low=0,mid->high=0::[5]
                                //then low is no longer less than high , goes to the last step it had and do the next line

Merge_Sort_Recursion(a,mid+1,high);
                                // we end up with small arrays sorted by default[5][4][3][2][1]
                                //because each one has only one element so we can say they are sorted by default

Merge_Sorted_Arrays(a,low,mid,high);}
//we just need to merge them

}


void Merge_Sorted_Arrays(int a[],int low,int mid,int high){
int left_length=mid-low+1;
int right_length=high-mid;


int temp_left_arr[left_length];
int temp_right_arr[right_length];
int i,j,k;

for(i=0;i<left_length;i++){

    temp_left_arr[i]=a[low+i];
}

for(j=0;j<right_length;j++){

    temp_right_arr[j]=a[mid+1+j];
}//until here we made copies of our array into 2 arrays left and right , then we can merge them


//lets say :
//           i
//temp left=[3 4 5]
//                  j
// temp right =[1 2]
//              k
//a[1  2  3 4 5 ]

for(i=0,j=0,k=low;k<=high;k++){

    if((i<left_length)&&(j>=right_length||temp_left_arr[i]<=temp_right_arr[j])){
       a[k]=temp_left_arr[i];
       i++;
       }
    else{
        a[k]=temp_right_arr[j];
        j++;
    }

}



}


/////////////////////////////////////////////////////////////////////heapsort:

void heapify(int a[],int s,int i){
int left_child=(2*i)+1;
int right_child=(2*i)+2;
int max=i;

if(left_child<s && a[left_child]>a[max]){
    max=left_child;
}
if(right_child<s && a[right_child]>a[max]){
    max=right_child;
}
if(max!=i){

    swap(&a[i],&a[max]);
    heapify(a,s,max);
}
}

void buildHeap(int a[] , int s){

for(int i=(s-1)/2;i>=0;i--){
    heapify(a,s,i);
}
//print_heap(a,s);
}

void Heap_Sort(int a[],int s){

buildHeap(a,s);

for(int i=s-1;i>=0;i--){
    swap(&a[0],&a[i]);
    heapify(a,i,0);
}
}

/////////////////////////////////////////////////////////////////////Selection sort

void Selection_Sort(int a[],int length){

for(int i=0;i<length-1;i++){
    int min_pos=i;
    for(int j=i+1;j<length;j++){
        if(a[j]<a[min_pos]){
            min_pos=j;
        }
            if(min_pos!=i){
                swap(&a[i],&a[min_pos]);

            }


    }

}


}
//////////////////////////////////////////////////////////////////////Insertion Sort

void Insertion_Sort(int a[],int length){

for(int i=1;i<=length;i++){

 int key=a[i];

 int j=i-1;

 while(j>=0&&a[j]>key){
    a[j+1]=a[j];
    j--;

    }

    a[j+1]=key;
}
}

///////////////////////////////////////////////////////////Find The kth smallest element

void kth_smallest(int a[],int length){
printf("\n\n\t\tWould you like to find the Kth smallest element in the array ? y/n \n\n");
char op;
scanf(" %c",&op);
if(op=='y'||op=='Y'){
    printf("\t\tPlease enter the number of kth smallest number that you are trying to find\n\n");
    int k;
    scanf("%d",&k);
    printf("\n\n\t\tThe %dth Smallest number in the array is: %d\n\n",k,a[k-1]);
}
else if(op!='n'&&op!='N'){

    printf("\t\tEnter A valid Letter\n");
    kth_smallest(a,length);
}
}


//////////////////////////////////////////////////////////////////////////////////////////hybrid Merge_Selection sort

void Hybrid_Sort(int a[],int length){
//this is a wrapper function to send the left and right index to the

printf("\nEnter the threshold value:\n");
int threshold;
scanf("%d",&threshold);
clock_t begin=clock();
hybrid_Sort_Recursion(a,0,length-1,threshold,length);
clock_t end=clock();
printf("\n\n\t\tThe program took %f micro Seconds To Execute",(float)(end-begin)/CLOCKS_PER_SEC*pow(10,6));
}

void hybrid_Sort_Recursion(int a[],int low,int high,int threshold,int length){
if(length<threshold){
    Selection_Sort(a,length);
}

else{
    if(low<high){
int mid=low+(high-low)/2;
hybrid_Sort_Recursion(a,low,mid,threshold,length);

hybrid_Sort_Recursion(a,mid+1,high,threshold,length);

Merge_Sorted_Arrays(a,low,mid,high);}

}
}



////////////////////////////////////////////////////////////////////////////////////////////Done


int main()
{

int length;
int operation;
printf("\t\tEnter the length of your array\n\t\t");
scanf("%d",&length);
int a[length];

CreateRandArr(a,length);

printf("\n\n\t\tChoose A Sorting Technique\n\n\t\t1-Quick Sort\n\n\t\t2-Merge Sort\n\n\t\t3-Heap Sort\n\n\t\t4-Selection Sort\n\n\t\t5-Insertion Sort\n\n\t\t6-Hybrid Merge & Selection Sort\n\n\t\t");
scanf("%d",&operation);
  clock_t begin=clock();

switch(operation){

case 1:
         QuickSort(a,length);
         clock_t end=clock();
         printf("\n\n\t\tThe program took %f micro Seconds To Execute",(float)(end-begin)/CLOCKS_PER_SEC*pow(10,6));
         print_arr(a,length);
         kth_smallest(a,length);
         break;

case 2:
         Merge_Sort(a,length);//for ex u send [5 4 3 2 1] length is 5
         end=clock();
         printf("\n\n\t\tThe program took %f micro Seconds To Execute",(float)(end-begin)/CLOCKS_PER_SEC*pow(10,6));
         print_arr(a,length);//the result is [1 2 3 4 5]
         break;

case 3:
         Heap_Sort(a,length);
         end=clock();
         printf("\n\n\t\tThe program took %f micro Seconds To Execute",(float)(end-begin)/CLOCKS_PER_SEC*pow(10,6));
         print_arr(a,length);
         break;

case 4:
         Selection_Sort(a,length);
         end=clock();
         printf("\n\n\t\tThe program took %f micro Seconds To Execute",(float)(end-begin)/CLOCKS_PER_SEC*pow(10,6));
         print_arr(a,length);
         break;


case 5:
        Insertion_Sort(a,length);
         end=clock();
         printf("\n\n\t\tThe program took %f micro Seconds To Execute",(float)(end-begin)/CLOCKS_PER_SEC*pow(10,6));
         print_arr(a,length);
         break;

case 6:
        Hybrid_Sort(a,length);
        print_arr(a,length);
        break;

}
printf("\n\n\t\tWould you like to sort another array? y/n\n\t\t");
char op;
scanf(" %c",&op);
if(op=='y'||op=='Y'){
    main();
}
else if(op=='n'||op=='N'){return 0;}

    return 0;
}
