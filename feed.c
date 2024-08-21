#include "feed.h"

short type_feed(char *type_post, short linha)
{
    {
        short counter = 0;
        char key;
        gotoxy(STARTING_DEFAUT_X_POSITION,linha);

        while (1) {
            if (_kbhit()) //retorna um valor diferente de zero se uma key foi pressionada e está disponível para leitura no buffer de entrada
            { 
                key = _getch();

                if(key == 27) return 1;

                else if(key == '\r' || key == '\n') { 
                    break;
                }
                else if(key == '\b') { 
                    if (counter > 0) {
                        putch('\b'); 
                        putch(' '); 
                        putch('\b');

                        if(counter-- == 93)
                        {
                            gotoxy(129, --linha);
                        }
                    }
                }
                else if(counter < MAX_POST_LENGTH - 1) {
                    type_post[counter] = key;
                    if(counter++ == 92)
                    {
                        gotoxy(STARTING_DEFAUT_X_POSITION, ++linha);
                    }
                    printf("%c",key); //printa o caractere
                }
            }
        }
        type_post[counter] = '\0'; // Adiciona o caractere nulo ao final da string
        return 0;
    }
}//NOVENTA E DOIS E O TANTO DE CARACTERES POR LINHA COMECANDO DA POSICAO 37. !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void print_feed_posts(struct user *logged_user, short starter_line)
{   
    short line = starter_line + 2, i;
    struct feed *print_this_post = logged_user -> next_feed;

    if (print_this_post == NULL)
    {
        gotoxy(STARTING_DEFAUT_X_POSITION, starter_line); printf(YEL" * "WHT"This user has no posts yet");
        return;
    }
    
    gotoxy(STARTING_DEFAUT_X_POSITION, starter_line); printf(YEL"User's feed posts sorted by newer to older: "WHT);
    while (print_this_post != NULL)
    {
        gotoxy(STARTING_DEFAUT_X_POSITION,line); 
        for(i = 0; i < strlen(print_this_post -> post); i++){
            printf("%c", print_this_post -> post[i]);
            if (i == 91)
            {
                gotoxy(STARTING_DEFAUT_X_POSITION, ++line);
            }
        }

        print_this_post = print_this_post -> next_struct_feed;
        line += 2;
        gotoxy(STARTING_DEFAUT_X_POSITION, line);
    }
}

void create_feed_post(struct user *logged_user)
{
    char type_post[MAX_POST_LENGTH];
    gotoxy(STARTING_DEFAUT_X_POSITION,11); printf("Press 'Esc' to stop writing");

    if(type_feed(type_post, 8))
    {
        gotoxy(STARTING_DEFAUT_X_POSITION,6); printf(YEL"1."WHT" Create a new post(maximum of 180 characters)");
        clean_area(92,4,STARTING_DEFAUT_X_POSITION,8);
        return;
    }
    
    gotoxy(74,11); printf(GRN"Post created successfully! <Press anything to continue>"WHT);
    pause_screen();
    clean_area(92,4,STARTING_DEFAUT_X_POSITION,8);
    gotoxy(STARTING_DEFAUT_X_POSITION,6); printf(YEL"1."WHT" Create a new post(maximum of 180 characters)");

    struct feed *new_feed = (struct feed*)malloc(sizeof(struct feed));
    strcpy(new_feed -> post, type_post);
    new_feed -> next_struct_feed = logged_user -> next_feed;
    logged_user -> next_feed = new_feed;

    clean_area(92,33,STARTING_DEFAUT_X_POSITION,13);
    print_feed_posts(logged_user,13);  
}

void manage_feed(struct user *logged_user)
{
    gotoxy(2,20); printf(CYN"4. My feed"WHT);
    gotoxy(36,12); for(int i = 0; i < 94; printf("-"), i++);

    print_feed_posts(logged_user,13);

    gotoxy(STARTING_DEFAUT_X_POSITION,6); printf(YEL"1."WHT" Create a new post(maximum of 180 characters)");
    gotoxy(95,6); printf(YEL"2."WHT" Go back");

    for(char case_manage;;)
    {
        case_manage = _getch();
        fflush(stdin);
        if(case_manage == '2')
        {
            clean_area(94,42,36,5);
            gotoxy(2,20); printf(YEL"4."WHT" My feed");
            return;
        }
        else if(case_manage == '1')
        {
            gotoxy(STARTING_DEFAUT_X_POSITION,6); printf(CYN"1. Create a new post(maximum of 180 characters)"WHT);
            create_feed_post(logged_user);
        }
    }
}
