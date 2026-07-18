#include <stdio.h>

char b[9]={'1','2','3','4','5','6','7','8','9'};

int win(){
    int w[8][3]={{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    for(int i=0;i<8;i++)
        if(b[w[i][0]]==b[w[i][1]]&&b[w[i][1]]==b[w[i][2]])
            return b[w[i][0]]=='O'?1:-1;
    return 0;
}

int full(){
    for(int i=0;i<9;i++)
        if(b[i]!='X'&&b[i]!='O') return 0;
    return 1;
}

int minimax(int ai){
    int s=win();
    if(s||full()) return s;

    int best=ai?-2:2;

    for(int i=0;i<9;i++)
        if(b[i]!='X'&&b[i]!='O'){
            char t=b[i];
            b[i]=ai?'O':'X';
            int v=minimax(!ai);
            b[i]=t;
            if(ai&&v>best) best=v;
            if(!ai&&v<best) best=v;
        }
    return best;
}

void aiMove(){
    int best=-2,m;
    for(int i=0;i<9;i++)
        if(b[i]!='X'&&b[i]!='O'){
            char t=b[i];
            b[i]='O';
            int v=minimax(0);
            b[i]=t;
            if(v>best) best=v,m=i;
        }
    b[m]='O';
}

void show(){
    printf("\n%c|%c|%c\n-+-+-\n%c|%c|%c\n-+-+-\n%c|%c|%c\n",
    b[0],b[1],b[2],b[3],b[4],b[5],b[6],b[7],b[8]);
}

int main(){
    int m;
    while(1){
        show();
        printf("Move: ");
        scanf("%d",&m);
        if(b[m-1]=='X'||b[m-1]=='O') continue;
        b[m-1]='X';

        if(win()==-1){show();puts("You Win");break;}
        if(full()){show();puts("Draw");break;}

        aiMove();

        if(win()==1){show();puts("AI Wins");break;}
        if(full()){show();puts("Draw");break;}
    }
}