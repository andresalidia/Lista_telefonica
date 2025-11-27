#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "menu.h"
#include "Cadastrar.h"
#include "Editar.h"
#include "Excluir.h"
#include "Consultar.h"

void main(){
    int escolha;
    do{
        
        printf("=====Lista Telefonica=======\n");
        printf("Menu\n");
        printf("1-Cadastra\n");
        printf("2-Editar\n");
        printf("3-Excluir\n");
        printf("4-Consultar\n");
        printf("5-Sair\n");
        scanf("%d" ,&escolha);
        switch (escolha)
        {
        case 1:
            Cadastrar();
            break;
         case 2:
            Editar();
            break;
        case 3:
            Excluir();
            break;
        case 4:
            Consultar();
            break;
        case 5:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida, digite um número entre 1 à 5.\n");
            printf("Tente novamente.\n");
            break;
        }
        
    
    } while (escolha != 5);

}