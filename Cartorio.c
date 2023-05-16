#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das strings

// este c�digo � excessivamente comentado para fins de estudo ;-)

//�REA RESERVA �S FUN��ES
int registro() // Fun��o respons�vel por cadastrar usu�rios no sistema
{
	setlocale(LC_ALL,"Portuguese"); // posibilita a o uso de palavras que tenham acentos em portugu�s.
	//in�cio da cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	int selecao = 1;
	//fim da cria��o das vari�veis
	
	do{
		system ("cls");
		printf("### CADASTRO ###\n\n\n");
		
		printf("Digite o CPF: ");
		scanf("%s",cpf);
		
		strcpy(arquivo,cpf); // respons�vel por copiar os valores da strings
		
		FILE*file; // cria o arquivo
		file =  fopen(arquivo,"w");// Cria um arquivo com o nome = ao conte�do da String "arquivo"
		fprintf(file,"CPF:"); //escreve dentro do arquivo o conte�do que est� entre aspas
		fprintf(file,cpf); //escreve no arquivo o conte�do da string "cpf"
		fprintf(file,"| ");
		fclose(file); // fecha o arquivo
		
		
		printf("Digite o NOME: "); //coletando informa��o do usu�rio
		scanf("%s",nome);//%s refere-se a strings
		
		file = fopen(arquivo,"a"); // abre o arquivo cujo nome est� armazenado na vari�veil "arquivo
		fprintf(file,"Nome: "); // escreve o conte�do das aspas dentro do arquivo
		fprintf(file,nome); // escreve o conte�do da vari�vel nome dentro do arquivo
		fprintf(file," ");// adiciona um espa�a dentro arquivo
		fclose(file); // fecha o arquivo
			
		printf("Digite o SOBRENOME: "); // coletando informa��o do usu�rio
		scanf("%s",sobrenome); // armazena o conte�do digitado dentro da string sobrenome
		
		file = fopen(arquivo,"a"); // abre o arquivo. O "a" significa que o arquivo ser� atualizado
		fprintf(file,sobrenome); // escreve o conte�do da vari�vel sobrenome dentro do arquivo
		fprintf(file,"| "); // escreve o conte�do das aspas no arquivo
		fclose(file); // fecha o arquivo
		
		printf("Digite o CARGO: "); //coletando informa��o do usu�rio
		scanf("%s", cargo); // armazena o conte�do digitado na string cargo
		
		file = fopen(arquivo,"a"); //abre o arquivo.
		fprintf(file,"Cargo: "); //escreve o conte�do das aspas dentro do arquivo
		
		fprintf(file,cargo); // escreve o conte�do da vari�vel cargo no arquivo
		fclose(file); // fecha o arquivo
		
		printf("\n\n\n");
		
		printf( "\nOp��es:\n");		
		printf( "\tDigite ( 1 )- Para PESQUISAR outro CPF.\n");
		printf( "\t\Digite outro n�mero para Voltar ao MENU\n");
				
		printf("\t\nEscolha: ");
				
		scanf("%d", &selecao);
		printf("%d", selecao);	
			
	}while (selecao ==1);
		
}

