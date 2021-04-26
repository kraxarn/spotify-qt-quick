#include "qtquickpaths.hpp"

QtQuickPaths::QtQuickPaths(QObject *parent)
	: QObject(parent)
{
	configFile = QString("%1.json").arg(QStandardPaths::writableLocation
		(QStandardPaths::AppConfigLocation)).toStdString();

	cachePath = QStandardPaths::writableLocation
		(QStandardPaths::CacheLocation).toStdString();
}

auto QtQuickPaths::config_file() const -> std::string
{
	return configFile;
}

auto QtQuickPaths::cache() const -> std::string
{
	return cachePath;
}
