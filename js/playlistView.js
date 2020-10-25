const loadPlaylists = () => {
	spotify.playlists.forEach(playlist => {
		listModel.append({
			"id": playlist.id,
			"name": playlist.name,
		})
	})
}

const loadPlaylist = id => {
	trackList.enabled = false

	let tracks = spotify.getPlaylistTracks(id)
	trackListModel.clear()

	tracks.forEach(track => trackListModel.append({
		"id": track["id"],
		"artist": track["artist"],
		"track": track["name"],
		"artistId": track["artist_id"],
		"albumId": track["album_id"]
	}))

	trackList.enabled = true
	root.currentContext = `spotify:playlist:${id}`
}

const clickedPlaylist = model => {
	drawer.close()
	loadPlaylist(model.id)
}