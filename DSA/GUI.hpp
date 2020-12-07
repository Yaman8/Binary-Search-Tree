#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
class GUI
{
private:
	sf::RectangleShape rect;
	sf::Text button_text[3];
	sf::Text msg;
	sf::Text title;
	sf::Font font;
public:
	GUI();
	sf::Text text;
	sf::RectangleShape button[3];
	void init();
	void display(sf::RenderWindow&);
	//void setTitle(sf::RenderWindow&);
};

