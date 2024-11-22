#include <stdio.h>
#include <stdlib.h> 
#include <string.h>


enum Constants
{
    QUESTION_MAX_LENGHT = 30,
    CHARACTER_MAX_LENGHT = 30,
    ANSWER_MAX_LENGHT = 10
};

struct node_t
{
    char question[QUESTION_MAX_LENGHT];  //поменять на нейтральное название так как возникает логические ошибки в коде типа персонаж\вопрос перемешиваются
    node_t* yes;
    node_t* no;
};

node_t* CreateNode(const char* content);
void PlayAkinator(node_t* CurrentNode);
void DtorTree(node_t* root);
void SaveTreeToFile(node_t* root, FILE* file);
node_t* LoadTreeFromFile(FILE* file);