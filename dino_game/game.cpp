#include "game.h"

void Game::zmienne()
{
	this->window = nullptr;
	this->enemySpawnTimerMax = 300;
	this->skok = false;
	this->enemySpawnTimer = 200;
	this->wrogvelocity = 1;
	this->time = 0.f;
	this->gravity = 0.2f;
	this->jumpStrength = -8.0f;
	this->dinoYVelocity = 0.0f;
	this->wrogacceleration = 0.2;
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
	elapsed_time = AnimationClock.restart().asSeconds();
}

void Game::SpawnWrog()
{
	int x;
	x = rand() % 2;
	switch (x)
	{
	case 1:
		wrogowie.push_back(std::make_unique<Arrow>());
		break;
	default:
		wrogowie.push_back(std::make_unique<Creeper>());
		break;
	}
}

void Game::UpdateWrog()
{
	Time dttime = clock.restart();
	float dt = dttime.asSeconds();
	time += dt;

	//increasing velocity
	if ((wrogvelocity = +wrogacceleration * time * 0.4) >= 3)
		wrogvelocity = +wrogacceleration * time * 0.4;
	else
		wrogvelocity = 3;

	//decreseing distance between object to ehnance iteration
	this->enemySpawnT =this->enemySpawnTimerMax - int(time);
	
	
	if (this->enemySpawnTimer >= this->enemySpawnT)
	{
		
		this->SpawnWrog();
		this->enemySpawnTimer = 0.f;
	}
	else
		this->enemySpawnTimer += 1.f;

	//
	for (auto& e : this->wrogowie)
	{
		e->move(sf::Vector2f(-wrogvelocity,0.f));
	}

	//Delete useless object
	if (!wrogowie.empty() && (wrogowie[0]->getPosition()).x<-60)
	{
		wrogowie.erase(wrogowie.begin());
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
	pl.Update(elapsed_time);

}

void Game::RenderWrog()
{
	for (auto& e : this->wrogowie)
	{
		e->draw(*this->window);
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

	this->pl.draw(*window);

	this->window->draw(ludzik);

	this->window->display();
}

void Game::defludzik()
{
	this->ludzik.setFillColor(Color::Black);
	this->ludzik.setSize(Vector2f(50.f,90.f));
	this->ludzik.setPosition(200.f, this->window->getSize().y - this->ludzik.getSize().y-31);
}

