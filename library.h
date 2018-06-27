//DECLARAÇÃO DE VARIAVEIS
#define TAM 10
int opt = 0, m=0, email_valido = 0, matricula_valida = 0;

//ESTRUTURA DOS ALUNOS
struct x{
	char nome[50], sobrenome[20], email[50];
	int matricula, disciplinas[5], grade[4][5];
};
typedef struct x alun;
alun alunos[TAM];

//ESTRUTURA DAS DISCIPLINAS
struct y{
	char nome[50], professor[50];
	int carga, alunos[TAM], horario[4][5];//horario[][] GRADE de horarioS - 0 para vazio e 1 para preenchido
	int codigo;
};
typedef struct y disc;
disc disciplinas[5];

//ASSOCIAR ALUNO A DISCIPLINA
void inserir_aluno(){
	matricula_valida = 0;
	int sair = 1;
	//se O NUMERO DE ALUNOS MATRICULADOS FOR MAIOR QUE tam(10)
	if(m < TAM){
		char x[50];

		printf("\tCadastro de Aluno em Disciplinas\n\nMatricula %d.\n\n", m);
		alunos[m].matricula = m;
		
		printf("Digite o Nome do Aluno: \n\n");
		fflush(stdin);
		gets(alunos[m].nome);
		
		printf("\n\nDigite o Sobrenome do Aluno:\n\n");
		fflush(stdin);
		gets(alunos[m].sobrenome);
		
		while(email_valido == 0){
			printf("\n\nDigite o  E-mail do Aluno:\n\n");
			fflush(stdin);
			gets(alunos[m].email);
			email_valido = valida_email(alunos[m].email);
		}
		while(matricula_valida == 0 && sair == 1){
			printf("\n\n\tQuais disciplinas %s %s vai cursar?\n\n\nDigite o codigo ou o nome:\n", alunos[m].nome, alunos[m].sobrenome);
			fflush(stdin);
			gets(x);
			matricula_valida = valida_matricula(x, m);
			if(matricula_valida == 1){
				printf("\nQuer matricula-lo em mais disciplinas? sim = 1 / nao = 0\n\n");
				scanf("%d", &sair);
				if(sair == 1)matricula_valida = 0;
			}else{
				printf("\n\nImossivel se matricular nessa disciplina ela não existe ou\nnao a espaco na grade do aluno!\n\n");
			}
		}
		m++;
		printf("\n\n");
	}else{
		printf("\n\n voce ja cadastrou o numero maximo de alunos\n\n");
	}
	opt = 0;
	system("pause");
	system("cls");
	
}
//VALIDAR E-MAIL
int valida_email(char x[], int m){
	
	return 1;	
}

//VALIDAR MATRICULA
int valida_matricula(char x[], int m){
	int i, l, c, cont;
	int cod = atoi(x);
	for(i = 0; i<5;i++){
		if ( disciplinas[i].codigo == cod || strcmp( disciplinas[i].nome, x) == 0 ){
			for(l=0;l<4;l++){
				for(c=0;c<5;c++){
					if(disciplinas[i].horario[l][c] == 1){
						if(alunos[m].grade[l][c] == 1){
							return 0;
						}
					}
				}
			}
			for(l=0;l<4;l++){
				for(c=0;c<5;c++){
					if(disciplinas[i].horario[l][c] == 1){
						if(alunos[m].grade[l][c] != 1){
							alunos[m].grade[l][c] = 1;
							//IGUALA A DISCIPLINA[] DO ALUNO - AO CODIGO DA DISCIPLINA
							alunos[m].disciplinas[i] = disciplinas[i].codigo;
							//IGUALA A MATRICULA DO ALUNO - AO VETOR CONTENDO AS MATRICULA DOS ALUNOS MATRICULADOS NESSA DISCIPLINA
							disciplinas[i].alunos[m] = alunos[m].matricula;
							printf("\n\nMatriculado em %s\n\n", disciplinas[i].nome);
						}
					}
				}
			}
			return 1;
		}
	}
	return 0;
}

//CONSULTAR ALUNO POR NOME OU PARTE DO NOME
consultar_aluno(){
	
}

//CONSULTAR DISCIPLINA ATRAVEZ DO CODIGO OU NOME
consultar_disciplina(){
	
}
