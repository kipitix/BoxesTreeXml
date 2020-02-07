#pragma once

// qt
#include <QObject>
#include <QSharedPointer>
#include <QDomComment>

#include "TreeItem.h"
#include "TreeComposer.h"

class ApplicationPrivate
	: public QObject
{
	Q_OBJECT

public:
	
	/* Members */

	QSharedPointer<TreeItem> _treeModelRootItem;
	TreeComposer _treeComposer;


	/* Methods */

	ApplicationPrivate();
	virtual ~ApplicationPrivate();

	bool parseDataFile(const QString &filePath, QString *error);

signals:

public slots:


private slots:

private:
	TreeItem *handleDomElement(const QDomElement &element);
};
