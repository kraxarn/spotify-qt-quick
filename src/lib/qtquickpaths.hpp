#pragma once

#include "lib/paths/paths.hpp"

#include <QObject>
#include <QStandardPaths>

class QtQuickPaths: public QObject, public lib::paths
{
public:
	explicit QtQuickPaths(QObject *parent);

	auto config_file() const -> std::string override;
	auto cache() const -> std::string override;

private:
	std::string configFile;
	std::string cachePath;
};
