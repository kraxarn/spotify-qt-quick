import Model.Home

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ListView {
	id: libraryList
	anchors.fill: parent

	model: HomeModel {}

	delegate: ItemDelegate {
		padding: 32

		anchors {
			left: parent.left
			right: parent.right
		}

		RowLayout {
			anchors {
				fill: parent
				leftMargin: 24
				rightMargin: 24
			}

			Image {
				source: model.icon ? icSrc(model.icon) : ""
				visible: !!model.icon
				Layout.rightMargin: 12
			}

			Label {
				text: model.text
				font.pointSize: model.title ? 22 : 16
				Layout.alignment: Qt.AlignVCenter
				Layout.fillWidth: true
			}

			Image {
				source: model.iconType === 1 ? icSrc("expand_more")
					: model.iconType === 2 ? icSrc("chevron_right")
					: ""
				visible: model.iconType > 0
				rotation: model.iconType === 1 ? 180 : 0
			}
		}
	}
}