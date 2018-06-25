/******************************************************************************

Suhail Munshi Assignment 2 Problem 1081 Game of Life.
				*ONLINE JUDGE ACCEPTED* ID : 15273

*******************************************************************************/
#include <stdio.h>
/*
Declare global variables for use in multiple methods.
*/
int rows;
int columns;
int steps;

/*Pre-declare methods that are used later.*/
char getChar();
void printArray();


/*
Method to retrieve and validate an Integer.
*/
int getInt(){
    int input = 0;
    while(1){
        scanf("%d",&input);
        if(input>0) break;
        else printf("\nMust be positive Integer\n");
    }
    return input;
}

/*Main Method*/
int main()
{
    rows = getInt();
    columns = getInt();
    steps = getInt();
    
    char arr[rows][columns];
    char newArr[rows][columns];
    
    /*
    For loop calling method to retrieve and input into 
    charachter array
    */
    for(int i=0;i<rows;i++ ){
        for(int j=0;j<columns;j++){
            arr[i][j] = getChar();
        }
    }
    
    /*Function to copy contents of first array into the second*/
    memcpy(newArr, arr, rows*columns);
    
    /*First for loop goes through each iteration*/
    for(int k =0;k<steps;k++){
        /*second and thrid for loop go through each item of the 2d array*/
        for(int i=0;i<rows;i++ ){
            for(int j=0;j<columns;j++){
                /*Calls method to retrieve number of live neighbours for each item of array*/
                int count = 0;
                count = getNeighbours(i,j,arr);
                
                /*Applying game of life rules*/
                if(count>3) newArr[i][j] = '.';
                if(count<2) newArr[i][j] = '.';
                if(count==3) newArr[i][j] = 'X';
            }
        }
        /*Copies second array contents to first to allow iteration to continue*/
        memcpy(arr,newArr, rows*columns);
    }
    
    /*Method to print Array*/
    printArray(newArr);
    
    return 0;
}


/*
* Method to determine the number of neighbours
* Method returns number of neighbours.
*/
getNeighbours(int i,int j,char arr[rows][columns]){
    int count=0;
    /*
    *   Outer If statement prevents unexpected results due to arrayOutOfBounds
    *   Inner if statement determines number of live neighbours.
    */
    if(i!=0){
     if(arr[i-1][j]=='X') count++;
    }
    
    if(j!=0){
        if(arr[i][j-1]=='X') count++;
    }
    
    if(j!=0 && i!=0){
        if(arr[i-1][j-1]=='X') count++;
    }
    
    if(i<rows-1){
        if(arr[i+1][j]=='X') count++;
    }
    
    if(j<columns-1){
        if(arr[i][j+1]=='X') count++;
    }
    
    if(j<columns-1 && i<rows-1){
        if(arr[i+1][j+1]=='X') count++;
    }
    
    if(i<rows-1 && j!=0){
        if(arr[i+1][j-1]=='X') count++;
    }
    
    if(i!=0 && j<columns-1){
        if(arr[i-1][j+1]=='X') count++;
    }
    
    return count;
}

/*
* Using array in parameter, Method prints array.
* Array is printed charachter by charachter with line break.
*/
void printArray(char newArr[rows][columns]){
    /*Output array charachter by charachter*/
    for(int i=0;i<rows;i++ ){
        for(int j=0;j<columns;j++){
            printf("%c",newArr[i][j]);
        }
        printf("\n");
    }
}

/*
Retrieve non empty charachter from input and return.
*/
char getChar(){
    char input;
    while(1){
        scanf("%c",&input);
        if(input != ' ' && input!='\n' && input!='EOL') break;
    }
    return input;
}




