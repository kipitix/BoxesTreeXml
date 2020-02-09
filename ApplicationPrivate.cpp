#include "ApplicationPrivate.h"


#include <QFile>
#include <QDomDocument>


const char *const ATTRIBUTE_TEXT_XML_KEY{ "name" };

const int DEFAULT_WIDTH{ 100 };
const int DEFAULT_HEIGHT{ 50 };
const int DEFAULT_H_MARGIN{ 50 };
const int DEFAULT_V_MARGIN{ 50 };

ApplicationPrivate::ApplicationPrivate()
	: QObject{ nullptr }
	, _treeComposer{ DEFAULT_WIDTH, DEFAULT_HEIGHT, DEFAULT_H_MARGIN, DEFAULT_V_MARGIN }
{
}



ApplicationPrivate::~ApplicationPrivate()
{

}



bool ApplicationPrivate::parseDataFile(const QString &filePath, TreeComposer::ParentPosition parentPosition, QString *error)
{
	/* Open File */
	QFile xmlFile{ filePath };
	if (!xmlFile.open(QFile::Text | QFile::ReadOnly))
	{
		if (error)
		{
			*error = tr("Can not open file %1").arg(filePath);
		}
		return  false;
	}

	/* Read XML */
	QDomDocument doc{};
	QString errorStr;
	int errorLine, errorColumn;
	if (!doc.setContent(xmlFile.readAll(), true, &errorStr, &errorLine, &errorColumn))
	{
		if (error)
		{
			*error = tr("Parse error at line %1, column %2:\n%3")
					.arg(errorLine)
					.arg(errorColumn)
					.arg(errorStr);
		}
		return false;
	}

	/* Build Tree */
	_treeModelRootItem = QSharedPointer<TreeItem>{ handleDomElement(doc.documentElement()) };

	/* Compose box positions */
	_treeComposer.composeTree(_treeModelRootItem.data(), parentPosition);

	return true;
}



TreeItem *ApplicationPrivate::handleDomElement(const QDomElement &element)
{
	auto result = new TreeItem{ };

	auto name = element.attribute(ATTRIBUTE_TEXT_XML_KEY);
	result->setText(name.toStdString());

	const auto list = element.childNodes();
	for (int i = 0; i < list.size(); i++)
	{
		auto child = list.at(i);
		if (!child.isElement())
		{
			continue;
		}

		result->addChild(handleDomElement(child.toElement()));
	}

	return result;
}
