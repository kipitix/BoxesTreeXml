#include "TreeDrawer.h"




TreeDrawer::TreeDrawer(TreeElementDrawer *drawer)
	: _drawer{ drawer }
{
}



TreeDrawer::~TreeDrawer()
{
	if (_drawer)
	{
		delete _drawer;
	}
}



void TreeDrawer::drawTree(TreeItem *item)
{
	_drawer->addRectangle(item->x(), item->y(), item->width(), item->height());
	_drawer->addText(item->x(), item->y(), item->text());

	for (auto child : item->children())
	{
		drawTree(child);

		// Draw connector
		{
			// int
			// int verticalDistance =
			// _drawer->addLine(item->x() + item->width() / 2, item->y() + item->height(), );

		}
	}
}
