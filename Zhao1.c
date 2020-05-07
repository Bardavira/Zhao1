#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void Game(){
    int random=rand()%101,guess, i=1;
    printf("Guess the drawn number!\n");
    scanf("%d", &guess);
    while (guess != random){
        i=i+1;
        if (guess>random){
            printf("You missed, the drawn number is smaller, try again:\n");
            scanf("%d", &guess);
        }else{
            printf("You missed, the drawn number is bigger, try again:\n");
            scanf("%d", &guess);
        }
    }
    printf("Congratulations, you guessed it right, the drawn number is %d, it only took you %d tries", random, i);
}
void Average (float *n, int t){
    int i=0;
    float sum=0, avrg;
    for (i;i<t;i++){
        sum=sum+n[i];
    }
    avrg=sum/t;
    printf("The given numbers average is: %f \n", avrg);
}
void Weighted_Average (float *n, int t){
    int i=0,j=0;
    float wts[t],sum=0,wtsum=0,wtavrg;
    printf("Please insert each number's weight:\n");
    for (i;i<t;i++){
        printf("Weight %d:\n",i+1);
        scanf("%f",&wts[i]);
    }
    for (j;j<t;j++){
        sum=sum+n[j]*wts[j];
        wtsum=wtsum+wts[j];
    }
    wtavrg=sum/wtsum;
    printf("The weighted average is: %f \n", wtavrg);
}
void Standart_Deviation(float *n, int t){
    int i=0,j=0;
    float sum=0, avrg, sqrdsum=0, standev;
    for (i;i<t;i++){
        sum=sum+n[i];
    }
    avrg=sum/t;
    for (j;j<t;j++){
        sqrdsum=sqrdsum+(n[j]-avrg)*(n[j]-avrg);
    }
    standev=sqrt(sqrdsum/t);
    printf("The populational standart deviation is: %f \n", standev);
}
void Bigger(float *n, int t){
    int i=1;
    float max=n[0];
    for(i;i<t;i++){
        if (n[i]>max){
            max=n[i];
        }
    }
    printf("The bigger number in the sample is: %f", max);
}
void Smaller(float *n, int t){
    int i=1;
    float min=n[0];
    for(i;i<t;i++){
        if (n[i]<min){
            min=n[i];
        }
    }
    printf("The smallest number in the sample is: %f", min);
}
void Operations(){
    int n=5;
    float nums[n];
    printf("Type %d numbers:\n", n );
    int i=0;
    for (i;i<n;i++){
        printf("%dº number:",i+1);
        scanf("%f", &nums[i]);
    }
    int oper;
    printf("Wich operation you want to do?\nSimple average: type 1\nWeighted Average: type 2\nStandart Deviation: type 3\nBigger Number: type 4\nSmaller Number: type 5\nExit: type 0\n");
    scanf ("%d", &oper);
    switch(oper){
        case 1: Average(nums, n); break;
        case 2: Weighted_Average(nums, n); break;
        case 3: Standart_Deviation(nums, n); break;
        case 4: Bigger(nums, n); break;
        case 5: Smaller(nums, n); break;
        case 0: break;
        default: printf("Invalid input, please relaunch the program");break;
    }
}
void main(){
    srand(time(0));
    int option;
    printf("Welcome, please select an option:\n");
    printf("Enter the operations module: type 1\n");
    printf("Play the Guessing Game: type 2\n");
    scanf("%d", &option);
    switch (option){
    case 1: Operations(); break;
    case 2: Game(); break;
    default: printf("Invalid input, please relaunch the program"); break;
    }
}
