/**
 * @type {Array<Object>}
 */
let pageData = []

/**
 * @param {number} count
 * @returns {string}
 */
const formatFollowers = count => {
	if (count > 1_000_000) {
		return `${Math.round(count / 1_000_000)}M`
	}
	if (count > 1_000) {
		return `${Math.round(count / 1_000)}k`
	}
	return count.toString()
}


/**
 * @param {Artist} data
 */
const load = data => {
	tabsInfo.currentIndex = 0
	banner.source = data.image
	artistName.text = data.name
	artistInfo.text = data.genres.join(", ")
	followArtist.text = formatFollowers(data.followers)

	let pages = spotify.getArtistPages(data.id)
	pageData = [
		pages.popular, pages.albums, pages.singles, pages.related
	]

	tabChanged()
	rootArtist.open()
}

/**
 * @param {string} id
 * @returns void
 */
const clickedItem = id => {
	switch (tabsInfo.currentIndex) {
		case 0:
			spotify.playTrack(id)
			break
		case 1:
		case 2:
			root.loadTracks(spotify.getAlbumTracks(id), `spotify:album:${id}`)
			rootArtist.close()
			break
		case 3:
			root.loadArtist(id)
			break
	}
}

/**
 * @returns void
 */
const tabChanged = () => {
	artistListModel.clear()
	pageData[tabsInfo.currentIndex].forEach(item => {
		artistListModel.append({
			"id": item.id,
			"text": item.name
		})
	})
}