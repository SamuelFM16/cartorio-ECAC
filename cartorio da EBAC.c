#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaços de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca resposnávelpor cuidas das strings
int registro() //função responsavel por cadastrar os usuários no sistema
{
	//inicio da criação de variáveis/string
	
	setlocale(LC_ALL,"portuguese"); //difinindo a liguagem	
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("digite o cpf a ser cadastrado:\n ");  //coletando as informações do usuário
	scanf("%s",cpf); //%s refere-se as strings
	
	strcpy(arquivo,cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo,"w"); //cria o arquivo
	fprintf(file,cpf); //salva o arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); //responsavel por abrir o arquivo
	fprintf(file,","); 
	fclose(file); //respnsavel por fechar bo arquivo
	
	printf("digite o nome a ser cadastrado:\n "); //coletando informações dos cientes
	scanf("%s",nome); //refere-se as strings
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado:\n ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado:\n ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
}

int consultar()
{
	setlocale(LC_ALL,"portuguese"); //difinindo a liguagem		
	
	char cpf[40];
	char conteudo[200];
	
	printf("digite o cpf a ser consultado: \n");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("o arquivo que você digitou não existe!\n");
	 } 
	 
	 while(fgets(conteudo, 200, file)!= NULL)
	 {
	 	printf("\nessas são as informações do usuario: \n");
	 	printf("%s",conteudo);
	 	printf("\n\n");
	 }
	 
	 system("pause");
	 
	}

int deletar()
{
	setlocale(LC_ALL,"portuguese"); //difinindo a liguagem
		
	char cpf[40];
	printf("digite o CPF que você deseja deletar\n");
	printf("CPF:");
	scanf("%s",cpf);
	
	remove(cpf);
	{
	
	printf("O usuário foi deletado com sucesso\n");
	system("pause");
	}
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		
		printf("o usuário não se encontra no sistema\n");
		system("pause");
	}
	
	
}


int main()
{
	int opcao=0; //definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
	
		setlocale(LC_ALL,"portuguese"); //difinindo a liguagem
	
		printf("###cartório da EBAC###\n\n"); //inicio do menu
		printf("escolha a opção desejada do menu:\n\n");
		printf("\t1 - registrar nomes\n");
		printf("\t2 - consultar nomes\n");
		printf("\t3 - deletar nomes\n\n");
		printf("\t4 - sair do programa\n\n");
		printf("\topção:"); // fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls");
	
		switch(opcao)
		{
			case 1:
			registro(); //responsavel por chamar as funções
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("obrigado por ultilizar nosso sitema\n");
			return 0;
			break;
			
			default:
				
			printf("essa opção não esta disponivel!\n");
			system("pause");
			break;	
		}   //fim da seleção
	
		
	}
}
