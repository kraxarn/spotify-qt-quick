
const togglePlayPause = () =>
	spotify.playing = playPause.icon.name === "media-playback-start"

const toggleShuffle = () =>
	spotify.shuffle = shuffle.checked

const toggleRepeat = () =>
	spotify.repeat = repeat.checked

const goPrevious = () =>
	spotify.previous()

const goNext = () =>
	spotify.next()