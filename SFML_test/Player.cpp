#include <stdexcept>
#include "Player.h"

Player::Player()
{
	m_posX = m_posY = 0; 
	m_currentSpriteIndex = 0;
}

Player::~Player()
{
	this->Dispose();
}

void Player::AddSprite( std::string filename, sf::Texture* texture )
{
	m_image.loadFromFile( filename );
	m_image.createMaskFromColor( sf::Color(181, 230, 29, 255) );
	texture->loadFromImage( m_image );
	m_spriteArray.push_back( sf::Sprite( *texture ));
	m_currentSpriteIndex = m_spriteArray.size() - 1;
	m_currentSprite = m_spriteArray.at( m_currentSpriteIndex );
}

void Player::AddSprite( sf::Sprite sprite ) 
{
	m_spriteArray.push_back(sprite);
	m_currentSpriteIndex = m_spriteArray.size();
}

void Player::SetPosition( float x, float y )
{
	m_posX = x; m_posY = y;
	m_currentSprite.setPosition( sf::Vector2f( m_posX, m_posY ));
}

void Player::SetRotation( float angle )
{
	m_currentSprite.setRotation( angle );
}

void Player::Dispose( void )
{
	m_spriteArray.clear();
}

sf::Sprite Player::GetCurrentSprite( void )
{
	if ( m_currentSpriteIndex > (int)m_spriteArray.size() - 1 )
	{
		m_currentSpriteIndex = (int)m_spriteArray.size() - 1;
		m_currentSprite = m_spriteArray.at( m_currentSpriteIndex );
	}
	return m_currentSprite;
}

/*
Index property get/set
*/
int Player::GetCurrentSpriteIndex( void )
{
	return m_currentSpriteIndex;
}
void Player::SetCurrentSpriteIndex( int index )
{
	if ( index <= (int)m_spriteArray.size() )
	{
		m_currentSpriteIndex = index;
		m_currentSprite = m_spriteArray.at( m_currentSpriteIndex );
	}
}


void Player::RemoveSprite( int index )
{
	m_spriteArray.erase( m_spriteArray.begin() + index );
}

void Player::RemoveSprite(std::string filename)
{
	throw std::exception("Player::RemoveSprite(string) not implemented yet.");
}


