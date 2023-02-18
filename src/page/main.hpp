#pragma once

#include <QObject>
#include <QtQml/qqmlregistration.h>

namespace Page
{
	class Main: public QObject
	{
	Q_OBJECT

		QML_ELEMENT

	public:
		explicit Main(QObject *parent);
	};
}