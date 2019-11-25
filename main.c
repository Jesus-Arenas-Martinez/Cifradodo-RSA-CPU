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
#include<math.h>
char letras[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',' ',',','.',';','1','2','3','4','5','6','7','8','9','0','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
double n=0;
int e=0;
int O0=0;
int d=0;
int P1;
double calc_n(int p,int q);
int calc_0(int p,int q);
int calc_e(int O0);
int calc_d_inv(int e, int O0);
int cifrar(int e,double n);
int generar_Primo();
int main(int argc, const char * argv[]) {
    printf("%d",P1);
    int p=0;
    int q=0;
   /* printf("Ingrese P\n");
    scanf("%i",&p);
    printf("Ingrese Q\n");
    scanf("%i",&q);*/
    p=generar_Primo();
    P1=p;
    q=generar_Primo();
    calc_n(p,q);
    calc_0(p-1, q-1);
    calc_e(O0);
    calc_d_inv( e,  O0);
  
    cifrar(e,n);
    return 0;
}


double calc_n(int p,int q){
    n=p*q;
    printf("---N=%d*%d=%f",p,q,n);
    return n;
}
int calc_0(int p,int q){
    O0=p*q;
    return O0;
}
int generar_Primo(){
     int num =0;
     srand(time(NULL));
     num = 1+rand()%1000;
    int conta=1;
     for(conta=1;conta<num;conta++){
        
        if(num%conta==0){

        num = 1+rand()%1000;
        conta=1;
        
        }
        if(P1==num){
            num = 1+rand()%1000;
        conta=1;
        }


    }

     return num;
}
int calc_e(int O0){
    int num = 0;
    int rango=O0+1;
    int n1,n2;
    int conta=2;
    srand(time(NULL));
    num = 2+rand()%(150-2);
    for(conta=2;conta<num;conta++){
      
        if(num%conta==0){
           //printf("\nnumero no es primo %d ",num);
        num = 2+rand()%(150-2);
        conta=2;
        
        }


    }

   // printf("%d", num);
    e=num;
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
int cifrar(int e,double n ){
FILE *archivo;
int *valores;

double *valores_Cifrados;
char letra;
double cifra;
archivo =fopen("texto_plano.txt","r");
int contador=0;
int cont=0;

while((letra=fgetc(archivo))!= EOF){
    cont=contador+2;
    valores=realloc(valores,cont*sizeof(int));
    
   valores_Cifrados=realloc(valores_Cifrados,cont*sizeof(double));
    for(int i=0;i<sizeof(letras);i++){
        if(letra==letras[i]){
            valores[contador]=i;
        }
    }
    
    //valores_Cifrados[contador]=(pow(valores[contador] ,e)%n);
    cifra=pow(valores[contador] ,e);
    cifra=fmod(cifra,n);
    valores_Cifrados[contador]=cifra;
    printf("\n%d %d mod %f =%f",valores[contador],e,n,valores_Cifrados[contador]);
    contador++;

}
return 0;
}