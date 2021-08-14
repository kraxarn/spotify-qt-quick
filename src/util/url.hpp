#pragma once

#include <QString>
#include <QObject>
#include <QDesktopServices>
#include <QUrl>
#include <QVariant>

class Url
{
public:
	static void open(const QString &url, QObject *parent);

private:
	Url() = default;
};
