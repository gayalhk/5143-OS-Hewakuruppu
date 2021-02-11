#include <iostream>
#include <fstream>
#include <cstdlib>

int main()
{
	ifstream file; 
	char word[250];
	
	file.open("characters.txt");
	if (!file.is_open())
	{
		exit(EXIT_FAILURE);
	}
	
	
	int counter = 0;
	while (counter < 10 && file.good() )
	{
		file.getline(word, 250);
		counter++;
		cout << word << endl;
	}
	
	if (counter < 10)
	{
		cout << "\nThe entire file was read.\n";
	}
	
	cout << "We read " << counter << " lines today.\n";
		
	cout << "Press enter to exit.\n";
	cin.get(word, 250);
	
	return 0;
	
}
