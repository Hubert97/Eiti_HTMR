#ifndef BOARD_H
#define BOARD_H
#include "Players.h"
#include <stdio.h>

typedef struct
{
    int Player_no;
    int Fish_no;
    int if_available;
} Tile;

typedef struct
{
    Tile ** Plane;
    int size_m;
    int size_n;
} Board_type;

void copy_2()
{

}

void Load(Board_type* Board, char File_Name[] )
{
    FILE *Input;
    char tmp_a[32];
    char tmp_b[2];
    int iter_a=0;
    int iter_b=0;

        printf("\n Loading File");
    Input=fopen(File_Name, "r");               //opening file
   // fgets(tmp, 6 , (FILE*)Input);
    fscanf(Input,"%d %d", &(Board->size_m), &(Board->size_n) );     //loading size of board
        printf(".");
   // sscanf(tmp, "%d %d" , &(Board->size_m), &(Board->size_n));
        printf(".");
        printf(" Board Size: %d %d ", Board->size_m, Board->size_n);    //printing size of board
    Board->Plane=malloc(sizeof(Tile*)*Board->size_m);                   //allocating Board
    for(iter_a=0;iter_a<Board->size_m;++iter_a)
    {
        printf(".");
        Board->Plane[iter_a]=malloc(sizeof(Tile)*Board->size_n);
    }
     printf("\n");
    for(iter_a=0 ; iter_a<Board->size_m ; ++iter_a)                     //filling board with data from Input File
    {
        for( iter_b=0; iter_b<Board->size_n; ++iter_b)
        {

            fscanf(Input,"%s", tmp_a);
            printf(" %s ",tmp_a);
            tmp_b[0]=tmp_a[1];
            tmp_a[1]='\0';
            Board->Plane[iter_a][iter_b].Fish_no=atoi(tmp_a);               // setting Number of fishes from file
            Board->Plane[iter_a][iter_b].Player_no=atoi(tmp_b);             // Reading and setting player number

            if(Board->Plane[iter_a][iter_b].Fish_no==0)
            {
               Board->Plane[iter_a][iter_b].if_available=0;
            }
            else
            {
               Board->Plane[iter_a][iter_b].if_available=1;
            }
        }
        printf("\n");
    }


fclose(Input);
}


void Make_Players(Board_type* Board, Player_type *Player_List)
{

}

#endif // BOARD_H
