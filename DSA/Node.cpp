#include "Node.hpp"
#include<SFML/Graphics.hpp>

Node::Node() {
	node.setFillColor(sf::Color::Green);
	node.setRadius(32.0f);
	node.setPosition(sf::Vector2f(200.0f, 200.0f));
	font.loadFromFile("unispace.ttf");
	text.setFont(font);
	text.setFillColor(sf::Color::Red);
	text.setCharacterSize(18);
	line.setPrimitiveType(sf::LinesStrip);
	line.resize(3);
}