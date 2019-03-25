#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ERRO_ALOCACAO printf("não foi possivel alocar a memoria!\n");
typedef struct{
	int operando;
	char operador;
	float resultado;
	struct Pilha *prox;
}Pilha;
int contaoperando=0;
int contaoperador =0;
int topo=0;
char n1='0';
char n2='0';
char n3='0';
char formula[30];
float re;
float ra;
float p=0;
int vazia(Pilha *pilha){
    if(pilha->prox == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
	}
}
void inicializar (Pilha *pilha){
    pilha->prox = NULL;
    topo = 0;
}
Pilha* conversao(int opcao){
	if(opcao == 48)
	opcao=0;
	if(opcao == 49)
	opcao=1;
	if(opcao == 50)
	opcao=2;
	if(opcao == 51)
	opcao=3;
	if(opcao == 52)
	opcao=4;
	if(opcao == 53)
	opcao=5;
	if(opcao == 54)
	opcao=6;
	if(opcao == 55)
	opcao=7;
	if(opcao == 56)
	opcao=8;
	if(opcao == 57)
	opcao=9;
	return opcao;
}
Pilha *desempilhar (Pilha *pilha){
    if (pilha->prox == NULL){
        printf("Nao ha elementos para desempilhar\n\n");
        return NULL;
    }
    else{
        Pilha *ultimo = pilha->prox,
        *penultimo = pilha->operando;

        while (ultimo->prox != NULL){
            penultimo = ultimo;
            ultimo = ultimo->prox;
        }
        penultimo->prox = NULL;
        topo--;
        return ultimo;
    }
}
Pilha *alocaOperando(Pilha *novo,int opcao){
   novo=(Pilha*) malloc(sizeof(Pilha));
    if(!novo){
        ERRO_ALOCACAO
        exit(1);
    }
    else{
    	novo->operando= conversao(opcao);
        return novo;
    }
}
Pilha *alocaOperador(char opcao){
    Pilha *novo=(Pilha*) malloc(sizeof(Pilha));
    if(!novo){
        ERRO_ALOCACAO
        exit(1);
    }
    else{
    	novo->operador=opcao;
        return novo;
    }
}
 void empilhaOperador(Pilha *pilha, char opcao){
    Pilha *novo=alocaOperador(opcao);
    novo->prox = NULL;
    if(vazia(pilha)){
        pilha->prox=novo;
    }
    else{
        Pilha *tmp = pilha->prox;
        while (tmp->prox != NULL)
            tmp = tmp->prox;
            tmp->prox = novo;
    }
    topo++;
    contaoperador++;
}

