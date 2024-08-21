#include "shared.h"

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void pause_screen()
{
    char pause = _getch();
    fflush(stdin);
}

void clean_area(int length, int height, int X_coord, int Y_coord)
{
    for(int i = 0; i < height; i++){
        gotoxy(X_coord,Y_coord + i);
        for(int j = 0; j < length; printf(" "), j++);
        printf("\n");
    }
}

short type_info(char *string, short max_length, short min_length)
{
    {
        short counter = 0;
        char key;
        while (1) {
            if (_kbhit()) 
            { //retorna um valor diferente de zero se uma key foi pressionada e está disponível para leitura no buffer de entrada
                key = _getch(); 

                if(key == 27) return 1;

                else if ((key == '\r' || key == '\n') && counter < min_length) {
                    continue;
                }
                else if (key == '\r' || key == '\n') { // Verifica se foi pressionada a key Enter
                    break;
                }
                else if (key == '\b') { // Verifica se foi pressionada a key Backspace
                    if (counter > 0) {
                        putch('\b'); // Move o cursor de volta
                        putch(' '); // Sobrescreve o caractere anterior com um espaço
                        putch('\b'); // Move o cursor de volta novamente
                        counter--;
                    }
                }
                else if (counter < max_length) {
                    string[counter] = key;
                    counter++;
                    printf("%c",key); 
                }
            }
        }
        string[counter] = '\0'; // Adiciona o caractere nulo ao final da senha
        return 0;
    }    
}
