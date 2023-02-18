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

	private:
		QList<Item::Home> items;

		static auto getLibraryItems() -> QList<Item::Home>;
		auto getPlaylistItems() -> QList<Item::Home>;
	};
}