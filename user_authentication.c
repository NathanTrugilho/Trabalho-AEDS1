#include "user_authentication.h"

struct user *chained_authentication_search(struct user *head, char *username_verification){
    struct user *aux = head;
    while (aux != NULL)
    {   
        if(!strcmp(aux ->username, username_verification)){
            return aux;
        }
        aux = aux -> next_user;
    }
    return NULL;
};

void print_user_authentication(){
    system("cls");
    printf(WHT);
    //167 '*' de largura
    //48 '*' de altura
    int i;

    for(i = 0; i < 167; printf("*"), i++);
    for(i = 1; i < 47; i++)
    {
        gotoxy(0,i); printf("*");
        gotoxy(166,i); printf("*");
    }
    gotoxy(0,47); for(i = 0; i < 167; printf("*"), i++);

    gotoxy(49,10); for(i = 0; i < 70; printf("*"), i++);
    for(i = 11; i < 25; i++)
    {
        gotoxy(49,i); printf("*");
        gotoxy(118,i); printf("*");
    }
    gotoxy(50,12); for(i = 0; i < 68; printf("-"), i++);
    gotoxy(49,25); for(i = 0; i < 70; printf("*"), i++);

    gotoxy(68,11); printf(""YEL"BMSM"WHT" - Big Machine Social Media");
    gotoxy(78,13); printf(""CYN"'2'"WHT". Sign in to an account |");
    gotoxy(51,13); printf(""CYN"'1'"WHT". Register an account |");
    gotoxy(107,13); printf(""CYN"'3'"WHT". Exit");
    gotoxy(50,14); for(i = 0; i < 68; printf("-"), i++);
};

short type_username(char *username)
{
    {
        short counter = 0;
        char key;
        while (1) {
            if (_kbhit()) 
            { //retorna um valor diferente de zero se uma key foi pressionada e está disponível para leitura no buffer de entrada
                key = _getch();

                if(key == 27) return 1;

                else if(key == ' '){
                    continue;
                }
                else if ((key == '\r' || key == '\n') && counter < 6) {
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
                else if (counter < USERNAME_MAX_LENGTH - 1) {
                    username[counter] = key;
                    counter++;
                    printf("%c",key); // Exibe um asterisco na tela
                }
            }
        }
        username[counter] = '\0'; // Adiciona o caractere nulo ao final da senha
        return 0;
    }    
}

short type_password(char *password)
{
    short counter = 0;
    char key;
    while (1) {
        if (_kbhit()) //retorna um valor diferente de zero se uma key foi pressionada e está disponível para leitura no buffer de entrada
        { 
            key = _getch(); 

            if(key == 27) return 1;

            else if(key ==' '){
                continue;
            }
            else if ((key == '\r' || key == '\n') && counter < 4) {
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
            else if (counter < 10) {
                password[counter] = key;
                counter++;
                putch('*'); // Exibe um asterisco na tela
            }
        }
    }
    password[counter] = '\0'; // Adiciona o caractere nulo ao final da senha
    return 0;
};

void create_account(struct user *head){
    char username_verification[USERNAME_MAX_LENGTH];
    char password[11];
    struct user *aux = head;
    gotoxy(51,13); printf(""CYN"'1'. Register an account "WHT"|");

    gotoxy(51,16); printf(YEL"Username (6 to 20 characters): "WHT);
    gotoxy(51,23); printf("Press 'Esc' at any point to go back");
    do
    {
        gotoxy(82,16);
        if(type_username(username_verification))
        {
            clean_area(60,9,51,16);
            gotoxy(51,13); printf(""CYN"'1'"WHT". Register an account |");
            return;
        }

        if(chained_authentication_search(head, username_verification) != NULL)
        {
            gotoxy(51,24); printf(RED"Username already taken! Press anything to continue"WHT);
            pause_screen();
            clean_area(30,1,81,16);
            clean_area(66,1,51,24);
            continue;
        };
        break;    
    } while (1);


    gotoxy(51,19); printf(YEL"Password (4 to 10 characters): "WHT);

    if(type_password(password))
    {
        clean_area(60,9,51,16);
        gotoxy(51,13); printf(""CYN"'1'"WHT". Register an account |");
        return;
    }

    struct user *person = (struct user*)malloc(sizeof(struct user));
    if(person == NULL) exit(1);
    person -> next_user = NULL;
    person -> next_friend = NULL;
    person -> next_feed = NULL;
    person -> next_message = NULL;
    person -> address[0] = '\0';
    person -> biography[0] = '\0';
    person -> full_name[0] = '\0';
    person -> social_engagement[0] = '\0';

    //salva o username e senha verificado na lista encadeada;
    strcpy(person->username, username_verification);
    strcpy(person -> password, password);

    while(aux -> next_user != NULL)
    {
        aux = aux -> next_user;
    }
    aux -> next_user = person;

    gotoxy(51,24); printf(GRN"Successfully registered user! Press anything to continue"WHT);
    pause_screen();
    clean_area(60,9,51,16);
    gotoxy(51,13); printf(""CYN"'1'"WHT". Register an account |");
};

void login(struct user *head, struct group *group_head){
    char username_verification[USERNAME_MAX_LENGTH];
    char password_verification[11];
    struct user *all_verification;

    gotoxy(78,13); printf(""CYN"'2'. Sign in to an account "WHT"|");
    gotoxy(51,16); printf(YEL"Username: "WHT);
    gotoxy(51,23); printf("Press 'Esc' at any point to go back");
    do
    {
        gotoxy(61,16);
        if(type_username(username_verification))
        { 
            clean_area(60,9,51,16);
            gotoxy(78,13); printf(""CYN"'2'"WHT". Sign in to an account |");
            return;
        }
        all_verification = chained_authentication_search(head, username_verification);
        if(all_verification == NULL)
        {
            gotoxy(51,24); printf(RED"Username not found! Press anything to continue"WHT);
            pause_screen();
            clean_area(30,1,60,16);
            clean_area(63,1,51,24);
            continue;
        };
        break;    
    } while (1);

    gotoxy(51,19); printf(YEL"Password: "WHT);
    do
    {
        gotoxy(61,19); 
        if(type_password(password_verification))
        { 
            clean_area(60,9,51,16);
            gotoxy(78,13); printf(""CYN"'2'"WHT". Sign in to an account |");
            return;
        }
        if(!strcmp(password_verification, all_verification -> password))
        {
            gotoxy(51,24); printf(GRN"Successfully logged in! Press anything to continue"WHT);
            pause_screen();
            break;
        }
        gotoxy(51,24); printf(RED"Wrong Password! Press anything to try again."WHT);
        pause_screen();

        clean_area(60,1,51,24);
        clean_area(10,1,61,19);
    } while (1);
    
    clean_area(70,16,49,10);
    initialize_main_menu(head, all_verification, group_head);
};
