#pragma once

#include <QApplication>

class Application;
#ifdef qApp
#undef qApp
#endif
#define qApp static_cast<Application *>(QApplication::instance())


class ApplicationPrivate;


#include "TreeItem.h"
#include "TreeComposer.h"


class Application
	: public QApplication
{
	Q_OBJECT

public:
	Application(int &argc, char *argv[]);
	virtual ~Application();

	bool parseDataFile(const QString &filePath, TreeComposer::ParentPosition parentPosition, QString *error);

	QSharedPointer<TreeItem> treeModelRootItem() const;

signals:


public slots:

private slots:

private:
	ApplicationPrivate *_impl;

};

