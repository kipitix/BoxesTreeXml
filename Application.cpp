#include "Application.h"


#include "ApplicationPrivate.h"


/* Application */

Application::Application(int &argc, char *argv[])
	: QApplication(argc, argv)
	, _impl{ new ApplicationPrivate() }
{
}



Application::~Application()
{
	if (_impl)
	{
		delete _impl;
		_impl = nullptr;
	}
}



bool Application::parseDataFile(const QString &filePath, TreeComposer::ParentPosition parentPosition, QString *error)
{
	return _impl->parseDataFile(filePath, parentPosition, error);
}




QSharedPointer<TreeItem> Application::treeModelRootItem() const
{
	return _impl->_treeModelRootItem;
}
