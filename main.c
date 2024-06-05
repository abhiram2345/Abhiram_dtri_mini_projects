#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

char matrix[3][3];
const char Player='X';
const char Computer='O';

void reset_matrix();
void print_matrix();
void player_move();
void computer_move();
int check_freespaces();
char check_winner();
void print_winner(char);

int main()
{
    char winner=' ';
    char response=' ';

    do
    {
        winner=' ';
        response=' ';
        reset_matrix();
        while(winner==' '&&check_freespaces()>0)
        {
            player_move();
            winner=check_winner();
            if(winner!=' '|| check_freespaces()==0)
            {
                break;
            }


            computer_move();
            winner=check_winner();
            if(winner!=' '|| check_freespaces()==0)
            {
                break;
            }
            print_matrix();
        }
        print_matrix();
        print_winner(winner);

        printf("\nWould you like to play again(Y/N)?");
        scanf("%c");
        scanf("\n%c",&response);
        response=toupper(response);
    }
    while(response=='Y');

    printf("Game Over!");

    return 0;
}

void reset_matrix()
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            matrix[i][j]=' ';
        }
    }

}

void print_matrix()
{

        printf(" %c | %c | %c ",matrix[0][0],matrix[0][1],matrix[0][2]);
        printf("\n");
        printf(" %c | %c | %c ",matrix[1][0],matrix[1][1],matrix[1][2]);
        printf("\n");
        printf(" %c | %c | %c ",matrix[2][0],matrix[2][1],matrix[2][2]);
        printf("\n");
}

void player_move()
{
    int x,y;
    do
    {
        printf("enter row between [1,3]\n");
        scanf("%d",&x);
        x--;

        printf("enter column between[1,3]\n");
        scanf("%d",&y);
        y--;

        if(matrix[x][y]!=' ')
        {
            printf("Invalid move\n");
            break;
        }
        else
        {
            matrix[x][y]=Player;
            break;
        }
    }
    while(matrix[x][y]!=' ');

}

void computer_move()
{
    int x,y;

    srand(time(0));
    if(check_freespaces()>0)
    {
        do
        {
            x=rand()%3;
            y=rand()%3;
        }
        while(matrix[x][y]!=' ');

        matrix[x][y]=Computer;
    }
    else
    {
        print_winner(' ');
    }

}
int check_freespaces()
{
    int freespaces=9;

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(matrix[i][j]!=' ')
                freespaces--;
        }
    }
    return freespaces;

}
char check_winner()
{
    //rows
    for(int i=0; i<3; i++)
    {
        if(matrix[i][0]==matrix[i][1]&& matrix[i][0]==matrix[i][2])
            return matrix[i][0];
    }
    //columns
    for(int i=0; i<3; i++)
    {
        if(matrix[0][i]==matrix[1][i]&& matrix[0][i]==matrix[2][i])
            return matrix[0][i];
    }
    //diagonals
    if(matrix[0][0]==matrix[1][1]&&matrix[0][0]==matrix[2][2])
        return matrix[0][0];
    if(matrix[0][2]==matrix[1][1]&&matrix[0][2]==matrix[2][0])
        return matrix[0][2];

    return ' ';
}
void print_winner(char winner)
{
    if(winner==Player)
    {
        printf("Player win");
    }
    else if(winner==Computer)
    {
        printf("computer wins");
    }
    else
    {
        printf("game tied");
    }
}
