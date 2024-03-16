#pragma once

#include <QObject>
#include <qqmlintegration.h>

class Greeter: public QObject
{
	Q_OBJECT
	QML_ELEMENT

	Q_PROPERTY(QString message READ getMessage NOTIFY messageChanged)

public:
	[[nodiscard]]
	static auto getMessage() -> QString;

signals:
	void messageChanged();
};
