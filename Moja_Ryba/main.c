#include <stdio.h>
#include <stdlib.h>
struct Tile
{
int Penguin_no;
int Fish_no;
int if_available;
};

struct Penguin
{
int pos_X, pos_Y;
int Player_No;
};

struct Player
{
char Name[256];
int Number_;
int Cought_Fish_;
};

int main()
{

    printf("Hello world!\n");
    return 0;
}
