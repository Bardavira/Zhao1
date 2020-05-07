#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void Game(){
    /*game function, defined by void once it doesn't return anything*/
    int random=rand()%101,guess, i=1;
    /*generates a random number from 0 to 100 (as the % operation only generates numbers in this range), initiates a 'guessing' variable and a loop intended counter (used to count the number of tries)*/
    printf("Guess the drawn number!\n");
    scanf("%d", &guess);
    /*prints a command to the user, asking for it to guess the generated number, and scans the number right after*/
    while (guess != random){
        i=i+1;
        if (guess>random){
            printf("You missed, the drawn number is smaller, try again:\n");
            scanf("%d", &guess);
        }else{
            printf("You missed, the drawn number is bigger, try again:\n");
            scanf("%d", &guess);
        }
        /*conditional used to let the player know if he guessed higher or lower than the random number*/
    }
    /*loop intended to keep the game working while the player doesn't win*/
    printf("Congratulations, you guessed it right, the drawn number is %d, it only took you %d tries", random, i);
    /*end of the game, only achieved if the player gets the number right*/
}
void Average (float *n, int t){
    /*Average function, takes a numbers array, and the array's lenght as parameters, doesn't return anything*/
    int i=0;
    float sum=0, avrg;
    /*generates three variables, a couter loop-intended, the sum of the numbers in the array, and the average of the numbers (print intended)*/
    for (i;i<t;i++){
        sum=sum+n[i];
    }
    /*loop used to sum all the numbers in the array*/
    avrg=sum/t;
    /*calculation of the average through the sum and the lenght of the array*/
    printf("The given numbers average is: %f \n", avrg);
    /*end of the function, prints the average*/
}
void Weighted_Average (float *n, int t){
    /*almost the same code used in the average calculator, takes as well a numbers array and the lenght of it, returns nothing*/
    int i=0,j=0;
    float wts[t],sum=0,wtsum=0,wtavrg;
    /*generates six variables, two counters, a new array for the weights of each number, the overall sum, the weights' sum and the weighted average*/
    printf("Please insert each number's weight:\n");
    for (i;i<t;i++){
        printf("Weight %d:\n",i+1);
        scanf("%f",&wts[i]);
    }
    /*asks for, reads and places the weights in an array of the same lenght of the numbers array*/
    for (j;j<t;j++){
        sum=sum+n[j]*wts[j];
        wtsum=wtsum+wts[j];
    }
    /*loop used to sum the weighted numbers as well as the numbers in the weights array*/
    wtavrg=sum/wtsum;
    /*calculation of the weighted average*/
    printf("The weighted average is: %f \n", wtavrg);
    /*end of the function prints the weighted average*/
}
void Standart_Deviation(float *n, int t){
    /*standart deviation function, takes a numbers array, it's lenght, returns nothing */
    int i=0,j=0;
    float sum=0, avrg, sqrdsum=0, standev;
    /*generates six variables, two counters, a sum used to produce the average of the given array, the average, the sum of the squared diferences between n[i] and the average (used in the stan. dev. calculus), and the standart deviation*/
    for (i;i<t;i++){
        sum=sum+n[i];
    }
    /*sums the numbers in the array*/
    avrg=sum/t;
    /*generates the average of the array*/
    for (j;j<t;j++){
        sqrdsum=sqrdsum+(n[j]-avrg)*(n[j]-avrg);
    }
    /*sums the squared differences between n[i] and the average*/
    standev=sqrt(sqrdsum/t);
    /*calculates the POPULATIONAL standart deviation, the sample standart deviation would use (t-1)*/
    printf("The populational standart deviation is: %f \n", standev);
    /*end of the function, prints the populational standart deviation of the array*/
}
void Biggest(float *n, int t){
    /*function used to pick the biggest number in the array, returns nothing*/
    int i=1;
    float max=n[0];
    /*generates a counter (i=1 because we already picked the n[0] in the max variable initiation), and the maximum value found*/
    for(i;i<t;i++){
        if (n[i]>max){
            max=n[i];
        }
    }
    /*simple iterator, goes through the array and replaces the max variable if the current number is bigger*/
    printf("The biggest number in the sample is: %f", max);
    /*end of function, prints the biggest number in the array*/
}
void Smallest(float *n, int t){
    /*is the "same" function as the last one, it's used, however, to pick the smallest*/
    int i=1;
    float min=n[0];
    for(i;i<t;i++){
        if (n[i]<min){
            min=n[i];
        }
    }
    /*the difference is made in this iterator, as it uses (n[i]<min) to pick the smallest number*/
    printf("The smallest number in the sample is: %f", min);
    /*end of function, prints the biggest number in the array*/
}
void Operations(){
    /*menu function for the mathematical part of the program, takes no parameter and returns nothing*/
    int n=5, i=0;
    float nums[n];
    /*generates three variables, the lenght n of the array, a counter, and the numbers array*/
    printf("Type %d numbers:\n", n );
    for (i;i<n;i++){
        printf("%dº number:",i+1);
        scanf("%f", &nums[i]);
    }
    /*asks, reads and places the numbers in the array*/
    int oper;
    /*initiates a variable used to determine wich operation will be called*/
    printf("Wich operation you want to do?\nSimple average: type 1\nWeighted Average: type 2\nStandart Deviation: type 3\nBigger Number: type 4\nSmaller Number: type 5\nExit: type 0\n");
    scanf ("%d", &oper);
    /*asks and reads the user choice*/
    switch(oper){
        case 1: Average(nums, n); break;
        case 2: Weighted_Average(nums, n); break;
        case 3: Standart_Deviation(nums, n); break;
        case 4: Biggest(nums, n); break;
        case 5: Smallest(nums, n); break;
        case 0: break;
        default: printf("Invalid input, please relaunch the program");break;
    }
    /*switch used to call the function selected by the user, if the user chooses an invalid operation, the switch prints that the option is invalid and tells the user to relaunch the program*/
}
void main(){
    /*main function, used to host the two main options of the program, either the math module or the game module*/
    srand(time(0));
    /*generates a new random seed everytime the program is loaded*/
    int option;
    /*creates the variable used to determine the user choice*/
    printf("Welcome, please select an option:\n");
    printf("Enter the operations module: type 1\n");
    printf("Play the Guessing Game: type 2\n");
    scanf("%d", &option);
    /*asks and reads the user choice*/
    switch (option){
    case 1: Operations(); break;
    case 2: Game(); break;
    default: printf("Invalid input, please relaunch the program"); break;
    }
    /*switch used to call the function selected by the user, if the user chooses an invalid operation, the switch prints that the option is invalid and tells the user to relaunch the program*/
}