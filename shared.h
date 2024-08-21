#ifndef SHARED_H
#define SHARED_H

#define RED "\x1B[0;31m"
#define RED1 "\x1B[1;31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[1;33m"
#define CYN "\x1B[1;36m"
#define CYN0 "\x1B[0;36m"
#define WHT "\x1B[1;37;40m"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#define MAX_POST_LENGTH 181
#define USERNAME_MAX_LENGTH 21
#define STARTING_DEFAUT_X_POSITION 37

struct message
{
    char username[USERNAME_MAX_LENGTH];
    char message[91];
    struct message *next_message;
};

struct feed
{
    char post[MAX_POST_LENGTH];
    struct feed *next_struct_feed;
};

struct friend
{
    char username[USERNAME_MAX_LENGTH];
    struct friend *next_friend;
};

struct user
{
    char username[USERNAME_MAX_LENGTH];
    char password[11];
    char full_name[41];
    char social_engagement[17];
    char address[31];
    char biography[91];
    struct friend *next_friend;
    struct feed *next_feed;
    struct message *next_message;
    struct user *next_user;
};

/**
 * @brief Função que move o cursor para um local específico do terminal com base em linhas e em colunas. Usada para a construção da interface do código
 * 
 * @param x Coluna
 * @param y Linha
 */
void gotoxy(int x, int y);

/**
 * @brief Função que limpa uma área retangular no terminal.
 * 
 * @param length Comprimento em colunas a partir da posição X.
 * @param height Altura em linhas a partir da linha Y (Cresce de cima para baixo).
 * @param X_coord Coordenada X.
 * @param Y_coord Linha Y.
 */
void clean_area(int length, int height, int X_coord, int Y_coord);

/**
 * @brief Função usada para ler uma string digitada pelo usuário.
 * 
 * @param string Vetor onde a string lida deverá ser armazenada.
 * @param max_length Tamanho máximo da string a ser lida.
 * @param min_length Tamanho mínimo da string a ser lida.
 * @return Retorna um short. "1" se a operação foi abortada e "0" se a operação foi concluída.
 */
short type_info(char *string, short max_length, short min_length);

/**
 * @brief Função usada para pausar a tela. Muito usada após mensagens de feedback.
 * 
 */
void pause_screen();

#endif