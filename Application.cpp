#include "Application.h"


#include "ApplicationPrivate.h"



/* Application */

Application::Application(int &argc, char *argv[])
	: QApplication(argc, argv)
	, _impl{ new ApplicationPrivate() }
{
	//connect(_impl, &ApplicationPrivate::connectionStateChanged, this, &Application::connectionStateChanged);
	
//	connect(_impl, &ApplicationPrivate::topicReceived, this, &Application::topicReceived);
//	connect(_impl, &ApplicationPrivate::responseReceived, this, &Application::responseReceived);
}



Application::~Application()
{
	if (_impl)
	{
		delete _impl;
		_impl = nullptr;
	}
}



bool Application::parseDataFile(const QString &filePath, QString *error)
{
	return _impl->parseDataFile(filePath, error);
}
