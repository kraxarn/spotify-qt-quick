import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material

Row {
	id: navBar
	height: 80
	spacing: 8
	anchors {
		horizontalCenter: parent.horizontalCenter
		top: parent.top
		topMargin: 12
	}

	property int currentIndex: 0

	Repeater {
		model: [
			{
				label: "Home",
				icon: "home",
				index: 0,
			},
			{
				label: "Search",
				icon: "search",
				index: 1,
			},
			{
				label: "Library",
				icon: "library_music",
				index: 2,
			},
		]

		Item {
			width: root.width / 3.5
			height: parent.height

			property bool active: {
				return modelData.index === navBar.currentIndex
			}

			ColumnLayout {
				spacing: 4
				anchors.centerIn: parent

				Rectangle {
					width: 64
					height: 32
					radius: 16
					color: active ? "#4A4458" : "#00000000"
					Layout.alignment: Qt.AlignCenter

					Image {
						height: 24
						width: 24
						source: icSrc(modelData.icon)
						anchors.centerIn: parent
					}
				}


				Label {
					text: modelData.label
					font.weight: active ? 700 : 500
					Layout.alignment: Qt.AlignCenter
				}
			}


			MouseArea {
				anchors.fill: parent
				onClicked: {
					if (navBar.currentIndex === modelData.index) {
						return
					}
					navBar.currentIndex = modelData.index
					switch (navBar.currentIndex) {
						case 0:
							content.replace(homePage)
							break
						case 1:
							content.replace(searchPage)
							break
						case 2:
							content.replace(libraryPage)
							break
					}
				}
			}
		}
	}
}