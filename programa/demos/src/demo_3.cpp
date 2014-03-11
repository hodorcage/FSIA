#include "demo_3.hpp"

bool Demo_3::prepare()
{

	
	frameTime = 0;
	win.create(sf::VideoMode::getDesktopMode(), "DEMO 3", sf::Style::Fullscreen);
	win.setFramerateLimit(60);
	win.setVerticalSyncEnabled(true);
	scoreRect = car.shape.getLocalBounds();
	car.shape.setOrigin(scoreRect.left + scoreRect.width / 2.f, scoreRect.top + 		scoreRect.height / 2.f);

    	return true;
}

void Demo_3::run()
{
	//Cargar imatge
	sf::Texture car_t;
	sf::Texture background;
	sf::Sprite circuit;
	
	circuit.setScale(float(win.getSize().x / 640.f) , float(win.getSize().y / 400.f));
	
	if(!car_t.loadFromFile("car2.png"))
		std::cout << "Error could not load car image" << std::endl;
	

	if(!background.loadFromFile("circuit.png"))
		std::cout << "Error could not load circuit image" << std::endl;
	circuit.setTexture(background);
	sf::Image image = background.copyToImage();
	
	auto old = car_t.getSize();
	
	//car.shape.setScale((old.x / 5.f) / old.x, (old.y /5.f) / (old.y));
	car.shape.setTexture(&car_t);
	
	while(win.isOpen())
	{
		while(win.pollEvent(eve))
		{
			switch(eve.type)
			{
				case sf::Event::Closed:
					win.close();
					break;
				case sf::Event::KeyPressed:
					switch(eve.key.code)
					{
						case sf::Keyboard::Escape:
							win.close();
							break;
						default:
							break;
					}
					break;
				default:
					break;
				
			}
		}
		
	
		float angle2 = car.shape.getRotation()*3.14/180;
		
		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			car.shape.setRotation(car.shape.getRotation()+2);
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			car.shape.setRotation(car.shape.getRotation()-2);
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			sf::Vector2f final2(cos(angle2) * 4.f, sin(angle2) * 4.f);
			car.shape.move(final2);
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			sf::Vector2f final2(-cos(angle2) * 2.f, -sin(angle2) * 2.f);
			car.shape.move(final2);
		}
				win.clear(sf::Color(20, 20, 20));
		}
		
		sf::Vector2f posicio = car.shape.getPosition();
		sf::Color color = image.getPixel(posicio.x,posicio.y);
		if (color == sf::Color::White)
		{
		car.shape.setPosition(10.f,10.f);
		}
		
		win.draw(circuit);
		win.draw(car.shape);
		win.display();
}

