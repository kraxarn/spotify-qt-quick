import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Dialog {
	title: "Logged out"
	modal: true
	anchors.centerIn: parent
	standardButtons: Dialog.Ok
	onAccepted: Qt.quit()
	onRejected: Qt.quit()
	Label {
		text: "You are now logged out, the application will now close"
	}
}