
#include <infos.h>

const int SCREENWIDTH = 80;
const int SCREENHEIGHT = 24;

void RefreshScreen()
{
    //clear the screen
    for (int i = 0; i < SCREENHEIGHT * SCREENWIDTH; i++)
    {
        printf("a");
    }
   
}

void Quit()
{
    
}

int main(const char *cmdline)
{
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
