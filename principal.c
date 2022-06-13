// #include <stdio.h>
// #include <stdlib.h>
// #include "abb.h"
// #include "fila.h"

// int main()
// {
//     printf("\nSISTEMA DE ENCOMENDA DE LIVRO\n");
//     int resp = -1;
//     while (resp != 0)
//     {
//         printf(" 1 - Encomendar um livro.\n");
//         printf(" 2 - Remover uma encomenda de livro.\n");
//         printf(" 3 - Remover um pedido de livro.\n");
//         printf(" 0 - Sair do sistema!\n");
//         printf("Digite a funcionalidade desejada: ");
//         scanf("%d", &resp);

//         if (resp == 1)
//         {
//             printf("\nDigite o nome do aluno:\n");
//             char nome[100];
//             scanf("%s", &nome);
//             printf("\nDigite a matricula do aluno:\n");
//             int matricula;
//             scanf("%d", &matricula);
//             printf("\nDigite a descrição do livro (maximo 500 caracteres):\n");
//             char descricao[500];
//             scanf("%s", &descricao);
//             // criar um funcao para gerar id unico (:D)
//             // add_abb(id, nome, matricula, descricao);
//         }
//         // else if (resp == 2)
//         // {
//         //     // remover uma encomenda de livro da ABB (id)
//         //     // para remover eu preciso:
//         //     // 1 - visualizar as encomendas (in_ordem)
//         //     in_ordem();
//         //     // 2 - verificar o usuario
//         //     printf(" Digite seu cpf:\n");
//         //     char cpf[100];
//         //     scanf("%s", &cpf);
//         //     printf(" Digite sua senha:\n");
//         //     char senha[100];
//         //     scanf("%s", &senha);
//         //     // int retorno = verificar(cpf, senha);
//         //     if (retorno == 1)
//         //     {
//         //         // 3 - chama a funcao remover_abb por id (CADE ESSA FUNCAO?)
//         //         // 4 - setar novos dados (faltando)
//         //         // 5 - add_fila(....);
//         //     }
//         //     else if (resp == 3)
//         //     {

//         //         // 2 - verificar o usuario
//         //         printf(" Digite seu cpf:\n");
//         //         char cpf[100];
//         //         scanf("%s", &cpf);
//         //         printf(" Digite sua senha:\n");
//         //         char senha[100];
//         //         scanf("%s", &senha);
//         //         // int retorno = verificar(cpf, senha);
//         //         if (retorno == 1)
//         //         {
//         //             // remover da fila de prioridade
//         //         }
//         //     }
//         // }
//     }

//     return 0;
// }