#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <iostream>
using std::ostream;

#include <locale>

// Sobrecarregando o operador de saída <<, para que possa imprimir o vector entre conchetes e separado por vírgulas.
template<typename T>
ostream& operator<<(ostream& s, const vector<T> v) 
{
   	s.put('[');
   	char virgula[3] = { '\0', ' ', '\0'};
   	for ( int e : v) {
       	s << virgula << e;
       	virgula[0] = ',';
   	}
   	return s << ']';
}

typedef vector<int> intVector;

int main()
{
	setlocale( LC_ALL, "portuguese" );
	
	// Construindo um vector vazio.
	intVector numbers1();
	cout << "numbers1: " << numbers1 << endl;
	
	// Construindo um vector com valores específicos.
	intVector numbers2 { 1, 2, 3, 4, 5};
	cout << "numbers2: " << numbers2 << endl;
	
	// Construindo um vector com os valores de outro vector do primeiro ao último.
	intVector numbers3( numbers2.begin(), numbers2.end());
	cout << "numbers3: " << numbers3 << endl;
	
	// Construindo um vector apartir dos valores de outro.
	intVector numbers4( numbers3 );
	cout << "numbers4: " << numbers4 << endl;
	
	return 0;
}
