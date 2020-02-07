#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include <QMessageBox>

#include "Application.h"


MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);


	connect(ui->pushButtonParseAndDraw, &QPushButton::pressed,[this]()
	{
		QString error;
		if (!qApp->parseDataFile(ui->lineEditXmlFilePath->text(), &error))
		{
			QMessageBox::critical(this, tr("Parse Error"), error);
		}
	});
}



MainWindow::~MainWindow()
{
	delete ui;
}

