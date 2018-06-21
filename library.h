//DECLARAÇÃO DE VARIAVEIS
#define TAM 10
int opt = 0;

//ESTRUTURA DOS ALUNOS
struct x{
	char nome[20], sobrenome[20], email[50];
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
void associar_aluno(){
	printf("as");
	opt = 0;
	printf("\n\n");
	system("pause");
	system("cls");
}

void inserir_aluno(){
	printf("as");
	opt = 0;
	printf("\n\n");
	system("pause");
	system("cls");
	
}
