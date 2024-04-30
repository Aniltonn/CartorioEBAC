#include <stdio.h>  //biblioteca de comuniação com o usuário
#include <stdlib.h>  //biblioteca de alocação de espaço em memória
#include <locale.h>  //biblioteca de alocação de texto por região
#include <string.h>  //biblioteca responsavel pelas strings

int registro()  //Função responsavel por cadastrar os usuarios no sistema
{
	//Inicio criação de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final criação de variaveis/string
	
	printf("Digite seu CPF a ser cadastrado: ");  //Coletando informação do usuario
	scanf("%s", cpf);  //%s refere-se a string
	
	strcpy(arquivo, cpf);  //Responsável por copiar os valores das strings
	
	FILE *file;  //Responsavel ppor criar um arquivo
	file = fopen(arquivo, "w");  //Abrir o arquivo e o "W" significa escrever
	fprintf(file,cpf);  //Salvo o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo,"a"); //Abrir o arquivo
	fprintf(file,",");  //Colocar virgula para a próxima 
	fclose(file);  //Fcehar o arquivo
	
	printf("Digite o nome a ser cadastrado: ");  //Coletando informações do usuario
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");  //Abrir o arquivo
	fprintf(file,nome);  //Salvar o valor da variavel/informação
	fclose(file);  //Fechar o arquivo
	
	file = fopen(arquivo,"a");  //Abrir o arquivo
	fprintf(file,",");  //Coloca virgula para a próxima
	fclose(file);  //Fechar arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");  //Coletando informações do usuario
	scanf("%s", sobrenome); //%s refere-se a string   (conjunto de variaveis)
	
	file = fopen(arquivo, "a"); //Abrir o arqivo
	fprintf(file,sobrenome);  //Salvar o valor da variavel/informação
	fclose(file);   //fechar o arquivo
	
	file = fopen(arquivo,"a");  //Abrir arquivo
	fprintf(file,",");  //Colocar virgula separar para a próxima
	fclose(file);  //Fcehar arquivo
	
	printf("Digite o cargo a ser cadastrado: ");  //Coletando informação do usuario
	scanf("%s", cargo);  //Refere-se a string
	
	file = fopen(arquivo, "a"); //Abrir arquivo
	fprintf(file,cargo);  //Salvaro valor da variavel/informação
	fclose(file); //Fechar arquivo
	
	system("pause"); //Pausar
	
}

int consulta()  //Função responsavel por consultar os usuáriois no sistema
{
	setlocale(LC_ALL, "Portuguese");  //Definindo a linguaguem
	
	//Inicio da criação de variaveis/string
    char cpf[40]; 
    char conteudo[200];
    //Fim da criação de variaveis
    
    printf("Digite o CPF a ser consultado: "); //Coletando informações do usuario
    scanf("%s",cpf);  //Refere-se a string
    
    FILE *file;  //Responsável por criar um arquivo
    file = fopen(cpf, "r");  //Responsável por abrir o arquivo/ "R" significa ler 
    
    if(file == NULL)  //Responsável por caso o usuario escolha opção que nao tenha em sistema
    {
    	printf("Não foi possivel abrir o arquivo, não localizado!.\n");  //Resposta ao usuário caso a informação dada nao tenha sido localizada
	}
	
	while(fgets(conteudo, 200, file) != NULL)  
	{
		printf("\n Essas são as informações do usuário: ");  //Responsavel por consultar nome do usuario
		printf("%s", conteudo);  //Refere-se a string
		printf("\n\n");  //Pular linha 
	}
	
	system("pause"); //Pausar o sistema
    
    
    
    
    
    
}

int deletar()  //Responsável pela função de deletar o usuário
{
	//Inicio criação de variaveis/string
    char cpf[40];
    //Fim criação de variaveis/string
    
    printf("Digite o CPF do usuário a ser deletado: ");  //Responsável por perguntar ao usuario o CPF a ser deletado
    scanf("%s",cpf);  //Refere-se a string
    
    remove(cpf);  //Responsavel por remover o usuario
    
    FILE *file; //Criar o arquivo
    file = fopen(cpf, "r");  //Abrir o arquivo
    
    if(file == NULL)  //Responável para verificar se a abertura de um arquivo foi bem-sucedida.
    {
    	printf("O usuário não se encontra no sistema!.\n");  //Responável por falar que o usuario nao se encontra mas nosistema
    	system("pause");  //Pausar sistema
    	
	}

}

int main()  //Responsável é o ponto de entrada principal para a execução do programa
{
	int opcao=0;  //Definindo variaveis
	int laco=1; 
	
	for(laco=1;laco=1;)
	{
	
	system("cls");  //Responsável por limpar a tela
	
	setlocale(LC_ALL, "Portuguese");  //Definindo a linguaguem
	
	printf("### Cartório da EBAC ###\n\n");  //Inicio do menu
	printf("Escolha a opção desejada do menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n");  
	printf("Opção: ");  //Fim do menu
	
    scanf("%d", &opcao);  //Armazenando a escolha do usuario
	
	system("cls");  //Serve para limpar a primeira ou a tela para a próxima etapa
	
	    switch(opcao)
	{
		case 1:  //Responsável por especificar as ações
		registro();  //Chamada de funções
		break;  //Responsável por sair de lopps
		
		case 2:  //Responsável por especificar as ações
		consulta();  //Chamada de funções
		break;  //Responsável por sair de lopps
		
		case 3:  //Responsável por especificar as ações
		deletar();  //Chamada de funções
		break; //Responsável por sair de lopps
		
		
		default:  //especificar uma ação a ser executada caso nenhum dos case correspondentes à expressão condicional exista
		printf("Essa opção não está disponivel!\n");  //Responsável por informar o usuario 
		system("pause");  //Pausar sistema
		break;  //Responável por sair de lopps
		}
	
	
 }

}

