#include <stdio.h>
#include <stdlib.h>

#include "Board.h"




int main()
{

    Board_type Board;
    Players Player_list;
    char Input_File_Name[]="Input.txt";
    char Output_File_Name[] = "Output.txt";
    Load( &Board,&Player_list, Input_File_Name);
    Is_Data_Correct(&Board, &Player_list);
    Save(&Board,&Player_list,Output_File_Name);

    return 0;
}
