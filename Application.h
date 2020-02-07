#pragma once

#include <QApplication>

#include "TreeItem.h"

class Application;
#ifdef qApp
#undef qApp
#endif
#define qApp static_cast<Application *>(QApplication::instance())


class ApplicationPrivate;

class Application
	: public QApplication
{
	Q_OBJECT

public:
	Application(int &argc, char *argv[]);
	virtual ~Application();

	bool parseDataFile(const QString &filePath, QString *error);

	QSharedPointer<TreeItem> treeModelRootItem() const;

signals:


public slots:

private slots:

private:
	ApplicationPrivate *_impl;

};

