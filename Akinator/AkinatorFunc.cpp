#include "Akinator.h"

node_t* CreateNode(const char* content) 
{
    node_t* newNode = (node_t*)calloc(1, sizeof(node_t));

    strcpy(newNode->question, content);

    newNode->yes = NULL;
    newNode->no = NULL;

    return newNode;
}

void PlayAkinator(node_t* CurrentNode)
{
    char answer[ANSWER_MAX_LENGHT] = {};

    if(CurrentNode->yes != NULL && CurrentNode->no != NULL)
    {
        printf("\n %s \n yes/no \n", CurrentNode->question);

        if(strcmp(answer, "yes") == 0)
        {
            PlayAkinator(CurrentNode->yes);
        }
        else if(strcmp(answer, "no") == 0)                                      //более умно сканить (н символов больше 10)
                                                                                //сравнить и вывести определение(стркип) + более умно
        {
            printf("It %s ?", CurrentNode->question);
            scanf("%s", answer);
            if (strcmp(answer, "yes") == 0)
            {
                printf("victory");
            }
            else
            {
                char new_character[CHARACTER_MAX_LENGHT];
                char new_question[QUESTION_MAX_LENGHT];

                printf("who you wish");
                scanf("%s", new_character);
                printf("ask a question pidor syka blyat drinking russian vodka");
                scanf("%s", new_question);

                node_t* new_character_node = CreateNode(new_character);
                node_t* old_character_node = CreateNode(CurrentNode->question);

                strcpy(CurrentNode->question, new_question);
                printf("anwer for 'yes' to %s? (yes/no): ", new_character);
                scanf("%s", answer);
                if (strcmp(answer, "yes") == 0) 
                {
                CurrentNode->yes = new_character_node;
                CurrentNode->no = old_character_node;
                } 
                else 
                {
                CurrentNode->yes = old_character_node;
                CurrentNode->no = new_character_node;
                }
            }   
        }
    }
}

node_t* LoadTreeFromFile(FILE* file) 
{
    char buffer[QUESTION_MAX_LENGHT];
    int ch = fgetc(file);
    if (ch == EOF || ch == '}') 
    {
        return NULL;
    }

    if (ch == '{') 
    {
        if (fscanf(file, " %[^{^}]s", buffer) != 1) 
        {
            return NULL;
        }

        node_t* newNode = CreateNode(buffer);
        newNode->yes = LoadTreeFromFile(file);
        newNode->no = LoadTreeFromFile(file);
        fgetc(file); //порверка
        return newNode;
    }
    return NULL;
}

void SaveTreeToFile(node_t* root, FILE* file) 
{
    if (root == NULL) 
    {
        fprintf(file, "{}");
        return;
    }
    fprintf(file, "{%s", root->question);
    SaveTreeToFile(root->yes, file);
    SaveTreeToFile(root->no, file);
    fprintf(file, "}");
}


void DtorTree(node_t* root)
{
    if(root != NULL)
    {
        DtorTree(root->yes);
        DtorTree(root->no);
        free(root);
    }
}

