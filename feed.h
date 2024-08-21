#ifndef FEED_H
#define FEED_H

#include "shared.h"
/**
 * @brief Permite ao usuário navegar pelo seu feed dando a opção do mesmo criar uma postagem.
 * 
 * @param logged_user Ponteiro para o nó que contém o usuário logado no momento.
 */
void manage_feed(struct user *logged_user);

/**
 * @brief Função que lê e armazena numa string uma postagem no feed.
 * 
 * @param type_feed String que terá o input guardado.
 * @param linha Linha em que a string será digitada.
 * @return Retorna um short. "1" se a operação foi abortada e "0" se a operação foi concluída.
 */
short type_feed(char *type_feed, short linha);

/**
 * @brief Cria um post no mural de um usuário.
 * 
 * @param logged_user Ponteiro para o nó que contém o usuário logado no momento.
 */
void create_feed_post(struct user *logged_user);

/**
 * @brief Imprime os posts do mural de um usuário na linha desejada.
 * 
 * @param logged_user Ponteiro para o nó que contém o usuário logado no momento.
 * @param starter_line Linha em que a impressão começará a ser feita.
 */
void print_feed_posts(struct user *logged_user, short starter_line);

#endif