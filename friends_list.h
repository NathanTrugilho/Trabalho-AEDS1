#ifndef FRIENDS_LIST_H
#define FRIENDS_LIST_H

#include "shared.h"
/**
 * @brief Função que adiciona amigos.
 * 
 * @param logged_user Ponteiro para o nó que contém o usuário logado no momento.
 * @param found_user Ponteiro para o nó que contém o usuário encontrado na função de busca que será adicionado como amigo pelo usuário logado.
 */
void add_friend(struct user *logged_user, struct user *found_user);

/**
 * @brief Função que imprime no terminal os amigos do usuário recebido por parâmetro numa posição específica.
 * 
 * @param user Ponteiro para o nó que contém o usuário cuja lista de amigos será imprimida.
 * @param column Coluna (coordenada X) em que a lista será impressa.
 * @param line Linha (coordenada Y) em que a lista começará a ser imprimida.
 */
void print_my_friends(struct user *user, short column, short line);

#endif