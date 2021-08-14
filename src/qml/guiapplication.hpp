#pragma once

#include "common.hpp"

#include <QGuiApplication>
#include <QClipboard>

namespace Qml
{
	class GuiApplication: public QObject
	{
	Q_OBJECT
		QML_ELEMENT

		Q_INVOKABLE void setClipboardText(const QString &text);

	public:
		explicit GuiApplication(QObject *parent = nullptr);
	};
}
