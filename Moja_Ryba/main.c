#include <stdio.h>
#include <stdlib.h>
#define NAME_MAX 256

typedef struct Tile
{
int Player_no;
int Fish_no;
int if_available;
} Pole;

typedef struct Penguin
{
int pos_X, pos_Y;
int Player_No;
} Pengu;

typedef struct Player
{
char Name[NAME_MAX];
int Number_;
int Cought_Fish_;
} Gracz;

int main()
{


    printf("Hello world!\n");
    return 0;
}
