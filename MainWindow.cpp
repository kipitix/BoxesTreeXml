#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include <QMessageBox>

#include "Application.h"


#include "TreeDrawer.h"
#include "GraphicsSceneTreeElementDrawer.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
	, _graphicsScene{ new QGraphicsScene{ this } }
{
	ui->setupUi(this);

	ui->graphicsView->setScene(_graphicsScene);

	connect(ui->pushButtonParseAndDraw, &QPushButton::pressed,[this]()
	{
		QString error;
		if (!qApp->parseDataFile(ui->lineEditXmlFilePath->text(), &error))
		{
			QMessageBox::critical(this, tr("Parse Error"), error);
			return;
		}
	
		_graphicsScene->clear();
		TreeDrawer treeDrawer{ new GraphhicsSceneTreeElementDrawer{ _graphicsScene } };
		treeDrawer.drawTree(qApp->treeModelRootItem().data());
	});
}



MainWindow::~MainWindow()
{
	delete ui;
}

