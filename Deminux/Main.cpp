#include "Main.h"

int main()

{
	system("color 21");

	std::cout << "Bienvenue dans Deminux" << std::endl << std::endl << std::endl;
	std::cout << "Menu Principal :" << std::endl;
	std::cout << "1 - Lancer une partie" << std::endl;
	std::cout << "2 - Quitter Deminux" << std::endl << std::endl;

	int choix = 0;
	do
	{
		std::cout << "choix : ";
		std::cin >> choix;
		std::cin.ignore();
		//std::cout << choix;
	} while (choix <= 0 || choix >= 3);

	switch (choix)
	{
	case 1:
		lancerDeminux();
		break;
	case 2:
		std::cout << "le jeu va quitter dans 3...";
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << "2...";
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << "1...";
		std::this_thread::sleep_for(std::chrono::seconds(1));
		break;
	default:
		std::cout << "Error : 01";
		std::this_thread::sleep_for(std::chrono::seconds(3));
		break;
	}

	return 0;
}

void lancerDeminux()
{
	int tempR = 10;
	int score = 0;

	std::thread *first = new std::thread(deminux, &tempR, &score);
	std::thread *second = new std::thread(timer, &tempR);

	second->join();
	first->detach();

	std::cout << std::endl << "Vous avez perdu" << std::endl;
	std::cout << "Score : " << score << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(3));

	first = nullptr;
	second = nullptr;

	main();
}

bool timer(int *temps)
{
	while (*temps > 0)
	{
		//std::cout << *temps;
		if (*temps <= 10 && *temps > 6)
		{
			system("color 21");
		}
		else if (*temps <  7 && *temps > 3)
		{
			system("color EC");
		}
		else if (*temps < 4)
		{
			system("color C5");
		}

		std::this_thread::sleep_for(std::chrono::seconds(1));
		*temps = *temps - 1;
	}
	return true;
}

bool deminux(int *temp, int *score)
{
	std::string aleat = "a";
	std::string rep = "";
	bool Token = true;
	srand(time(NULL));
	do
	{
		std::cout << "Tape " << aleat << std::endl;
		std::getline(std::cin, rep);
		if (rep != aleat)
		{
			Token = false;
		}
		else
		{
			//std::cout << "Score : " << *score << std::endl;
			*score = *score + 1;
			//std::cout << "Score : " << *score << std::endl;
			*temp = 10;
			aleat = RandomString(aleat);
		}
	} while (Token);
	return false;
}
//char lettre = 97

std::string RandomString(std::string Precedent)
{
	char lettre;
	std::string aleat;
	int nbAleat;
	do
	{
		nbAleat = rand() % 89 + 33;
	} while (nbAleat > 90 && nbAleat < 97);
	//std::cout << nbAleat << std::endl;
	lettre = nbAleat;
	aleat = lettre;
	return aleat;
}