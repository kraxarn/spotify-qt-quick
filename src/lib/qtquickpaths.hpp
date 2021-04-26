#pragma once

#include "lib/paths/paths.hpp"

#include <QObject>
#include <QStandardPaths>

class QtQuickPaths: public QObject, public lib::paths
{
public:
	explicit QtQuickPaths(QObject *parent);

	auto config_file() const -> ghc::filesystem::path override;
	auto cache() const -> ghc::filesystem::path override;

private:
	ghc::filesystem::path configFile;
	ghc::filesystem::path cachePath;
};
