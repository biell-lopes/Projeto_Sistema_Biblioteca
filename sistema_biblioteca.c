#include<stdio.h>
#include<stdlib.h>
#include<string.h> //Biblioteca para usar a funçao strcmp.
#include <windows.h>
#include <string.h> //necessário para strcpy
#include <locale.h>
#include <ctype.h>
#define cls system("cls")
#define size 200 //variavel constante que nao muda seu valor.


//variaveis globais
char nome0[100];
int subMenu,opcao, opcao2;
int numCadastro[size];
int telefone[size];
char nomeCli[size] [50];
char endeCli[size] [50];
int cpfCli[];
int sair;

char titulo[size] [50];
char autor[size] [50];
int paginas[size];
int quantidade[size];


int valorFinal2;
int valorFinal1;

static int linha;



//Funcoes usadas no programa
void menu2();
void cadastro();
void exibi();
void pedido();
void total();
void inform();


//inicio do programa
int main()
{
   setlocale(LC_ALL,"Portuguese");
   system("mode con lines=60");//Altera as Linhas Da Kill Black Window/
   system("mode con cols=115");//Altera as Colunas Da Kill Black Window/


   int x;
if (x != 1){cls;}
    char line[100];
    FILE*file = fopen("texto//DRAW1.txt", "r");
        if (file != NULL){
            while (fgets(line, 100, file) != NULL)
                printf("\x1b[31m \t\t%s \x1b[0m", line);
        }
    char line2[100];
    FILE*file2 = fopen("texto//DRAW2.txt", "r");
        if (file2 != NULL){
            while (fgets(line2, 100, file2) != NULL)
                printf("\x1b[33m \t\t%s \x1b[0m", line2);
        }

    system("PAUSE");

            puts("\t                          +===========================================+");
            puts("\t                          |                                           |");
            puts("\t                          |                                           |");
            printf("\t                                            LOGIN:");  
            fflush(stdin);
            scanf("%[^\n]s" ,nome0);
            printf("\t                                            SENHA:");
            scanf("%d" , &opcao);



   switch(opcao){
   case 123:
        menu2();
        break;

   default:
    //system("cls");
    printf("\n\t                                 senha invalida Insira login e senha:\n");
    Sleep(1200);
    main();

   }

   return 0;
}
//Funcao de menu
void menu2(){
        setlocale(LC_ALL,"Portuguese");

        system("color 03");
        system("mode con lines=60");
        system("mode con cols=115");
        system("cls");

        puts("\t+===================================================================================================+");
        puts("\t|                                                                                                   |");
        puts("\t|                                        TELA DE CADASTRO                                           |");
        puts("\t|                                ===============================                                    |");
        puts("\t|                                       BEM VINDO - ADMIM                                           |");
        puts("\t                                                                                                     ");
        puts("\t+===================================================================================================+");
        puts("\t|                                                                                                   |");
        puts("\t|                                1- Cadastrar cliente                                               |");
        puts("\t|                                2- Exibir dados dos Clientes                                       |");
        puts("\t|                                3- Realizar Pedidos                                                |");
        puts("\t|                                4- Informacoes do programa                                         |");
        puts("\t|                                5- Elogios e Reclamacoes                                           |");
        puts("\t|                                6- Sair                                                            |");
        puts("\t|                                                                                                   |");
        puts("\t+===================================================================================================+\t");


        printf("\tSelecione uma opcao por favor:\t");
        scanf("%d", &opcao);
        system("cls");

        if(opcao == 1){
            cadastro();
        }
        else if (opcao == 2){
              exibi();
        }
        else if(opcao == 3){
            pedido();
        }

        else if(opcao == 4 ){
            inform();
        }

        else if(opcao == 5 ){
            menu2();
        }

        else if(opcao == 6 ){
              exit(0);
        }
        else if(opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4 && opcao != 5 && opcao != 6){
             menu2();
        }
}

