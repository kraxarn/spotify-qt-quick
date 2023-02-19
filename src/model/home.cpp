#include "model/home.hpp"

#include "lib/qtquickpaths.hpp"
#include "lib/cache/jsoncache.hpp"

#include <QQmlApplicationEngine>

Model::Home::Home(QObject *parent)
	: QAbstractListModel(parent)
{
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
	return libraryItemCount + static_cast<int>(playlists.count());
}

auto Model::Home::data(const QModelIndex &index, int role) const -> QVariant
{
	const auto &item = index.row() < libraryItemCount
		? libraryItem(index.row())
		: playlistItem(index.row());

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

auto Model::Home::libraryItem(int index) -> Item::Home
{
	switch (index)
	{
		case 0:
			return {QStringLiteral("Library"), {}, Item::Home::IconType::Expand, true};

		case 1:
			return {QStringLiteral("History"), QStringLiteral("history")};

		case 2:
			return {QStringLiteral("Liked tracks"), QStringLiteral("audiotrack")};

		case 3:
			return {QStringLiteral("Top tracks"), QStringLiteral("trending_up")};

		case 4:
			return {QStringLiteral("New releases"), QStringLiteral("new_releases")};

		case 5:
			return {QStringLiteral("Liked albums"), QStringLiteral("album"),
				Item::Home::IconType::Navigate};

		case 6:
			return {QStringLiteral("Top artists"), QStringLiteral("timeline"),
				Item::Home::IconType::Navigate};

		case 7:
			return {QStringLiteral("Followed artists"), QStringLiteral("people"),
				Item::Home::IconType::Navigate};

		default:
			return {{}, {}};
	}
}

auto Model::Home::playlistItem(int index) const -> Item::Home
{
	return playlists.at(index - libraryItemCount);
}

auto Model::Home::canFetchMore(const QModelIndex &/*parent*/) const -> bool
{
	return playlists.empty();
}

void Model::Home::fetchMore(const QModelIndex &parent)
{
	// TODO: I don't like this solution, but it works
	const QtQuickPaths paths;
	const lib::json_cache cache(paths);
	const auto cachedPlaylists = cache.get_playlists();

	beginInsertRows(parent, libraryItemCount,
		libraryItemCount + static_cast<int>(cachedPlaylists.size()));

	playlists.push_back({QStringLiteral("Playlists"), {}, Item::Home::IconType::Expand, true});

	for (const auto &playlist: cachedPlaylists)
	{
		playlists.push_back({QString::fromStdString(playlist.name), {}});
	}

	endInsertRows();
}