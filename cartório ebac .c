#include <stdio.h>  //biblioteca de comunia��o com o usu�rio
#include <stdlib.h>  //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>  //biblioteca de aloca��o de texto por regi�o
#include <string.h>  //biblioteca responsavel pelas strings

int registro()  //Fun��o responsavel por cadastrar os usuarios no sistema
{
	//Inicio cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final cria��o de variaveis/string
	
	printf("Digite seu CPF a ser cadastrado: ");  //Coletando informa��o do usuario
	scanf("%s", cpf);  //%s refere-se a string
	
	strcpy(arquivo, cpf);  //Respons�vel por copiar os valores das strings
	
	FILE *file;  //Responsavel ppor criar um arquivo
	file = fopen(arquivo, "w");  //Abrir o arquivo e o "W" significa escrever
	fprintf(file,cpf);  //Salvo o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo,"a"); //Abrir o arquivo
	fprintf(file,",");  //Colocar virgula para a pr�xima 
	fclose(file);  //Fcehar o arquivo
	
	printf("Digite o nome a ser cadastrado: ");  //Coletando informa��es do usuario
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");  //Abrir o arquivo
	fprintf(file,nome);  //Salvar o valor da variavel/informa��o
	fclose(file);  //Fechar o arquivo
	
	file = fopen(arquivo,"a");  //Abrir o arquivo
	fprintf(file,",");  //Coloca virgula para a pr�xima
	fclose(file);  //Fechar arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");  //Coletando informa��es do usuario
	scanf("%s", sobrenome); //%s refere-se a string   (conjunto de variaveis)
	
	file = fopen(arquivo, "a"); //Abrir o arqivo
	fprintf(file,sobrenome);  //Salvar o valor da variavel/informa��o
	fclose(file);   //fechar o arquivo
	
	file = fopen(arquivo,"a");  //Abrir arquivo
	fprintf(file,",");  //Colocar virgula separar para a pr�xima
	fclose(file);  //Fcehar arquivo
	
	printf("Digite o cargo a ser cadastrado: ");  //Coletando informa��o do usuario
	scanf("%s", cargo);  //Refere-se a string
	
	file = fopen(arquivo, "a"); //Abrir arquivo
	fprintf(file,cargo);  //Salvaro valor da variavel/informa��o
	fclose(file); //Fechar arquivo
	
	system("pause"); //Pausar
	
}

int consulta()  //Fun��o responsavel por consultar os usu�riois no sistema
{
	setlocale(LC_ALL, "Portuguese");  //Definindo a linguaguem
	
	//Inicio da cria��o de variaveis/string
    char cpf[40]; 
    char conteudo[200];
    //Fim da cria��o de variaveis
    
    printf("Digite o CPF a ser consultado: "); //Coletando informa��es do usuario
    scanf("%s",cpf);  //Refere-se a string
    
    FILE *file;  //Respons�vel por criar um arquivo
    file = fopen(cpf, "r");  //Respons�vel por abrir o arquivo/ "R" significa ler 
    
    if(file == NULL)  //Respons�vel por caso o usuario escolha op��o que nao tenha em sistema
    {
    	printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");  //Resposta ao usu�rio caso a informa��o dada nao tenha sido localizada
	}
	
	while(fgets(conteudo, 200, file) != NULL)  
	{
		printf("\n Essas s�o as informa��es do usu�rio: ");  //Responsavel por consultar nome do usuario
		printf("%s", conteudo);  //Refere-se a string
		printf("\n\n");  //Pular linha 
	}
	
	system("pause"); //Pausar o sistema
    
    
    
    
    
    
}

int deletar()  //Respons�vel pela fun��o de deletar o usu�rio
{
	//Inicio cria��o de variaveis/string
    char cpf[40];
    //Fim cria��o de variaveis/string
    
    printf("Digite o CPF do usu�rio a ser deletado: ");  //Respons�vel por perguntar ao usuario o CPF a ser deletado
    scanf("%s",cpf);  //Refere-se a string
    
    remove(cpf);  //Responsavel por remover o usuario
    
    FILE *file; //Criar o arquivo
    file = fopen(cpf, "r");  //Abrir o arquivo
    
    if(file == NULL)  //Respon�vel para verificar se a abertura de um arquivo foi bem-sucedida.
    {
    	printf("O usu�rio n�o se encontra no sistema!.\n");  //Respon�vel por falar que o usuario nao se encontra mas nosistema
    	system("pause");  //Pausar sistema
    	
	}

}

int main()  //Respons�vel � o ponto de entrada principal para a execu��o do programa
{
	int opcao=0;  //Definindo variaveis
	int laco=1; 
	
	for(laco=1;laco=1;)
	{
	
	system("cls");  //Respons�vel por limpar a tela
	
	setlocale(LC_ALL, "Portuguese");  //Definindo a linguaguem
	
	printf("### Cart�rio da EBAC ###\n\n");  //Inicio do menu
	printf("Escolha a op��o desejada do menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n");  
	printf("Op��o: ");  //Fim do menu
	
    scanf("%d", &opcao);  //Armazenando a escolha do usuario
	
	system("cls");  //Serve para limpar a primeira ou a tela para a pr�xima etapa
	
	    switch(opcao)
	{
		case 1:  //Respons�vel por especificar as a��es
		registro();  //Chamada de fun��es
		break;  //Respons�vel por sair de lopps
		
		case 2:  //Respons�vel por especificar as a��es
		consulta();  //Chamada de fun��es
		break;  //Respons�vel por sair de lopps
		
		case 3:  //Respons�vel por especificar as a��es
		deletar();  //Chamada de fun��es
		break; //Respons�vel por sair de lopps
		
		
		default:  //especificar uma a��o a ser executada caso nenhum dos case correspondentes � express�o condicional exista
		printf("Essa op��o n�o est� disponivel!\n");  //Respons�vel por informar o usuario 
		system("pause");  //Pausar sistema
		break;  //Respon�vel por sair de lopps
		}
	
	
 }

}

