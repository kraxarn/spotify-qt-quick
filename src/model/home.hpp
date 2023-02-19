#pragma once

#include "item/home.hpp"

#include <QAbstractListModel>

namespace Model
{
	class Home: public QAbstractListModel
	{
	Q_OBJECT

	public:
		enum class ItemRole
		{
			Text = Qt::UserRole + 1,
			Icon,
			Title,
			IconType,
		};

		explicit Home(QObject *parent = nullptr);

		[[nodiscard]] auto rowCount(const QModelIndex &parent) const -> int override;
		[[nodiscard]] auto data(const QModelIndex &index, int role) const -> QVariant override;
		[[nodiscard]] auto roleNames() const -> QHash<int, QByteArray> override;
		[[nodiscard]] auto canFetchMore(const QModelIndex &parent) const -> bool override;
		void fetchMore(const QModelIndex &parent) override;

	private:
		constexpr static int libraryItemCount = 8;

		QList<Item::Home> playlists;

		[[nodiscard]] static auto libraryItem(int index) -> Item::Home;
		[[nodiscard]] auto playlistItem(int index) const -> Item::Home;
	};
}