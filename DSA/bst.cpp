#include "bst.hpp"
#include<iostream>
#include<Windows.h>

bst::bst() {
	root = NULL;
}


Node* bst::Insert(Node* q, int key) {
	Node* t = NULL;
	if (q == NULL) {
		t = new Node;
		t->data = key;
		t->rchild = t->lchild = NULL;
		return t;
	}
	if (key >= q->data) {
		q->rchild = bst::Insert(q->rchild, key);
	}
	if (key < q->data) {
		q->lchild = bst::Insert(q->lchild, key);
	}
	return q;

}


Node* bst::getRoot() {
	return root;
}

void bst::setRoot(Node* q) {
	root = q;
}


void bst::draw(Node* q, sf::RenderWindow& window) {
	if (q) {
		window.draw(q->line);
		window.draw(q->node);
		window.draw(q->text);

		draw(q->lchild, window);
		draw(q->rchild, window);
	}
}

Node* bst::FindMin(Node* p) {
	if (p == NULL)
		return NULL;
	else if (p->lchild == NULL)
		return p;
	else
		return bst::FindMin(p->lchild);
}

Node* bst::Delete(int key, Node* p) {
	Node* q;
	if (p == NULL) {
		return NULL;
	}
	else if (key < p->data)
		p->lchild = bst::Delete(key, p->lchild);
	else if (key > p->data)
		p->rchild = bst::Delete(key, p->rchild);
	else if (p->lchild && p->rchild) {
		q = bst::FindMin(p->rchild);
		p->data = q->data;
		p->rchild = bst::Delete(p->data, p->rchild);
	}
	else {
		q = p;
		if (p->lchild == NULL)
			p = p->rchild;
		else if (p->rchild == NULL)
			p = p->lchild;
		delete q;
	}
	return p;

}

void bst::setPoints(Node* q, int dist) {
	if (q) {
		if (q == root) {
			q->node.setPosition(400, 140);
			q->text.setPosition(418, 160);
			q->text.setString(std::to_string(q->data));
		}

		for (int i = 0; i < 3; i++) {
			q->line[i].color = sf::Color::Black;
			q->line[i].position = (sf::Vector2f(q->node.getPosition().x + q->node.getRadius(), q->node.getPosition().y + q->node.getRadius()));

		}

		if (q->lchild) {
			(q->lchild)->node.setPosition(sf::Vector2f(q->node.getPosition().x - dist, q->node.getPosition().y + 100));
			(q->lchild)->text.setPosition(sf::Vector2f(q->node.getPosition().x + 18 - dist, q->node.getPosition().y + 100 + 20));
			q->lchild->text.setString(std::to_string(q->lchild->data));
			q->line[0].position = (sf::Vector2f(q->lchild->node.getPosition().x + q->lchild->node.getRadius(), q->lchild->node.getPosition().y + q->lchild->node.getRadius()));
			q->line[0].color = sf::Color::Black;
			setPoints(q->lchild, dist / 2);
		}

		if (q->rchild) {
			(q->rchild)->node.setPosition(sf::Vector2f(q->node.getPosition().x + dist, q->node.getPosition().y + 100));
			(q->rchild)->text.setPosition(sf::Vector2f(q->node.getPosition().x + dist + 18, q->node.getPosition().y + 100 + 20));
			q->rchild->text.setString(std::to_string(q->rchild->data));
			q->line[2].position = (sf::Vector2f(q->rchild->node.getPosition().x + q->rchild->node.getRadius(), q->rchild->node.getPosition().y + q->rchild->node.getRadius()));
			q->line[2].color = sf::Color::Black;
			setPoints(q->rchild, dist / 2);
		}
	}
}

Node* bst::Search(int key, Node* q) {
	if (q == NULL)
		return q;
	else if (q->data == key)
		return q;
	else if (key < q->data)
		return Search(key, q->lchild);
	else if (key > q->data)
		return Search(key, q->rchild);
	return NULL;
}

void bst::setspcolor(Node* t, bool& value, sf::Clock& clock) {
	if (t && value == false) {
		t->node.setFillColor(sf::Color::Yellow);
		value = true;
		clock.restart();
	}
}

void bst::setbackcolor(Node* t, bool& value) {
	t->node.setFillColor(sf::Color::Green);
	value = false;
}
