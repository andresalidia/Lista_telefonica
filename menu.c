#include <stdio.h>
#include "menu.h"
#include "Cadastrar.h"
#include "Editar.h"
#include "Excluir.h"
#include "Consultar.h" 

int escolha;
void Cadastrar(){
   
   do{
        printf("=====Lista Telefonica=======\n");
        printf("Cadastrar\n");
         printf("1-Pessoa\n");
         printf("2-Telefone\n");
         printf("3-Retornar\n");
         scanf("%d" ,&escolha);
         switch (escolha)
         {
         case 1:
             Cadastrar_pessoa();
             break;
         case 2:
            Cadastrar_telefone();
               break;
         case 3:
               printf("Retornando ao menu principal...\n");
               break;
         default:
               printf("Opcao invalida, digite um número entre 1 à 3.\n");
               printf("Tente novamente.\n");
               break;

       }
   }while(escolha!=3);

}
void Editar(){
   do{
        printf("=====Lista Telefonica=======\n");
        printf("Editar\n");
         printf("1-Pessoa\n");
         printf("2-Telefone\n");
         printf("3-Retornar\n");
         scanf("%d" ,&escolha);
         switch (escolha)
         {
         case 1:
             Editar_pessoa();
             break;
         case 2:
            Editar_telefone();
               break;
         case 3:
               printf("Retornando ao menu principal...\n");
               break;
         default:
               printf("Opcao invalida, digite um número entre 1 à 3.\n");
               printf("Tente novamente.\n");
               break;

       }
   }while(escolha!=3);
}
void Excluir(){
    do{
        printf("=====Lista Telefonica=======\n");
        printf("Editar\n");
         printf("1-Pessoa\n");
         printf("2-Telefone\n");
         printf("3-Retornar\n");
         scanf("%d" ,&escolha);
         switch (escolha)
         {
         case 1:
             Excluir_pessoa();
             break;
         case 2:
            Excluir_telefone();
               break;
         case 3:
               printf("Retornando ao menu principal...\n");
               break;
         default:
               printf("Opcao invalida, digite um número entre 1 à 3.\n");
               printf("Tente novamente.\n");
               break;

       }
   }while(escolha!=3);
}

void Consultar(){

}

