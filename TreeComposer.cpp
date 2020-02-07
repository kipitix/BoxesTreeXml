#include "TreeItem.h"
#include "TreeComposer.h"



TreeComposer::TreeComposer(int boxWidth, int boxHeight, int boxHorizontalMargin, int boxVerticalMargin)
	: _boxWidth{ boxWidth }
	, _boxHeight{ boxHeight }
	, _boxHorizontalMargin{ boxHorizontalMargin }
	, _boxVerticalMargin{ boxVerticalMargin }
{
}



TreeComposer::~TreeComposer()
{
}



void TreeComposer::composeTree(TreeItem *item) const
{
	composeTreeRecursive(item, 0, 0);
}



void TreeComposer::composeTreeRecursive(TreeItem *item, int x, int y) const
{
	item->setX(x);
	item->setY(y);
	item->setWidth(_boxWidth);
	item->setHeight(_boxHeight);
	item->setWidthWithChildren(_boxWidth);
	item->setHeightWithChildren(_boxHeight);

	bool firstChild{ true };
	int totalChildrenWidth{ 0 };
	int maxChildHeight{ 0 };
	for (auto childItem : item->children())
	{
		if (firstChild)
		{
			composeTreeRecursive(childItem, x, y + _boxVerticalMargin);
		
			totalChildrenWidth = childItem->widthWithChildren();

			firstChild = false;
		}
		else
		{
			composeTreeRecursive(childItem, x + item->widthWithChildren() + _boxHorizontalMargin, y + _boxVerticalMargin);
			
			totalChildrenWidth += _boxHorizontalMargin + childItem->widthWithChildren();
		}

		if (childItem->heightWithChildren() > maxChildHeight)
		{
			maxChildHeight = childItem->heightWithChildren();
		}
	}

	if (totalChildrenWidth > item->widthWithChildren())
	{
		item->setWidthWithChildren(totalChildrenWidth);
	}

	item->setHeightWithChildren(item->height() + _boxVerticalMargin + maxChildHeight);
}
