//
//  main.c
//  rsa
//
//  Created by Jesus Arenas Martinez on 10/30/19.
//  Copyright © 2019 Jesus Arenas Martinez. All rights reserved.
//

#include <stdio.h>
#include<time.h>
#include<stdlib.h>
char letras[]={'A'};
int n=0;
int e;
int O0=0;
int d=0;
int calc_n(int p,int q);
int calc_0(int p,int q);
int calc_e(int O0);
int calc_d_inv(int e, int O0);
int main(int argc, const char * argv[]) {
    int p=0;
    int q=0;
    printf("Ingrese P\n");
    scanf("%i",&p);
    printf("Ingrese Q\n");
    scanf("%i",&q);
    calc_n(p,q);
    calc_0(p-1, q-1);
    calc_e(O0);
    calc_d_inv( 3,  O0);
    printf("%d",d);
    return 0;
}


int calc_n(int p,int q){
    n=p*q;
    return n;
}
int calc_0(int p,int q){
    O0=p*q;
    return O0;
}
int calc_e(int O0){
    int num = 0;
    int rango=O0+1;
    int n1,n2;
    int conta=2;
    srand(time(NULL));
    num = 2+rand()%(rango-2);
    for(conta=2;conta<num;conta++){
        if(num%conta==0){
           //printf("\nnumero no es primo %d ",num);
        num = 2+rand()%(rango-2);
        conta=2;
        
        }


    }

   // printf("%d", num);
    
    return e;
}

int calc_d_inv(int e, int O0){
int *g =malloc(2 * sizeof *g);
    int *u =malloc(2 * sizeof *u);
    int *v =malloc(2 * sizeof *v);
    int *y =malloc(2 * sizeof *y);
    float t;
    g[0]=O0;
    g[1]=e;
    u[0]=1;
    u[1]=0;
    v[0]=0;
    v[1]=1;
    y[0]=0;
    y[1]=0;
    int i=1;
    int cont=0;
    
    while(g[i]!=0){
    cont=i+2;
    y=realloc(y,cont*sizeof(int));
    g=realloc(g,cont*sizeof(int));
    u=realloc(u,cont*sizeof(int));
    v=realloc(v,cont*sizeof(int));
    y[i+1]=g[i-1] / g[i];
    g[i+1]=g[i-1]-(y[i+1]*g[i]);
    u[i+1]=u[i-1]-(y[i+1]*u[i]);
    v[i+1]=v[i-1]-(y[i+1]*v[i]);
    i++;
    }

    int x=0;
    if(v[i-1]<0){
        v[i-1]=v[i-1]+O0;
    }
    x=v[i-1];
    d=x;
    return d;
}