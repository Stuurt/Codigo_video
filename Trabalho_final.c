/*Alunos:

Alex xavier de moraes                                           Periodo: Noturno
Alisson Rodrigues                                               Periodo: Noturno
Thiago Roberto Indalecio de Oliveira                            Periodo: Noturno

As linhas 41 e 42 foram utilizadas para que a IDE compreendesse os caracteres especiais como 'ç', 'ã' entre outros.
A IDE que eu utilizei foi o Visual Studio Code
Para rodar em qualquer outra IDE basta remover as linhas 41, 42 e a biblioteca '#include <windows.h>'.

Link do video no Youtube: https://youtu.be/poAfikWYxSE

*/

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#define MAX_CONTAS 50


typedef struct {
    int numero;
    char cliente[51];
    int especial;
    float saldo;
} Conta;

void inserir(Conta* contas[], int* totalContas);                //O 'int*' indica que 'totalContas' é um ponteiro para um inteiro. O uso do asterisco * indica que estamos lidando com um ponteiro. Nesse caso específico, o ponteiro 'totalContas' é usado para permitir que a função altere o valor da variável 'totalContas' definida na função 'main'.
void alterar(Conta* contas[], int totalContas);
void procurar(Conta* contas[], int totalContas);
void listar(Conta* contas[], int totalContas);
void depositar(Conta* contas[], int totalContas);
void sacar(Conta* contas[], int totalContas);
void imprimir(Conta* contas[], int totalContas);
void saldoGeral(Conta* contas[], int totalContas);

int escolha;

