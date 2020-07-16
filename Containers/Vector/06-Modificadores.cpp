#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;
#include <algorithm>
using std::for_each;

#include <locale>

void saida(const char *comentario, vector<int>& v)
{
	cout << comentario;
	for(int n : v)
		cout << n << ' ';
}

int main()
{
	setlocale( LC_ALL, "portuguese" );
	vector<int>nums(4, 0);
	vector<int>aux {1, 2, 3};
	saida("nums: ", nums);
	saida("\naux: ", aux);
	/*
	O m�todo insert adiciona valores ou copias de outros vectors em qualquer posi��o por meio de iteradores, tamb�m
	podemos informar a quantidade de vezes que queremos adicion�-los.
	*/
	// Criando um iterador constante que apontar� para a primeira posi��o de nums.
	vector<int>::const_iterator it = nums.begin();
	// Inserindo os valores de aux na metade de nums.
	nums.insert(it+2, aux.begin(), aux.end());
	saida("\nnums: ", nums);
	// Inserindo tr�s vezes o n�mero 2 no in�cio de nums.
	nums.insert(nums.begin(), 3, 2);
	saida("\nnums: ", nums);
	/*
	Sa�da:
	nums: 0 0 0 0
	aux: 1 2 3
	nums: 0 0 1 2 3 0 0
	nums: 2 2 2 0 0 1 2 3 0 0
	*/
	
	// Deletando todo o conte�do de nums por meio do m�todo clear.
	nums.clear();
	// Redefinindo um novo tamanho para nums pelo m�todo resize.
	nums.resize(4);
	saida("\nnums: ", nums);
	// Trocando os conte�dos dos vectors nums e aux.
	nums.swap(aux);
	saida("\nnums: ", nums);
	saida("\naux: ", aux);
	/*
	Sa�da:
	nums: 0 0 0 0
	nums: 1 2 3
	aux: 0 0 0 0
	*/
	/*
	O m�todo push_back � o mais utilizado no vector, pois com ele podemos adicionar elementos no final do vector. diferentemente
	do m�todo insert que utiliza iteradores, no push_pack podemos passar os valores diretamente como par�metro, mas ficamos restritos
	� aloca��o desses valores apenas no final do vector.
	E para deletarmos o �ltimo elemento do vector temos o m�todo pop_back. 
	*/
	nums.push_back(4);
	nums.push_back(5);
	saida("\nnums: ", nums);
	nums.pop_back();
	saida("\nnums: ", nums);
	// Com o m�todo erase podemos apagar um ou v�rios elementos espec�ficos por meio de iteradores no intervalo [first, last).
	nums.erase(nums.begin()+1, nums.begin()+3);
	saida("\nnums: ", nums);
	/*
	Sa�da:
	nums: 1 2 3 4 5
	nums: 1 2 3 4
	nums: 1 4
	*/
	
	return 0;
}
