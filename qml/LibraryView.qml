import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import "/js/LibraryView.js" as JS

ListView {
	id: libraryList
	model: listModel
	delegate: listDelegate
	Layout.fillHeight: true

	function itemClicked(item) {
		JS.itemClicked(item)
	}

	Component.onCompleted: JS.load()

	Component {
		id: listDelegate
		LibraryItem {
			itemModel: model
		}
	}

	ListModel {
		id: listModel
	}
}