import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material

Rectangle {
	id: navigationBar
	width: parent.width
	height: 80 + 12 + 16

	gradient: Gradient {
		GradientStop {
			position: 0.0
			color: "#00000000"
		}
		GradientStop {
			position: 1.0
			color: "#211F26"
		}
	}

	NowPlaying {
	}

	MainNavigationBar {
	}
}
