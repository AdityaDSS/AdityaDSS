#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


void main(){
    //Initialization of the array
    char pos[9];
    pos[0] = '1';
    for (int i=1; i<9; i++)
        pos[i] = pos[i-1] + 1; // filling the array
    int flag=1, i=0;
    printf("The game looks like:   (User-X & Comp. - O) \n");
    print_board(&pos);
    printf("\n\n");
    printf("Toss: (if the randomly generated integer number is even you play first) ");
    time_t t;
    srand((unsigned) time(&t));
    int toss = rand();
    printf("The number is %d.\n", toss);
    int odd = (toss%2==0)?1:0;

    do{
        printf("\n");
        char mark;
        int c;
        if (odd){
            here:
            mark='X';
            printf("Your turn (enter a position in the grid): ");
            odd=0;
        }
        else{
            mark='O';
            printf("Now, it's my turn :) \n");
            c=comp_turn(&pos);
            char temp=c+48;
            pos[c-1] = mark;
            i++;
            printf("The game looks like: (User-X & Comp. - O)\n");
            print_board(&pos);
            check_win(&pos, &flag);
            if (!flag){
                if (mark=='X')
                    printf("\n^-^ You won Player1!\n");
                else
                    printf("\nI won!!!\n");
                return;
            }
            odd=1;
            continue;
        }
        scanf("%d", &c);
        char temp=c+48;
        if(c<1 || c>9 || pos[c-1]!= temp){
            printf("Enter a valid position.\n");
            goto here;
        }
        pos[c-1] = mark;
        i++;
        printf("The game looks like: (User-X & Comp. - O)\n");
        print_board(&pos);
        check_win(&pos, &flag);
        if (!flag){
            if (mark=='X')
                printf("\n^-^ You won Player1!\n");
            else
                printf("\n*-* You won Player2!\n");
            return;
        }
        system("cls");
    }while(flag && i<9);
    if (i==9)
        printf("Match Drawn.Well played!");
}

void print_board(char pos[]){
    for(int i=0; i<9;i++){
        printf("%c  ", pos[i]);
        if (i%3 == 2)
            printf("\n");
    }
}

check_win(char pos[], int *flag){
    if ( (pos[0] == pos[1] && pos[1] == pos[2]) || (pos[0] == pos[3] && pos[3] == pos[6]) || (pos[0] == pos[4] && pos[4] == pos[8]) )
        *flag = 0;
    else if ( (pos[1] == pos[4] && pos[4] == pos[7]) || (pos[2] == pos[4] && pos[4] == pos[6]) || (pos[2] == pos[5] && pos[5] == pos[8]) )
        *flag=0;
    else if ( (pos[3] == pos[4] && pos[4] == pos[5]) || (pos[6] == pos[7] && pos[7] == pos[8]) )
        *flag=0;
    else
        *flag=1;
}

int comp_turn(char pos[], int *flag){
    int d[9], mark=1;
    for(int i=0; i<9; i++){
        if ( (pos[i]=='X') || (pos[i]=='O') ){
            d[i]=-100;
        }
        else
            d[i]=0;
    }
    for (int i=1; i<9; i++){
        if (i==4)
            continue;
        if (d[i]!=0)
            mark=0;
    }
    if (pos[4]=='X' && mark){
        return 1;
    }
    for(int i=0; i<9; i++){
        flag=1;
        if(d[i]>=0){
            pos[i]='X';
            check_win(pos, &flag);
            if(!flag){
                pos[i]=i+ 49;
                return (i+1);
            }
            pos[i]='O';
            check_win(pos, &flag);
            if (!flag){
                pos[i] = i + 49;
                return i+1;
            }
            pos[i]=i+49;
        }
    }
    if (pos[4]=='O'){
        if (pos[0]=='1' && pos[1]!='X' && pos[3]!='X')
            return 1;
        if (pos[2]=='3' && pos[1]!='X' && pos[5]!='X')
            return 3;
        if (pos[6]=='7' && pos[3]!='X' && pos[7]!='X')
            return 7;
        if (pos[8]=='9' && pos[7]!='X' && pos[5]!='X')
            return 9;
    }
    if (pos[4]=='5')
        return 5;
    int max=0;
    for (int i=0; i<9; i++){
            if(d[i]>=max)
                max=d[i];
    }
    for(int i=0; i<9; i++){
        if(d[i]==max)
            return i+1;
    }
}
