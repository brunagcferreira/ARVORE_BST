#include "bst.c"
#include <stdio.h>
#include <stdlib.h>

int main(){
    arvore raiz = NULL;
    int loop = 1;
    int opc = 0;
    int valor = 0;
    printf("******MENU******\n");
    printf("1- INSERIR\n");
    printf("2- PREORDER\n");
    printf("3- INORDER\n");
    printf("4- POSORDER\n");
    printf("5- REVERSO\n");
    printf("6- ALTURA\n");
    printf("7- QUANTIDADE DE FOLHAS\n");
    printf("8- CAMINHO\n");
    printf("9- REMOVER\n");
    printf("99 - SAIR\n");

    while(loop){

        scanf("%d", &opc);

        switch (opc){
        case 1:
            //1- INSERIR
            scanf("%d", &valor);
            raiz = inserir(valor, raiz);
            break;
        case 2:
            //2- PREORDER
            preorder(raiz);
            printf("\n");
            break;
        case 3:
            //3- INORDER
            inorder(raiz);
            printf("\n");
            break;
        case 4:
            //4- POSORDER
            posorder(raiz);
            printf("\n");
            break;
        case 5:
            //5- REVERSO
            reverso(raiz);
            printf("\n");
            break;
        case 6:
            //6- ALTURA
            printf("%d", altura(raiz));
            printf("\n");
            break;
        case 7:
            //7- QUANTIDADE DE FOLHAS
            printf("%d", qntdFolhas(raiz));
            printf("\n");
            break;
        case 8:
            //8- CAMINHO
            scanf("%d", &valor);
            caminho(raiz, valor);
            printf("\n");
            break;
        case 9:
            //9- REMOVER
            scanf("%d", &valor);
            raiz = remover(valor, raiz);
            break;
        case 99:
            loop = 0;
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }

    }
    return 0;
}