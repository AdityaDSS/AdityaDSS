#include <stdio.h>
#include <math.h>

void main(){
    printf("Enter three integers(Number, width, and length) : ");
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
   // pat1(a,b);
    //pat2(a,b);
    pat1(a,b,c);
    //pat2(a);

}


void pat1(a,b,c){
    int n=a, spaces, r=1, col, num, flag1, sp, hor=1, flag2, bts;
    for (int j=c; j>=1; j--){
        sp=n;
        bts = 1;
        for (int r=1; r<=n; r++){//first half first scene
            for (spaces=((2*n)); spaces>=(2*r); spaces--)
                printf(" ");
            for (col =1, num=1; col<=(2*r -1); col++){
                if (col < r)
                    printf("%d ", num++);
                else if (col == r)
                    printf("%d ", num);
                else
                    printf("%d ", --num);
            }
            flag1=1;
            sp--;
            hor=1;
            here:
            hor++;
            if (hor<=b){//first half repetition horizontally scene
                label:
                if (flag1){
                    for (int k=1; k<= (4*sp); k++)
                        printf(" ");

                    for (col = 1, num = 1; col <= (2*r -1); col++){
                        if (col < r)
                            printf("%d ", num++);
                        else if (col == r)
                            printf("%d ", num);
                        else
                            printf("%d ", --num);
                    }
                    if (++hor>b)
                        flag1=0;
                    goto label;
                }
            }
            printf("\n");
        }
        int n=a-1,r=1, spaces, col, num;
        for (r=n; r>=1; r--){//Second ha;f first scene
            for (spaces=(2*(n+1)); spaces >= (2*r); spaces--){
                printf(" ");
            }
            for (col=1, num=1; col <= (2*r -1); col++){
                if (col < r)
                    printf("%d ", num++);
                else if (col == r)
                    printf("%d ", num);
                else
                    printf("%d ", --num);
            }

            flag2=1;
            hor=1;
            hor++;
            if(hor<=b){//Second half repetition scene...
                label2:
                if (flag2){
                    for (int k=1; k<=4*bts; k++){
                        printf(" ");
                    }
                    for (col=1, num=1; col <= (2*r -1); col++){
                        if (col < r)
                            printf("%d ", num++);
                        else if (col == r)
                            printf("%d ", num);
                        else
                            printf("%d ", --num);
                    }
                    if (++hor>b)
                        flag2=0;
                    goto label2;

                }
            }
            bts++;
            printf("\n");
        }
    }
}





