#include "tri.h"
#include <time.h>
#define TAILLE_MAX 100
void Tri_Casier(int *table, int taille,int element_min,int element_max){
    if(element_max-element_min+1>100){
        printf("Erreur difference entre les elements trop grande");
        return;
    }
    int taille2=element_max-element_min+1;
    int trietable[TAILLE_MAX]={0};
    int d;
    for(int i=0;i<taille;i++){
        d=table[i];
        trietable[d-element_min]=trietable[d-element_min]+1;
    }
    int index=0;
    for(int i=0;i<taille2;i++){
        while(trietable[i]>0){
            table[index]=i+element_min;
            index++;
            trietable[i]=trietable[i]-1;
        }
    }
}

void Tri_Rapide(int* table,int indice_min, int indice_max){
    if(indice_max-indice_min<=0){
        return;
    }
    int c;
    int pivot=indice_min;
    int indice_milieu=indice_min;
    for(int i=indice_min+1;i<=indice_max;i++){
        if (table[pivot] > table[i]) {
            indice_milieu++;
            c=table[i];
            table[i]=table[indice_milieu];
            table[indice_milieu]=c;
        }
    }
    c=table[pivot];
    table[pivot]=table[indice_milieu];
    table[indice_milieu]=c;
    Tri_Rapide(table, indice_min,indice_milieu-1);
    Tri_Rapide(table, indice_milieu+1, indice_max);
}

void Tri_Base(int *table, int taille){
    int d=4354;
    for (int i=1;d/i>0;i=i*10){
        Tri_Rapide(table,0,9);
    }
}
/*
void Tri_Casier2(int *table, int taille){
    int trietable[10]={0};
    int d;
    for(int i=0;i<taille;i++){
        d=table[i];
        trietable[d-element_min]=trietable[d-element_min]+1;
    }
    int index=0;
    for(int i=0;i<taille2;i++){
        while(trietable[i]>0){
            table[index]=i+element_min;
            index++;
            trietable[i]=trietable[i]-1;
        }
    }
}*/