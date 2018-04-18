#ifndef PlAYERS_H
#define PlAYERS_H
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

} Player_type;

typedef struct
{
    Player_type * Players;
    int No_Player_;

} Players;
#endif // PlAYERS_H
