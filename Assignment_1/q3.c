#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void print(int arr[10][10]);

int main(void){

    srand(time(NULL));

    int sum;
    //Change the answer key as per your needs 
    int answer_key[] = {3,1,4,1,2,3,4,2,4,1};
    int answer_sheet[10][10];
    
    //Filling the answer sheet randomly
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
            answer_sheet[i][j] = 1 + rand()%4;

    //Checking the answer sheet
    printf("\t***Marks***\n");
    for(int i=0; i<10; i++)
    {
        sum = 0;
        for(int j=0; j<10; j++)
            if(answer_key[j] == answer_sheet[i][j])
                sum += 4;
        printf("Student %d: %d \n",i+1,sum);


    }
    
//  print(answer_sheet);
}


//optional function to print answer sheet of students
/*
void print(int array[10][10]){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            printf("%d   ",array[i][j]);
        }
        printf("\n");
    }
}
*/