void empilhaOperando(Pilha *pilha, int opcao){
    Pilha *novo=alocaOperando(pilha,opcao);
    novo->prox = NULL;
    if(vazia(pilha)){
        pilha->prox=novo;
    }
    else{
        Pilha *tmp = pilha->prox;
        while (tmp->prox != NULL)
            tmp = tmp->prox;
            tmp->prox = novo;
    }
    topo++;
    contaoperando++;
    if(contaoperador >=1){
    	contaoperando =2;
	}
}
Pilha* imprimisoma(Pilha *pilha){
	int u=0;
	float x,y;
	if(contaoperador == 1){
    	Pilha* tmp;
     	tmp = pilha->prox;
    	desempilhar(pilha);
    	while (tmp != NULL){
    		if(u==0)
       			x=tmp->operando;
        	if(u==1)
        		y=tmp->operando;
        	tmp = tmp->prox;
        	u++;
    	}
    	re=x+y;
    	pilha->operando=re;
    	printf("Resultado 1 = %.2f\n",re);
	}
	if(contaoperador == 2){
    	Pilha* tmp;
    	tmp = pilha->prox;
    	desempilhar(pilha);
    	u=0;
    	while (tmp != NULL){
    		if(u==3){
        		x=tmp->operando;
    		}
        	if(u==4){
        		y=tmp->operando;
			}
        	tmp = tmp->prox;
			u++;
    	}
    	ra=x+y;
    	pilha->operando=ra;
    	printf("\nResultado 2 = %.2f",ra);
	}
}
Pilha* imprimisub(Pilha *pilha){
	int u=0;
	float x,y;
	if(contaoperador == 1){
    	Pilha* tmp;
     	tmp = pilha->prox;
    	desempilhar(pilha);
    	while (tmp != NULL){
    		if(u==0){
        		x=tmp->operando;
        	}
        	if(u==1){
        		y=tmp->operando;
			}
        	tmp = tmp->prox;
        	u++;
    	}
    	re=x-y;
    	pilha->operando=re;
    	printf("Resultado 1 = %.2f\n",re);
	}
	if(contaoperador == 2){
    	Pilha* tmp;
    	tmp = pilha->prox;
    	desempilhar(pilha);
    	u=0;
    	while (tmp != NULL){
    		if(u==3){
        		x=tmp->operando;
    		}
        	if(u==4){
        		y=tmp->operando;
			}
        	tmp = tmp->prox;
			u++;
    	}
    	ra=x-y;
    	pilha->operando=ra;
    	printf("\nResultado 2 = %.2f",ra);
	}
}
Pilha* imprimimult(Pilha *pilha){
	int u=0;
	float x,y;
	if(contaoperador == 1){
    	Pilha* tmp;
     	tmp = pilha->prox;
    	desempilhar(pilha);
    	while (tmp != NULL){
    		if(u==0){
        		x=tmp->operando;
        	}
        	if(u==1){
        		y=tmp->operando;
        	}
        	tmp = tmp->prox;
        	u++;
    	}
    	re=x*y;
    	pilha->operando=re;
    	printf("Resultado 1 = %.2f\n",re);
	}
	if(contaoperador == 2){
    	Pilha* tmp;
    	tmp = pilha->prox;
    	desempilhar(pilha);
    	u=0;
    	while (tmp != NULL){
    		if(u==3){
        		x=tmp->operando;
    		}
        	if(u==4){
        		y=tmp->operando;
			}
        	tmp = tmp->prox;
			u++;
    	}
    	ra=x*y;
    	pilha->operando=ra;
    	printf("\nResultado 2 = %.2f",ra);
	}
}
Pilha* imprimidiv(Pilha *pilha){
	int u=0;
	float x,y;
	if(contaoperador == 1){
    	Pilha* tmp;
     	tmp = pilha->prox;
    	desempilhar(pilha);
    	while (tmp != NULL){
    		if(u==0){
        		x=tmp->operando;
    		}
        	if(u==1){
        	y=tmp->operando;
        	if(tmp->operando==0){
        		printf("\ndeu ruim.... nao pode dividir por 0\n");
            	exit(1);
        	}
        	}
        	tmp = tmp->prox;
        	u++;
    	}
    	re=x/y;
    	pilha->operando=re;
    	printf("Resultado 1 = %.2f\n",re);
	}
	if(contaoperador == 2){
    	Pilha* tmp;
    	tmp = pilha->prox;
    	desempilhar(pilha);
    	u=0;
    	while (tmp != NULL){
    		if(u==3){
       			x=tmp->operando;
    		}
        	if(u==4){
        		y=tmp->operando;
        		if(tmp->operando==0){
                	printf("\ndeu ruim.... nao pode dividir por 0\n");
            		exit(1);
        		}
			}
        	tmp = tmp->prox;
			u++;
    	}
    	ra=x/y;
    	pilha->operando=ra;
    	printf("\nResultado 2 = %.2f",ra);
	}
}
Pilha *soma(){
    p=re+ra;
    printf("\n\nResultado Final:  %.2f\n",p);
}
Pilha *sub(){
    p=re-ra;
    printf("\n\nResultado Final:  %.2f\n",p);
}
Pilha *mult(){
	p=re*ra;
    printf("\n\nResultado Final:  %.2f\n",p);
}
Pilha *divi(){
	if(re==0){
        printf("\ndeu ruim.... nao pode dividir por 0\n");
        exit(1);
    }
    p=re/ra;
    printf("\n\nResultado Final:  %.4f\n",p);
}
int main(){
	Pilha* mat = (Pilha*) malloc(sizeof(Pilha));
    int i,s,x;
    char y,a;
    int b,q;
	printf("digite a formula matematica:");
	scanf("%s",&formula);
	printf("\n");
	x=strlen(formula);	
	inicializar(mat);
	for(i=0;i<x;i++){
	    if(formula[i] == '*' || formula[i] =='/' || formula[i] == '+' || formula[i] == '-' && contaoperando>=2){
                empilhaOperador(mat,formula[i]);
                if(formula[i] == '+' && contaoperando >=1 && contaoperador >=1){
                    imprimisoma(mat);
                    if(contaoperador ==3)
                        soma();
                }
                if(formula[i] == '-' && contaoperando >=1 && contaoperador >=1){
                    imprimisub(mat);
                    if(contaoperador ==3)
                        sub();
                }
                if(formula[i] == '*' || formula[i] == 'x' || formula[i] == 'X' && contaoperando >=1 && contaoperador >=1){
                    imprimimult(mat);
                    if(contaoperador ==3)
                        mult();
                }
                if(formula[i] == '/' && contaoperando >=1 && contaoperador >=1){
                    imprimidiv(mat);
                    if(contaoperador ==3)
                        divi();
                }
                }
		b= conversao(formula[i]);
		empilhaOperando(mat,b);
		}
	free(mat);
	return 0;
}
