#pragma once

#include "lib/settings.hpp"

#include "common.hpp"
#include "lib/qtquickpaths.hpp"

namespace Qml
{
	class Settings: public QObject
	{
	Q_OBJECT
		QML_ELEMENT

	public:
		explicit Settings(QObject *parent = nullptr);

		auto get() -> lib::settings &;
		auto getConst() const -> const lib::settings &;

	private:
		QtQuickPaths paths;
		lib::settings settings;
	};
}
