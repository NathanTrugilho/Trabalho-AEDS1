#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "shared.h"
#include "user_profiles.h"
#include "friends_list.h"
#include "user_authentication.h"
#include "feed.h"
#include "groups.h"

/**
 * @brief Imprime no terminal o layout principal do programa.
 * 
 * @param logged_user Ponteiro para o usuário logado no momento.
 */
void print_main_menu(struct user *logged_user);

/**
 * @brief Função principal que faz a ligação de todas as funcionalidades do programa. Esta possui um switch que chama todas as outras funções.
 * 
 * @param head Ponteiro para o nó cabeça da lista encadeada com todos os usuários cadastrados.
 * @param logged_user Ponteiro para o nó que contém o usuário logado no momento.
 * @param group_head Ponteiro para o nó cabeça da lista encadeada com todos os grupos existentes durante a execução do programa.
 */
void initialize_main_menu(struct user *head, struct user *logged_user, struct group *group_head);

#endif