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

	int parentCenterX = item->x() + item->width() / 2;
	int parentBottomY = item->y() + item->height();

	for (auto child : item->children())
	{
		drawTree(child);

		// Draw connector
		{
			int	childCenterX = child->x() + child->width() / 2;
			int childTopY = child->y();
			
			int verticalDistance = childTopY - parentBottomY;
			
			_drawer->addLine(parentCenterX, parentBottomY, parentCenterX, parentBottomY + verticalDistance / 2);
			_drawer->addLine(childCenterX, childTopY, childCenterX, childTopY - verticalDistance / 2);

			_drawer->addLine(parentCenterX, parentBottomY + verticalDistance / 2, childCenterX, childTopY - verticalDistance / 2);
		}
	}
}
