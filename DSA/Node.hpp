#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
class Node
{
public:
	Node();
	int data;
	int height;
	Node* lchild, * rchild;
	sf::CircleShape node;
	sf::VertexArray line;
	sf::Text text;
	sf::Font font;
};

