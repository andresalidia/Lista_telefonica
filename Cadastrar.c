#include "Cadastrar.h"
#include "Contatos.h"
#include "Validacao.h"
#include <stdlib.h>
#include <stdio.h>

void Cadastrar_pessoa(){
    struct Contato novo_contato;

    do{
        printf("Nome:");
        scanf("%s", novo_contato.nome);
    } while (!validar_Nome(novo_contato.nome));
    
    do{
        printf("Data de Nascimento (DD/MM/AAAA): ");
        scanf("%s", novo_contato.dataNasc);
    } while (!validar_DataNasc(novo_contato.dataNasc));
    do{
        printf("CPF (Apenas numeros): ");
        scanf("%s", novo_contato.CPF);
    } while (!validar_CPF(novo_contato.CPF));
    
    do{
        printf("E-mail: ");
        scanf("%s", novo_contato.email);
    } while (!validar_Email(novo_contato.email));
    
    
   
    // Salvando pessoa em um arquivo
    FILE *arquivo = fopen("ListaTelefonica.csv", "a");
    if (arquivo == NULL) {
        printf("Arquivo não pôde ser aberto.\n");
        return;
    }
    fprintf(arquivo, "%d;%s;%s;%s;%s\n", Ultimo_ID() + 1, novo_contato.nome, novo_contato.dataNasc, novo_contato.CPF, novo_contato.email);
    fclose(arquivo);
}