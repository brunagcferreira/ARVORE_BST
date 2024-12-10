#ifndef BST_H
#define BST_H

typedef struct No {
    int valor;
    struct No *esq, *dir;
}No;

typedef No *arvore;

arvore inserir(int valor, arvore raiz);
arvore maiorElemento(arvore raiz);
arvore remover(int valor, arvore raiz);
void preorder (arvore raiz);
void inorder (arvore raiz);
void posorder (arvore raiz);
void reverso (arvore raiz);
int altura (arvore raiz);
int qntdFolhas (arvore raiz);
int busca (arvore raiz, int valor);
void caminho (arvore raiz, int valor);

#endif