/******************************************************************************

Suhail Munshi Assignment 2 Problem 1084 Highway Lite.
			*ONLINE JUDGE ACCEPTED* ID : 17900

*******************************************************************************/

#include <stdio.h>

/*Declare Variables for global use*/
int rows;
int columns;
int tMax;
int elements;

/*Method for output of 2d array*/
void print2dArray(char newArr[rows][columns]){
    /*Output array charachter by charachter*/
    for(int i=0;i<rows;i++ ){
        for(int j=0;j<columns;j++){
            printf("%c",newArr[i][j]);
        }
        printf("\n");
    }
}

/*Method for input of integer and validation of input*/
int getInt(){
    int input = 0;
    /*While loop recieves input until conditions are met.*/
    while(1){
        scanf("%d",&input);
        if(input>0) break;
        else printf("\nMust be positive Integer\n");
    }
    return input;
}

int main()
{   
    /*Variables are assigned values.*/
    rows = getInt();
    columns = getInt();
    tMax = getInt();
    
    /*Declaration of arrays*/
    int a[tMax];
    int b[tMax];
    char array[rows][columns];
    
    /*Sets value of all chatachters in array equal to '.' */
    memset(array,'.',rows*columns);
    
    /*Inputs the number of cars and rows of each car into coressponding arrays*/
    int elements = 0;
    while(scanf("%d%d",&a[elements],&b[elements])!=EOF){
        elements++;
    }
    
    /*New Array Declaration of the size equal to the number of elements*/
    int timeAlloc[elements];
    int rowAlloc[elements];
    
    /*This is done to shrink the size of the arrays declared earlier - Prevent unexpected errors.*/
    for(int i = 0 ;i<=elements;i++){
        timeAlloc[i] = a[i];
        rowAlloc[i] = b[i];
    }
    
    /*
    *   Count is the index of the array timeAlloc and rowAlloc
    *   It is used to allow intro of new cars at times required    
    */
    int count = 0;
    for(int t = 0;t<tMax;t++){
        
        /* Goes through elements of 2d array from right to left */
        for(int i=0;i<rows;i++ ){
            for(int y=columns-1;y>=0;y--){
               
                /* Checks if item of array is 1. */
                if(array[i][y]=='1'){ 
                    
                    /* If 1 is at the end of the array it is replaced with '.' */
                    if(y == columns-1){
                        array[i][y]='.';
                    }
                    else{
                        /* 
                        *   If 1 is not at the end of the array 
                        *   It is swapped with the item in front of it.
                        */
                        char a = array[i][y];
                        char b = array[i][y+1];
                        
                        array[i][y+1] = a;
                        array[i][y] = b;
                    }
                }
                
            }
        }
        
        /*
        *   While loop checks it time is equal to the time cars should arrive
        *   If equal, a car is introduced on the row given by array rowAlloc.
        */
        while(t == timeAlloc[count]){
            int temp = rowAlloc[count];
            array[temp][0] = '1';
            count++;
        }
    }
    /*Prints the array output.*/
    print2dArray(array);
}
