#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 150
#define NUM_WA 15
#define NUM_DR 15
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// State begin
	char warrior[NUM_WA][MAX_LENGTH] = {""};
	char kingdom[NUM_WA][MAX_LENGTH] = {""};
	char title[NUM_WA][MAX_LENGTH] = {""};
	
	char dragon[NUM_DR][MAX_LENGTH] = {""};
    char age[NUM_DR][MAX_LENGTH] = {""};
    char element[NUM_DR][MAX_LENGTH] = {""};
    
    int dragonRented[NUM_WA] = {};
    
    char dateDelivery[NUM_WA][MAX_LENGTH] = {""};
   	char search[MAX_LENGTH];

	int controller = 0;
    int codWarrior = 0;
    int codDragon = 0;
    int encontradoW = 0;
    int encontradoD = 0;
    int quantiWarrior = 0;
    int quantiDragon = 0;
   	int	quantiRented = 0;
// State end

void listarGuerreiros()
{
    for(i = 0; i < NUM_WA; i++) {
        if(strcmp(warrior[i], "\0") != 0) {
            printf("Guerreiro encontrado(s).\nCodigo: %d\nNome: %s\nReino: %s\nTitulo: %s\n\n", i, warrior[i], kingdom[i], title[i]);
            quantiWarrior++;
        }
    }if (quantiWarrior == 0){
        printf("Nenhum guerreiro cadastrado.\n\n");
    }
}

void cadastrarGuerreiroPeloCodigo()
{
    printf("Digite o codigo do guerreiro:\n");
    scanf("%d", &codWarrior);

    if(codWarrior < 0 || codWarrior > NUM_WA - 1) {
        printf("Codigo Invalido\n");
    } 
    else if (strcmp(warrior[codWarrior], "\0") != 0) {
        printf("Ja existe um guerreiro cadastrado nesse codigo.\n\n");
    }
    else {
        printf("Qual o nome do guerreiro:\n");
        scanf("%s", warrior[codWarrior]);

        printf("Qual o reino do guerreiro:\n");
        scanf("%s", kingdom[codWarrior]);

        printf("Qual o titulo do guerreiro:\n");
        scanf("%s", title[codWarrior]);
    }
}

void pesquisarGuerreiroPeloNome()
{
    printf("Digite o nome do guerreiro:\n");
    scanf("%s", search);

    for (i = 0; i < NUM_WA; i++) {
        if(strcmp(search, warrior[i]) == 0) {
            printf("Guerreiro encontrado(s).\nCodigo: %d\nNome: %s\nReino: %s\nTitulo: %s\n\n", i, warrior[i], kingdom[i], title[i]);
            encontradoW ++;
        }
    }if (encontradoW == 0){
        printf("Nenhum guerreiro cadastrado.\n\n");
    }
}

void excluirGuerreiroPeloCodigo()
{
    for( i = 0; i < NUM_WA; i++) {
        if(strcmp(warrior[i], "\0") != 0) {
            printf("Codigo: %d\nNome: %s\nReino: %s\nTitulo: %s\n\n", i, warrior[i], kingdom[i], title[i]);
        }
    }

    printf("Digite o codigo do guerreiro:\n");
    scanf("%d", &codWarrior);

    if(codWarrior < 0 || codWarrior > NUM_WA - 1) {
        printf("Codigo Invalido\n");
    } else if(strcmp(warrior[codWarrior], "\0") == 0) {
        printf("Guerreiro nao existe");
    } else {
        strcpy(warrior[codWarrior], "\0");
        strcpy(kingdom[codWarrior], "\0");
        strcpy(title[codWarrior], "\0");
    }
}

void listarDragoes()
{
    for(i = 0; i < NUM_DR; i++) {
        if(strcmp(dragon[i], "\0") != 0) {
            printf("Dragao encontrado(s).\nCodigo: %d\nNome: %s\nIdade: %s\nElemento: %s\n\n", i, dragon[i], age[i], element[i]);
            quantiDragon++;
        }
    }if (quantiDragon == 0){
        printf("Nenhum dragao cadastrado.\n\n");
    }
}

void cadastrarDragaoPeloCodigo()
{
    printf("Digite o codigo do dragao:\n");
    scanf("%d", &codDragon);

    if(codDragon < 0 || codDragon > NUM_DR - 1) {
        printf("Codigo Invalido\n");
    }
        else if(strcmp(dragon[codDragon], "\0") != 0){
            printf("Ja existe um dragao cadastrado nesse codigo.\n\n");
        }
    else {
        printf("Qual o nome do dragao:\n");
        scanf("%s", dragon[codDragon]);

        printf("Qual a idade do dragao:\n");
        scanf("%s", age[codDragon]);

        printf("Qual o elemento do dragao:\n");
        scanf("%s", element[codDragon]);
    }
}

