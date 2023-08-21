#include "CEnemies.h"


void CEnemies::wyborwrog1()
{
	int x;
	x = rand() % 2;
	switch (x)
	{
	case 1:
		std::cout << x;
		this->wrog.setSize(Vector2f(50.f, 70.f));
		break;
	default:
		std::cout << x;
		this->wrog.setSize(Vector2f(30.f, 30.f));
		break;
	}
}

CEnemies::CEnemies()
{

}

void CEnemies::UpdateWrog1()
{


}
