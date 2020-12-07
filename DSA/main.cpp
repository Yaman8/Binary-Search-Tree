#include<iostream>
#include<SFML/Graphics.hpp>
#include"bst.hpp"
#include"GUI.hpp"
#include"Node.hpp"
using namespace std;

int main() {
	sf::RenderWindow window(sf::VideoMode(1366, 768), "Binary Search Tree Visualization", sf::Style::Fullscreen);
	sf::View view(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));
	view.setCenter(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
	sf::Clock clock;
	bool search = false;

	bst tree;
	GUI gui;
	//gui.setTitle(window);
	Node* t = NULL;
	string str = "";

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.text.unicode >= 26 && event.text.unicode <= 35) {
					char temp = event.text.unicode + 22;
					str += temp;
					(gui.text).setString(str);
				}
				else if (event.key.code == sf::Keyboard::Escape) {
					window.close();
				}
				else if (event.text.unicode == 59) {
					str.pop_back();
					gui.text.setString(str);
				}
				switch (event.key.code) {
				case sf::Keyboard::Right:
					view.move(sf::Vector2f(-4.0f, 0.0f));
					break;
				case sf::Keyboard::Left:
					view.move(sf::Vector2f(4.0f, 0.0f));
					break;
				case sf::Keyboard::Down:
					view.move(sf::Vector2f(0.0f, -4.0f));
					break;
				case sf::Keyboard::Up:
					view.move(sf::Vector2f(0.0f, 4.0f));
					break;
				case sf::Keyboard::I:
					view.zoom(0.99f);
					break;
				case sf::Keyboard::O:
					view.zoom(1.01f);
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}
			if (sf::Mouse::isButtonPressed((sf::Mouse::Left))) {
				if (gui.button[0].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) && str.empty() == false) {
					if (tree.getRoot() == NULL)
						tree.setRoot(tree.Insert(tree.getRoot(), atoi(str.c_str())));
					else
						tree.Insert(tree.getRoot(), atoi(str.c_str()));
					str.clear();
					gui.text.setString(str);
				}
				if (gui.button[1].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) && str.empty() == false) {
					tree.Delete(atoi(str.c_str()), tree.getRoot());
					str.clear();
					gui.text.setString(str);
				}
				if (gui.button[2].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) && str.empty() == false) {
					if (!search) {
						t = tree.Search(atoi(str.c_str()), tree.getRoot());
						tree.setspcolor(t, search, clock);
					}
					str.clear();
					gui.text.setString(str);
				}
			}

		}
		if (search == true) {
			if (clock.getElapsedTime().asMilliseconds() > 1000) {
				tree.setbackcolor(t, search);
			}
		}
		window.clear(sf::Color(210, 105, 30));
		window.setView(view);
		tree.setPoints(tree.getRoot(), 250);
		tree.draw(tree.getRoot(), window);
		window.setView(window.getDefaultView());
		gui.display(window);
		window.display();
	}
	return 0;
}