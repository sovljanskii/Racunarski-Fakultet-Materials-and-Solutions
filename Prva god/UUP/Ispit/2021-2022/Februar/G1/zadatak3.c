#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char opstina[50];
    char naziv[50];
    int brsprava;
    int brkard;
    struct Node *left;
    struct Node *right;
}Node;

void menu(){
    printf("1.Ucitavanje\n");
    printf("2.Ispis\n");
    printf("3.Ispis sa sprava\n");
    printf("4.Ispis u nekoj opstini\n");
    printf("5.Brisanje\n");
}

Node *createNode(char *opstina,char*naziv,int brsprava,int brkard){
    Node *new = (Node*) malloc(sizeof(Node));
    strcpy(new->naziv,naziv);
    strcpy(new->opstina,opstina);
    new->brsprava = brsprava;
    new->brkard = brkard;
    new->left = NULL;
    new->right = NULL;
    return new;
}

Node *loadNode(Node *root,Node *new){
    if (root==NULL) return new;
    if (strcmp(root->opstina,new->opstina)<0){
        root->left = loadNode(root->left,new);
    }
    else root->right = loadNode(root->right,new);
    return root;
}


Node *loadFile(){
    FILE *fp = fopen("teretana.txt","r");
    Node *root=NULL;
    char line[255];
    while (fgets(line,255,fp)){
        char *opstina = strtok(line,"-");
        char *naziv = strtok(NULL,"-");
        int brsprava = atoi(strtok(NULL,"-"));
        int brkard = atoi(strtok(NULL,"\n"));
        Node *new = createNode(opstina,naziv,brsprava,brkard);
        root = loadNode(root,new);
    }
    return root;
}

void printTree(Node *root){
    if (root==NULL) return;
    printTree(root->left);
    printf("%s (%s) - %d [%d]\n",root->naziv,root->opstina,root->brsprava,root->brkard);
    printTree(root->right);
}

void freeNode(Node *root){
    if (root==NULL) return;
    freeNode(root->left);
    freeNode(root->right);
    free(root);
}

void podc(Node *root,int brsp){
    if (root==NULL) return;
    podc(root->left,brsp);
    if (root->brsprava>brsp) printf("%s (%s) - %d [%d]\n",root->naziv,root->opstina,root->brsprava,root->brkard);
    podc(root->right,brsp);
}

int checkSub(char *first,char *second){
    for (int i=0;i< strlen(second);i++){
        if (first[strlen(first)- strlen(second)+i] ==second[i]) continue;
        return 0;
    }

    return 1;
}

void podd(Node *root,char *deo){
    if (root==NULL) return;
    podd(root->left,deo);
    if (checkSub(root->opstina,deo)) printf("%s (%s) - %d [%d]\n",root->naziv,root->opstina,root->brsprava,root->brkard);
    podd(root->right,deo);
}

int main() {
    int option=-1;
    Node *root=NULL;
    int brsp=0;
    char deo[50];
    while (1){
        menu();
        scanf("%d",&option);
        switch (option) {
            case 1:
                root = loadFile();
                break;
            case 2:
                printTree(root);
                break;
            case 3:
                scanf("%d",&brsp);
                podc(root,brsp);
                break;
            case 4:
                getchar();
                fgets(deo,sizeof deo,stdin);
                deo[strlen(deo)-1]=0;
                podd(root,deo);
                break;
            case 5:
                freeNode(root);
                return 0;
        }
    }
}
