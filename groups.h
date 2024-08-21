#ifndef GROUPS_H
#define GROUPS_H

#include "shared.h"
#include "feed.h"

struct group_feed
{
    char post[MAX_POST_LENGTH];
    char username[USERNAME_MAX_LENGTH];
    struct group_feed *next_struct_feed;
};

struct group
{
    char name[31];
    char description[91];
    struct friend *next_group_member;
    struct group_feed *next_group_feed;
    struct group *next_group;   
    struct user *leader;
};

/**
 * @brief Percorre a lista de todos os grupos existentes até encontrar o grupo desejado.
 * 
 * @param next_group Ponteiro para o primeiro nó que contém um grupo ou nulo.
 * @param logged_user Ponteiro para o nó que contém o usuário logado no momento.
 * @param group_name_verification String que armazena o nome do grupo a ser verificado.
 * @return struct group*. Retorna um ponteiro para o nó que contém o grupo desejado ou nulo caso não encontrado.
 */
struct group *chained_authentication_group_search(struct group *next_group, struct user *logged_user, char *group_name_verification);

/**
 * @brief Cria um grupo e o insere na lista encadeada que contém todos os grupos.
 * 
 * @param logged_user Ponteiro para o nó que contém o usuário logado no momento.
 * @param group_head Nó cabeça da lista encadeada que guarda todos os grupos cadastrados.
 */
void create_group(struct user *logged_user, struct group *group_head);

/**
 * @brief Lista todos os grupos existentes em ordem alfabética.
 * 
 * @param group_head Nó cabeça da lista encadeada que guarda todos os grupos cadastrados.
 * @param logged_user Ponteiro para o nó que contém o usuário logado no momento.
 */
void list_all_groups(struct group *group_head, struct user *logged_user);

/**
 * @brief Traz um feedback ao usuário quanto à busca por grupos e permite a esse voltar ou continuar buscando.
 * 
 * @param group_head Nó cabeça da lista encadeada que guarda todos os grupos cadastrados.
 * @param logged_user Ponteiro para o nó que contém o usuário logado no momento.
 */
void search_groups(struct group *group_head, struct user *logged_user);

/**
 * @brief Disponibiliza as funcionalidades do programa após encontrar um grupo.
 * 
 * @param found_group Ponteiro para o nó que contém o grupo desejado a sofrer a ação.
 * @param logged_user Ponteiro para o nó que contém o usuário logado no momento.
 */
void full_group_actions(struct group *found_group, struct user *logged_user);

/**
 * @brief Mostra os dados do grupo encontrado.
 * 
 * @param found_group Ponteiro para o nó que contém o grupo desejado a sofrer a ação.
 */
void show_group_data(struct group *found_group);

/**
 * @brief Cria um post no mural do grupo encontrado.
 * 
 * @param found_group Ponteiro para o nó que contém o grupo desejado a sofrer a ação.
 * @param logged_user Ponteiro para o nó que contém o usuário logado no momento.
 */
void create_group_post(struct group *found_group, struct user *logged_user);

/**
 * @brief Adiciona o usuárip logado como membro do grupo encontrado.
 * 
 * @param found_group Ponteiro para o nó que contém o grupo desejado a sofrer a ação.
 * @param logged_user Ponteiro para o nó que contém o usuário logado no momento.
 */
void join_group(struct group *found_group, struct user *logged_user);

/**
 * @brief Disponibiliza oções para o usuário com relação aos grupos (Buscar um grupo, entrar em um grupo, etc).
 * 
 * @param logged_user Ponteiro para o nó que contém o usuário logado no momento.
 * @param head Nó cabeça da lista encadeada que guarda todos os usuários cadastrados.
 * @param group_head Nó cabeça da lista encadeada que guarda todos os grupos cadastrados.
 */
void manage_groups(struct user *logged_user, struct user *head, struct group *group_head);

/**
 * @brief Imprime os dados do grupo e permite ao lider alterar a descrição.
 * 
 * @param logged_user Ponteiro para o nó que contém o usuário logado no momento.
 * @param found_group Ponteiro para o nó que contém o grupo desejado a sofrer a ação.
 */
void edit_group(struct user *logged_user, struct group *found_group);

/**
 * @brief Imprime no terminal as postagens no mural do grupo
 * 
 * @param found_group Ponteiro para o nó que contém o grupo desejado a sofrer a ação.
 */
void print_group_feed(struct group *found_group);

#endif