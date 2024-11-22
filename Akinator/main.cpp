#include "Akinator.h"

int main()
{
    node_t* root = NULL;
    FILE* file = fopen("AkinatorBaze.txt", "r");

    if (file != NULL) 
    {
        root = LoadTreeFromFile(file);
        fclose(file);
        printf("Tree loaded from file.\n");
    } 
    else
    {
        printf("File not found. Creating a new tree.\n");
        node_t* root = CreateNode("Kvadrober\n");
        root->yes = CreateNode("ded\n");
        root->no = CreateNode("Animal\n");
    }
    
    while(1)
    {
        PlayAkinator(root);
        printf("One more?\n");
        char answer[ANSWER_MAX_LENGHT];
        scanf("%s", answer);
        if(strcmp(answer, "no") == 0)
        {
            break;
        }
    }

    file = fopen("AkinatorBaze.txt", "w");//ass
    if (file != NULL) 
    {
        SaveTreeToFile(root, file);
        fclose(file);
        printf("Tree saved to file.\n");
    } 
    else 
    {
        printf("Error saving the tree.\n");//жак фреско почему корень из двух
    }

    DtorTree(root);
    printf("thanks for game\n");
    return 0;

}