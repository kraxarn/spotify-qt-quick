#include "qml/guiapplication.hpp"

Qml::GuiApplication::GuiApplication(QObject *parent)
	: QObject(parent)
{
}

void Qml::GuiApplication::setClipboardText(const QString &text)
{
	QGuiApplication::clipboard()->setText(text);
}
