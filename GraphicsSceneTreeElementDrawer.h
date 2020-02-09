#pragma once

#include <QGraphicsScene>

#include "TreeElementDrawer.h"



class GraphhicsSceneTreeElementDrawer
	: public TreeElementDrawer
{
public:
	GraphhicsSceneTreeElementDrawer(QGraphicsScene *graphicsScene);

	virtual ~GraphhicsSceneTreeElementDrawer();
	
	virtual void addRectangle(int x, int y, int width, int height) override;
	virtual void addText(int x, int y, std::string text) override;
	virtual void addLine(int x1, int y1, int x2, int y2) override;

private:
	QGraphicsScene *_graphicsScene{ nullptr };
};
