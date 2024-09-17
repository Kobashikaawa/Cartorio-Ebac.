#include <stdio.h> // Biblioteca para opera��es de entrada e sa�da (como printf, scanf, fopen, etc.)
#include <stdlib.h> // Biblioteca para aloca��o de mem�ria, controle de processos e fun��es como system() e exit()
#include <locale.h> // Biblioteca para definir a localidade (linguagem e formato regional)
#include <string.h> // Biblioteca para manipula��o de strings (como strcpy)

int registro()
{
	setlocale(LC_ALL, "Portuguese_Brazil");	// Define a localidade para o portugu�s do Brasil, garantindo  corretamente os acentos, etc
	
	// In�cio da cria��o de strings
	char arquivo[40]; // Vari�vel para armazenar o nome do arquivo (o CPF)
	char cpf[40]; // Vari�vel para armazenar o CPF
	char nome[40]; // Vari�vel para armazenar o nome
	char sobrenome[40]; // Vari�vel para armazenar o sobrenome
	char cargo[40]; // Vari�vel para armazenar o cargo
	// Fim da cria��o de strings
	
	printf("Digite o CPF a ser cadastrado: \n"); // Solicita o CPF ao usu�rio	
	scanf("%s", cpf); // L� o CPF digitado pelo usu�rio (%s refere-se a uma string)
	
	strcpy(arquivo, cpf); // Copia o valor da vari�vel cpf para a vari�vel arquivo (nome do arquivo)
	
	// Cria��o do arquivo
	FILE *file; // Ponteiro para o arquivo
	file = fopen(arquivo, "w"); // Abre/cria o arquivo com o nome do CPF, no modo de escrita ("w")
	fprintf(file, cpf); // Escreve o CPF no arquivo
	fclose(file); // Fecha o arquivo
	
	// Reabre o arquivo para adicionar (apensar) conte�do
	file = fopen(arquivo, "a"); // Abre o arquivo no modo de apensar ("a") para adicionar conte�do
	fprintf(file, ","); // Escreve uma v�rgula no arquivo para separar os dados
	fclose(file); // Fecha o arquivo
	
	// Solicita o nome do usu�rio
	printf("Digite o NOME a ser cadastrado: \n"); 
	scanf("%s", nome); // L� o nome digitado
	
	file = fopen(arquivo, "a"); // Abre o arquivo no modo de apensar ("a")
	fprintf(file, nome); // Escreve o nome no arquivo
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); // Abre o arquivo novamente no modo de apensar
	fprintf(file, ","); // Escreve uma v�rgula para separar os dados
	fclose(file); // Fecha o arquivo
	
	// Solicita o sobrenome do usu�rio
	printf("Digite o SOBRENOME a ser cadastrado: \n");
	scanf("%s", sobrenome); // L� o sobrenome digitado
	
	file = fopen(arquivo, "a"); // Abre o arquivo no modo de apensar
	fprintf(file, sobrenome); // Escreve o sobrenome no arquivo
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); // Abre o arquivo no modo de apensar
	fprintf(file, ","); // Escreve uma v�rgula no arquivo
	fclose(file); // Fecha o arquivo
	
	// Solicita o cargo do usu�rio
	printf("Digite o CARGO a ser cadastrado: \n");
	scanf("%s", cargo); // L� o cargo digitado
	
	file = fopen(arquivo, "a"); // Abre o arquivo no modo de apensar
	fprintf(file, cargo); // Escreve o cargo no arquivo
	fclose(file); // Fecha o arquivo
	
	system("pause"); // Pausa o sistema para que o programa n�o feche imediatamente
}

int consulta() // Fun��o para consultar os registros
{
	setlocale(LC_ALL, "Portuguese_Brazil"); // Define a localidade para o portugu�s do Brasil
	
	// Cria��o de vari�veis para armazenar dados
	char cpf[40]; // Vari�vel para armazenar o CPF
	char conteudo[40]; // Vari�vel para armazenar o conte�do do arquivo
	
	// Solicita o CPF a ser consultado
	printf("Digite o cpf a ser consultado: "); 
	scanf("%s", cpf); // L� o CPF digitado pelo usu�rio
	
	FILE *file; // Ponteiro para o arquivo
	file = fopen(cpf, "r"); // Abre o arquivo no modo de leitura ("r")
	
	// Verifica se o arquivo foi aberto corretamente
	if(file == NULL) // Se o arquivo n�o existir
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n"); // Exibe mensagem de erro
	}
	
	// L� o conte�do do arquivo e exibe na tela
	while(fgets(conteudo, 200, file) != NULL) // L� uma linha do arquivo por vez
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); // Exibe as informa��es
		printf("%s", conteudo); // Mostra o conte�do do arquivo
		printf("\n\n"); // Quebra de linha
	}
	
	system("pause"); // Pausa o sistema para que o programa n�o feche imediatamente
}

int deletar() // Fun��o para deletar o arquivo
{
	char cpf[40]; // Vari�vel para armazenar o CPF
	
	// Solicita o CPF a ser deletado
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf); // L� o CPF digitado
	
	remove(cpf); // Remove o arquivo com o nome correspondente ao CPF
	
	FILE *file; // Ponteiro para o arquivo
	file = fopen(cpf, "r"); // Tenta abrir o arquivo para verificar se foi realmente deletado
	
	if(file == NULL) // Se o arquivo n�o existir
	{
		printf("Usu�rio N�o Existente!.\n"); // Exibe mensagem de que o arquivo n�o foi encontrado
		system("pause"); // Pausa o sistema para que o programa n�o feche imediatamente
	}
}

int main()  // Feito por Ryuki alex Katsurem, terminado em 13/09 e inicio em 03/09.
{
	int opcao = 0; // Vari�vel para armazenar a op��o do usu�rio
	int repeticao = 1; // Vari�vel para controlar a repeti��o do menu
	
	for(repeticao = 1; repeticao = 1;) // Loop infinito para repetir o menu
	{
		system("cls"); // Limpa a tela
		
		setlocale(LC_ALL, "Portuguese_Brazil"); // Define a localidade para o portugu�s do Brasil
	
		// Menu principal
 		printf("### Cart�rio da EBAC ###\n\n");
		printf("Escolha a op��o desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n"); // \t cria uma tabula��o (espa�o)
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o: ");
		
		scanf("%d", &opcao); // L� a op��o escolhida pelo usu�rio
		
		system("cls"); // Limpa a tela ap�s a escolha
		
		switch (opcao)
		{
			case 1: // Caso o usu�rio escolha a op��o 1
				registro(); // Chama a fun��o de registro	
				break; // Interrompe o fluxo para n�o executar outras op��es
				
			case 2: // Caso o usu�rio escolha a op��o 2
				consulta(); // Chama a fun��o de consulta
				break;
				
			case 3: // Caso o usu�rio escolha a op��o 3
				deletar(); // Chama a fun��o de deletar
				break;
				
			default: // Caso o usu�rio insira uma op��o inv�lida
	            printf("Op��o inv�lida. Tente novamente.\n"); // Exibe mensagem de erro
	            system("pause"); // Pausa para que o usu�rio veja a mensagem antes de repetir o menu
	            break; // Interrompe o fluxo
		}
	}
}
