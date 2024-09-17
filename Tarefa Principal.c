#include <stdio.h> // Biblioteca para operações de entrada e saída (como printf, scanf, fopen, etc.)
#include <stdlib.h> // Biblioteca para alocação de memória, controle de processos e funções como system() e exit()
#include <locale.h> // Biblioteca para definir a localidade (linguagem e formato regional)
#include <string.h> // Biblioteca para manipulação de strings (como strcpy)

int registro()
{
	setlocale(LC_ALL, "Portuguese_Brazil");	// Define a localidade para o português do Brasil, garantindo  corretamente os acentos, etc
	
	// Início da criação de strings
	char arquivo[40]; // Variável para armazenar o nome do arquivo (o CPF)
	char cpf[40]; // Variável para armazenar o CPF
	char nome[40]; // Variável para armazenar o nome
	char sobrenome[40]; // Variável para armazenar o sobrenome
	char cargo[40]; // Variável para armazenar o cargo
	// Fim da criação de strings
	
	printf("Digite o CPF a ser cadastrado: \n"); // Solicita o CPF ao usuário	
	scanf("%s", cpf); // Lê o CPF digitado pelo usuário (%s refere-se a uma string)
	
	strcpy(arquivo, cpf); // Copia o valor da variável cpf para a variável arquivo (nome do arquivo)
	
	// Criação do arquivo
	FILE *file; // Ponteiro para o arquivo
	file = fopen(arquivo, "w"); // Abre/cria o arquivo com o nome do CPF, no modo de escrita ("w")
	fprintf(file, cpf); // Escreve o CPF no arquivo
	fclose(file); // Fecha o arquivo
	
	// Reabre o arquivo para adicionar (apensar) conteúdo
	file = fopen(arquivo, "a"); // Abre o arquivo no modo de apensar ("a") para adicionar conteúdo
	fprintf(file, ","); // Escreve uma vírgula no arquivo para separar os dados
	fclose(file); // Fecha o arquivo
	
	// Solicita o nome do usuário
	printf("Digite o NOME a ser cadastrado: \n"); 
	scanf("%s", nome); // Lê o nome digitado
	
	file = fopen(arquivo, "a"); // Abre o arquivo no modo de apensar ("a")
	fprintf(file, nome); // Escreve o nome no arquivo
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); // Abre o arquivo novamente no modo de apensar
	fprintf(file, ","); // Escreve uma vírgula para separar os dados
	fclose(file); // Fecha o arquivo
	
	// Solicita o sobrenome do usuário
	printf("Digite o SOBRENOME a ser cadastrado: \n");
	scanf("%s", sobrenome); // Lê o sobrenome digitado
	
	file = fopen(arquivo, "a"); // Abre o arquivo no modo de apensar
	fprintf(file, sobrenome); // Escreve o sobrenome no arquivo
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); // Abre o arquivo no modo de apensar
	fprintf(file, ","); // Escreve uma vírgula no arquivo
	fclose(file); // Fecha o arquivo
	
	// Solicita o cargo do usuário
	printf("Digite o CARGO a ser cadastrado: \n");
	scanf("%s", cargo); // Lê o cargo digitado
	
	file = fopen(arquivo, "a"); // Abre o arquivo no modo de apensar
	fprintf(file, cargo); // Escreve o cargo no arquivo
	fclose(file); // Fecha o arquivo
	
	system("pause"); // Pausa o sistema para que o programa não feche imediatamente
}

int consulta() // Função para consultar os registros
{
	setlocale(LC_ALL, "Portuguese_Brazil"); // Define a localidade para o português do Brasil
	
	// Criação de variáveis para armazenar dados
	char cpf[40]; // Variável para armazenar o CPF
	char conteudo[40]; // Variável para armazenar o conteúdo do arquivo
	
	// Solicita o CPF a ser consultado
	printf("Digite o cpf a ser consultado: "); 
	scanf("%s", cpf); // Lê o CPF digitado pelo usuário
	
	FILE *file; // Ponteiro para o arquivo
	file = fopen(cpf, "r"); // Abre o arquivo no modo de leitura ("r")
	
	// Verifica se o arquivo foi aberto corretamente
	if(file == NULL) // Se o arquivo não existir
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n"); // Exibe mensagem de erro
	}
	
	// Lê o conteúdo do arquivo e exibe na tela
	while(fgets(conteudo, 200, file) != NULL) // Lê uma linha do arquivo por vez
	{
		printf("\nEssas são as informações do usuário: "); // Exibe as informações
		printf("%s", conteudo); // Mostra o conteúdo do arquivo
		printf("\n\n"); // Quebra de linha
	}
	
	system("pause"); // Pausa o sistema para que o programa não feche imediatamente
}

int deletar() // Função para deletar o arquivo
{
	char cpf[40]; // Variável para armazenar o CPF
	
	// Solicita o CPF a ser deletado
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf); // Lê o CPF digitado
	
	remove(cpf); // Remove o arquivo com o nome correspondente ao CPF
	
	FILE *file; // Ponteiro para o arquivo
	file = fopen(cpf, "r"); // Tenta abrir o arquivo para verificar se foi realmente deletado
	
	if(file == NULL) // Se o arquivo não existir
	{
		printf("Usuário Não Existente!.\n"); // Exibe mensagem de que o arquivo não foi encontrado
		system("pause"); // Pausa o sistema para que o programa não feche imediatamente
	}
}

int main()  // Feito por Ryuki alex Katsurem, terminado em 13/09 e inicio em 03/09.
{
	int opcao = 0; // Variável para armazenar a opção do usuário
	int repeticao = 1; // Variável para controlar a repetição do menu
	
	for(repeticao = 1; repeticao = 1;) // Loop infinito para repetir o menu
	{
		system("cls"); // Limpa a tela
		
		setlocale(LC_ALL, "Portuguese_Brazil"); // Define a localidade para o português do Brasil
	
		// Menu principal
 		printf("### Cartório da EBAC ###\n\n");
		printf("Escolha a opção desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n"); // \t cria uma tabulação (espaço)
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção: ");
		
		scanf("%d", &opcao); // Lê a opção escolhida pelo usuário
		
		system("cls"); // Limpa a tela após a escolha
		
		switch (opcao)
		{
			case 1: // Caso o usuário escolha a opção 1
				registro(); // Chama a função de registro	
				break; // Interrompe o fluxo para não executar outras opções
				
			case 2: // Caso o usuário escolha a opção 2
				consulta(); // Chama a função de consulta
				break;
				
			case 3: // Caso o usuário escolha a opção 3
				deletar(); // Chama a função de deletar
				break;
				
			default: // Caso o usuário insira uma opção inválida
	            printf("Opção inválida. Tente novamente.\n"); // Exibe mensagem de erro
	            system("pause"); // Pausa para que o usuário veja a mensagem antes de repetir o menu
	            break; // Interrompe o fluxo
		}
	}
}
