#pragma once


#include "TreeElementDrawer.h"
#include "TreeItem.h"


class TreeDrawer
{
public:
	TreeDrawer(TreeElementDrawer *drawer);

	virtual ~TreeDrawer();
	
	void drawTree(TreeItem *item);

private:
	TreeElementDrawer *_drawer{ nullptr };
};
