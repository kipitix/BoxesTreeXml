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



void TreeComposer::composeTree(TreeItem * item, ParentPosition parentPosition) const
{
	composeTreeRecursive(item, 0, 0, parentPosition);
}



void TreeComposer::composeTreeRecursive(TreeItem *item, int x, int y, ParentPosition parentPosition) const
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
			composeTreeRecursive(childItem, x, y + _boxHeight + _boxVerticalMargin, parentPosition);

			totalChildrenWidth = childItem->widthWithChildren();

			firstChild = false;
		}
		else
		{
			composeTreeRecursive(childItem, x + totalChildrenWidth + _boxHorizontalMargin, y + _boxHeight + _boxVerticalMargin, parentPosition);

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

	if (parentPosition == ParentPosition::MiddleChildWidth)
	{
		auto x = item->x();
		const auto childrenList = item->children();
		const auto childCount = childrenList.size();
		if (childCount > 0)
		{
			if (childCount % 2 == 0) // Even
			{
				const auto lastItemIndex = childCount / 2;
				const auto firstItemIndex = lastItemIndex - 1;

				x = (childrenList[lastItemIndex]->x() + childrenList[firstItemIndex]->x()) / 2;
			}
			else // Odd
			{
				const auto middleItemIndex = childCount / 2;

				x = childrenList[middleItemIndex]->x();
			}

			item->setX(x);
		}
	}
	else if (parentPosition == ParentPosition::AverageChildWidth)
	{
		item->setX(item->x() + item->widthWithChildren() / 2);
	}
}
