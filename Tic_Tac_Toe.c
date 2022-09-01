#include <stdio.h>

void main(){
    char pos[9];
    pos[0] = '1';
    for (int i=1; i<9; i++)
        pos[i] = pos[i-1] + 1;
    int flag=1, i=0;
    printf("The game looks like: \n");
    print_board(&pos);
    do{
        printf("\n");
        char mark;
        int c;
        if (i%2==0){
            mark='X';
            printf("It's your turn Player1(enter a position in the grid): ");
        }
        else{
            mark='O';
            printf("It's your turn Player2(enter a position in the grid): ");
        }
        scanf("%d", &c);
        char temp=c+48;
        if(c<1 || c>9 || pos[c-1]!= temp){
            printf("Enter a valid position.\n");
            continue;
        }
        pos[c-1] = mark;
        i++;
        printf("The game looks like: \n");
        print_board(&pos);
        check_win(&pos, &flag);
        if (!flag){
            if (mark=='X')
                printf("\n^-^ You won Player1!\n");
            else
                printf("\n*-* You won Player2!\n");
            return;
        }
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
