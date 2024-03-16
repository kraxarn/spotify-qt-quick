import Model.Home
import Greeter

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material

ColumnLayout {
	Rectangle {
		width: root.width
		height: 32 + 16 + 16
		z: 1

		gradient: Gradient {
			GradientStop {
				position: 0.0
				color: "#211F26"
			}
			GradientStop {
				position: 1.0
				color: "#00000000"
			}
		}

		RowLayout {
			anchors.fill: parent
			spacing: 16

			Image {
				width: 32
				height: 32
				fillMode: Image.PreserveAspectCrop
				sourceSize.width: width
				sourceSize.height: height
				Layout.leftMargin: 16
			}

			Greeter {
				id: greeter
			}

			Label {
				text: greeter.message
				horizontalAlignment: Text.AlignLeft
				font.pixelSize: 24
				font.weight: 700
				Layout.fillWidth: true
			}
		}
	}

	ListView {
		id: libraryList
		Layout.fillHeight: true
		Layout.fillWidth: true

		model: HomeModel {
		}

		delegate: ItemDelegate {
			width: parent ? parent.width : 0
			padding: 32

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
}