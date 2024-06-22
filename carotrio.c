#include <stdio.h>  //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca resposnsavel por cuidar das strings

int registro () //Função resposável por cadastrar usuários no sistema		
{
	//início criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char  sobrenome[40];
	char cargo[40];
	int num;
	//final da criação de variáveis
	
	system("cls");//limpa a tela	
	printf("Digite o CPF a ser cadastrado:  ");//coletando informação do usuário
	scanf("%s", cpf); //%s salva string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria arquivo // "w" escreve no arquivo a informação inserida
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
	printf("1-SIM\n2-NÃO\n");
	printf("Opção:\t");
	scanf ("%d",&num);
		if (num==1)
        {
        	printf ("\n\nRetornando ao registro de usuários.\n\n");
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
	//inicio da criação de variaveis
	char cpf[40];
	char conteudo[200];
	//fim da criação de variaveis
	
	printf("Digite o cpf a ser consultado:  ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");//abre e le o arquivo
	
	while(fgets(conteudo, 200, file) != NULL)//busca as informações do arquivo inserido pelo usuário
	{
		printf("\nEssas são as informações do usuário:  ");
		printf("%s", conteudo);//Exibe na tela as informações encontradas
		printf("\n\n");
		system("pause");
		fclose(file);
		return main();
	}
	
		
	if(file == NULL);//Verifica se o arquivo esta presente no DB
	{
		printf("Registro não encontrado! \n\n");//Caso arquino não esteja presente informa o usuário
	}
	
	
	
system("pause");
	
		
}


int deletar ()
{
	//inicio da criação de variaveis
	char conteudo[200];
	char cpf[40];
	//fim da criação de variaveis
	
	int escolha=2;
	
	system("cls");//Limpa a tela 
	printf("Digite o CPF do usuário a ser excluído: ");//Coletando informações
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");//Abre o arquivo e realiza leitura com o uso do "r"
	
	if(file == NULL)//Caso o arquivo escolhido não esteja presente no DB
	{
		printf("\n\nRegistro não encontrado.\nVerifique o CPF informado.\nRetornando ao menu inicial\n");//Informando ao usuário que o arquivo não se encontra no DB
		system("pause");
		return main();//Volta para tela inicial do menu
	}
		
		
			if(file != NULL);// Caso o arquivo seja encontrado
			{
			printf("Registro de usuário encontrado: \n\n");
			fgets(conteudo, 200, file);//Busca a informação completa do arquivo
			printf("%s", conteudo);//Escreve para o usuário a informação completa do arquivo encontrado
			printf("\n\nDeseja excluir este registro?\n");//Confirmando a escolha do usuário
			printf("\t1 - SIM\n");//Dando opção ao usuário por deletar arquivo
			printf("\t2 - Não\n");//Dando opçao ao usuário para cancelar ação de deletar arquivo
			scanf("%d", &escolha);//Cria variável de escolha
			fclose(file);//fecha a pasta
		
				switch(escolha)//Teste da variável "escolha" feita pelo usuário
				{
					case 1:
					deletando();//Chamada de função
					break;

					case 2:
					printf("Registro NÃO excluído!\n\nretornando ao menu inicial.\n");//Confirmando que a ação de deletar o arquivo não foi realizada
					system("pause");
					break;
				
					default:
					printf("Opção inválida!\nRetornando ao menu inicial\n");//Mostra que o usuário escolheu uma opção que não lhe foi oferecida.
					system("pause");
					break;
				}	
			
			
			}
	
	
}

int deletando ()
{
	//inicio criação de variaveis
	char cpf[40];
	//fim criação de variaveis
					
	printf("Confirme o CPF do usuário a ser excluído: ");//Pede confirmação do arquivo a ser deletado pelo usuario
	scanf("%s",cpf);//armazena variaveis
	
	remove(cpf);//deleta o arquivo apos confirmação
	
		FILE *file;
	file = fopen(cpf,"r");//inicio da validação de exclusão de arquivo
	
	if(file == NULL)
	{
		printf("\n\nUsuário não consta no banco de dados.\n\n");
		system("pause");
		return main();//fim da validação de exclusão de arquivo
	}

	

	
}



int main()
{
	int opcao=0; // Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //Limpa a tela
			
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); // Inicio do menu
		printf ("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n\n");
		printf("Opção: "); //Fim do menu 
		
		scanf("%d", &opcao); // Armazenando as variáveis

		system("cls");
		
		switch(opcao) //inicio da seleção do função
		{
			case 1:
			registro();//Chamada de função
			break;
			
			case 2:
			consulta();//chamada de função
			break;
			
			case 3:
			deletar();//chamada de função
			break;
			
			case 4:
				printf("Obrigado por utilizar o sistema.");
				return 0;
				break;
				
			
			default:
			printf("Opção inválida!\n\n");//caso usuário insira uma opção que não esteja disponivel
			system("pause");
			break;
			
		}
	}
}
