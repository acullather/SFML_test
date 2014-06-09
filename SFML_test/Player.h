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
	void			AddSprite(sf::Sprite sprite);
	void SetPosition( float x, float y );
	void SetRotation( float angle );
	void			Dispose( void );
	sf::Sprite		GetCurrentSprite( void );
	int				GetCurrentSpriteIndex( void );
	void			SetCurrentSpriteIndex( int index );
	void			RemoveSprite( int index );
	void			RemoveSprite( std::string filename );

private:
	float						m_posX;
	float						m_posY;
	int						m_currentSpriteIndex;
	
	sf::Image				m_image;
	sf::Texture				m_texture;
	sf::Sprite				m_currentSprite;
	std::vector<sf::Sprite> m_spriteArray;
	std::vector<sf::Texture> m_textureArray;
};

