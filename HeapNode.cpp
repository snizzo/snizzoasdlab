
#include "HeapNode.hpp"
#include <iostream>

HeapNode::HeapNode()
{
	this->data = 0;
	this->right = NULL;
	this->left = NULL;
	this->parent = NULL;
}

void HeapNode::set_data(int n)
{
	this->data = n;
}

int HeapNode::get_data()
{
	return this->data;
}

HeapNode * HeapNode::get_left()
{
	return this->left;
}

HeapNode * HeapNode::get_right()
{
	return this->right;
}

void HeapNode::set_left(HeapNode * n)
{
	this->left = n;
}

void HeapNode::set_right(HeapNode * n)
{
	this->right = n;
}
