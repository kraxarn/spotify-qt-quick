#include "model/home.hpp"

Model::Home::Home(QObject *parent)
	: QAbstractListModel(parent)
{
	items.append(getLibraryItems());
	items.append(getPlaylistItems());
}

auto Model::Home::roleNames() const -> QHash<int, QByteArray>
{
	QHash<int, QByteArray> names;

	names[static_cast<int>(ItemRole::Text)] = "text";
	names[static_cast<int>(ItemRole::Icon)] = "icon";
	names[static_cast<int>(ItemRole::Title)] = "title";
	names[static_cast<int>(ItemRole::IconType)] = "iconType";

	return names;
}

auto Model::Home::rowCount(const QModelIndex &/*parent*/) const -> int
{
	return static_cast<int>(items.count());
}

auto Model::Home::data(const QModelIndex &index, int role) const -> QVariant
{
	const auto &item = items.at(index.row());

	switch (static_cast<ItemRole>(role))
	{
		case ItemRole::Text:
			return item.text;

		case ItemRole::Icon:
			return item.icon;

		case ItemRole::Title:
			return item.title;

		case ItemRole::IconType:
			return static_cast<int>(item.iconType);
	}
}

auto Model::Home::getLibraryItems() -> QList<Item::Home>
{
	return {
		Item::Home(QStringLiteral("Library"), {}, Item::Home::IconType::Expand, true),
		Item::Home(QStringLiteral("History"), QStringLiteral("history")),
		Item::Home(QStringLiteral("Liked tracks"), QStringLiteral("audiotrack")),
		Item::Home(QStringLiteral("Top tracks"), QStringLiteral("trending_up")),
		Item::Home(QStringLiteral("New releases"), QStringLiteral("new_releases")),
		Item::Home(QStringLiteral("Liked albums"), QStringLiteral("album"),
			Item::Home::IconType::Navigate),
		Item::Home(QStringLiteral("Top artists"), QStringLiteral("timeline"),
			Item::Home::IconType::Navigate),
		Item::Home(QStringLiteral("Followed artists"), QStringLiteral("people"),
			Item::Home::IconType::Navigate),
	};
}

auto Model::Home::getPlaylistItems() -> QList<Item::Home>
{
	QList<Item::Home> playlists{
		Item::Home(QStringLiteral("Playlists"), {}, Item::Home::IconType::Expand, true),
	};

	return playlists;
}
