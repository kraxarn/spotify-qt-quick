import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import "/js/logOutDialog.js" as JS

Dialog {
	title: "Are you sure?"
	modal: true
	anchors.centerIn: parent
	footer: DialogButtonBox {
		Button {
			text: "Clear everything"
			flat: true
			DialogButtonBox.buttonRole: DialogButtonBox.AcceptRole
			onClicked: JS.logOut("clearAll")
		}
		Button {
			text: "Only log out"
			flat: true
			DialogButtonBox.buttonRole: DialogButtonBox.AcceptRole
			onClicked: JS.logOut("logOut")
		}
		Button {
			text: "Cancel"
			flat: true
			DialogButtonBox.buttonRole: DialogButtonBox.RejectRole
		}
	}
	Label {
		text: "Do you also want to clear your application credentials or only log out?"
	}
}