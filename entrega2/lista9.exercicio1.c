/* 1. Uma empresa que organiza concursos está realizando um grande processo seletivo e conta com um sistema informatizado para auxiliar no gerenciamento de informações sobre os candidatos. Nesse sistema, as informações referentes aos candidatos são armazenadas em um vetor de ponteiros para dados estruturados do tipo Candidato, conforme descrito a seguir: 

typedef struct candidato {
    int inscr;
    char nome[81];

    Data nasc;
    Local *loc;
    Notas nt;

} Canditado

*/

#include <stdlib.h>
#include <stdio.h>

typedef struct data {
    int dia, mes, ano;
} Data;

typedef struct local {
    char ender[81];
    int sala;
} Local;

typedef struct notas {
    float geral;
    float especifica;
} Notas;

typedef struct candidato {
    int inscr;
    char nome[81];

    Data nasc;
    Local *loc;
    Notas nt;
} Candidato;

void le_candidatos(int n, Candidato **candidatos);
void impreme_candidatos(int n, Candidato **candidatos);
void muda_sala(Candidato **candidatos)

int main() {
    int n; // número de candidatos
    printf("Digite a quantidade de candidatos que deseja armazenar: ");
    scanf("%d", &n);

    Candidato **candidatos; // declara variável de um vetor de ponteiros para armazenar os candidatos
    
    candidatos = (Candidato**) malloc (n * sizeof(Candidato*)); 

    for (int i = 0; i < n; i++) {
        candidatos[i] = (Candidato*) malloc(sizeof(Candidato));
        candidatos[i]->loc = (Local*) malloc(sizeof(Local));
    }


    int nMenu = 1;
    printf("=========== MENU ===========");

    while (nMenu != 0) {
        printf("1- Ler dados dos candidatos\n2- Imprimir todos os dados\n3- Mudar endereço e sala de determinado candidato\n0- Sair");
        scanf("%d", nMenu);

        if (nMenu == 1) {
            le_candidatos(n, candidatos);
        } else if (nMenu == 2) {
            impreme_candidatos(n, candidatos);
        } else if (nMenu == 3) {
            muda_sala(candidatos)
        }
    }
    
    

    return 0;
}

void le_candidatos(int n, Candidato **candidatos) {
    for (int i = 0; i < n; i++) {
        printf("Digite a inscrição do candidato %d", i);
        scanf("%d", &candidatos[i]->inscr);

        printf("Digite o nome do candidato %d: ", i);
        scanf(" %80s", &candidatos[i]->nome);

        printf("Digite o dia de nascimento do candidato: ");
        scanf("%d", &candidatos[i]->nasc.dia);

        printf("Digite o mês de nascimento do candidato: ");
        scanf("%d", &candidatos[i]->nasc.mes);

        printf("Digite o ano de nascimento do candidato: ");
        scanf("%d", &candidatos[i]->nasc.ano);

        printf("Digite o endereço do local de provas: ");
        scanf(" %80s", &candidatos[i]->loc->ender);

        printf("Digite o número da sala onde ocorrerá a prova: ");
        scanf("%d", &candidatos[i]->loc->sala);
            
        printf("Digite a nota geral das provas desse candidato: ");
        scanf("%f", &candidatos[i]->nt.geral);

        printf("Digite a nota específica desse candidato: ");
        scanf("%f", &candidatos[i]->nt.especifica);
        }
}