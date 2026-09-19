/*Um cinema que possui capacidade de 20 lugares está quase sempre lotado. Certo dia cada
espectador respondeu a um questionário, onde constava:
- sua idade;
- sua opinião em relação ao filme, que podia ser: ótimo, bom, regular, ruim ou péssimo.
Elabore um programa que, recebendo estes dados calcule em funções e mostre:
a. a quantidade de respostas ótimo;
b. a diferença percentual entre respostas bom e regular;
c. a média de idade das pessoas que responderam ruim;
d. a porcentagem de respostas péssimo e a maior idade que utilizou esta opção;
e. a diferença de idade entre a maior idade que respondeu ótimo e a maior idade que respondeu
ruim.*/
#include <stdio.h>
void opniao_filme(int *q_ot, int *q_bom, int *q_reg, int *q_ruim, int *q_pes, int idade, int *somaidade_ruim, int *idade_maior_pessimo, int *idade_maior_otimo, int *idade_maior_ruim);
float mediaidade_ruim(int r_ruim, int soma_idade);
float diferenca_percentual(int r_bom, int r_regul, int n);
float porcentagem_pessimo(int r_pessimo, int n);
int diferenca_idade(int idade_otimo, int idade_ruim);
int main(){
    int opcao,num,cont = 1,otimo = 0,bom = 0,regular = 0,ruim = 0,pessimo = 0,som_ruim = 0, maior_pessimo = 0, maior_otimo = 0, maior_ruim = 0;
    printf("O cinema lotou?\n");
    printf("1. Sim\n");
    printf("2. Nao\n");
    scanf("%i", &opcao);
    if(opcao != 1){
        while(cont == 1){
            printf("Numero de espectadores: \n");
            scanf("%i", &num);
            if(num > 20 || num < 0) printf("Tente Novamente!\n");
            else break;
        }
    }
    else num = 20;
    int idades[num];
    for(int i = 0; i < num; i++){
        printf("Digite a idade: \n");
        scanf("%i", &idades[i]);
        opniao_filme(&otimo, &bom, &regular, &ruim, &pessimo, idades[i], &som_ruim, &maior_pessimo, &maior_otimo, &maior_ruim);

    }
    float dif_percentual = diferenca_percentual(bom, regular, num);
    float med_ida_ruim = mediaidade_ruim(ruim, som_ruim);
    float porcent_pes = porcentagem_pessimo(pessimo, num);
    int difc = diferenca_idade(maior_otimo, maior_ruim);
    printf("Tiveram %i respostas otimo\n", otimo);
    printf("A diferenca percentual entre bom e regular e: %.2f\n", dif_percentual);
    printf("A media da idade das pessoas que responderam ruim e: %.2f\n", med_ida_ruim);
    printf("A maior idade que respondeu pessimo e %i\n", maior_pessimo);
    printf("A porcentagem de quem falou pessimo e: %.2f\n", porcent_pes);
    printf("A diferenca entre a maior idade otima e a maior ruim e: %i", difc);

}
void opniao_filme(int *q_ot, int *q_bom, int *q_reg, int *q_ruim, int *q_pes, int idade, int *somaidade_ruim, int *idade_maior_pessimo, int *idade_maior_otimo, int *idade_maior_ruim){
    printf("Opiniao sobre o filme: \n");
    int opc2;
        printf("1. Otimo\n");
        printf("2. Bom\n");
        printf("3. Regular\n");
        printf("4. Ruim\n");
        printf("5. Pessimo\n");
        scanf("%i", &opc2);
        if(opc2 == 1){ 
            (*q_ot)++;
            if(idade > *idade_maior_otimo) *idade_maior_otimo = idade;
        }
        if(opc2 == 2) (*q_bom)++;
        if(opc2 == 3) (*q_reg)++;
        if(opc2 == 4){
            (*q_ruim)++;
            *somaidade_ruim += idade;
            if(idade > *idade_maior_ruim) *idade_maior_ruim = idade;
        }
        if(opc2 == 5) {
            (*q_pes)++;
            if(idade > *idade_maior_pessimo) *idade_maior_pessimo = idade;
    }
}
float mediaidade_ruim(int r_ruim, int soma_idade){
    if (r_ruim == 0) return 0;
    float media = (float)soma_idade / r_ruim;
    return media;
}
float diferenca_percentual(int r_bom, int r_regul, int n){
    float perc_bom = ((float)r_bom/n) * 100;
    float perc_regular = ((float)r_regul/n) * 100;
    float diferenca = perc_bom - perc_regular;
    return diferenca;
}
float porcentagem_pessimo(int r_pessimo, int n){
    float porcentagem = ((float)r_pessimo/n) * 100;
    return porcentagem;
}
int diferenca_idade(int idade_otimo, int idade_ruim){
    float diferenca_id = idade_otimo - idade_ruim;
    return diferenca_id;
}
