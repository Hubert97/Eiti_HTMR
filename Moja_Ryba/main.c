#include <stdio.h>
#include <stdlib.h>
#define NAME_MAX 256

typedef struct
{
int Player_no;
int Fish_no;
int if_available;
} Tile;

typedef struct
{
int pos_X, pos_Y;
int Player_No;
} Penguin;

typedef struct
{
char Name[NAME_MAX];
int Number_;
int Cought_Fish_;
Penguin *Penguins;
} Player;

int main()
{

    Player c;
    c.Cought_Fish_=2;

    printf("Hello world! %d \n", c.Cought_Fish_);
    return 0;
}
