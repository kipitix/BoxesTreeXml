#include "GraphicsSceneTreeElementDrawer.h"


#include <QGraphicsTextItem>


GraphhicsSceneTreeElementDrawer::GraphhicsSceneTreeElementDrawer(QGraphicsScene * graphicsScene)
	: _graphicsScene{ graphicsScene }
{
}



GraphhicsSceneTreeElementDrawer::~GraphhicsSceneTreeElementDrawer()
{
}



void GraphhicsSceneTreeElementDrawer::addRectangle(int x, int y, int width, int height)
{
	_graphicsScene->addRect(x, y, width, height);
}



void GraphhicsSceneTreeElementDrawer::addText(int x, int y, std::string text)
{
	auto item = _graphicsScene->addText(QString::fromStdString(text));
	item->setX(x);
	item->setY(y);
}



void GraphhicsSceneTreeElementDrawer::addLine(int x1, int y1, int x2, int y2)
{
	_graphicsScene->addLine(x1, y1, x2, y2);
}
