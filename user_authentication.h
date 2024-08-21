#ifndef USER_AUTHENTICATION_H
#define USER_AUTHENTICATION_H

#include "shared.h"
#include "main_menu.h"
#include "groups.h"

/**
 * @brief Printa no terminal o menu que dará orientações ao usuário na parte de autenticação.
 * 
 */
void print_user_authentication();

/**
 * @brief Função usada para ler a senha do usuário.
 * 
 * @param password Vetor onde a senha deverá ser guardada.
 * @return Retorna um short. "1" se a operação foi abortada e "0" se a operação foi concluída.
 */
short type_password(char *password);

/**
 * @brief Função usada para ler o nome de usuário.
 * 
 * @param username Vetor onde o nome de usuário deverá ser guardado.
 * @return Retorna um short. "1" se a operação foi abortada e "0" se a operação foi concluída. 
 */
short type_username(char *username);

/**
 * @brief Função que verifica a existência de um usuário.
 * 
 * @param head Nó cabeça da lista encadeada que guarda todos os usuários cadastrados.
 * @param verification Vetor que guarda um nome de usuário que será comparado com os nomes pertencentes à lista encadeada.
 * @return struct user*. Retorna o endereço do usuário encontrado ou NULL caso não encontrado.
 */
struct user* chained_authentication_search(struct user *head, char *verification);

/**
 * @brief Função que cria a conta de um usuário e o insere na lista encadeada.
 * 
 * @param head Nó cabeça da lista encadeada que guarda todos os usuários cadastrados.
 */
void create_account(struct user *head);

/**
 * @brief Função que faz a verificação de login do usuário.
 * 
 * @param head Nó cabeça da lista encadeada que guarda todos os usuários cadastrados.
 * @param group_head Nó cabeça da lista encadeada que guarda todos os grupos cadastrados. Será requisitado durante a execução do programa.
 */
void login(struct user *head, struct group *group_head);

#endif