#include <stdio.h>
#include <stdlib.h>
#include "Input_Output.h"
#include "Board.h"




int main()
{

    Board_type *Board;
    Player_type *Player_list;
    char Input_File_Name[]="Input.txt";
    char Output_File_Name[] = "Output.txt";
    Load( &Board, Input_File_Name);

    Player_type c;
    c.Cought_Fish_=2;

    printf("\n %d \n", c.Cought_Fish_);
    return 0;
}
