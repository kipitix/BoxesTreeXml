#include "TreeItem.h"




TreeItem::TreeItem()
{
}



TreeItem::~TreeItem()
{
	for (auto item : _children)
	{
		delete  item;
	}
}



void TreeItem::addChild(TreeItem *child)
{
	_children.push_back(child);
}



std::vector<TreeItem *> TreeItem::children() const
{
	return _children;
}



void TreeItem::setText(const std::string &text)
{
	_text = text;
}



std::string TreeItem::text() const
{
	return _text;
}



void TreeItem::setX(int x)
{
	_x = x;
}



int TreeItem::x() const
{
	return _x;
}



void TreeItem::setY(int y)
{
	_y = y;
}



int TreeItem::y() const
{
	return _y;
}



void TreeItem::setWidth(int width)
{
	_width = width;
}



int TreeItem::width() const
{
	return _width;
}



void TreeItem::setHeight(int height)
{
	_height = height;
}



int TreeItem::height() const
{
	return _height;
}



void TreeItem::setWidthWithChildren(int width)
{
	_widthWithChildren = width;
}



int TreeItem::widthWithChildren() const
{
	return _widthWithChildren;
}



void TreeItem::setHeightWithChildren(int height)
{
	_heightWithChildren = height;
}



int TreeItem::heightWithChildren() const
{
	return _heightWithChildren;
}
