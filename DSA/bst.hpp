#pragma once
#include"Node.hpp"
#include<iostream>
#include<SFML/Graphics.hpp>
class bst
{
private:
	Node* root;

public:
	bst();
	Node* Insert(Node*, int);
	Node* Delete(int key, Node*);
	Node* FindMin(Node*);
	void setRoot(Node*);
	Node* getRoot();
	void draw(Node*, sf::RenderWindow&);
	void setPoints(Node*, int);
	void setbackcolor(Node*, bool&);
	Node* Search(int, Node*);
	void setspcolor(Node*, bool&, sf::Clock&);
};