int consulta() // consulta usu�rio cadastrados
{	
	setlocale(LC_ALL,"Portuguese"); //Definindo a Linguagem
	
	//definindo vari�veis
	char cpf[40];
	char conteudo[200];
	int selecao = 1;
	do{
		system("cls");
		printf("### CONSULTA POR CPF ###\n\n\n");// t�tulo da tela
		
		printf("Digite o CPF: "); // coletando informa��o do usu�rio
		scanf("%s",cpf); // armazena o conte�do digitado dentro da vari�vel cpf
			
		FILE *file; //chama o arquivo
		file = fopen(cpf,"r"); // abre o arquivo cujo nome seja igual ao conte�do da vari�vel cpf. "r" read - le o arquivo
		
		if(file == NULL) // condicional: se o arquivo for nulo
		{   // verdadeiro: exibe mensagem
			printf("\nCPF n�o encontrado!\nVerifique o n�mero digitado."); // exibe mensagem na tela
			printf("\n\n\n");
		}
		
		while (fgets(conteudo, 200,file) != NULL) // armazena at� 200 caracteres na vari�vel conte�do, enquanto a condi��o for verdadeira ( diferente de Nulo)
		{
			printf("\nDados do Usu�rio:\n"); // exibe mensagema na tela
			printf(conteudo); // exibe conte�do do arquivo
			printf("\n\n\n"); // pula 3 linhas
		}
		
			printf( "\nOp��es:\n");		
			printf( "\tDigite ( 1 )- Para PESQUISAR outro CPF.\n");
			printf( "\t\Digite outro n�mero para Voltar ao MENU\n");
				
			printf("\t\nEscolha: ");
				
			scanf("%d", &selecao);
			printf("%d", selecao);	
			
	}while (selecao ==1);
}

int deletar() {//deleta usu�rios cadastrados
	
	int selecao;
	char cpf [40]; // declara��o de vari�vel	
	
	do{	
		system ("cls");
		printf("\t### DELETAR NOMES ###\n\n");
		printf(" Digite o CPF a ser DELETADO: "); // coletando informa��o do usu�rio
		scanf("%s", cpf); // armazena o conte�do da digitado na vari�vel cpf
				
		FILE *file; // chama o arquivo
		file = fopen (cpf, "r"); // abre o arquivo e l� seu conte�do
		fclose(file); // feche o arquivo
					
		printf("__________________________________________\n\n"); // exibe um separador na tela
			
		if ( file == NULL) { // condicinal: se o arquivo for nula
				
			printf(">>> Este CPF  n�o existe no cadastro. <<<\n"); // verdadeiro: exibe mensagem na tela
				
			} else { // caso contr�rio; exibe mensagem na tela.( condi��o falsa )
				remove(cpf); // remove da pasta o arquivo com nome igual ao conte�do da vari�vel cpf
				printf(">>> CPF DELETADO com sucesso! <<<\n");
			} // fim de if/else
				
		printf("__________________________________________\n\n"); // exibe um separador na tela	
			
		printf( "\nOp��es:\n");		
		printf( "\tDigite ( 1 )- Para informar outro CPF.\n");
		printf( "\t\Digite outro n�mero para Voltar ao MENU\n");
			
		printf("\t\nEscolha: ");
			
		scanf("%d", &selecao);
		printf("%d", selecao);	
			
	}while (selecao ==1);

} // fim da fun��o deletar

//IN�CIO DO PROGRAMA
int main ()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	
	
	for(laco=1;laco=1;)	// in�cio da repeti��o ( neste caso sempre repete, pois a condi��o � sempre verdadeira)
	{
		setlocale(LC_ALL,"Portuguese"); //Definindo a Linguagem		
		
		system("cls");	// limpa os dados da tela
					
		//In�cio do Menu
		printf("\t### Cart�rio da EBAC ###\n\n");
		printf("Escolha a op��o desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n\n");
		printf("Digite o C�digo da Op��o:"); 
		//Fim do Menu
		
		scanf("%d", &opcao); //armazenando a escolha do usu�rio dentro da vari�vel opcao
		
		system("cls"); // limpa os dados da tela
		
		switch(opcao) // executa uma fun��o espec�fica de acordo com o conte�do da vari�vel opcao
		{
			case 1: // executa a fun��o registro se opcao=1
			registro();
			break;
			
			case 2: // executa a fun��o consulta se opcao=2
			consulta();
			break;
			
			case 3: // executa a fun��o deletar se opcao=3
			deletar();
			break;
				
			default:// exibe a mensagem na tela quando a entrada n�o corresponde a nenhum valor da vari�vel opcao
			printf("Op��o Indispon�vel\n\n"); 
			system("pause");
			main();
			break;
			
			
			// Fim da sele��o
		}
		
	}

	return 0;
}


