#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�os de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca resposn�velpor cuidas das strings
int registro() //fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o de vari�veis/string
	
	setlocale(LC_ALL,"portuguese"); //difinindo a liguagem	
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("digite o cpf a ser cadastrado:\n ");  //coletando as informa��es do usu�rio
	scanf("%s",cpf); //%s refere-se as strings
	
	strcpy(arquivo,cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo,"w"); //cria o arquivo
	fprintf(file,cpf); //salva o arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); //responsavel por abrir o arquivo
	fprintf(file,","); 
	fclose(file); //respnsavel por fechar bo arquivo
	
	printf("digite o nome a ser cadastrado:\n "); //coletando informa��es dos cientes
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
		printf("o arquivo que voc� digitou n�o existe!\n");
	 } 
	 
	 while(fgets(conteudo, 200, file)!= NULL)
	 {
	 	printf("\nessas s�o as informa��es do usuario: \n");
	 	printf("%s",conteudo);
	 	printf("\n\n");
	 }
	 
	 system("pause");
	 
	}

int deletar()
{
	setlocale(LC_ALL,"portuguese"); //difinindo a liguagem
		
	char cpf[40];
	printf("digite o CPF que voc� deseja deletar\n");
	printf("CPF:");
	scanf("%s",cpf);
	
	remove(cpf);
	{
	
	printf("O usu�rio foi deletado com sucesso\n");
	system("pause");
	}
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		
		printf("o usu�rio n�o se encontra no sistema\n");
		system("pause");
	}
	
	
}


int main()
{
	int opcao=0; //definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
	
		setlocale(LC_ALL,"portuguese"); //difinindo a liguagem
	
		printf("###cart�rio da EBAC###\n\n"); //inicio do menu
		printf("escolha a op��o desejada do menu:\n\n");
		printf("\t1 - registrar nomes\n");
		printf("\t2 - consultar nomes\n");
		printf("\t3 - deletar nomes\n\n");
		printf("\t4 - sair do programa\n\n");
		printf("\top��o:"); // fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls");
	
		switch(opcao)
		{
			case 1:
			registro(); //responsavel por chamar as fun��es
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
				
			printf("essa op��o n�o esta disponivel!\n");
			system("pause");
			break;	
		}   //fim da sele��o
	
		
	}
}
