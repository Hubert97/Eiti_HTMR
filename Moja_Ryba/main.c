#include <stdio.h>
#include <stdlib.h>
#include "Input_Output.h"
#include "Board.h"
#define NAME_MAX 256


typedef struct
{
int pos_X, pos_Y;
} Penguin;

typedef struct
{
char Name[NAME_MAX];
int Number_;
int Cought_Fish_;
Penguin *Penguins;
int amount_of_penguins;
} Player;


int main()
{

    Board *Board;
    char Input_File_Name[]="Input.txt";
    char Output_File_Name[] = "Output.txt";
    Load( Board, Input_File_Name);

    Player c;
    c.Cought_Fish_=2;

    printf("Hello world! %d \n", c.Cought_Fish_);
    return 0;
}
