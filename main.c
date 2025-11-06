#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "menu.h"
int main(){
    int continuar = 1;
    while (continuar)
    {
        int escolha;
        printf("=====Lista Telefonica=======\n");
        printf("Menu\n");
        printf("1-Cadastra\n");
        printf("2-Editar\n");
        printf("3-Excluir\n");
        printf("4-Consultar\n");
        printf("5-Sair\n");
        scanf("%d" ,&escolha);
        
        continuar= menu_principal(escolha);
    
    }  
    return 0;
}