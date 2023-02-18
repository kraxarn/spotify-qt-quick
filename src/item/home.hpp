#pragma once

#include <QString>

namespace Item
{
	class Home
	{
	public:
		enum IconType
		{
			None,
			Expand,
			Navigate,
		};

		Home(const QString &text, const QString &icon,
			IconType iconType = IconType::None, bool title = false);

		QString text;
		QString icon;
		bool title;
		IconType iconType;
	};
}
