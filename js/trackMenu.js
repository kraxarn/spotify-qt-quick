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

const getIsLiked = () => {
	const isSaved = spotify.isSavedTrack(trackId)
	like.text = isSaved ? "Dislike" : "Like"
	like.icon.name = `${isSaved ? "non-" : ""}starred-symbolic`
	like.enabled = true
}

const setIsLiked = () =>
	spotify.setSavedTrack(trackId, like.text === "Like")