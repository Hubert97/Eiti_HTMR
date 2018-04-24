    #ifndef BOARD_H
    #define BOARD_H
    #include "Players.h"
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
    } Board_type;


    int countlines(char *File_Name)
    //counts "\n" in file
    {
        FILE *Input ;
        Input= fopen(File_Name,"r");
        int ch=0;
        int lines=0;

        if (Input != NULL);
        {

        lines++;
        while(!feof(Input))
        {
            ch = fgetc(Input);
            if(ch == '\n')
            {
                lines++;
            }
        }

        }
        fclose(Input);
        return lines;
    }


    int Is_Data_Correct(Board_type* Board, Players *Player_List)
    //checks for Discrepancies in structures
    {
        int iter_a=0;
        int iter_b=0;
        int tab[11];
        int amount=0;
        int err=0;
        int tmp=0;

        for(iter_a=0 ; iter_a<Board->size_m ; ++iter_a)                     //filling board with data from Input File
        {
            for( iter_b=0; iter_b<Board->size_n; ++iter_b)
            {

                tab[(Board->Plane[iter_a][iter_b].Player_no)]=1;

            }

        }

        for(iter_a=1; iter_a<10;++iter_a)                           //tests if all players that are on board exist.
        {
             tmp=0;



               if(tab[iter_a]==1)
               {
                      for(iter_b=0; iter_b<Player_List->amout_of_players; ++iter_b)
                    {

                       if(Player_List->Players[iter_b].Number_==iter_a)
                            {
                            tmp=1;
                            }
                   }

                      if(!tmp)
                    {
                        err=1;
                    }

               }



        }

        printf("\n err code: %d ", err);
        if(err!=0)
        {
           printf(" Discrepancy found. Input file not valid \n");
        }
        else
        {
            printf(" Structure integrity correct. \n");
        }

return err;


    }


    int Load(Board_type* Board, Players *Player_List, char File_Name[] )
    //Loads Input file and creates structures
    {

        FILE *Input;
        char tmp_a[32];
        char tmp_b[2];
        int iter_a=0;
        int iter_b=0;
        Board->size_m=0;
        Board->size_n=0;
        int lines=countlines(File_Name);
        //printf("\n zostalo linni:  %d \n",lines);
        // Players Tmp_Player_List;


        printf("\n Loading File");
        Input=fopen(File_Name, "r");               //opening file

        fscanf(Input,"%d %d", &(Board->size_m), &(Board->size_n) );     //loading size of board
        lines--;
        printf(" Board Size: %d %d ", Board->size_m, Board->size_n);    //printing size of board

        if( 0>(Board->size_n) || 0>(Board->size_m) )            //checking for size error
        {
            printf("\n Error: table size not correct");
            return 1;
        }
        printf(" Board Size: %d %d ", Board->size_m, Board->size_n);    //printing size of board

        Board->Plane=malloc(sizeof(Tile*)*Board->size_m);                   //allocating Board
        for(iter_a=0; iter_a<Board->size_m; ++iter_a)
        {
            printf(".");
            Board->Plane[iter_a]=malloc(sizeof(Tile)*Board->size_n);
        }
        printf("\n");
        for(iter_a=0 ; iter_a<Board->size_m ; ++iter_a)                     //filling board with data from Input File
        {
            for( iter_b=0; iter_b<Board->size_n; ++iter_b)
            {

                fscanf(Input,"%s", tmp_a);


                tmp_b[0]=tmp_a[1];
                tmp_a[1]='\0';
                Board->Plane[iter_a][iter_b].Fish_no=atoi(tmp_a);               // setting Number of fishes from file
                Board->Plane[iter_a][iter_b].Player_no=atoi(tmp_b);             // Reading and setting player number
                printf(" %d%d ",  Board->Plane[iter_a][iter_b].Fish_no,Board->Plane[iter_a][iter_b].Player_no);
                if(Board->Plane[iter_a][iter_b].Fish_no==0)
                {
                    Board->Plane[iter_a][iter_b].if_available=0;
                }
                else
                {
                    Board->Plane[iter_a][iter_b].if_available=1;
                }
            }
            lines--;
            printf("\n");
        }
            printf("\n zostalo linni:  %d \n",lines);
        if(lines>0)
        {

            Player_List->Players=malloc(sizeof(Player_type)*lines);
            Player_List->amout_of_players=lines;
            int iter_c;
            for(iter_c=0; iter_c<lines; iter_c++)
            {
                fscanf(Input,"%s %d %d", Player_List->Players[iter_c].Name, &Player_List->Players[iter_c].Number_, &Player_List->Players[iter_c].Cought_Fish_ );
                printf("\n %s %d %d line [%d]", Player_List->Players[iter_c].Name, Player_List->Players[iter_c].Number_, Player_List->Players[iter_c].Cought_Fish_, iter_c );

            }

        }

        system("cls");
        fclose(Input);
        return 0;
    }


    int Save(Board_type *Board,Players *Player_list, char Output_File_Name[] )
    //saves internal structures to file
    {
        if(Is_Data_Correct(Board,Player_list)==0)
            {

                FILE *Output;
                Output=fopen(Output_File_Name, "w");
                int iter_a=0;
                int iter_b=0;
                fprintf(Output, "%d %d\n", Board->size_m, Board->size_n);
                for(iter_a=0 ; iter_a<Board->size_m ; ++iter_a)                     //filling board with data from Input File
                {
                    for( iter_b=0; iter_b<Board->size_n; ++iter_b)
                    {
                        fprintf(Output,"%d%d " , Board->Plane[iter_a][iter_b].Fish_no,Board->Plane[iter_a][iter_b].Player_no);
                    }
                 fprintf(Output,"\n");

                }


                for(iter_a=0; iter_a<Player_list->amout_of_players;++iter_a)
                {
                    fprintf(Output, "%s %d %d\n", Player_list->Players[iter_a].Name, Player_list->Players[iter_a].Number_,Player_list->Players[iter_a].Cought_Fish_ );
                }


   fclose(Output);
   // system("cls");
    printf("\n Saving to File: %s\n", Output_File_Name);
            }
return 0;

    }

    #endif // BOARD_H
