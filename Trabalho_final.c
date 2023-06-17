/*Alunos:

Alex xavier de moraes                                           Periodo: Manha
Alisson Rodrigues                                               Periodo: Noturno
Thiago Roberto Indalecio de Oliveira                            Periodo: Noturno

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

void inserir(Conta* contas[], int* totalContas);
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

    switch (opcao) {

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

    Conta* novaconta = (Conta*) malloc (sizeof(Conta));


        printf("\n----------------- Cadastro -----------------\n");
        printf("Número da conta: "); scanf("%d", &(novaconta -> numero));
        printf("Nome do cliente: ");
        fflush(stdin);
        fgets(novaconta -> cliente, 51, stdin);

    do
    {
        printf("\nConta especial?\n");
        printf("[ 1 - Sim | 0 - Não ] =\t"); scanf("%d", &(novaconta -> especial));

            if(novaconta -> especial != 0 && novaconta -> especial != 1){
                printf("\n!!! Essa opção não é possivel !!!\n !!! Tente com '1' ou '0' !!!");
                printf("\n--------------------------------------------\n");
            }
    }while(novaconta -> especial != 0 && novaconta -> especial != 1);

    do   
    {
        printf("\nSaldo atual: "); scanf("%f", &(novaconta -> saldo));
            if(novaconta -> saldo < 0){
                printf("\nNao pode iniciar com saldo negativo.\n");
                printf("\n--------------------------------------------\n");
            }
    }while(novaconta -> saldo < 0);

    contas[*totalContas] = novaconta;
    (*totalContas)++;
    
    printf("--------------------------------------------\n");
    printf("Conta cadastrada com sucesso.\n");
    printf("--------------------------------------------\n");
    

}

void alterar(Conta* contas[], int totalContas){

    int numeroconta, i;

    printf("\n-------------- Alterar Dados ---------------\n");
    printf("Digite o número da conta a ser alterada: "); scanf("%d", &numeroconta);
    printf("--------------------------------------------\n");
   

    for (i = 0; i < totalContas; i++)
    {
        if(contas[i] -> numero == numeroconta){
            printf("\n\t\tOlá %s\n", contas[i] -> cliente);
            printf("Insira o novo nome de cliente: ");
            fflush(stdin);
            fgets(contas[i] -> cliente, 51, stdin);

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
            printf("Número da conta: %d\n", contas[i] -> numero);
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
            printf("\nEssa conta pertence a/ao %s\n Esta correto?\n", contas[i] -> cliente);
            printf("1 - Sim.\n");
            printf("0 - Não.\n");
            scanf("%d", &escolha);

                if(escolha == 0){
                    return;
                }else if(escolha == 1){

                    printf("\nDigite o valor a ser depositado: "); scanf("%f", &valor);

                        if(valor > 0){
                            contas[i] -> saldo += valor;
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
                    contas[i] -> saldo -= valor;
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
        saldototal += contas[i] -> saldo;
    }
    printf("Saldo geral de todas as contas: %.2f", saldototal);
    printf("\n--------------------------------------------\n");


}