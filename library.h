//DECLARAÇÃO DE VARIAVEIS
#define TAM 10
int opt = 0, m=0, matricula_valida = 0;

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
	int carga, horario[4][5];//horario[][] GRADE de horarioS - 0 para vazio e 1 para preenchido
	int alunos[TAM];
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
		alunos[m].matricula = m+1;
		printf("\tCADASTRO DE ALUNO EM DISCIPLINAS\n\nMatricula %d.\n\n",alunos[m].matricula);
		printf("Digite o Nome do Aluno: \n\n");
		fflush(stdin);
		gets(alunos[m].nome);
		
		printf("\n\nDigite o Sobrenome do Aluno:\n\n");
		fflush(stdin);
		gets(alunos[m].sobrenome);
		int	email_valido = 0;
		while(email_valido == 0){
			printf("\n\nDigite o  E-mail do Aluno:\n\n");
			fflush(stdin);
			gets(alunos[m].email);
			email_valido = valida_email(alunos[m].email, m);
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
		printf("\n\nVoce ja cadastrou o numero maximo de alunos!\n\n");
	}
	opt = 0;
	system("pause");
	system("cls");
	
}
//VALIDAR E-MAIL
int valida_email(char x[], int m){
	int len, i=0, a, p;
	//PEGO O TAMANHO DA STRING
	len=strlen(x);
	
	//ENCONTRAR O PONTO E O ARROBA
	for(i=0;i<len;i++){
		if(x[i] == '@'){
			a=i;
		}
		if(x[i] == '.'){
			p=i;
		}
	}
	if(len<3) printf("\nE necessario inserir ao menos 3 caracteres\n");
	if(a==0) printf("\nO e-mail precisa de @\n");
	if(p==0) printf("\nO e-mail precisa de ponto\n");
	if((p+3) > len) printf("\nE necessario 2 caracteres apos o ponto\n");
	if((p-a) < 4) printf("\nE necessario que apos o @ tenha no minimo 3 caracteres\n");
	if(a<3) printf("\nE necessario inserir o @ apos os 3 primeiros caracteres!\n");
	//SE NAO ENCONTRAR O @ OU . PRINTA A MENSAGEM RETORNA 0
	if(a==0 || p==0 || len<3 || (p-a) < 4 || (p+3) > len) return 0;
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
						if(alunos[m].grade[l][c] != 0){
							return 0;
						}
					}
				}
			}
			for(l=0;l<4;l++){
				for(c=0;c<5;c++){
					if(disciplinas[i].horario[l][c] == 1){
						if(alunos[m].grade[l][c] != 1){
							alunos[m].grade[l][c] = disciplinas[i].codigo;
							
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
	char nom[50];
	int i;
	printf("\tCONSULTAR ALUNO\n\n");
	printf("\nDigite o nome ou parte do nome: \n");
	fflush(stdin);
	gets(nom);
	if(strcmp(nom,"") == 0 ){
		printf("\n\nNao foi possivel encontrar esta vazio o campo\n\n");
		opt = 0;
		system("pause");
		system("cls");
		return;
	} 
	for(i=0;i<TAM;i++){
	
		if(strcmp(alunos[i].nome, nom) == 0 || strstr(alunos[i].nome,nom) != NULL){  
			printf("Matricula %d\n", alunos[i].matricula);
			puts(alunos[i].nome);
			puts(alunos[i].sobrenome);
			puts(alunos[i].email);
			mostrar_grade(alunos[i].grade);	
			opt = 0;
			system("pause");
			system("cls");
			return;		  
    	}	
	}
	if(strcmp(alunos[i].nome, nom) != 0) printf("\n\nNão foi possivel encontrar o nome\n\n");	
	
	opt = 0;
	system("pause");
	system("cls");
}

//MOSTRAR GRADE
mostrar_grade(int grade[4][5]){
	int i, j;
	printf("Hora : Segunda Terca Quarta Quinta Sexta \n");
	for(i=0;i<4;i++){
		if(i==0)printf("08:00   ");
		if(i==1)printf("10:00   ");
		if(i==2)printf("13:00   ");
		if(i==3)printf("15:00   ");
			
		for(j=0;j<5;j++){
			if(grade[i][j] == 0) printf  ("   -  ");
			if(grade[i][j] == 122) printf(" Algo ");
			if(grade[i][j] == 127) printf(" Estr ");
			if(grade[i][j] == 132) printf(" SoA  ");
			if(grade[i][j] == 143) printf(" Pdp  ");
			if(grade[i][j] == 135) printf(" Bd2  ");
		}
	printf("\n");
	}
}

//CONSULTAR DISCIPLINA ATRAVEZ DO CODIGO OU NOME
void consultar_disciplina(){
	char nom[50];
	int i, cod, j, e;
	
	printf("\tCONSULTAR DISCIPLINA\n\n");
	printf("Digite o codigo ou nome da disciplina:\n");
	fflush(stdin);
	gets(nom);
	cod = atoi(nom);
	for(i=0;i<5;i++){
		if(disciplinas[i].codigo == cod || strcmp( disciplinas[i].nome, nom) == 0 ){
			e=1;
			printf("\n%s \nAlunos |   Matricula : Nome\n", disciplinas[i].nome);
			for(j=0;j<TAM;j++){
				if(alunos[j].matricula == disciplinas[i].alunos[j]){
					//SE A MATRICULA E 0 NAO E EXIBIDA 
					//OBS: POR PADRAO TODAS AS MATRICULAS SAO 0
					if ((j+1)==0 || disciplinas[i].alunos[j] != 0) printf("           %d           %s\n\n",disciplinas[i].alunos[j], alunos[j].nome);
				}
			}
		}
	}
	if(e==0) printf("\nNao foi possivel encontrar!\n");
	opt = 0;
	system("pause");
	system("cls");
}
