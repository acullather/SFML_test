#include <SFML\Graphics.hpp>

#ifndef CPLAYER
#define CPLAYER
#endif

class Player
{
public:
	Player();
	~Player();

	void AddSprite( std::string filename, sf::Texture* texture );
	void AddSprite( sf::Sprite sprite );
	void Dispose( void );
	sf::Sprite GetCurrentSprite( void );
	int	GetCurrentSpriteIndex( void );
	void SetCurrentSpriteIndex( int index );
	void SetDestination( float x, float y );
	void SetPosition( float x, float y );
	void SetRotation( float angle );
	void RemoveSprite( int index );
	void RemoveSprite( std::string filename );

private:
	float m_posX;
	float m_posY;
	float m_destX;
	float m_destY;

	int	 m_currentSpriteIndex;
	sf::Vector2f m_velocity;
	
	sf::Image m_image;
	sf::Texture	m_texture;
	sf::Sprite	m_currentSprite;
	std::vector<sf::Sprite> m_spriteArray;
	std::vector<sf::Texture> m_textureArray;
};

