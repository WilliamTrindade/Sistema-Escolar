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
	char nome[20], professor[20];
	int carga, horario[4][5];//horario bloco de horario 0 para vazio e 1 para preenchido
	int codigo;
};
typedef struct y disc;
disc disciplinas[5];

//ASSOCIAR ALUNO A DISCIPLINA

void inserir_aluno(){
	//se O NUMERO DE ALUNOS MATRICULADOS FOR MAIOR QUE tam(10)
	if(m < TAM){
		char x[50];
		int sair;
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
		while(matricula_valida == 0 && sair == 0){
			printf("\n\n\tQuais disciplinas %s %s vai cursar?\n\n\nDigite o codigo ou o nome:\n", alunos[m].nome, alunos[m].sobrenome);
			gets(x);
			matricula_valida = valida_matricula(x);
			if(matricula_valida == 1){
				printf("\nQuer matricula-lo em mais disciplinas? sim = 1 / nao = 0\n\n");
				scanf("%d", &sair);
			}
		}
		
		v
		m++;
		printf("\n\n");
	}else{
		printf("\n\n voce ja cadastrou o numero maximo de alunos\n\n");
	}
	
	opt = 0;
	system("pause");
	system("cls");
	
}
int valida_email(){
	
	return 1;	
}
char valida_matricula{

}
