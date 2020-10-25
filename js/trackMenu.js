const newAction = (name, id) =>
	Qt.createQmlObject(`import QtQuick.Controls 2.12; Action{text: "${name}"; 
	onTriggered: addToPlaylist("${id}")}`, playlistMenu)

const getPlaylists = () => {
	let playlists = spotify.playlists
	playlists.forEach(playlist =>
		playlistMenu.addAction(newAction(playlist.name, playlist.id)))
	playlistMenu.open()
}

const addToPlaylist = playlistId =>
	spotify.addToPlaylist(playlistId, `spotify:track:${trackId}`)