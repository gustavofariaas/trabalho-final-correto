#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{

 char heroi[25];
 int poder;
} heroes;

void ordenarpoder(heroes herois[]) {
    int i, j, aux=0;
    for (i = 10; i >=1; i--) {
        for (j = 0;i>j; j++) {
            if (herois[j].poder < herois[j + 1].poder) {
                aux = herois[j].poder;
                herois[j].poder= herois[j + 1].poder;
                herois[j + 1].poder = aux;
            }
        }
    }
}


void simularBatalha(heroes * herois[], heroes *thanos){

    FILE * saida;
    saida = fopen("gabarito.txt","w");
    int i;
    if(saida!=NULL){

        while (thanos->poder <10){
            for(i=0;i<11;i++){
            ordenarpoder(herois);
            imprime(&thanos, herois[i]->poder);



            }
        }


        }
    }



heroes** selecaoParaAtaque(heroes herois[]){
    heroes **locao = (heroes*) malloc( sizeof(heroes*)*11);

    int i,c=0,escolha=0;
    for(i=0;i<11;i++){
            locao[i]=NULL;
            if(herois[i].poder>10){
                printf("Escolha se o %s vai entrar:\n",herois[i].heroi);
                printf("1-SIM || 2-NAO\n");
                scanf("%d",&escolha);
                if(escolha > 2 || escolha < 1){
                        printf("Opcao invalida.\n");
                        i--;
                } else if (escolha == 1) {
                        locao[c] = &herois[i];
                        c++;
                }
            }
     }

     return locao;
    }



void imprime(heroes*thanos, heroes  herois[]){
    int i;
    printf("%s\n",thanos->heroi);
    printf("%d\n",thanos->poder);
    for(i=0; i<11;i++){
        printf("%s\n",herois[i].heroi);
        printf("%d\n",herois[i].poder);
    }
}
//heroes** selecaoParaAtaque(heroes vetor[])
//}
void leHeroi(heroes *thanos,heroes h[])  {
    int i=0, temp1=0, temp2=0;
    FILE * entrada;
    entrada = fopen ("herois.txt", "r");
    if (entrada != NULL){

        do{
            fscanf (entrada,"%s",thanos->heroi);
            fscanf (entrada,"%d",&temp1);
            thanos->poder = temp1;
            for (i=0 ; i<11 ; i++){
            fscanf(entrada,"%s",h[i].heroi);
            fscanf(entrada,"%d",&h[i].poder);
            }
        }while(!feof(entrada));
        fclose(entrada);


    } else { printf("Deu ruim."); }// treta no file







}


