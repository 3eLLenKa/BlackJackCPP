#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <ctime>

using namespace std;

void play(vector<int> cards) {

	int p1, p2;
	int countP1 = 0, countP2 = 0, cardTMP = 0;
	char tmp;

	while (true)
	{
		while (true)
		{
			cout << "Ходит 1 игрок" << endl;
			cout << endl;
			cout << "Возьмите карту (1 - 32): ";
			cin >> p1;
			countP1 += cards[p1];
			replace(cards.begin(), cards.end(), cards[p1 - 1], 0);
			cout << "Брать ещё одну карту? (y/n): ";
			cin >> tmp;
			if (tmp == 'y' && cardTMP < 3)
			{
				cardTMP += 1;
				continue;
			}
			if (tmp == 'n')
			{
				break;
			}
			if (cardTMP >= 3)
			{
				cout << "Лимит карт привышен!" << endl;
				break;
			}
		}

		while (true)
		{
			cout << "Ходит 2 игрок" << endl;
			cout << endl;
			cout << "Возьмите карту (1 - 32): ";
			cin >> p2;
			countP1 += cards[p2];
			replace(cards.begin(), cards.end(), cards[p2 - 1], 0);
			cout << "Брать ещё одну карту? (y/n): ";
			cin >> tmp;
			if (tmp == 'y' && cardTMP < 3)
			{
				cardTMP += 1;
				continue;
			}
			if (tmp == 'n')
			{
				break;
			}
			if (cardTMP >= 3)
			{
				cout << "Лимит карт привышен!" << endl;
				break;
			}
		}
		if (countP1 == 21)
		{
			cout << "Победил игрок 1" << endl;
			cout << "Очков: " << countP1;
			break;

		}
		if (countP2 == 21)
		{
			cout << "Победил игрок 2" << endl;
			cout << "Очков: " << countP2;
			break;
		}
		if (countP1 > 21)
		{
			cout << "Игрок 1 проиграл" << endl;
			cout << "Очков: " << countP1;
			break;
		}
		if (countP2 > 21)
		{
			cout << "Игрок 2 проиграл" << endl;
			cout << "Очков: " << countP2;
			break;
		}
		else continue;
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	vector<int> cards;

	cards.resize(36);

	for (int i = 0; i < cards.size(); i++)
	{
		cards[i] = 2 + rand() % 10;
	}

	for (int i = 0; i < cards.size(); i++)
	{
		cout << cards[i] << "  ";
	}

	random_shuffle(cards.begin(), cards.end());

	play(cards);

}