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

void Load(Board* Board, char File_Name[] )
{
    FILE *Input;
    char tmp[32];
    printf("\n Loading File");
    Input=fopen(File_Name, "r");
    fgets(tmp, , (FILE*)Input);
    printf(".. \n%s end",tmp);


}
