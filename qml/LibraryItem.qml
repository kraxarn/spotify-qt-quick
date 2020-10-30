import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Material 2.12

ColumnLayout {
	id: itemLayout
	width: parent.width

	property var itemModel

	readonly property var expandButton: expandButton
	readonly property var subList: subList
	readonly property var subListModel: subListModel

	readonly property var foregroundColor: expandButton.icon.name === "collapse" ? Material.accent : undefined

	Button {
		Layout.fillWidth: true
		Layout.preferredHeight: listItemHeight * 1.25
		flat: true

		onClicked: libraryList.itemClicked(itemLayout)

		Label {
			anchors {
				verticalCenter: parent.verticalCenter
				left: parent.left
				leftMargin: 16
			}
			text: itemModel.name
			Material.foreground: foregroundColor
		}

		ToolButton {
			id: expandButton
			anchors {
				verticalCenter: parent.verticalCenter
				right: parent.right
				rightMargin: 16
			}
			icon.name: "expand"
			flat: true
			visible: itemModel.expandable
		}
	}

	ColumnLayout {
		id: subList
		visible: false
		Layout.fillWidth: true
		Layout.preferredHeight: listItemHeight * subListModel.count

		BusyIndicator {
			Layout.fillWidth: true
			visible: subListModel.count <= 0
		}

		ListView {
			id: subListView
			Layout.leftMargin: 16
			Layout.fillWidth: true
			Layout.fillHeight: true

			model: ListModel {
				id: subListModel
			}
			delegate: Component {
				Button {
					flat: true
					text: model.text
					width: subList.width - 32
					onClicked: libraryList.subListItemClicked(model.parentId, model.id)
				}
			}
		}
	}
}