void pesquisarDragaoPeloNome()
{
    printf("Digite o nome do dragao:\n");
    scanf("%s", search);

    for (i = 0; i < NUM_DR; i++) {
        if(strcmp(search, dragon[i]) == 0) {
            printf("Dragao encontrado(s).\nCodigo: %d\nNome: %s\nIdade: %s\nElemento: %s\n\n", i, dragon[i], age[i], element[i]);
            encontradoD++;
        }
    }

    if (encontradoD == 0){
        printf("Dragao nao encontrado.\n\n");
    }
}

void excluirDragaoPeloCodigo()
{
    for(i = 0; i < NUM_DR; i++) {
        if(strcmp(dragon[i], "\0") != 0) {
            printf("\nCodigo: %d\nNome: %s\nIdade: %s\nElemento: %s\n\n", i, dragon[i], age[i], element[i]);
        }
    }
    printf("Digite o codigo do dragao:\n");
    scanf("%d", &codDragon);

    for(i = 0; i < NUM_WA; i++) {
        if(dragonRented[i] == codDragon) {
            printf("Esse dragao possui uma locacao.\n");
            break;
        }
    }
    if(codDragon < 0 || codDragon > NUM_DR - 1) {
        printf("Codigo Invalido\n");
    } else if (strcmp(dragon[codDragon], "\0") == 0) {
        printf("Dragao nao existe");
    } else {
        strcpy(dragon[codDragon], "\0");
        strcpy(age[codDragon], "\0");
        strcpy(element[codDragon], "\0");
    }
}

void listarDragoesLocados()
{
    for(i = 0; i < NUM_WA; i++) {
        if(dragonRented[i] >= 0) {
            printf("Dragao locado:\ncodigo: %d\nDragao: %s\nIdade: %s\nElemento: %s\n\n", dragonRented[i], dragon[dragonRented[i]], age[dragonRented[i]], element[dragonRented[i]]);
            quantiRented++;
        }
    }
    
    if(quantiRented == 0){
        printf("Nao ha dragao locado.\n\n");
    }
}

void locarDragao()
{
    printf("Digite o codigo do guerreiro:\n");
    scanf("%d", &codWarrior);

    printf("Digite o codigo do dragao:\n");
    scanf("%d", &codDragon);

    if(codWarrior < 0 || codWarrior > NUM_WA - 1 || strcmp(warrior[codWarrior], "\0") == 0) {
        printf("Codigo do guerreiro eh invalido\n");
    } else if (codDragon < 0 || codDragon > NUM_WA - 1 || strcmp(dragon[codDragon], "\0") == 0) {
        printf("Codigo do guerreiro eh invalido\n");
    } else if (dragonRented[codWarrior] >= 0) {
        printf("Esse guerreiro ja tem uma locacao ativa\n");
    } else {
        printf("Digite a data de entrega:\n");
        scanf("%s", dateDelivery[codWarrior]);
        dragonRented[codWarrior] = codDragon;
    }
}

void devolverDragaoPeloCodigoDoCliente()
{
    printf("Digite o codigo do guerreiro:\n");
    scanf("%d", &codWarrior);
    if(codWarrior < 0 || codWarrior > NUM_WA - 1) {
        printf("Codigo do guerreiro eh invalido\n");
    } else if (dragonRented[codWarrior] == -1) {
        printf("Esse guerreiro nao tem uma locacao ativa\n");
    } else {
        strcpy(dateDelivery[codWarrior], "\0");
        dragonRented[codWarrior] = -1;
        printf("Dragao devolvido.\n");
    }
}

void menu()
{
    int controller = 0;
    do {
        printf( "LOCADORA KALEESI:\n\n"
                "0- Sair.\n"
                "1- Listar guerreiros:\n"
                "2- Cadastrar guerreiro pelo codigo:\n"
                "3- Pesquisar guerreiro pelo nome:\n"
                "4- Excluir guerreiro pelo codigo:\n"
                "5- Listar dragoes:\n"
                "6- Cadastrar dragao pelo codigo:\n"
                "7- Pesquisar dragao pelo nome:\n"
                "8- Excluir dragao pelo codigo:\n"
                "9- Listar dragoes locados:\n"
                "10- Locar dragao:\n"
                "11- Devolver dragao pelo codigo do cliente:\n");
        scanf("%d", &controller);

        switch (controller){
            case 1:
                listarGuerreiros();
                break;
            case 2:
                cadastrarGuerreiroPeloCodigo();
                break;
            case 3:
                pesquisarGuerreiroPeloNome();
                break;
            case 4:
                excluirGuerreiroPeloCodigo();
                break;
            case 5:
                listarDragoes();
                break;
            case 6:
                cadastrarDragaoPeloCodigo();
                break;
            case 7:
                pesquisarDragaoPeloNome();
                break;
            case 8:
                excluirDragaoPeloCodigo();
                break;
            case 9:
                listarDragoesLocados();
                break;
            case 10:
                locarDragao();
                break;
            case 11:
                devolverDragaoPeloCodigoDoCliente();
                break;
            default:
                break;
        }

    }while(controller != 0);
}

void initDragonRented(){
    int i;

    for (i = 0; i < NUM_WA; i++) {
        dragonRented[i] = -1;
    }
}

int main(int argc, char *argv[]) {
    initDragonRented();
    menu();
}