int main(void){
int i,somapoder=0,selecao;
heroes thanos, herois[11] ;
leHeroi(&thanos, herois);
printf("                                                                                                                                                      \n\
                                                                                    /oooooooooooooooooo:`                                             \n\
                                                                                  `+NMMMMMMMMMMMMMMMMMNo`                                             \n\
                                                                                 `oNMMMMMMMMMMMMMMMMMMNo`                                             \n\
                                                                                 +mMMMMMMMMMMMMMMMMMMMNo`                                             \n\
                                                                               `/NMMMMMMMMMMMMMMMMMMMMNo`                                             \n\
                                                                              `+mMMMMMMMMMMMMMMMMMMMMMNo`                                             \n\
                                                                              +mMMMMMMMMMMMMMMMMMMMMMMNo`                                             \n\
                                                                            `/mMMMMMMMMMMMMMMMMMMMMMMMNo`                                             \n\
                                                                           `/mMMMMMMMMMMMMMMMMMMMMMMMMNo`                                             \n\
                                                             ``..--:///++++smMMMMMMMMMMMMMMMMMMMMMMMMMNo`                                             \n\
                                                       `-:+oyhdmmNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNo`                                             \n\
                                                 `.:+shmmNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNo`                                             \n\
                                             `.:ohmNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNo`                                             \n\
                                          `-+hmNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMd+.`                                           \n\
                                       `:odNMMMMMMMMMMMMMMMMMMMNNmmdhhhmMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNmho-`                                        \n\
                                    `-odNMMMMMMMMMMMMMMMNNmhso/:-..```/mMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMmh+.`                                     \n\
                                  ./hNMMMMMMMMMMMMMMNdyo/-``         /mMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMms:`                                   \n\
                                .odNMMMMMMMMMMMMNdy/-.`            `:mMMMMMMMMMMMMMMmhNMMMMMMMMMMMMMMMMMMMMMMMMMMNy/`                                 \n\
                              .+dMMMMMMMMMMMMNds:.`               `:dMMMMMMMMMMMMMMMo/NMMMMMMMMMMMMMMMMMMMMMMMMMMMMNh/`                               \n\
                            .+mMMMMMMMMMMMNds:`                   :dMMMMMMMMMMMMMMMy`/NMMMMMMMMMMMMMMMNsymMMMMMMMMMMMNh/`                             \n\
                          `/hNMMMMMMMMMMmy/.`                    -dMMMMMMMMMMMMMMMh- /NMMMMMMMMMMMMMMMm:`-ohNMMMMMMMMMMNs-`                           \n\
                         -sNMMMMMMMMMMNs:`                      -hMMMMMMMMMMMMMMMd-  /NMMMMMMMMMMMMMMMm:   .+hNMMMMMMMMMMm+`                          \n\
                       `/dMMMMMMMMMMms:`                       -dMMMMMMMMMMMMMMMm:   /NMMMMMMMMMMMMMMMm:     `/hNMMMMMMMMMMy-                         \n\
                      .oNMMMMMMMMMNh:`                        .dMMMMMMMMMMMMMMMm+`   /NMMMMMMMMMMMMMMMm:       .+dMMMMMMMMMMd/`                       \n\
                     -yNMMMMMMMMMd+`                         -hMMMMMMMMMMMMMMMNo`    /NMMMMMMMMMMMMMMMm:         .sNMMMMMMMMMN+`                      \n\
                    -dMMMMMMMMMNy.                          -hMMMMMMMMMMMMMMMMs.     /NMMMMMMMMMMMMMMMm:          `/dMMMMMMMMMNs.                     \n\
                   :hMMMMMMMMMm+`                          .dMMMMMMMMMMMMMMMMh.      /NMMMMMMMMMMMMMMMm:            .yNMMMMMMMMNy`                    \n\
                  -hMMMMMMMMMm/                           .yMMMMMMMMMMMMMMMMd:       /NMMMMMMMMMMMMMMMm:             `sNMMMMMMMMMs.                   \n\
                 .hMMMMMMMMMm:                           .hMMMMMMMMMMMMMMMMm/`       /NMMMMMMMMMMMMMMMm:              `+MMMMMMMMMNo`                  \n\
                .sMMMMMMMMMd:                           `hMMMMMMMMMMMMMMMMN/`        /NMMMMMMMMMMMMMMMm:                oNMMMMMMMMm+                  \n\
               `+NMMMMMMMMN:                           .yMMMMMMMMMMMMMMMMNs`         /NMMMMMMMMMMMMMMMm:                `sNMMMMMMMMm-                 \n\
               :dMMMMMMMMN+                           .yNMMMMMMMMMMMMMMMNs.          /NMMMMMMMMMMMMMMMm:                 .yMMMMMMMMMs.                \n\
              `yNMMMMMMMMy.                          `yNMMMMMMMMMMMMMMMMh-           /NMMMMMMMMMMMMMMMm:                  -mMMMMMMMMm/`               \n\
              -mMMMMMMMMm:                          `sMMMMMMMMMMMMMMMMMm-            /NMMMMMMMMMMMMMMMm:                   oMMMMMMMMMy.               \n\
             `oMMMMMMMMMo`                         `sNMMMMMMMMMMMMMMMMm/             /NMMMMMMMMMMMMMMMm:                   .hMMMMMMMMm/               \n\
             -hMMMMMMMMN-                         `sNMMMMMMMMMMMMMMMMm+`             :mMMMMMMMMMMMMMMMm:                   `oNMMMMMMMMs`              \n\
             /mMMMMMMMMh`                        `oNMMMMMMMMMMMMMMMMMo`               -yNMMMMMMMMMMMMMm:                    :mMMMMMMMMd.              \n\
            `oNMMMMMMMMo                        `oNMMMMMMMMMMMMMMMMNy`                  .omMMMMMMMMMMMm:                    .hMMMMMMMMN-              \n\
            `yMMMMMMMMN/                       `oNMMMMMMMMMMMMMMMMMh-                -/`  .omMMMMMMMMMm:                    `sMMMMMMMMM:              \n\
            `hMMMMMMMMm:                      `+NMMMMMMMMMMMMMMMMMd:                 /md+`  .omMMMMMMMm:                    `+MMMMMMMMM/              \n\
            `hMMMMMMMMd:                     `+NMMMMMMMMMMMMMMMMMN:                  /NMMm+.  .+dMMMMMm:                     /MMMMMMMMM/              \n\
            `hMMMMMMMMd:                    `+mMMMMMMMMMMMMMMMMMN+                   /NMMMMms.  .+hNMMm:                     /MMMMMMMMM/              \n\
            `yMMMMMMMMm:                   `/NMMMMMMMMMMMMMMMMMMmyssssssssssssssssssshNMMMMMMms-  `/hNm:                    `+MMMMMMMMM/              \n\
            `sNMMMMMMMN/                  `+mMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNs-` `:s-                    `sMMMMMMMMM:              \n\
            `+NMMMMMMMMo                  /mMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMmy-` `                     .hMMMMMMMMm-              \n\
             :mMMMMMMMMh`               `/mMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNy:`                     :mMMMMMMMMh.              \n\
             .hMMMMMMMMN:              `/mMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNy/`                  `sNMMMMMMMNs               \n\
             `+MMMMMMMMMs`             /dMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNh-                 -dMMMMMMMMm:               \n\
              -mMMMMMMMMm/            :mMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNh+.                `sMMMMMMMMNy.               \n\
              `sNMMMMMMMMh.          :dMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNds-`                  :NMMMMMMMMm:                \n\
               -hMMMMMMMMNs`        :dMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMmy/.``                  -hMMMMMMMMMo`                \n\
               `/mMMMMMMMMN+`      -dMMMMMMMMMMMMMMMMMMMNyyyyyyyyyyyyyyyyyyyyyyyyyyyhNMMMMMMMMNdo-` ./s-                .yMMMMMMMMMd.                 \n\
                `oNMMMMMMMMm+`    -dMMMMMMMMMMMMMMMMMMMN+```````````````````````````-dMMMMMMms:. `-sdNd-               `yNMMMMMMMMm/                  \n\
                 `yNMMMMMMMMm/   -hMMMMMMMMMMMMMMMMMMMNo`                           .dMMMNh+-` `:smMMMd-              .sMMMMMMMMMm+`                  \n\
                  .yNMMMMMMMm/  .dMMMMMMMMMMMMMMMMMMMMo`                            .dMds:`  ./hNMMMMMd-             -yNMMMMMMMMN+`                   \n\
                   -yMMMMMMm/` -hMMMMMMMMMMMMMMMMMMMMy`                             .o+.` `-odNMMMMMMMd-           `:dMMMMMMMMMNo`                    \n\
                    .yNMMMm:  .hMMMMMMMMMMMMMMMMMMMMh-                               `  `-smNMMMMMMMMMd-          .+mMMMMMMMMMm+`                     \n\
                     .sNMm/  .hMMMMMMMMMMMMMMMMMMMMh-                                 `/yNMMMMMMMMMMMMd-        `-hNMMMMMMMMMm/`                      \n\
                      `/h:` .yMMMMMMMMMMMMMMMMMMMMm:                                 -ohhhhhhhhhhhhhhhs.       -smMMMMMMMMMNh:                        \n\
                        `  .yNMMMMMMMMMMMMMMMMMMMm/                                  ``````````````````     `.+mMMMMMMMMMMNo.                         \n\
                          `hMMMMMMMMMMMMMMMMMMMMm+`                                                       `-smMMMMMMMMMMNh/                           \n\
                         .sMMMMMMMMMMMMMMMMMMMMN+`                                                      `/ymMMMMMMMMMMMm+.                            \n\
                        .sNMMMMMMMMMMMMMMMMMMMNs`                                                    `-ohNMMMMMMMMMMMms-                              \n\
                       `yNMMMMMMMMMMMMMMMMMMMNy. ``                                              `.:ohNMMMMMMMMMMMMms-                                \n\
                      .sNMMMMMMMMMMMMMMMMMMMMy- `+hs/-``                                     `.-+ydNMMMMMMMMMMMMNmo-`                                 \n\
                     `sNMMMMMMMMMMMMMMMMMMMMd-  +mMMNNdyo:-.``                         ``.-/ohmNMMMMMMMMMMMMMMNh+.                                    \n\
                    `sNMMMMMMMMMMMMMMMMMMMMd: `/NMMMMMMMMMNmhys+/:--..````````...--:/oshdmNMMMMMMMMMMMMMMMMNdo:`                                      \n\
                   `oNMMMMMMMMMMMMMMMMMMMMm/``/mMMMMMMMMMMMMMMMMNNNNmmddddddddmmmNNNMMMMMMMMMMMMMMMMMMMMNds:`                                         \n\
                  `oNMMMMMMMMMMMMMMMMMMMMN+` .yNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNmh+:`                                            \n\
                 `oNMMMMMMMMMMMMMMMMMMMMNo`   `./shmNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNdy+:.                                                \n\
                `+NMMMMMMMMMMMMMMMMMMMMNs`        `.-/shdmNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNmdyo/.``                                                   \n\
               `+mMMMMMMMMMMMMMMMMMMMMMy.               `.-/+oyhdmNNNNMMMMMMMMNNNNNmdhyo+:-``                                                         \n\
               .+ssssyyyyyyyyhhhhhhhhhy.                          ``..--------...``                                                                   \n\n\n\n\n\n\n\n\n\n\n ");
printf("|\tVoce foi escolhido para ajudar os vingadores na luta contra thanos!\t|\n |\tVocê pode escolher para batalhar contra thanos ou simular a batalha.\t|\n |\t(para não estragar o jogo, tente antes lutar contra thanos sem a sim-\t|\n|\tulação!!)\t");
printf("|\tEscolha se você quer 1-Batalhar ou 2-Simular\t|\n");
scanf("%d",&selecao);
printf("|\tVocê escolheu Batalhar contra thanos.\n");
printf("|\tPara lutar contra thanos, a cada turno voce deve escolher os herois que atacarão.\n");
printf("|\tA luta acabará quando o poder de thanos for igual ou menor a 10.\n|\tToda vez que a soma dos poderes dos herois\n escolhidos for menor que o poder de thanos, thanos ficará mais forte! Mas se a soma dos poderes for maior que o poder de thanos mais 25 por cento universo acabará \n");
if (selecao == 2){
ordenarpoder(herois);
selecaoParaAtaque(herois);
}
if (selecao == 1){
    while(thanos.poder > 10){
        somapoder=0;
        printf("Herois disponiveis\n");
        imprime(&thanos, herois);
        heroes ** locao = selecaoParaAtaque(herois);

        for(i=0;i<11;i++){
            if(locao[i] != NULL){
                somapoder += locao[i]->poder ;
                printf("%s\n", locao[i]->heroi);

            }

        }

        printf("%d",somapoder);

        if (somapoder > (thanos.poder*1.25)){
            printf("Você destruiu o universo. parabens.\n");
            break;
        }else if (somapoder<thanos.poder){
                thanos.poder = thanos.poder * 1.5;
                for(i=0;i<11;i++){
                    if(locao[i]!=NULL){
                        locao[i]->poder = locao[i]->poder * 0.5;                   }

                }

        }else if (somapoder>thanos.poder && somapoder < (thanos.poder*1.25)){
                thanos.poder = thanos.poder * 0.5;
                for(i=0;i<11;i++){
                    if(locao[i] !=NULL){
                        locao[i]->poder = locao[i]->poder * 0.5;}
                    }
                    }else if(locao[i] = NULL){
                        break;
                    }




    }
}

if (thanos.poder <= 10){
    printf("OS VINGADORES SALVARAM O MUNDO NOVAMENTE!!\n");


}









return 0;
}
