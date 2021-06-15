//Nome completo:Luisa Tolentino Ribeiro Gomes 
//Matrícula:UC20102823 
//Curso:Engenharia de Software
#include<stdio.h>
#include<locale.h> 
#include"conio.h" 
#include<string.h>
#include<stdlib.h>
struct passageiros{
	char nome[50];
	int idade;
	int reg;
	int assento;
};
int menu();
int diluc(int,char[]);
int contador(struct passageiros []);
int verificador(struct passageiros [], int);
int main(){
	char destino[50],pause;
	float passagem,passagemR, total;
	int assentos,i,aux,aux2, u=10000, reg, cont=0;
	setlocale(LC_ALL, "Portuguese");
	
	printf("Boas Vindas a SALUMAR LINHAS AEREAS!\n\n");
	do{
		printf("\nInforme o nome do destino que deseja:\n");
		gets(destino);
		if(strlen(destino)<=0){
		printf("\nDestino Inválido!\nTente novamente.\n");
		}
	}while(strlen(destino)<=0);	
	printf("Informe o valor da passagem:\n");
	scanf("%f",&passagem);
	do{	
		printf("Informe a capacidade do avião(quantidade de assentos):\n");
		scanf("%d",&assentos);
		if (assentos<=90 || assentos>=200){
		printf("\nCapacidade inválida!\nTente novamente.\n");
		}
	}while(assentos<=90 || assentos>=200);
	
	struct passageiros compras[assentos];
	char aviao[assentos];
	for (i=1;i<=assentos;i++){
		aviao[i]='D';
	}
	
	do{
		system("cls");
		textcolor(15);
		aux=menu();
		i = contador(compras);
		if(i != -1){
			switch(aux){
				case 1:	//Comprar na hora do embarque
					printf("Informe seu nome:\n");
					fflush(stdin);
					gets(compras[cont].nome);	
					if(strlen(compras[cont].nome)<=0){
					printf("\nNome Inválido!\nTente novamente.\nPressione qualquer tecla para voltar ao menu.");
					pause = getche();
					}else{
						printf("Informe a idade do interessado:\n");
						scanf("%d",&compras[cont].idade);		
						if(compras[cont].idade<=5){
							passagemR=(passagem/2);
							printf("O valor da passagem sofreu um reajuste devido a idade do passageiro.\n");
							printf("O novo valor: R$ %.2f",passagemR);
						}
						aux2=diluc(assentos,aviao);	
						if (aux2<assentos&&aux2>0&&aviao[aux2]!='C'&&aviao[aux2]!='R'){
							aviao[aux2]='C';
							compras[cont].assento = aux2;
							if(compras[cont].idade<=5) total += passagemR;
							else total += passagem;
							compras[cont].assento = aux2;
							printf("Compra realizada com sucesso, obrigado pela preferência!\nProssiga para a área de embarque.\nSeu assento é o n°%d", aux2);
							cont = contador(compras);
							compras[cont].reg = u;
							printf("\nAnote o número do seu registro de reserva:%d", u);
							u++;
							pause = getche();
						}
						else{
							printf("Por favor, selecione um assento válido!\nPressione qualquer tecla para selecionar novamente.");
							pause = getche();
						}
					}
					break;
				case 2: //Reservar
					printf("Informe seu nome:\n");
					fflush(stdin);
					gets(compras[cont].nome);
					if(strlen(compras[cont].nome)<=0){
					printf("\nNome Inválido!\nTente novamente.\n");
					pause = getche();
					}else{
						printf("Informe a idade do interessado:\n");
						scanf("%d",&compras[cont].idade);		
						if(compras[cont].idade<=5){
							passagemR=(passagem/2);
							printf("O valor da passagem sofreu um reajuste devido a idade do passageiro.\n");
							printf("O novo valor: R$ %.2f.\n",passagemR);
						}
						printf("Selecione o assento que deseja reservar:");
						aux2=diluc(assentos,aviao);
						if (aux2<assentos&&aux2>0&&aviao[aux2]!='C'&&aviao[aux2]!='R'){
							aviao[aux2]='R';
							printf("Reserva realizada com sucesso!");
							if(compras[cont].idade<=5) total += passagemR;
							else total += passagem;
							compras[cont].assento = aux2;
							cont = contador(compras);
							compras[cont].reg = u;
							printf("Anote o número do seu registro de reserva:%d", u);
							u++;
							pause = getche();
						}else{
							printf("Selecione um assento disponível./Pressione qualquer tecla para tentar novamente.");
							pause = getche();
						}
					}
					break;	
				case 3:
					printf("Digite seu número de registro de reserva:");
					scanf("%d", &reg);
					if(verificador(compras, reg) != -1){
						aviao[compras[cont].assento] = 'C';
						printf("Reserva confirmada!\nObrigado pela preferência e boa viagem.\nSeu assento é o n°%d", aux2);
					}else printf("Registro inexistente.");
					pause = getche();
					break;
				case 4:
					printf("Digite seu número de registro de reserva:");
					scanf("%d", &reg);
					if(verificador(compras, reg) != -1){
						aviao[aux2] = 'D';
						printf("Reserva cancelada!");
						compras[i].reg = 0;
					}else printf("Registro inexistente.");
					pause = getche();
					break;
			}
		}else{
			printf("Compras esgotadas, espere o próximo vôo.");
			aux = 0;	
		}
	}while(aux!=0);
	
	
return 0;
}

