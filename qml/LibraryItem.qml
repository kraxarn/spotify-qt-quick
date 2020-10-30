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
			Material.foreground: foregroundColor
		}
	}

	ColumnLayout {
		id: subList
		visible: false
		Layout.fillWidth: true

		Label {
			Layout.leftMargin: 16
			text: "items"
		}
	}
}