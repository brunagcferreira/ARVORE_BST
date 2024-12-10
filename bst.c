#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

arvore inserir(int valor, arvore raiz){
    if(raiz == NULL){
        arvore novo = (arvore)(malloc(sizeof(No)));
        novo->valor = valor;
        novo->dir = NULL;
        novo->esq = NULL;
        return novo;
    } else{
        if(valor >= raiz->valor){
            raiz->dir = inserir(valor, raiz->dir);
        } else{
            raiz->esq = inserir(valor, raiz->esq);
        }
    }
    return raiz;
}

arvore maiorElemento(arvore raiz){
    while (raiz->dir != NULL){
        raiz = raiz->dir;
    }
    return raiz;
}

arvore remover (int valor, arvore raiz){
    //se a arvore for vazia, ou se o elemento não estiver na arvore
    if (raiz == NULL){
        return NULL;
    }

    //se o valor for maior, busca na subarvore a direita
    if (valor > raiz->valor){
        raiz->dir = remover(valor, raiz->dir);
    } 

    //se o valor for menor, busca na subarvore a esquerda
    else if (valor < raiz->valor){
        raiz->esq = remover(valor, raiz->esq);
    } 
    
    //caso encontre o valor, remove
    else {
        //CASO 01. o elemento é uma folha. remove e att o ponteiro do pai
        if(raiz->dir == NULL && raiz->esq == NULL){
            free(raiz);
            return NULL;
        }
        //CASO 02.A. o elemento possui exatamente um filho direito
        if(raiz->dir != NULL && raiz->esq == NULL){
            arvore aux = raiz;
            raiz = raiz->dir;
            free (aux);
            return raiz;
        }

        //CASO 02.B. o elemento possui exatamente um filho esquerdo
        if(raiz->esq != NULL && raiz->dir == NULL){
            arvore aux = raiz;
            raiz = raiz->esq;
            free (aux);
            return raiz;
        }

        //CASO 03. o elemento possui 2 filhos
        if(raiz->dir != NULL && raiz->esq !=NULL){
            arvore elemento = maiorElemento(raiz->esq);
            raiz->valor = elemento->valor;
            raiz->esq = remover(elemento->valor, raiz->esq);
        }

    }
    return raiz;
}

void preorder (arvore raiz){
    if (raiz != NULL) {
        printf("[%d]", raiz->valor);
        preorder(raiz->esq);
        preorder(raiz->dir);
    }
}

void inorder(arvore raiz){
    if(raiz != NULL) {
        inorder(raiz->esq);
        printf("[%d]", raiz->valor);
        inorder(raiz->dir);
    }
}

void posorder(arvore raiz) {
    if(raiz != NULL) {
        posorder(raiz->esq);
        posorder(raiz->dir);
        printf("[%d]", raiz->valor);
    }
}

void reverso(arvore raiz) {
    if (raiz != NULL) {
        reverso(raiz->dir);
        printf("[%d]", raiz->valor);
        reverso(raiz->esq);
    }
}

int altura(arvore raiz){
    if(raiz == NULL){
        return 0;
    }
    int alturaesquerda = altura(raiz->esq);
    int alturadireita = altura(raiz->dir);

    if(alturaesquerda >= alturadireita){
        return  1 + alturaesquerda;
    }
    return 1 + alturadireita;
}

int qntdFolhas(arvore raiz){
    if(raiz == NULL){
        return 0;
    }

    if (raiz->dir == NULL && raiz->esq == NULL){
        return 1;
    }

    return qntdFolhas(raiz->dir) + qntdFolhas(raiz->esq);
}

int busca (arvore raiz, int valor){
    if(raiz == NULL){
        return 0;
    }
    if(raiz->valor == valor){
        return 1;
    }
    if(valor > raiz->valor){
        return busca(raiz->dir, valor);
    }
    return busca(raiz->esq, valor);
}

void caminho (arvore raiz, int valor){
    if(busca(raiz, valor)){
        if(raiz == NULL){
            return;
        }
        if(raiz->valor == valor){
            printf("[%d]", raiz->valor);
        }
        if(raiz->valor > valor){
            printf("[%d]", raiz->valor);
            caminho(raiz->esq, valor);
        }
        else if(raiz->valor < valor){
            printf("[%d]", raiz->valor);
            caminho(raiz->dir, valor);
        }
    }
}

