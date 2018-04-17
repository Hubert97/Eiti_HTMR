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
} Board;

void copy_2()

void Load(Board* Board, char File_Name[] )
{
    FILE *Input;
    char tmp[32];
    char conv[3];
    conv[2]='\0';
        printf("\n Loading File");
    Input=fopen(File_Name, "r");
    fgets(tmp, 6 , (FILE*)Input);
        printf("..",tmp);
    conv[0]=tmp[0];
    conv[1]=tmp[1];
    atoi()




}
