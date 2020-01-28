
#include <infos.h>
#include "character.h"
#include "random.h"

const int SCREENWIDTH = 80;
const int SCREENHEIGHT = 23;

bool map[SCREENWIDTH][SCREENHEIGHT];

//List<Character *> characters;
//List<Item*> items;
RNG *rng;
void RefreshScreen()
{
    // clear the screen
    for (int i = 0; i < SCREENHEIGHT; i++)
    {
        printf("\n");
    }

    for (int i = 0; i < SCREENHEIGHT; i++)
    {
        for (int j = 0; j < SCREENWIDTH; j++)
        {
            if (map[j][i])
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
    }
}

void Quit()
{
}

void CreateNewFloor()
{
    //using cellular automata
    //create initial seed world
    for (int i = 0; i < SCREENHEIGHT; i++)
    {
        for (int j = 0; j < SCREENWIDTH; j++)
        {
            if (i == 0 || i == SCREENHEIGHT - 1 || j == 0 || j == SCREENWIDTH - 1)
            {
                map[j][i] = true;
                continue;
            }
            int roll = rng->Next(100);
            if (roll < 55)
            {
                map[j][i] = false;
            }
            else
            {
                map[j][i] = true;
            }
        }
    }
    //iterate
    for (int k = 0; k < 3; k++)
    {
        bool newMap[SCREENWIDTH][SCREENHEIGHT];
        for (int i = 0; i < SCREENHEIGHT; i++)
        {
            for (int j = 0; j < SCREENWIDTH; j++)
            {
                if (i == 0 || i == SCREENHEIGHT - 1 || j == 0 || j == SCREENWIDTH - 1)
                {
                    newMap[j][i] = true;
                    continue;
                }
                int numWalls = 0;
                for (int ii = i - 1; ii <= i + 1; ii++)
                {
                    for (int jj = j - 1; jj <= j + 1; jj++)
                    {
                        if (map[jj][ii])
                        {
                            numWalls++;
                        }
                    }
                }

                if (numWalls >= 5)
                {
                    newMap[j][i] = true;
                }
                else
                {
                    newMap[j][i] = false;
                }
            }
        }
        //copy the new map across
        for (int i = 0; i < SCREENHEIGHT; i++)
        {
            for (int j = 0; j < SCREENWIDTH; j++)
            {

                map[j][i] = newMap[j][i];
            }
        }
    }
}

int main(const char *cmdline)
{
    printf("    APPLETON TOWER QUEST\n    By Nimrod Libman\n");
    getch();
    RNG r = RNG();

    printf("SOFTWARE RELATED CRIMES THESE DAYS... APPLETON TOWER IS NOT THE EXCEPTION\n");
    getch();
    printf("VOLKER SEEKER HAS BEEN KIDNAPPED BY HACKERS.\n ARE YOU A BAD ENOUGH STUDENT TO SAVE VOLKER?\n");
    getch();
    rng = &r;
    struct tod t;

    int rc = get_time_of_day(&t);
    rng->SetSeed(t.seconds);

    CreateNewFloor();
    printf("\n");
    while (true)
    {
        RefreshScreen();
        char c = getch();
        if (c == '\n')
            break;
    }
    Quit();
    return 0;
}