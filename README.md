# ☎️ Lista Telefonica

Este projeto foi desenvolvido em C como parte da disciplina de Algoritmos e consiste na implementação de uma lista telefônica funcional e persistente. O sistema permite o cadastro, consulta, edição e exclusão de pessoas e seus respectivos telefones, garantindo organização e integridade dos dados por meio de armazenamento permanente. O objetivo é exercitar conceitos fundamentais da linguagem C, como manipulação de arquivos, ponteiros, estruturas e modularização.

---
## 🚀 Tecnologias Utilizadas

<img src="https://img.icons8.com/?size=100&id=40670&format=png&color=000000" width="40" style="vertical-align:middle; margin-right:10px;" />

---

## 🗂️ Estrutura de Dados (MER)

A estrutura do projeto é baseada em duas tabelas principais — **Pessoas** e **Telefones** — com relacionamento de **um para muitos**, onde uma pessoa pode ter vários telefones, mas cada telefone pertence a apenas uma pessoa.

### 📊 Diagrama MER

![Diagrama MER](diagrama-mer.png)

## 📐 Especificações dos Campos

| **Campo**           | **Descrição**                              | **Tamanho Máximo**            |
|---------------------|---------------------------------------------|-------------------------------|
| **Nome**            | Nome completo da pessoa.                   | Texto de **30 caracteres**    |
| **Telefone**        | Número de telefone (incluindo DDD).        | Texto de **11 caracteres**    |
| **E-mail**          | Endereço de e-mail.                        | Texto de **30 caracteres**    |
| **CPF**             | Cadastro de Pessoa Física.                 | Texto de **11 caracteres**    |
| **Data de Nascimento** | Data de nascimento da pessoa.          | Texto de **10 caracteres**    |


## ✅ Regras de Validação

| **Campo**              | **Regra de Validação**                                                                 |
|------------------------|-------------------------------------------------------------------------------------------|
| **Nome**               | Deve ter mais de 2 caracteres e não pode existir na lista no momento do cadastro.        |
| **Telefone**           | Deve possuir **10 ou 11 dígitos numéricos** (DDD incluso).                                |
| **E-mail**             | Deve ter mais de 10 caracteres e ser um **e-mail válido**.                                |
| **CPF**                | Deve ser um **CPF válido**.                                                               |
| **Data de Nascimento** | Deve ser uma data válida no formato **dd/mm/YYYY** e ser **menor ou igual à data atual**. |


## ⚙️ Organização do Programa e Menus

A navegação do sistema é feita por menus, sempre aceitando valores inteiros (`int`).  
O programa **encerra ao digitar 5** no Menu Principal.  
Qualquer entrada inválida deve ser solicitada novamente.

---

## 🌳 Estrutura em Árvore dos Menus
```
📌 Menu Principal
│
├── 1. Cadastrar
│ │
│ ├── 1. Pessoa\n
│ │ └── 1.1 Cadastrar Pessoa\n
│ │ ├── Digita Nome
│ │ ├── Digita Data de Nascimento\n
│ │ ├── Digita CPF
│ │ ├── Digita E-mail
│ │ └── Digita Telefone(s)
│ │
│ ├── 2. Telefone
│ │ ├── 1.2.1 Cadastrar Telefone (Pesquisa por Nome)
│ │ └── 1.2.2 Cadastrar Telefone (Pesquisa por ID)
│ │
│ └── 3. Retornar ao Menu Principal
│
├── 2. Editar
│ │
│ ├── 1. Pessoa
│ ├── 2. Telefone
│ └── 3. Retornar ao Menu Principal
│
├── 3. Excluir
│ │
│ ├── 1. Pessoa
│ ├── 2. Telefone
│ └── 3. Retornar ao Menu Principal
│
├── 4. Consultar
│ │
│ ├── 1. Pessoa
│ ├── 2. Telefone
│ └── 3. Retornar ao Menu Principal
│
└── 5. Sair
```
