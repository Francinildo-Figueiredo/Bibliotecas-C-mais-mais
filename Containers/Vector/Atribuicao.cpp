#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <utility> // Nem havia a necessidade de incluir a biblioteca utility, pois ela ja vem por padrão inclusa no C++11. mas como
using std::move;   // não queria apenas lançá-la no código, resolvi então inclui-la para mostrar de onde veio a função move.

#include <locale>

// Função para impressão de um comentário e um vector de qualquer tipo.
template<typename T>
void saida( const char *comentario, vector<T>& v )
{
	cout << comentario << "{ ";
	for ( auto e : v )
		cout << e << ' ';
	cout << "}" << endl;
}

int main()
{
	setlocale( LC_ALL, "portuguese" );
	/*
	Utilizando o operador de atribuição e a função utilitária move, para realizar atribuições aos vectors.
	------------------------------------------------------------------------------------------------------
	*/
	
	// Criando três vectors de inteiros, um inicializado e dois vazios.
	vector<int> num1 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, num2, num3;
	saida("num1: ", num1);
	
	// Atribuindo os valores do vector num1 a num2.
	num2 = num1;
	saida("num2: ", num2);
	
	// Movendo os valores de num1 para num3.
	cout << "\nApós movermos os valores de num1 para num3." << endl;
	num3 = move(num1);
	saida("num1: ", num1);
	saida("num3: ", num3);
	
	// Redefinindo os valores e tamanho de num2.
	cout << "\nRedefinimos num2 com novos valores." << endl;
	num2 = {4, 3, 2, 1};
	saida("num2: ", num2);
	/*
	Saída:
	
	num1: { 1 2 3 4 5 6 7 8 9 10 }
	num2: { 1 2 3 4 5 6 7 8 9 10 }
	
	Após movermos os valores de num1 para num3.
	num1: { }
	num3: { 1 2 3 4 5 6 7 8 9 10 }

	Redefinimos num2 com novos valores.
	num2: { 4 3 2 1 }
	*/
	
	/*
	Uilizando a função-membro assing para atribuir valores aos vectors. Ela funciona preticamente como uma segunda chamada do 
	construtor, logo podemos utilizar os mesmos parâmetros do construtor para a atribuição.
	-------------------------------------------------------------------------------------------------------------------------
	*/
	
	cout << "\nUtilizaremos agora a função-membro assing, para as atribuições." << endl;
	// Criando um vector vazio.
	vector<char> caracteres1;
	// Inicializando o vector com 5 caracteres 'a', por meio do assing.
	caracteres1.assign(5, 'a');
	saida("caracteres1: ", caracteres1);
	
	vector<char> caracteres2(3, 'b');
	// Atribuindo os valores de caracteres2 para caracteres1.
	caracteres1.assign(caracteres2.begin(), caracteres2.end());
	saida("caracteres1: ", caracteres2);
	
	// Redefinindo caracteres1.
	caracteres1.assign({'C', '+', '+', '1', '1'});
	saida("caracteres1: ", caracteres1);
	
	/*
	Saída:
	
	Utilizaremos agora a função-membro assing, para as atribuições.
	caracteres1: { a a a a a }
	caracteres1: { b b b }
	caracteres1: { C + + 1 1 }
	*/
	
	return 0;
}
