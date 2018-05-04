#include <stdio.h>
#include <stdlib.h>

#include "Board.h"




int main()
{

    Board_type Board;
    Players Player_list;
    char Input_File_Name[]="Input.txt";
    char Output_File_Name[] = "Output.txt";
    int phase=0; // 0 placement 1 game
    int How_Many_Penguins=3;
   if( Load( &Board,&Player_list, Input_File_Name)==0)
   {


    Is_Data_Correct(&Board, &Player_list);
    Fill_penguins(&Board, &Player_list, How_Many_Penguins,phase);
    Save(&Board,&Player_list,Output_File_Name);
   }
   else
    {
        system("cls");
    printf("error");
    }

    return 0;
}
