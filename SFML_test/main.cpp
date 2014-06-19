#include <string>
#include <SFML\Graphics.hpp>
#include <SFML\System\Clock.hpp>

#include "Player.h"
#include "Configuration.h"

const std::string IMAGE_PATH_MAN1 = "c:\\dev\\images\\man1.png";
const std::string IMAGE_PATH_MAN2 = "c:\\dev\\images\\man2.png";
const std::string IMAGE_PATH_MAN3 = "c:\\dev\\images\\man3.png";
const std::string IMAGE_PATH_MAN4 = "c:\\dev\\images\\man4.png";

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int MAX_IMAGES = 4;
const float MAXIMUM_VELOCITY = 4.0f;
const float accel = 0.6f;

const float FRAME_RATE = 1/20.0f;

int main()
{
	std::string filename = "c:\\dev\\test.cfg";
	Configuration c( &filename );



	sf::Clock clock;
	sf::Time time1 = clock.getElapsedTime();
	sf::Time time2;
	sf::Time animTimer = time1;

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "My Game Window");
	window.setFramerateLimit(60);

	Player player;
	float destX = 0.0f, destY = 0.0f;
	float posX = 0.0f, posY = 0.0f;
	float angle = 0.0f;
	float vi = 0.0f, vf = 1.0f, tvf = vf;
	float dt = 0.0f;
	sf::Texture t1, t2, t3, t4;
	player.AddSprite(IMAGE_PATH_MAN1, &t1);
	player.AddSprite(IMAGE_PATH_MAN2, &t2);
	player.AddSprite(IMAGE_PATH_MAN3, &t3);
	player.AddSprite(IMAGE_PATH_MAN4, &t4);

	int currentImageIndex = 0;
	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if ( event.type == sf::Event::MouseButtonPressed )
			{
				switch ( event.mouseButton.button )
				{
					case sf::Mouse::Left:
						break;
					default:
						break;
				}
			}

			if ( event.type == sf::Event::KeyPressed )
			{
				switch ( event.key.code )
				{
					case sf::Keyboard::Escape:
						window.close();
						break;
					case sf::Keyboard::Left:
						posX -= MAXIMUM_VELOCITY;
						if ( posX < 0.0f )
						{
							posX = WINDOW_WIDTH;
						}
						break;
					case sf::Keyboard::Right:
						posX += MAXIMUM_VELOCITY;
						if ( posX > WINDOW_WIDTH )
						{
							posX = 0.0;
						}
						break;
					case sf::Keyboard::Up:
						posY -= MAXIMUM_VELOCITY;
						if ( posY < 0.0f )
						{
							posY = WINDOW_HEIGHT;
						}
						break;
					case sf::Keyboard::Down:
						posY += MAXIMUM_VELOCITY;
						if ( posY > WINDOW_HEIGHT )
						{
							posY = 0.0f;
						}
						break;
					default:
						break;
				}
			}
		}

		time2 = clock.getElapsedTime();
		dt = time2.asSeconds() - time1.asSeconds();
		posX = ( vi * dt ) + ( 0.5 * accel * powf( dt, 2 ));
		tvf = vf;
		vf = vi + ( accel * dt );
		vi = tvf;

		if ( time2.asSeconds() - animTimer.asSeconds() >= FRAME_RATE * 2 )
		{
			currentImageIndex = player.GetCurrentSpriteIndex();
			currentImageIndex++;
			if ( currentImageIndex > ( MAX_IMAGES - 1 ))
			{
				player.SetCurrentSpriteIndex( 0 );
			}
			else
			{
				player.SetCurrentSpriteIndex( currentImageIndex );
			}
			animTimer = time2;
		}

		if ( posX > WINDOW_WIDTH )
		{
			posX = 0.0f;
			vi = 0.0f;
			vf = 1.0f;
			time1 = time2;
		}

		player.SetPosition( posX, posY );

		if ( (int)dt % 2 == 0 )
		{
			printf("t=%f d=(%f, %f) vi=%f vf=%f\r\n", dt, posX, posY, vi, vf);
		}

		window.clear();
		window.draw( player.GetCurrentSprite() );
		window.display();
	}

	return 0;
}
