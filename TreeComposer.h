#pragma once


#include "TreeItem.h"


class TreeComposer
{
public:
	enum class ParentPosition
	{
		MiddleChildWidth,
		AverageChildWidth,
	};

	TreeComposer(int boxWidth, int boxHeight, int boxHorizontalMargin, int boxVerticalMargin);

	virtual ~TreeComposer();

	void composeTree(TreeItem *item, ParentPosition parentPosition = ParentPosition::MiddleChildWidth) const;

private:
	int _boxWidth{ 0 };
	int _boxHeight{ 0 };
	int _boxHorizontalMargin{ 0 };
	int _boxVerticalMargin{ 0 };


	void composeTreeRecursive(TreeItem *item, int x, int y, ParentPosition parentPosition) const;
};
