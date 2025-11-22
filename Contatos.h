#ifndef CONTATOS_H
#define CONTATOS_H  
struct Contato
{
    int id;
    char nome[31];
    char telefone[12];
    char email[31];
    char CPF[12];
    char dataNasc[11];
};

#endif