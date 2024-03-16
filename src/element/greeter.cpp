#include "greeter.hpp"

#include <QDateTime>

auto Greeter::getMessage() -> QString
{
	const auto now = QDateTime::currentDateTime();
	const auto hour = now.time().hour();

	constexpr auto morningStart = 6;
	constexpr auto afternoonStart = 12;
	constexpr auto eveningStart = 18;

	if (hour >= morningStart && hour < afternoonStart)
	{
		return QStringLiteral("Good morning!");
	}

	if (hour < eveningStart)
	{
		return QStringLiteral("Good afternoon!");
	}

	return QStringLiteral("Good evening!");
}