//Funcao de cadastro de cliente
void cadastro(){
     setlocale(LC_ALL,"Portuguese");


     puts("\t+===================================================================================================+");
     puts("\t|                                                                                                   |");
     puts("\t|                                        TELA DE CADASTRO                                           |");
     puts("\t|                                ===============================                                    |");
   printf("\t|                                        BEM VINDO %s                                             |" ,nome0);
     puts("\t                                                                                                     ");
     puts("\t+===================================================================================================+");


    do{
    printf("\t\t   Digite um numero de (1 a 200) para cadastrar novo cliente:\t ");
    scanf("%d", &numCadastro[linha]);
    printf("\n\tDigite nome do cliente : ");
    fflush(stdin);
    scanf("%[^\n]s",nomeCli[linha]);
    printf("\n\tDigite o endereco do cliente : ");
    fflush(stdin);
    scanf("%[^\n]s",endeCli[linha]);
    printf("\n\tDigite o telefone do cliente : ");
    scanf("%d", &telefone[linha]);
    printf("\n\tDigite 1 para continuar a cadastrar ou numero 0 para voltar ao menu\t");
    scanf("%d" , &opcao);

    linha++;


    }while(opcao==1);
    return menu2();
}

//Funcao de verificacao de cadastro
void exibi(){
    setlocale(LC_ALL,"Portuguese");
    int verifCadastro;
    int i;

    puts("\t+===================================================================================================+");
    puts("\t|                                                                                                   |");
    puts("\t|                                       TELA DE VERIFICACAO                                         |");
    puts("\t|                                ===============================                                    |");
    puts("\t|                                                                                                   |");
    puts("\t|                                                                                                   |");
    puts("\t+===================================================================================================+\t");



    printf("\n\t(1) - para pesquisar por (numero) de codigo ou \n\t(2) - para verificar todos os cadastros - ");
    scanf("%d" , &opcao);
    switch(opcao){
        case 1:
            printf("\n\tDigite o Codigo :");
            scanf("%d", &verifCadastro);
            for(i=0;i<size;i++){
                if(numCadastro[i]== verifCadastro ){
                    printf("\nCodigo: %i\nNome: %s\nEndereco: %s\nTelefone: %i\n", numCadastro[i], nomeCli[i], endeCli[i], telefone[i]);
                }
            }
        break;
        case 2:
            printf("\n\tTodos os cadastros: ");
            if (numCadastro[0] !=0){
                for(i=0;i<size;i++){
                    if(numCadastro[i] != 0 ){
                        printf("\n\tCodigo: %i\n\tNome: %s\n\tEndereco: %s\n\tTelefone: %i\n", numCadastro[i], nomeCli[i], endeCli[i], telefone[i]);
                    }
                  }
            }else{
                printf("nao ha clientes cadastrados");
            }
            break;

        default:

            break;
    }




    printf("\n---------------------------------------------------------------------------------------------------------\n");
    printf("\n\t(1) - para continuar a pesquisa ou qualquer numero para sair - ");
    scanf("%i", &sair);

    if(sair == 1){
        system("cls");
        exibi();

    }else{
    menu2();
    }
    return 0;



};

