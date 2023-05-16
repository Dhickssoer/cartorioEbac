#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsável por cuidar das strings

// este código é excessivamente comentado para fins de estudo ;-)

//ÁREA RESERVA ÀS FUNÇÕES
int registro() // Função responsável por cadastrar usuários no sistema
{
	setlocale(LC_ALL,"Portuguese"); // posibilita a o uso de palavras que tenham acentos em português.
	//início da criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	int selecao = 1;
	//fim da criação das variáveis
	
	do{
		system ("cls");
		printf("### CADASTRO ###\n\n\n");
		
		printf("Digite o CPF: ");
		scanf("%s",cpf);
		
		strcpy(arquivo,cpf); // responsável por copiar os valores da strings
		
		FILE*file; // cria o arquivo
		file =  fopen(arquivo,"w");// Cria um arquivo com o nome = ao conteúdo da String "arquivo"
		fprintf(file,"CPF:"); //escreve dentro do arquivo o conteúdo que está entre aspas
		fprintf(file,cpf); //escreve no arquivo o conteúdo da string "cpf"
		fprintf(file,"| ");
		fclose(file); // fecha o arquivo
		
		
		printf("Digite o NOME: "); //coletando informação do usuário
		scanf("%s",nome);//%s refere-se a strings
		
		file = fopen(arquivo,"a"); // abre o arquivo cujo nome está armazenado na variáveil "arquivo
		fprintf(file,"Nome: "); // escreve o conteúdo das aspas dentro do arquivo
		fprintf(file,nome); // escreve o conteúdo da variável nome dentro do arquivo
		fprintf(file," ");// adiciona um espaça dentro arquivo
		fclose(file); // fecha o arquivo
			
		printf("Digite o SOBRENOME: "); // coletando informação do usuário
		scanf("%s",sobrenome); // armazena o conteúdo digitado dentro da string sobrenome
		
		file = fopen(arquivo,"a"); // abre o arquivo. O "a" significa que o arquivo será atualizado
		fprintf(file,sobrenome); // escreve o conteúdo da variável sobrenome dentro do arquivo
		fprintf(file,"| "); // escreve o conteúdo das aspas no arquivo
		fclose(file); // fecha o arquivo
		
		printf("Digite o CARGO: "); //coletando informação do usuário
		scanf("%s", cargo); // armazena o conteúdo digitado na string cargo
		
		file = fopen(arquivo,"a"); //abre o arquivo.
		fprintf(file,"Cargo: "); //escreve o conteúdo das aspas dentro do arquivo
		
		fprintf(file,cargo); // escreve o conteúdo da variável cargo no arquivo
		fclose(file); // fecha o arquivo
		
		printf("\n\n\n");
		
		printf( "\nOpções:\n");		
		printf( "\tDigite ( 1 )- Para PESQUISAR outro CPF.\n");
		printf( "\t\Digite outro número para Voltar ao MENU\n");
				
		printf("\t\nEscolha: ");
				
		scanf("%d", &selecao);
		printf("%d", selecao);	
			
	}while (selecao ==1);
		
}

int consulta() // consulta usuário cadastrados
{	
	setlocale(LC_ALL,"Portuguese"); //Definindo a Linguagem
	
	//definindo variáveis
	char cpf[40];
	char conteudo[200];
	int selecao = 1;
	do{
		system("cls");
		printf("### CONSULTA POR CPF ###\n\n\n");// título da tela
		
		printf("Digite o CPF: "); // coletando informação do usuário
		scanf("%s",cpf); // armazena o conteúdo digitado dentro da variável cpf
			
		FILE *file; //chama o arquivo
		file = fopen(cpf,"r"); // abre o arquivo cujo nome seja igual ao conteúdo da variável cpf. "r" read - le o arquivo
		
		if(file == NULL) // condicional: se o arquivo for nulo
		{   // verdadeiro: exibe mensagem
			printf("\nCPF não encontrado!\nVerifique o número digitado."); // exibe mensagem na tela
			printf("\n\n\n");
		}
		
		while (fgets(conteudo, 200,file) != NULL) // armazena até 200 caracteres na variável conteúdo, enquanto a condição for verdadeira ( diferente de Nulo)
		{
			printf("\nDados do Usuário:\n"); // exibe mensagema na tela
			printf(conteudo); // exibe conteúdo do arquivo
			printf("\n\n\n"); // pula 3 linhas
		}
		
			printf( "\nOpções:\n");		
			printf( "\tDigite ( 1 )- Para PESQUISAR outro CPF.\n");
			printf( "\t\Digite outro número para Voltar ao MENU\n");
				
			printf("\t\nEscolha: ");
				
			scanf("%d", &selecao);
			printf("%d", selecao);	
			
	}while (selecao ==1);
}

int deletar() {//deleta usuários cadastrados
	
	int selecao;
	char cpf [40]; // declaração de variável	
	
	do{	
		system ("cls");
		printf("\t### DELETAR NOMES ###\n\n");
		printf(" Digite o CPF a ser DELETADO: "); // coletando informação do usuário
		scanf("%s", cpf); // armazena o conteúdo da digitado na variável cpf
				
		FILE *file; // chama o arquivo
		file = fopen (cpf, "r"); // abre o arquivo e lê seu conteúdo
		fclose(file); // feche o arquivo
					
		printf("__________________________________________\n\n"); // exibe um separador na tela
			
		if ( file == NULL) { // condicinal: se o arquivo for nula
				
			printf(">>> Este CPF  não existe no cadastro. <<<\n"); // verdadeiro: exibe mensagem na tela
				
			} else { // caso contrário; exibe mensagem na tela.( condição falsa )
				remove(cpf); // remove da pasta o arquivo com nome igual ao conteúdo da variável cpf
				printf(">>> CPF DELETADO com sucesso! <<<\n");
			} // fim de if/else
				
		printf("__________________________________________\n\n"); // exibe um separador na tela	
			
		printf( "\nOpções:\n");		
		printf( "\tDigite ( 1 )- Para informar outro CPF.\n");
		printf( "\t\Digite outro número para Voltar ao MENU\n");
			
		printf("\t\nEscolha: ");
			
		scanf("%d", &selecao);
		printf("%d", selecao);	
			
	}while (selecao ==1);

} // fim da função deletar

//INÍCIO DO PROGRAMA
int main ()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	
	
	for(laco=1;laco=1;)	// início da repetição ( neste caso sempre repete, pois a condição é sempre verdadeira)
	{
		setlocale(LC_ALL,"Portuguese"); //Definindo a Linguagem		
		
		system("cls");	// limpa os dados da tela
					
		//Início do Menu
		printf("\t### Cartório da EBAC ###\n\n");
		printf("Escolha a opção desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n\n");
		printf("Digite o Código da Opção:"); 
		//Fim do Menu
		
		scanf("%d", &opcao); //armazenando a escolha do usuário dentro da variável opcao
		
		system("cls"); // limpa os dados da tela
		
		switch(opcao) // executa uma função específica de acordo com o conteúdo da variável opcao
		{
			case 1: // executa a função registro se opcao=1
			registro();
			break;
			
			case 2: // executa a função consulta se opcao=2
			consulta();
			break;
			
			case 3: // executa a função deletar se opcao=3
			deletar();
			break;
				
			default:// exibe a mensagem na tela quando a entrada não corresponde a nenhum valor da variável opcao
			printf("Opção Indisponível\n\n"); 
			system("pause");
			main();
			break;
			
			
			// Fim da seleção
		}
		
	}

	return 0;
}