int menu(){
	int exit;
	printf("|1|Comprar Passagem\n");
	printf("|2|Reservar Assento\n");
	printf("|3|Confirmar Reserva\n");
	printf("|4|Cancelar Reserva\n");
	printf("|0|Sair\n");
	printf("Digite a opção:\n");
	scanf("%d",&exit);
	
	return exit;	
}
int diluc(int assentos,char aviao[]){
	int i,assentoR;	
	system("cls");
	printf("ASSENTOS:\n");
	if((assentos%2)==0){
		for(i=1;i<=assentos/4;i++){
			if(aviao[i]=='D'&&i<=assentos/4){
				textcolor(2);
				printf("%.2d(D) ",i);	
			}
			if (aviao[i]=='R'&&i<=assentos/4){
				textcolor(4);
				printf("%.2d(R) ",i);
			}
			if (aviao[i]=='C'&&i<=assentos/4){
				textcolor(1);
				printf("%.2d(C) ",i);
			} 
		}
		printf("\n");
		for(i;i<=assentos/2;i++){
			if(aviao[i]=='D'&&i>assentos/4&&i<=assentos/2){
				textcolor(2);
				printf("%d(D) ",i);	
			}
			if (aviao[i]=='R'&&i>assentos/4&&i<=assentos/2){
				textcolor(4);
				printf("%d(R) ",i);
			}
			if (aviao[i]=='C'&&i>assentos/4&&i<=assentos/2){
				textcolor(1);
				printf("%d(C) ",i);
			}
		}
		printf("\n\n");
		for(i;i<=(assentos*3)/4;i++){
			if(aviao[i]=='D'&&i>assentos/2&&i<=(assentos*3)/4){
				textcolor(2);
				printf("%d(D) ",i);	
			}
			if (aviao[i]=='R'&&i>assentos/2&&i<=(assentos*3)/4){
				textcolor(4);
				printf("%d(R) ",i);
			}
			if (aviao[i]=='C'&&i>assentos/2&&i<=(assentos*3)/4){
				textcolor(1);
				printf("%d(C) ",i);
			}			
		}
		printf("\n");
		for(i;i<=assentos;i++){
			if(aviao[i]=='D'&&i>(assentos*3)/4&&i<=assentos){
				textcolor(2);
				printf("%d(D) ",i);	
			}
			if (aviao[i]=='R'&&i>(assentos*3)/4&&i<=assentos){
				textcolor(4);
				printf("%d(R) ",i);
			}
			if (aviao[i]=='C'&&i>(assentos*3)/4&&i<=assentos){
				textcolor(1);
				printf("%d(C) ",i);
			}
		}
	}
	printf("\nInforme o assento desejado:");
	scanf("%d",&assentoR);
	return assentoR;	
}
int contador(struct passageiros compras[]){
	int cont=0;
	do{
		if(compras[cont].reg!= 0)
			cont++;
	}while(compras[cont].reg!=0);
	if(compras[cont].reg== 0) return cont;
	else return -1;
}

int verificador(struct passageiros compras[], int reg){
	int cont=0;
	do{
		if(compras[cont].reg == reg){
			cont++;
		}else
			return 0;
	}while(compras[cont].reg == reg);
	return -1;
}