//Funcao de Alugar o livro 
void pedido(){
setlocale(LC_ALL,"Portuguese");    
int sair2;
int verficaCpf;
int i;
int j;
int OpcaoPedido;
int valorTotal;
char nome[30];
// VARIAVEIS ANTIGAS



// VARIAVEIS LITERATURA BRASILEIRA
int gh = 15;
int vidaS = 15;
int grandeS = 15;
int memorias = 15;
//VARIAVEIS ROMANCE
int org = 15;
int mise = 15;
int dorian = 15;
int crime = 15;
//VARIAVEIS FICÇÃO CIENTIFICA
int george = 15;
int admi = 15;
int guerra = 15;
int odisseia = 15;
//VARIAVEIS POESIA
int senti = 15;
int alberto = 15;
int canticos = 15;
int paulo = 15;

float valorlivro =0;
int valorlivro1=0;
int quantPed, Option;

// VARIAVEIS DOS GENEROS
int opcao,opcao1,opcao2,opcao3;
//VARIAVEIS DOS LIVROS
int livOp,livOp1,livOp2,livOp3;





    system("color 09");
    system("mode con lines=60");//Altera as Linhas Da Kill Black Window/
    system("mode con cols=115");//Altera as Colunas Da Kill Black Window/

    puts("\t+===================================================================================================+");
    puts("\t|                                                                                                   |");
    puts("\t|                                        TELA DE PEDIDOS                                            |");
    puts("\t|                                ===============================                                    |");
    puts("\t|                                                                                                   |");
    puts("\t|                                                                                                   |");
    puts("\t+===================================================================================================+\t");

    printf("\tDigite o Codigo do cliente para cadastar o pedido :");
    scanf("%i", &verficaCpf);

   for(i=0;i<size;i++){
        if(cpfCli[i] == verficaCpf){
            printf("\n\tCodigo: %i \n\tNome: %s \n\tEndereco: %s \n\tTelefone: %i \n\tCPF: %i\n", numCadastro[i], nomeCli[i], endeCli[i], telefone[i], cpfCli[i]);
        }else{
            printf("\n\tCliente cadastrado\n");
 
        }

        break;
    }
    puts("\t+===================================================================================================+\t");
    printf("\n\tDigite (1) - para fazer pedido ou (0) - para voltar ao menu principal: ");
    scanf("%i", &sair2);

    if(sair2 == 1){


            do{
                system("cls");
                puts("\t+===================================================================================================+\t");
                puts("\t|                                                                                                   |");
                puts("\t|                                         ESCOLHA UM GENERO                                         |");
                puts("\t|                                                                                                   |");
                puts("\t|                            1 - Literatura Brasileira                                              |");
                puts("\t|                                                                                                   |");
                puts("\t|                            2 - Romance                                                            |");
                puts("\t|                                                                                                   |");
                puts("\t|                            3 - Ficcao Cientifica                                                  |");
                puts("\t|                                                                                                   |");
                puts("\t|                            4 - Poesia                                                             |");
                puts("\t|                                                                                                   |");
                puts("\t|                                                                                                   |");     
                puts("\t|                                                                                                   |");
                puts("\t|                          _____                                                                    |");
                puts("\t|                         /    /|_ ___________________________________________                      |"); 
                puts("\t|                        /    // /|                                          /|                     |");
                puts("\t|                       (====|/ // O bom livro e aquele que se abre         / |                     |");
                puts("\t|                        (=====|/   com interesse e se fecha com proveito. / .|                     |");
                puts("\t|                       (= ===|/                                          / /||                     |");
                puts("\t|                      /_________________________________________________/ / ||                     |");
                puts("\t|                      |  _____________________________________________  ||  ||                     |");
                puts("\t|                      | ||                                            | ||                         |");
                puts("\t|                      | ||                                            | ||                         |");
                puts("\t|                      | |                                             | |                          |");
                puts("\t|                                                                                                   |");
                puts("\t|                                                                                                   |");
                puts("\t+===================================================================================================+\t\n");

                puts("\t+===================================================================================================+\t");
                printf("\n\tDigite uma opcao : ");
                scanf("%i", &opcao1);

                int total=0;

                if(opcao1 ==1){
                    strcpy(nome, "Literatura Brasileira");
                    system("cls");
                puts("\t+===================================================================================================+\t");
                puts("\t|                                                                                                   |");
                puts("\t|                                         LITERATURA BRASILEIRA                                     |");
                puts("\t|                                                                                                   |");
                puts("\t|                            1 - Grande Sertao: Veredas (1956), Guimaraes Rosa                      |");
                puts("\t|                                                                                                   |");
                puts("\t|                            2 - A Paixao Segundo GH (1964), Clarice Lispector                      |");
                puts("\t|                                                                                                   |");
                puts("\t|                            3 - Vidas Secas (1938), Graciliano Ramos                               |");
                puts("\t|                                                                                                   |");
                puts("\t|                            4 - Memorias Postumas de Bras Cubas (1881), Machado de Assis           |");
                puts("\t|                                                                                                   |");
                puts("\t|                                                                                                   |");     
                puts("\t|                                                                                                   |");
                puts("\t|                          _____                                                                    |");
                puts("\t|                         /    /|_ ___________________________________________                      |"); 
                puts("\t|                        /    // /|                                          /|                     |");
                puts("\t|                       (====|/ // O bom livro e aquele que se abre         / |                     |");
                puts("\t|                        (=====|/   com interesse e se fecha com proveito. / .|                     |");
                puts("\t|                       (= ===|/                                          / /||                     |");
                puts("\t|                      /_________________________________________________/ / ||                     |");
                puts("\t|                      |  _____________________________________________  ||  ||                     |");
                puts("\t|                      | ||                                            | ||                         |");
                puts("\t|                      | ||                                            | ||                         |");
                puts("\t|                      | |                                             | |                          |");
                puts("\t|                                                                                                   |");
                puts("\t|                                                                                                   |");
                puts("\t+===================================================================================================+\t\n");

                puts("\t+===================================================================================================+\t");
                printf("\n\tDigite uma opcao : ");
                scanf("%i", &livOp);
    // 000000000000000000000000000000000000000000000000  CONTINUAR  0000000000000000000000000000000000000000000000000000000000000000000000000
                    if (livOp == 1){
                        strcpy(nome, "Grande Sertao: Veredas");
                        printf("\n\tVoce Alugou %s, De Preco R$: %i\n",nome, grandeS);
                        valorlivro = valorlivro + 15.00;
                        printf("\tSoma: %0.2f", valorlivro);
                        printf("\n\tPressione 1 para continuar pedindo ou 8 para finalizar pedido: ");
                        scanf("%d", &Option);
                    }
                    else if (livOp == 2){
                        strcpy(nome, "A Paixao Segundo GH");
                        printf("\n\tVoce Alugou %s, De Preco R$: %i\n",nome, gh);
                        valorlivro = valorlivro + 15.00;
                        printf("\tSoma: %0.2f", valorlivro);
                        printf("\n\tPressione 1 para continuar pedindo ou 8 para finalizar pedido: ");
                        scanf("%d", &Option);   
                    }
                    else if (livOp == 3){
                        strcpy(nome, "Vidas Secas");
                        printf("\n\tVoce Alugou %s, De Preco R$: %i\n",nome, vidaS);
                        valorlivro = valorlivro + 15.00;
                        printf("\tSoma: %0.2f", valorlivro);
                        printf("\n\tPressione 1 para continuar pedindo ou 8 para finalizar pedido: ");
                        scanf("%d", &Option);    
                    }
                    else if (livOp == 4){
                        strcpy(nome, "Memorias Postumas de Bras Cubas");
                        printf("\n\tVoce Alugou %s, De Preco R$: %i\n",nome, memorias);
                        valorlivro = valorlivro + 15.00;
                        printf("\tSoma: %0.2f", valorlivro);
                        printf("\n\tPressione 1 para continuar pedindo ou 8 para finalizar pedido: ");
                        scanf("%d", &Option);

                    }
                    // FIM DO IF NOVO ---------------------------------------------------------------------------------
                }

                else if(opcao1 ==2){
                    strcpy(nome, "Romance");
                    system("cls");
                puts("\t+===================================================================================================+\t");
                puts("\t|                                                                                                   |");
                puts("\t|                                         ROMANCES DISPONIVEIS                                      |");
                puts("\t|                                                                                                   |");
                puts("\t|                            1 - Orgulho e preconceito, de Jane Austen                              |");
                puts("\t|                                                                                                   |");
                puts("\t|                            2 - Os miseraveis, de Victor Hugo                                      |");
                puts("\t|                                                                                                   |");
                puts("\t|                            3 - O retrato de Dorian Gray, de Oscar Wilde                           |");
                puts("\t|                                                                                                   |");
                puts("\t|                            4 - Crime e castigo, de Fiodor Dostoievski                             |");
                puts("\t|                                                                                                   |");
                puts("\t|                                                                                                   |");     
                puts("\t|                                                                                                   |");
                puts("\t|                          _____                                                                    |");
                puts("\t|                         /    /|_ ___________________________________________                      |"); 
                puts("\t|                        /    // /|                                          /|                     |");
                puts("\t|                       (====|/ // O bom livro e aquele que se abre         / |                     |");
                puts("\t|                        (=====|/   com interesse e se fecha com proveito. / .|                     |");
                puts("\t|                       (= ===|/                                          / /||                     |");
                puts("\t|                      /_________________________________________________/ / ||                     |");
                puts("\t|                      |  _____________________________________________  ||  ||                     |");
                puts("\t|                      | ||                                            | ||                         |");
                puts("\t|                      | ||                                            | ||                         |");
                puts("\t|                      | |                                             | |                          |");
                puts("\t|                                                                                                   |");
                puts("\t|                                                                                                   |");
                puts("\t+===================================================================================================+\t\n");

                puts("\t+===================================================================================================+\t");
                printf("\n\tDigite uma opcao : ");
                scanf("%i", &livOp1);
// 000000000000000000000000000000000000000000000000  CONTINUAR  0000000000000000000000000000000000000000000000000000000000000000000000000
                    if (livOp1 == 1){
                        strcpy(nome, "Orgulho e preconceito");
                        printf("\n\tVoce Alugou %s, De Valor R$:%i\n",nome, org);
                        valorlivro = valorlivro + 15;
                        printf("\tSoma: %0.2f", valorlivro);
                        printf("\n\tPressione 1 para continuar pedindo ou 8 para finalizar pedido: ");
                        scanf("%d", &Option);
                   }
                   else if(livOp1 == 2){
                        strcpy(nome, "Os miseraveis");
                        printf("\n\tVoce Alugou %s, De Valor R$:%i\n",nome, mise);
                        valorlivro = valorlivro + 15;
                        printf("\tSoma: %0.2f", valorlivro);
                        printf("\n\tPressione 1 para continuar pedindo ou 8 para finalizar pedido: ");
                        scanf("%d", &Option);
                   }
                    else if(livOp1 == 3){
                        strcpy(nome, "O retrato de Dorian Gray");
                        printf("\n\tVoce Alugou %s, De Valor R$:%i\n",nome, dorian);
                        valorlivro = valorlivro + 15;
                        printf("\tSoma: %0.2f", valorlivro);
                        printf("\n\tPressione 1 para continuar pedindo ou 8 para finalizar pedido: ");
                        scanf("%d", &Option);
                   }
                    else if(livOp1 == 4){
                        strcpy(nome, "Crime e castigo");
                        printf("\n\tVoce Alugou %s, De Valor R$:%i\n",nome, crime);
                        valorlivro = valorlivro + 15;
                        printf("\tSoma: %0.2f", valorlivro);
                        printf("\n\tPressione 1 para continuar pedindo ou 8 para finalizar pedido: ");
                        scanf("%d", &Option);
                   }
                   // FIM DO IF NOVO ------------------------------------------------------------------------------------------------
                }
                else if(opcao1 ==3){
                    strcpy(nome, "Ficção Científica");
                    system("cls");
                puts("\t+===================================================================================================+\t");
                puts("\t|                                                                                                   |");
                puts("\t|                           LIVROS DE FICCAO CIENTIFICA DISPONIVEIS                                 |");
                puts("\t|                                                                                                   |");
                puts("\t|                            1 - 1984, George Orwell                                                |");
                puts("\t|                                                                                                   |");
                puts("\t|                            2 - Admiravel Mundo Novo, Aldous Huxley                                |");
                puts("\t|                                                                                                   |");
                puts("\t|                            3 - A Guerra dos Mundos, H. G. Wells.                                  |");
                puts("\t|                                                                                                   |");
                puts("\t|                            4 - 2001: uma Odisseia no Espaço, Arthur C. Clarke                     |");
                puts("\t|                                                                                                   |");
                puts("\t|                                                                                                   |");     
                puts("\t|                                                                                                   |");
                puts("\t|                          _____                                                                    |");
                puts("\t|                         /    /|_ ___________________________________________                      |"); 
                puts("\t|                        /    // /|                                          /|                     |");
                puts("\t|                       (====|/ // O bom livro e aquele que se abre         / |                     |");
                puts("\t|                        (=====|/   com interesse e se fecha com proveito. / .|                     |");
                puts("\t|                       (= ===|/                                          / /||                     |");
                puts("\t|                      /_________________________________________________/ / ||                     |");
                puts("\t|                      |  _____________________________________________  ||  ||                     |");
                puts("\t|                      | ||                                            | ||                         |");
                puts("\t|                      | ||                                            | ||                         |");
                puts("\t|                      | |                                             | |                          |");
                puts("\t|                                                                                                   |");
                puts("\t|                                                                                                   |");
                puts("\t+===================================================================================================+\t\n");

                puts("\t+===================================================================================================+\t");
                printf("\n\tDigite uma opcao : ");
                scanf("%i", &livOp2);
// 000000000000000000000000000000000000000000000000  CONTINUAR  0000000000000000000000000000000000000000000000000000000000000000000000000
                    if (livOp2 == 1){
                        strcpy(nome, "1984, George Orwell");
                        printf("\n\tVoce Alugou %s, De Valor R$:%i\n",nome, george);
                        valorlivro = valorlivro + 15;
                        printf("\tSoma: %0.2f", valorlivro);
                        printf("\n\tPressione 1 para continuar pedindo ou 8 para finalizar pedido: ");
                        scanf("%d", &Option);    
                    }
                    else if (livOp2 == 2){
                        strcpy(nome, "Admiravel Mundo Novo");
                        printf("\n\tVoce Alugou %s, De Valor R$:%i\n",nome, admi);
                        valorlivro = valorlivro + 15;
                        printf("\tSoma: %0.2f", valorlivro);
                        printf("\n\tPressione 1 para continuar pedindo ou 8 para finalizar pedido: ");
                        scanf("%d", &Option);    
                    }
                    else if (livOp2 == 3){
                        strcpy(nome, "A Guerra dos Mundos");
                        printf("\n\tVoce Alugou %s, De Valor R$:%i\n",nome, guerra);
                        valorlivro = valorlivro + 15;
                        printf("\tSoma: %0.2f", valorlivro);
                        printf("\n\tPressione 1 para continuar pedindo ou 8 para finalizar pedido: ");
                        scanf("%d", &Option);    
                    }
                    else if (livOp2 == 4){
                        strcpy(nome, "2001: uma Odisseia no Espaco");
                        printf("\n\tVoce Alugou %s, De Valor R$:%i\n",nome, odisseia);
                        valorlivro = valorlivro + 15;
                        printf("\tSoma: %0.2f", valorlivro);
                        printf("\n\tPressione 1 para continuar pedindo ou 8 para finalizar pedido: ");
                        scanf("%d", &Option);    
                    }
                    // FIM DO IF NOVO--------------------------------------------------------------------------------------------------------
                }
                else if(opcao1 ==4){
                    strcpy(nome, "Poesia");
                    system("cls");
                puts("\t+===================================================================================================+\t");
                puts("\t|                                                                                                   |");
                puts("\t|                                    LIVROS DE POESIA DISPONIVEIS                                   |");
                puts("\t|                                                                                                   |");
                puts("\t|                            1 - Sentimento do mundo, de Carlos Drummond de Andrade                 |");
                puts("\t|                                                                                                   |");
                puts("\t|                            2 - Poemas completos de Alberto Caeiro, de Fernando Pessoa             |");
                puts("\t|                                                                                                   |");
                puts("\t|                            3 - Canticos, de Cecilia Meireles                                      |");
                puts("\t|                                                                                                   |");
                puts("\t|                            4 - Vida, de Paulo Leminski                                            |");
                puts("\t|                                                                                                   |");
                puts("\t|                                                                                                   |");     
                puts("\t|                                                                                                   |");
                puts("\t|                          _____                                                                    |");
                puts("\t|                         /    /|_ ___________________________________________                      |"); 
                puts("\t|                        /    // /|                                          /|                     |");
                puts("\t|                       (====|/ // O bom livro e aquele que se abre         / |                     |");
                puts("\t|                        (=====|/   com interesse e se fecha com proveito. / .|                     |");
                puts("\t|                       (= ===|/                                          / /||                     |");
                puts("\t|                      /_________________________________________________/ / ||                     |");
                puts("\t|                      |  _____________________________________________  ||  ||                     |");
                puts("\t|                      | ||                                            | ||                         |");
                puts("\t|                      | ||                                            | ||                         |");
                puts("\t|                      | |                                             | |                          |");
                puts("\t|                                                                                                   |");
                puts("\t|                                                                                                   |");
                puts("\t+===================================================================================================+\t\n");

                puts("\t+===================================================================================================+\t");
                printf("\n\tDigite uma opcao : ");
                scanf("%i", &livOp3);
    // 000000000000000000000000000000000000000000000000  CONTINUAR  0000000000000000000000000000000000000000000000000000000000000000000000000
                    if (livOp3 == 1){
                        strcpy(nome, "Sentimento do mundo");
                        printf("\n\tVoce Alugou %s, De Valor R$:%i\n",nome, senti);
                        valorlivro = valorlivro + 15;
                        printf("\tSoma: %0.2f", valorlivro);
                        printf("\n\tPressione 1 para continuar pedindo ou 8 para finalizar pedido: ");
                        scanf("%d", &Option);
                    }
                    else if (livOp3 == 2){
                        strcpy(nome, "Poemas completos de Alberto Caeiro");
                        printf("\n\tVoce Alugou %s, De Valor R$:%i\n",nome, alberto);
                        valorlivro = valorlivro + 15;
                        printf("\tSoma: %0.2f", valorlivro);
                        printf("\n\tPressione 1 para continuar pedindo ou 8 para finalizar pedido: ");
                        scanf("%d", &Option);
                    }
                    else if (livOp3 == 3){
                        strcpy(nome, "Canticos");
                        printf("\n\tVoce Alugou %s, De Valor R$:%i\n",nome, canticos);
                        valorlivro = valorlivro + 15;
                        printf("\tSoma: %0.2f", valorlivro);
                        printf("\n\tPressione 1 para continuar pedindo ou 8 para finalizar pedido: ");
                        scanf("%d", &Option);
                    }
                    else if (livOp3 == 4){
                        strcpy(nome, "Vida");
                        printf("\n\tVoce Alugou %s, De Valor R$:%i\n",nome, paulo);
                        valorlivro = valorlivro + 15;
                        printf("\tSoma: %0.2f", valorlivro);
                        printf("\n\tPressione 1 para continuar pedindo ou 8 para finalizar pedido: ");
                        scanf("%d", &Option);
                    }
                }
                if(Option == 8){

                    printf("\n\tValor total da compra R$: %0.2f ", valorlivro);
                    printf("\n\tPressione 1 para voltar ao menu principal ");
                    scanf("%d", &Option);

                }
                if(Option == 1){
                     system("cls");
                     menu2();
                }
            }while(opcao1 == 1 || opcao1 == 2 || opcao1 == 3 || opcao1 == 4 );
            menu2();



    }else if(sair2==0){
        menu2();
    }


    return 0;
};

