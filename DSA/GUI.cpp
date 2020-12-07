#include "GUI.hpp"
#include<cstring>
#include<iostream>
GUI::GUI() {
	init();
}

void GUI::init() {
	font.loadFromFile("unispace.ttf");

	for (int i = 0; i < 3; i++) {
		static float k = 300.0f;
		button[i].setFillColor(sf::Color(153, 50, 204));
		button[i].setOutlineColor(sf::Color::Black);
		button[i].setOutlineThickness(2);
		button[i].setSize(sf::Vector2f(140.0f, 51.0f));
		button[i].setPosition(sf::Vector2f(k, 50.0f));
		k += 200.0f;

		std::string disp[3] = { "Insert","Delete","Search" };
		button_text[i].setCharacterSize(19);
		button_text[i].setPosition(sf::Vector2f(button[i].getPosition().x + 24, button[i].getPosition().y + 15));
		button_text[i].setString(disp[i]);
		button_text[i].setFillColor(sf::Color::Black);
		button_text[i].setFont(font);
	}

	rect.setFillColor(sf::Color::White);
	rect.setSize(sf::Vector2f(140.0f, 40.0f));
	rect.setPosition(sf::Vector2f(110.0f, 50.0f));
	text.setCharacterSize(19);
	text.setFont(font);
	text.setFillColor(sf::Color::Black);
	text.setPosition(sf::Vector2f(rect.getPosition().x + 4, rect.getPosition().y + 10));


	msg.setCharacterSize(13);
	msg.setFont(font);
	msg.setString("NUMBER:");
	msg.setFillColor(sf::Color::Black);
	msg.setPosition(sf::Vector2f(rect.getPosition().x, rect.getPosition().y - 25));

}

//void GUI::setTitle(sf::RenderWindow& window) {
//	title.setCharacterSize(40);
//	title.setOutlineColor(sf::Color::Black);
//	title.setOutlineThickness(2);
//	title.setPosition(sf::Vector2f(window.getSize().x * 3 / 9, window.getSize().y * 1 / 29));
//	title.setFont(font);
//	title.setString("BST Tree");
//	title.setFillColor(sf::Color::Blue);
//}

void GUI::display(sf::RenderWindow& window) {
	for (int i = 0; i < 3; i++) {
		window.draw(button[i]);
		window.draw(button_text[i]);

	}
	window.draw(msg);
	window.draw(rect);
	window.draw(title);
	window.draw(text);
}