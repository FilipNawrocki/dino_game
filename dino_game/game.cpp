#include "game.h"

void Game::zmienne()
{
	this->window = nullptr;
	this->enemySpawnTimerMax = 350;
	this->skok = false;

}

void Game::okno()
{

	this->window = new RenderWindow(VideoMode(800, 600), "dino_game", Style::Titlebar | Style::Close);
	
	this->window->setFramerateLimit(60);
}


Game::Game()
{
	this->texture.loadFromFile("y27zIvC.png");
	this->sprite.setTexture(texture);
	this->sprite.setTextureRect(sf::IntRect(0, 57, 600, 11));
	this->sprite.setScale(sf::Vector2f(3, 3));
	this->sprite.setPosition(sf::Vector2f(0.f, 567.f));
	
	this->zmienne();
	this->okno();
	this->wrogowie();
	this->defludzik();
}

Game::~Game()
{
	delete this->window;
}

const bool Game::getWindowIsOpen() const
{
	return this->window->isOpen();
}

void Game::choicewrog()
{
	

	int x;
	x = rand() % 2;
	switch (x)
	{
	case 1:
		//std::cout << x;
		this->wrog.setSize(Vector2f(50.f, 70.f));
		break;
	default:
		//std::cout << x;
		this->wrog.setSize(Vector2f(30.f, 30.f));
		break;
	}

}

void Game::pullevents()
{
	
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case Event::Closed:
			this->window->close();
			break;
		case Event::KeyPressed:
			if (ev.key.code == Keyboard::Escape)
				this->window->close();
			if (ev.key.code == Keyboard::Space && !skok)
			{
				this->skok = true;
				dinoYVelocity = jumpStrength;
			}
			break;

		}

	}
}

void Game::SpawnWrog()
{
	this->wrog.setPosition(this->window->getSize().x, this->window->getSize().y - this->wrog.getSize().y);
	//std::cout << "aaaa" << std::endl;
	int x;
	x = rand() % 2;
	switch (x)
	{
	case 1:
		wrogowie1.push_back(std::make_unique<Arrow>());
		break;
	default:
		wrogowie1.push_back(std::make_unique<Creeper>());
		break;
	}

	this->wrogow.push_back(this->wrog);
}

void Game::UpdateWrog()
{
	choicewrog();
	Time dttime = clock.restart();
	float dt = dttime.asSeconds();
	time += dt;

	wrogvelocity =+wrogacceleration * time*0.5;
	this->enemySpawnT =this->enemySpawnTimerMax - int(time*0.3);
	
	//std::cout <<"-" << enemySpawnT << " "<< int(time * 0.4)<<"- ";
	
	
	
	if (this->enemySpawnTimer >= this->enemySpawnT)
	{
		
		this->SpawnWrog();
		this->enemySpawnTimer = 0.f;
	}
	else
		this->enemySpawnTimer += 1.f;

	for (auto& e : this->wrogow)
	{
		e.move(-wrogvelocity, 0.f);
	}

}

void Game::UpdateLudz()
{
	if (skok) {
		dinoYVelocity += gravity;
		ludzik.move(0, dinoYVelocity);

		if (ludzik.getPosition().y >= this->window->getSize().y - this->ludzik.getSize().y-31) {
			ludzik.setPosition(ludzik.getPosition().x, this->window->getSize().y - this->ludzik.getSize().y-31);
			skok = false;
		}
	}

}


void Game::Update()
{
	this->pullevents();
	this->UpdateWrog();
	this->UpdateLudz();

}

void Game::RenderWrog()
{
	for (auto& e : this->wrogow)
	{
		this->window->draw(e);
	}

}

void Game::Rendfloor()
{
	this->window->draw(sprite);
}

void Game::Render()
{
	this->window->clear(Color::Blue);
	this->Rendfloor();
	this->RenderWrog();

	this->window->draw(ludzik);

	this->window->display();
}

void Game::wrogowie()
{
	
	int x;
	x = rand() % 2;
	switch (x)
	{
	case 1:
		this->wrog.setSize(Vector2f(50.f, 70.f));
		break;
	default:
		this->wrog.setSize(Vector2f(30.f, 30.f));
		break;
	}
	
	this->wrog.setFillColor(Color::Cyan);

}

void Game::defludzik()
{
	this->ludzik.setFillColor(Color::Black);
	this->ludzik.setSize(Vector2f(50.f,90.f));
	this->ludzik.setPosition(200.f, this->window->getSize().y - this->ludzik.getSize().y-31);
}