//Funçao de informacoes sobre o programa e ciradores
void inform(){
    setlocale(LC_ALL,"Portuguese");

    int Option;


    system("color 011");
    system("mode con lines=60");//Altera as Linhas Da Kill Black Window/
    system("mode con cols=115");//Altera as Colunas Da Kill Black Window/
    system("cls");


    puts("\t+===================================================================================================+");
    puts("\t+===================================================================================================+");
    puts("\t*===                                                                                             ===*");
    puts("\t*===                                                                                             ===*");
    puts("\t*===                                    TELA DE INFORMACAO                                       ===*");
    puts("\t*===                              ===============================                                ===*");
    puts("\t*===                                                                                             ===*");
    puts("\t*===                                                                                             ===*");
    puts("\t+===================================================================================================+\t");
    puts("\t+===================================================================================================+\n\n");


    puts("\t+===================================================================================================+\t");
    puts("\t|                                                                                                   |");
    puts("\t|                     UNASP - Centro Universitario Adventista de Sao Paulo                          |");
    puts("\t|                       ================================================                            |");
    puts("\t|                                                                                                   |");
    puts("\t|                                          Integrantes                                              |");
    puts("\t|                       -----------------------------------------------                             |");
    puts("\t|                       *                                             *                             |");
    puts("\t|                       *         Gabriel Lopes    RA: 062848         *                             |");
    puts("\t|                       *         Matheus D'Avila  RA: 056903         *                             |");
    puts("\t|                       *                                             *                             |");
    puts("\t|                                                                                                   |");
    puts("\t|                                                                                                   |");
    puts("\t+===================================================================================================+\n\t");


    printf("\n\tPressione (1) para voltar ao menu principal ");
    scanf("%d", &Option);

    if(Option == 1){
        system("cls");
        menu2();
    }
system("PAUSE");
return 0;
};

