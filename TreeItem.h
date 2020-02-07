#pragma once

#include <vector>
#include <string>



class TreeItem
{
public:
	TreeItem();

	virtual ~TreeItem();

	void addChild(TreeItem *child);
	std::vector<TreeItem *> children() const;

	void setText(const std::string &text);
	std::string text() const;

	void setX(int x);
	int x() const;

	void setY(int y);
	int y() const;

	void setWidth(int width);
	int width() const;

	void setHeight(int height);
	int height() const;

	void setWidthWithChildren(int width);
	int widthWithChildren() const;
	
	void setHeightWithChildren(int height);
	int heightWithChildren() const;


private:
	std::vector<TreeItem *> _children;

	std::string _text;

	int _x{ 0 };
	int _y{ 0 };
	int _width{ 0 };
	int _height{ 0 };
	int _widthWithChildren{ 0 };
	int _heightWithChildren{ 0 };
};
