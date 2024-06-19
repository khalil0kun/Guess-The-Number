#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

void hot_cold(int n,int u){
    int d=abs(n-u);
    if (d<5){
        printf("You're BURNING !!!\n");
    }else if(d<=10){
        printf("You're REALLY HOT !\n");
    }else if(d<=25){
        printf("Getting Hot In Here.\n");
    }else{
        printf("Cold...\n");
    }
}

int main(){
    srand(time(NULL));
    printf(">>>>>>>>>>>>   Welcome To Guess The Number !!!   <<<<<<<<<<<<\n");
    int PlayAgain=1,Numb,User,Attempts,Record=0,FirstGame=1;
    while (PlayAgain==1){
        Attempts=1;
        Sleep(2000);
        system("cls");
        Numb=rand()%100;
        printf("Enter Your Guess   ");
        scanf("%d",&User);
        while(User != Numb){
            printf("Wrong...");
            hot_cold(Numb,User);
            Attempts+=1;
            printf("Enter Your Guess   ");
            scanf("%d",&User);
        }
        printf("GOOD GUESS, YOU DID IT !!!");
        if (Attempts==1){
            printf("\n\nYou Won The Game After %d Try !",Attempts);
        }else{
            printf("\n\nYou Won The Game After %d Tries !",Attempts);
        }
        if (FirstGame || Attempts < Record) {
            Record = Attempts;
            printf("\n\n------->Your New Personal Best Is %d tries!\n", Record);
            FirstGame = 0;
        }
        printf("\nWould You Like To Play Again ? (Press 1 To Continue)   ");
        scanf("%d",&PlayAgain);
    }
    if (Record==1){
            printf("\n\nYour Personal Best Was %d Try !",Record);
        }else{
            printf("\n\nYour Personal Best Was %d tries !",Record);
        }
    return 0;
}