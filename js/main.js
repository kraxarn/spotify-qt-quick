
const playbackChanged = () => {
	let playback = spotify.playback
	let item = playback["item"]

	if (!playback["is_playing"] && playback["item"]["name"] === "(no name)") {
		toolBar.currentArtist.text = null
		toolBar.currentTrack.text = "No media playing"
		footer.playPause.icon.name = "media-playback-start"
		return
	}

	toolBar.currentArtist.text = item["artist"]
	toolBar.currentTrack.text = item["name"]
	toolBar.currentAlbum.source = item["image"]
	currentTrackId = item["id"]

	footer.playPause.icon.name = `media-playback-${playback["is_playing"] ? "pause" : "start"}`
	footer.progress.to = item["duration"]
	footer.progress.value = playback["progress_ms"]
	footer.position.text = utils.formatTime(playback["progress_ms"])
	footer.duration.text = utils.formatTime(item["duration"])

	footer.shuffle.checked = playback["shuffle"]
	footer.repeat.checked = playback["repeat"] !== "off"
}

/**
 * @param {number} index
 */
const playTrack = index => {
	let status = spotify.playTracksWithContext(index, root.currentContext)
	if (status) {
		console.log(status)
	} else {
		spotify.requestPlayback()
	}
}

/**
 * @param {Array<Track>} tracks
 */
const loadTracks = tracks => {
	trackListModel.clear()
	let i = 0
	tracks.forEach(track => trackListModel.append({
		"id": track.id,
		"artist": track.artist,
		"track": track.name,
		"artistId": track.artist_id,
		"albumId": track.album_id,
		"index": i++
	}))
}

/**
 * @param {string} id
 */
const loadArtist = id => {
	drawer.close()
	artistDrawer.load(spotify.getArtist(id))
}