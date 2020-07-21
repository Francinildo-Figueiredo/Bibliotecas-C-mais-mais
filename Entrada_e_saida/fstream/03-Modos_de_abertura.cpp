#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <fstream>
using std::fstream;
using std::ios;

#include <locale>

int main()
{
	setlocale( LC_ALL, "portuguese" );
	
	/*
	Modos de abertura de arquivos:
	
	ios::in --> Abre para leitura (default de ifstream)
	ios::out --> Abre para grava��o (default de ofstream)
	ios::ate --> Abre e posiciona no final do arquivo (Este modo trabalha com leitura e grava��o)
	ios::app --> Grava a partir do fim do arquivo
	ios::trunc --> Abre e apaga todo o conte�do do arquivo
	ios::binary --> Abre em bin�rio (default � texto)
	*/
	
	// Podemos utilizar estes modos de abertura tanto no construtor quanto na fun��o open, que ser� a utilizada nesse exemplo.
	fstream arqv("Exemplo2.txt", ios::ate | ios::out | ios::in); // Arquivo de entrada e sa�da
	if (!arqv.is_open())										 // Testa se o arquivo foi aberto
		cout << "O arquivo n�o foi aberto!" << endl;
	for ( unsigned int i = 0; i < 20; i++)
		arqv << i << endl; // Armazenando inteiros de 0 a 19 no arquivo
	
	int *nums = new int[10];
	int *nums2 = new int[10];
	
	arqv.seekg(0); // Posicionando o ponteiro no come�o do arquivo
	for ( unsigned int i = 0; i < 10; i++)
		arqv >> nums[i];					// Passando o conte�do do arquivo para arrays
	for ( unsigned int i = 0; i < 10; i++)
		arqv >> nums2[i];
	cout << "nums: ";
	for ( unsigned int i = 0; i < 10; i++)
		cout << nums[i] << ' ';
	cout << "\nnums2: ";
	for ( unsigned int i = 0; i < 10; i++)
		cout << nums2[i] << ' ';
	/*
	Sa�da:
	nums: 0 1 2 3 4 5 6 7 8 9
	nums2: 10 11 12 13 14 15 16 17 18 19
	*/
	
	return 0;
}
