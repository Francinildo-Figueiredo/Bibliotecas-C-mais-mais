#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <fstream>
using std::fstream;
using std::ios;

#include <locale>

class Pessoa{
	private:
		char nome[50];
		char cpf[20];
		short int idade;
		double altura;
	public:
		void novoRegistro();
		void imprimirRegistro();
};

void Pessoa::novoRegistro()
{
	cout << "Nome: ";
	cin.get(nome, 50);
	cout << "CPF: ";
	cin.ignore();
	cin.get(cpf, 20);
	cout << "Idade: ";
	cin >> idade;
	cout << "Altura: ";
	cin >> altura;
}

void Pessoa::imprimirRegistro()
{
	cout << "Nome: " << nome
		<< "\nCPF: " << cpf
		<< "\nIdade: " << idade
		<< "\nAltura: " << altura << endl;
}

int main()
{
	setlocale( LC_ALL, "portuguese" );
	
	fstream file; // Arquivo para entrada e saída dos dados
	Pessoa pessoa; // Objeto da classe pessoa
	file.open("Registro.txt", ios::ate | ios::out | ios::in ); // Abrindo o arquivo para leitura e escrita apartir do final
	if(!file.is_open())
		cout << "O arquivo não foi aberto!" << endl;
	
	char aux = 's';
	while( aux == 's')
	{
		pessoa.novoRegistro();
		file.write((char *)&pessoa, sizeof(Pessoa)); // Gravando os registro
		cout << "Adicionar outro registro?(s/n): ";
		cin >> aux;
		cin.ignore();
		system("cls");
	}
	
	file.seekg(0); // Posicionando o ponteiro no início do arquivo
	int i = 0;
	while(file.read((char *)&pessoa, sizeof(Pessoa))) // Lendo o arquivo e passando o registro para o objeto
	{
		i++;
		cout << "\n" << i << "º Registro:\n";
		pessoa.imprimirRegistro();
	}
	file.close(); // Fechando arquivo
		
	return 0;
}