int main(){

    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);

    Conta contas[MAX_CONTAS];
    int totalContas = 0;
    int opcao;

    do {
        printf("\n------------------- Menu -------------------\n");
        printf("1. Inserir nova conta\n");
        printf("2. Alterar dados de uma conta\n");
        printf("3. Procurar uma conta\n");
        printf("4. Listar todas as contas\n");
        printf("5. Realizar depósito\n");
        printf("6. Realizar saque\n");
        printf("7. Imprimir dados de uma conta\n");
        printf("8. Mostrar saldo geral\n");
        printf("0. Sair\n");
        printf("--------------------------------------------\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        printf("--------------------------------------------\n");

    switch (opcao){

        case 1:
            inserir(contas, &totalContas);
        break;

        case 2:
            alterar(contas, totalContas);
        break;

        case 3:
            procurar(contas, totalContas);
        break;

        case 4:
            listar(contas, totalContas);
        break;

        case 5:
            depositar(contas, totalContas);
        break;

        case 6:
            sacar(contas, totalContas);
        break;
        
        case 7:
            imprimir(contas, totalContas);
        break;

        case 8:
            saldoGeral(contas, totalContas);
        break;

        case 0:
            printf("Encerrando o programa...\n");
        break;

        default:
            printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}


void inserir(Conta* contas[], int* totalContas){

    if(*totalContas == MAX_CONTAS){
        printf("Ultima conta possivel.\n");
    }else if(*totalContas > MAX_CONTAS){
        printf("Limite de contas atingido.\n");
    }

    Conta* novaconta = (Conta*) malloc (sizeof(Conta));                 //Essa linha está alocando dinamicamente memória para uma nova chamada da struct


        printf("\n----------------- Cadastro -----------------\n");
        printf("Número da conta: "); scanf("%d", &(novaconta -> numero));
        printf("Nome do cliente: ");
        fflush(stdin);
        fgets(novaconta -> cliente, 51, stdin);

    do
    {
        printf("\nConta especial?\n");
        printf("[ 1 - Sim | 0 - Não ] =\t"); scanf("%d", &(novaconta -> especial));         //'novaconta -> especial' e um ponteiro que direciona se a 'novaconta' sera especial ou nao;

            if(novaconta -> especial != 0 && novaconta -> especial != 1){
                printf("\n!!! Essa opção não é possivel !!!\n !!! Tente com '1' ou '0' !!!");
                printf("\n--------------------------------------------\n");
            }
    }while(novaconta -> especial != 0 && novaconta -> especial != 1);

    do   
    {
        printf("\nSaldo atual: "); scanf("%f", &(novaconta -> saldo));
            if(novaconta -> saldo < 0){
                printf("\nNão pode iniciar com saldo negativo.\n");
                printf("\n--------------------------------------------\n");
            }
    }while(novaconta -> saldo < 0);

    contas[*totalContas] = novaconta;                                  //Aqui o "contas" e um tipo de array = "conjunto" de dados, que atribui a proxima posicao do array para "novaconta";
    (*totalContas)++;                                                  //"totalContas" corresponde ao total de contas do codigo, aqui e um contador para que sempre quando passar por aqui somar uma conta no totalContas;

    printf("--------------------------------------------\n");
    printf("Conta cadastrada com sucesso.\n");
    printf("--------------------------------------------\n");
    

}

void alterar(Conta* contas[], int totalContas){

    int numeroconta, i;

    printf("\n-------------- Alterar Dados ---------------\n");
    printf("Digite o número da conta a ser alterada: "); scanf("%d", &numeroconta);
    printf("--------------------------------------------\n");
   

    for (i = 0; i < totalContas; i++)                                  //Esse 'for' e responsavel por percorrer todas as contas (sera muito visto durante o codigo);
    {
        if(contas[i] -> numero == numeroconta){                        //O 'if' aqui e responsavel por conferir quando o 'numeroconta' for igual ao numero de uma conta existente no codigo (sera muito visto durante o codigo);
            printf("\n\t\tOlá %s\n", contas[i] -> cliente);            //'contas[i] -> cliente' e um ponteiro que e direcionado para o cliente;
            printf("Insira o novo nome de cliente: ");
            fflush(stdin);                                             //'fflush' e usado para limpar a memoria de saida e mandar para memoria do console;
            fgets(contas[i] -> cliente, 51, stdin);                    //'fgets' lê uma cadeia de caracteres do argumento, aqui sera o nome do cliente;

            printf("--------------------------------------------\n");
            printf("Dados alterados com sucesso.\n");
            printf("--------------------------------------------\n");
            

            return;
        }
    }
    printf("--------------------------------------------\n");
    printf("!!! Conta não encontrada !!!\n");
    printf("--------------------------------------------\n");
    
       
}

void procurar(Conta* contas[], int totalContas){

    int numeroconta, i;

    printf("\n-------------- Procurar conta --------------\n");
    printf("Digite o número da conta a ser procurada: "); scanf("%d", &numeroconta);
    printf("--------------------------------------------\n");
    

    for (i = 0; i < totalContas; i++)
    {
        if(contas[i] -> numero == numeroconta){
            printf("Número da conta: %d\n", contas[i] -> numero);       //'contas[i] -> numero' e um ponteiro que e direcionado para o numero da conta;
            printf("Nome do cliente: %s", contas[i] -> cliente);        //'contas[i] -> cliente' e um ponteiro que e direcionado para o cliente da conta;

                if(contas[i] -> especial == 1){                         //O 'if' aqui funciona para conferir a escolha anterior de '1' ou '0' para conta especial;
                    printf("Conta especial: Sim\n");
                }else{
                    printf("Conta especial: Não\n");
                }

            printf("Saldo atual: %.2f\n", contas[i] -> saldo);          //'contas[i] -> saldo' e um ponteiro que e direcionado para o saldo da conta;
            return;
        }
    }
    printf("--------------------------------------------\n");
    printf("!!! Conta não encontrada !!!\n");
    printf("--------------------------------------------\n");
    

}

void listar(Conta* contas[], int totalContas){

    int i;

    printf("\n-------------- Todas as contas -------------\n\n");

        if(totalContas == 0){
            printf("Não existe contas cadastradas.\n");
        }

    for (i = 0; i < totalContas; i++)
    {
        printf("------------------- Conta %d ----------------\n", contas[i] -> numero);
        printf("Nome do cliente: %s", contas[i] -> cliente);

                if(contas[i] -> especial == 1){
                    printf("Conta especial: Sim\n");
                }else{
                    printf("Conta especial: Não\n");
                }

        printf("Saldo atual: %.2f\n\n", contas[i] -> saldo);
        printf("--------------------------------------------\n");
        

    }
    
}

void depositar(Conta* contas[], int totalContas){

    int numeroconta, i;
    float valor;

    printf("\n----------------- Deposito -----------------\n");
    printf("Digite o número da conta: "); scanf("%d", &numeroconta);
    printf("--------------------------------------------\n");
    

    for (i = 0; i < totalContas; i++)
    {
        if(contas[i] -> numero == numeroconta){
            printf("\nEssa conta pertence a/ao %s\n Esta correto?\n", contas[i] -> cliente);        //Uma maneira de conferir se o 'numeroconta' foi escolhido certo, printa o nome do cliente antes do deposito;
            printf("1 - Sim.\n");
            printf("0 - Não.\n");
            scanf("%d", &escolha);

                if(escolha == 0){
                    return;
                }else if(escolha == 1){

                    printf("\nDigite o valor a ser depositado: "); scanf("%f", &valor);

                        if(valor > 0){
                            contas[i] -> saldo += valor;                                            //'contas[i] -> saldo' e um ponteiro que e direcionado para o saldo do cliente onde apos o '+=' soma com o valor de deposito;
                            printf("--------------------------------------------\n");
                            printf("Deposito realizado com sucesso.\n");
                            printf("--------------------------------------------\n");
                        }else{
                            printf("\n!!! Valor inválido !!!\n");
                        }
            
                    return;
                }else{
                    printf("\n!!! Não existe essa opção !!!\n");
                    return;
                }

        }

    }
    printf("--------------------------------------------\n");
    printf("!!! Conta não encontrada !!!\n");
    printf("--------------------------------------------\n");


}

void sacar(Conta* contas[], int totalContas){

    int numeroconta, i;
    float valor;

    printf("\n------------------ Saque -------------------\n");
    printf("Digite o número da conta: "); scanf("%d", &numeroconta);
    printf("--------------------------------------------\n");
    

    for (i = 0; i < totalContas; i++)
    {
        if(contas[i] -> numero == numeroconta){
            printf("\n\t\tBem vindo(a) %s\n", contas[i] -> cliente);
            printf("Digite o valor a ser sacado: "); scanf("%f", &valor);

                if((valor > 0) && (valor <= contas[i] -> saldo)){
                    contas[i] -> saldo -= valor;                                                //'contas[i] -> saldo' e um ponteiro que e direcionado para o saldo do cliente onde apos o '-=' subtrai o valor do saque escolhido;
                    printf("--------------------------------------------\n");
                    printf("Saque realizado com sucesso.\n");
                    printf("--------------------------------------------\n");
                    

                }else{
                    printf("\n!!! Valor inválido ou saldo insuficiente !!!\n");
                }
            
            return;
        }

    }
    printf("--------------------------------------------\n");
    printf("!!! Conta não encontrada !!!\n");
    printf("--------------------------------------------\n");
    

}

void imprimir(Conta* contas[], int totalContas){

    int numeroconta, i;

    printf("\n---------------- Impressão -----------------\n");
    printf("Digite o número da conta a ser impressa: "); scanf("%d", &numeroconta);
    printf("--------------------------------------------\n");
    

    for (i = 0; i < totalContas; i++)
    {
        if(contas[i] -> numero == numeroconta){
            printf("\n\t\tOlá %s\nAqui estão seus dados impressos:\n", contas[i] -> cliente);
            printf("\n------------------ Conta %d -----------------\n", contas[i] -> numero);
            printf("Nome do cliente: %s", contas[i] -> cliente);

                if(contas[i] -> especial == 1){
                    printf("Conta especial: Sim\n");
                }else{
                    printf("Conta especial: Não\n");
                }

            printf("Saldo atual: %.2f\n", contas[i] -> saldo);
            return;
        }
    }
    printf("--------------------------------------------\n");
    printf("!!! Conta não encontrada !!!\n");
    printf("--------------------------------------------\n");
    

}

void saldoGeral(Conta* contas[], int totalContas){

    float saldototal = 0;
    int i;

    printf("\n---------------- Saldo Geral ---------------\n");

    for (i = 0; i < totalContas; i++)
    {
        saldototal += contas[i] -> saldo;                                   //Aqui o 'saldototal' representa uma variavel que apos o '+=' faz uma somatoria de todos os saldos das contas existentes;
    }
    printf("Saldo geral de todas as contas: %.2f", saldototal);
    printf("\n--------------------------------------------\n");


}
