#include "lib/qtquickpaths.hpp"

QtQuickPaths::QtQuickPaths(QObject *parent)
	: QObject(parent)
{
	configFile = QString("%1.json")
		.arg(QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation))
		.toStdString();

	cachePath = QStandardPaths::writableLocation(QStandardPaths::CacheLocation)
		.toStdString();
}

auto QtQuickPaths::config_file() const -> ghc::filesystem::path
{
	return configFile;
}

auto QtQuickPaths::cache() const -> ghc::filesystem::path
{
	return cachePath;
}
