#include <iostream>
#include <ctime>
#include <string>
#include <cstring>

using namespace std;

unsigned long int seeder = time(NULL);

int length = 0;

char random_char()
{
	srand (seeder);

	char random = (rand() % 93) + 33;
	
	seeder = seeder + ((rand() % 10) - 20);

	return random;
};

string gen_passwd()
{
	string output;

	for (int i = 0; i < length; i++) 
	{		
		output.push_back(random_char());
	};

	return output;
}

string include_num()
{
	srand (seeder);

	string temp = gen_passwd();

	temp.pop_back();

	temp.push_back((rand() % 10) + 48);

	return temp;
}



int main(int argc, char** argv)
{
	if (argc > 1) // argument handler
	{
		for (int i = 1; i < argc; i++)
		{
			if ( strncmp( argv[i], "-l", 2) == 0 ) // compares string in argv1 to -l, if equal 0 then argv1 = -l
			{
				length = atoi(argv[i+1]);
			}

			if ( strncmp( argv[i], "-n", 2) == 0 ) // MUST include numbers // if -n is first, disregards -l // FIX THAT
			{
				if (length == 0)
				{
					cout << "Enter password length: ";
					cin >> length;
					cout << "\n";
				}
			
				cout << "Password: " << include_num() << "\n";
				return 0;
			}
		}
	}

	if (length == 0)
	{
		cout << "Enter password length: ";
		cin >> length;
		cout << "\n";
	}

	cout << "Password: " << gen_passwd() << "\n";

	return 0;

};
