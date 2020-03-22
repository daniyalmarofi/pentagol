#include <stdio.h>
#include <stdlib.h>
#define TRUE 1

void showBoard();
void getUserInput(char );
void rotateArea(int , char);
char board[6][6]={0};


int main()
{
    
    board[2][3]='b';
    board[1][5]='b';
    board[0][4]='w';
    board[3][0]='w';
    board[4][1]='b';
    board[5][5]='w';

    while (TRUE){
        showBoard();
        getUserInput('b');
        showBoard();
        getUserInput('w');
    }
    
    getchar();
    return 0;
}

void getUserInput(char turn){
    printf("\n%c player's turn:",turn);
    int input=0,y=0;
    int getOK=1;
    while(getOK){
        y=scanf("%d",&input);
        // ignore if user input was "abc..." : clearBuffer
        // TODO fix bug in 20fdfdfdsfgdfgrjhfgds
        while(getchar() != '\n');
        if(y!=1 || input<11){
            printf("Wrong input! Try again! :");
            continue;
            }
        getOK=0;
        int column=input%10;
        int row=input/10;
        if(column>6 || row>6 || column<1 || row<1){getOK=1;printf("Wrong input! Try again! :");continue;}
        if(board[row-1][column-1]==0){
            board[row-1][column-1]=turn;
        }else{
            getOK=1;printf("This place is already taken! Try another! :");
        }
    }
    printf("select the area to rotate:");
    int selectedArea=0;
    getOK=1;
    while(getOK){
        y=scanf("%d",&selectedArea);
        // ignore if user input was "abc..." : clearBuffer
        // TODO fix bug in 20fdfdfdsfgdfgrjhfgds
        while(getchar() != '\n');
        if(y!=1 || selectedArea<1 || selectedArea>4){
            printf("Wrong input! Try again! :");
            continue;
        }
        getOK=0;
    }

    printf("select the direction of rotate:");
    char direction;
    getOK=1;
    while (getOK)
    {
        y=scanf("%c",&direction);
        // ignore if user input was "abc..." : clearBuffer
        // TODO fix bug in 20fdfdfdsfgdfgrjhfgds
        while(getchar() != '\n');
        if(y!=1 || (direction!='-' && direction!='+')){
            printf("Wrong input! Try again! :");
            continue;
        }
        getOK=0;
    }
    // do the rotate
    rotateArea(selectedArea,direction);

}


void rotateArea(int area, char dircetion){
    int iFirst,jFirst;
    if(area==1){
        iFirst=0;
        jFirst=3;
    }else if(area==2){
        iFirst=0;
        jFirst=0;
    }else if(area==3){
        iFirst=3;
        jFirst=0;
    }else if(area==4){
        iFirst=3;
        jFirst=3;
    }
    char temp[3][3]={0};

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            // +
            if(dircetion=='+'){
                temp[j][2-i]=board[iFirst+i][jFirst+j];
            }else if(dircetion=='-'){
                temp[2-j][i]=board[iFirst+i][jFirst+j];
            }
        }
    }

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            // if(temp[i][j]==0){printf("\t.");}
            // else{printf("\t%c",temp[i][j]);}
            board[iFirst+i][jFirst+j]=temp[i][j];
        }
    }
    

}


void showBoard(){
    system("cls");
    printf("  \t1\t2\t3\t \t4\t5\t6 \n");
    printf("  ______________________________________________________________ \n");
    for (int i = 0; i < 6; i++)
    {
        if(i==3){printf(" |------------------------------|-------------------------------|\n");}
        else if(i>0){printf(" |\t \t \t \t|\t \t \t \t|\n |\t \t \t \t|\t \t \t \t|\n");}
        printf("%d|",(i+1));
        for (int j = 0; j < 6; j++){
            if(j==3){printf("\t|");}
            if(board[i][j]==0){printf("\t.");}
            else{printf("\t%c",board[i][j]);}
            if(j==5){printf("\t|\n");}
        }
    }
    printf(" |______________________________|_______________________________|\n");
}