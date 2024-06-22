#include <stdio.h>  //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca resposnsavel por cuidar das strings

int registro () //Fun��o respos�vel por cadastrar usu�rios no sistema		
{
	//in�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char  sobrenome[40];
	char cargo[40];
	int num;
	//final da cria��o de vari�veis
	
	system("cls");//limpa a tela	
	printf("Digite o CPF a ser cadastrado:  ");//coletando informa��o do usu�rio
	scanf("%s", cpf); //%s salva string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria arquivo // "w" escreve no arquivo a informa��o inserida
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:  ");
	scanf("%s" ,nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);

	printf("Digite o sobrenome a ser cadastrado:  ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:  ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	fclose(file);
	
	printf("\n\nGostaria de incluir um novo cadastro?\n");
	printf("1-SIM\n2-N�O\n");
	printf("Op��o:\t");
	scanf ("%d",&num);
		if (num==1)
        {
        	printf ("\n\nRetornando ao registro de usu�rios.\n\n");
        	system("pause");
        	return registro();
        }
	if (num==2)
   		printf ("\n\nRetornando ao menu principal.\n\n");
	system("pause");
	return main();
	
	
}


int consulta ()
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	//inicio da cria��o de variaveis
	char cpf[40];
	char conteudo[200];
	//fim da cria��o de variaveis
	
	printf("Digite o cpf a ser consultado:  ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");//abre e le o arquivo
	
	while(fgets(conteudo, 200, file) != NULL)//busca as informa��es do arquivo inserido pelo usu�rio
	{
		printf("\nEssas s�o as informa��es do usu�rio:  ");
		printf("%s", conteudo);//Exibe na tela as informa��es encontradas
		printf("\n\n");
		system("pause");
		fclose(file);
		return main();
	}
	
		
	if(file == NULL);//Verifica se o arquivo esta presente no DB
	{
		printf("Registro n�o encontrado! \n\n");//Caso arquino n�o esteja presente informa o usu�rio
	}
	
	
	
system("pause");
	
		
}


int deletar ()
{
	//inicio da cria��o de variaveis
	char conteudo[200];
	char cpf[40];
	//fim da cria��o de variaveis
	
	int escolha=2;
	
	system("cls");//Limpa a tela 
	printf("Digite o CPF do usu�rio a ser exclu�do: ");//Coletando informa��es
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");//Abre o arquivo e realiza leitura com o uso do "r"
	
	if(file == NULL)//Caso o arquivo escolhido n�o esteja presente no DB
	{
		printf("\n\nRegistro n�o encontrado.\nVerifique o CPF informado.\nRetornando ao menu inicial\n");//Informando ao usu�rio que o arquivo n�o se encontra no DB
		system("pause");
		return main();//Volta para tela inicial do menu
	}
		
		
			if(file != NULL);// Caso o arquivo seja encontrado
			{
			printf("Registro de usu�rio encontrado: \n\n");
			fgets(conteudo, 200, file);//Busca a informa��o completa do arquivo
			printf("%s", conteudo);//Escreve para o usu�rio a informa��o completa do arquivo encontrado
			printf("\n\nDeseja excluir este registro?\n");//Confirmando a escolha do usu�rio
			printf("\t1 - SIM\n");//Dando op��o ao usu�rio por deletar arquivo
			printf("\t2 - N�o\n");//Dando op�ao ao usu�rio para cancelar a��o de deletar arquivo
			scanf("%d", &escolha);//Cria vari�vel de escolha
			fclose(file);//fecha a pasta
		
				switch(escolha)//Teste da vari�vel "escolha" feita pelo usu�rio
				{
					case 1:
					deletando();//Chamada de fun��o
					break;

					case 2:
					printf("Registro N�O exclu�do!\n\nretornando ao menu inicial.\n");//Confirmando que a a��o de deletar o arquivo n�o foi realizada
					system("pause");
					break;
				
					default:
					printf("Op��o inv�lida!\nRetornando ao menu inicial\n");//Mostra que o usu�rio escolheu uma op��o que n�o lhe foi oferecida.
					system("pause");
					break;
				}	
			
			
			}
	
	
}

int deletando ()
{
	//inicio cria��o de variaveis
	char cpf[40];
	//fim cria��o de variaveis
					
	printf("Confirme o CPF do usu�rio a ser exclu�do: ");//Pede confirma��o do arquivo a ser deletado pelo usuario
	scanf("%s",cpf);//armazena variaveis
	
	remove(cpf);//deleta o arquivo apos confirma��o
	
		FILE *file;
	file = fopen(cpf,"r");//inicio da valida��o de exclus�o de arquivo
	
	if(file == NULL)
	{
		printf("\n\nUsu�rio n�o consta no banco de dados.\n\n");
		system("pause");
		return main();//fim da valida��o de exclus�o de arquivo
	}

	

	
}



int main()
{
	int opcao=0; // Definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //Limpa a tela
			
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); // Inicio do menu
		printf ("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n\n");
		printf("Op��o: "); //Fim do menu 
		
		scanf("%d", &opcao); // Armazenando as vari�veis

		system("cls");
		
		switch(opcao) //inicio da sele��o do fun��o
		{
			case 1:
			registro();//Chamada de fun��o
			break;
			
			case 2:
			consulta();//chamada de fun��o
			break;
			
			case 3:
			deletar();//chamada de fun��o
			break;
			
			case 4:
				printf("Obrigado por utilizar o sistema.");
				return 0;
				break;
				
			
			default:
			printf("Op��o inv�lida!\n\n");//caso usu�rio insira uma op��o que n�o esteja disponivel
			system("pause");
			break;
			
		}
	}
}
