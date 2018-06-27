#include<stdio.h>
#include<string.h>
#include"library.h"
main(){
	//DISCIPLINAS CONSTANTES
	//0
	disciplinas[0].codigo = 122;
	strcpy(disciplinas[0].nome, "Algoritmos");
	strcpy(disciplinas[0].professor, "Jonas");
	disciplinas[0].carga = 60;
	disciplinas[0].horario[0][0] = 1; 
	disciplinas[0].horario[3][1] = 1;
	
	//1
	disciplinas[1].codigo = 127;
	strcpy(disciplinas[1].nome, "Estrutura de dados");
	strcpy(disciplinas[1].professor, "Jonas");
	disciplinas[1].carga = 60;
	disciplinas[1].horario[2][1] = 1; 
	disciplinas[1].horario[1][1] = 1;
	
	//2
	disciplinas[2].codigo = 132;
	strcpy(disciplinas[2].nome, "Sistemas Operacionais A");
	strcpy(disciplinas[2].professor, "Rafael");
	disciplinas[2].carga = 60;
	disciplinas[2].horario[2][1] = 1; 
	disciplinas[2].horario[1][3] = 1;
	
	//3
	disciplinas[3].codigo = 143;
	strcpy(disciplinas[3].nome, "Padroes de Projeto");
	strcpy(disciplinas[3].professor, "Daniel");
	disciplinas[3].carga = 30;
	disciplinas[3].horario[1][4] = 1; 
	
	//4
	disciplinas[4].codigo = 135;
	strcpy(disciplinas[4].nome, "Banco de dados II");
	strcpy(disciplinas[4].professor, "Daniel");
	disciplinas[4].carga = 60;
	disciplinas[4].horario[1][2] = 1; 
	disciplinas[4].horario[1][4] = 1;
	
	while(1){
		printf("\tGerenciador de Alunos v1.0\n\n1.Inserir Aluno\n\n2.Consultar Aluno\n\n3.Consultar Disciplinas\n\n4.Sair\n\n");
		scanf("%d",&opt);
		system("cls");
		switch(opt){
			case 1:{
				inserir_aluno();
				break;
			}
			case 2:{
				consultar_aluno();
				break;
			}
			case 3:{
				consultar_disciplina();
				break;
			}
			case 4:{
				
				break;
			}
			default:{
				printf ("Valor invalido!\n");
				opt = 0;
				system("pause");
				break;
			}
				
			
		}
	}
}
