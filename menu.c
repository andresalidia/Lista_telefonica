#include <stdio.h>
#include "menu.h"
#include "Cadastrar.h"
#include "Editar.h"
#include "Excluir.h"
#include "Consultar.h" 

void Cadastrar(){
   int escolha;
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
            
               break;
         case 3:
               printf("Retornando ao menu principal...\n");
               break;

       }
   }while(escolha!=3);

}
void Editar(){

}
void Excluir(){

}
void Consultar(){

}

