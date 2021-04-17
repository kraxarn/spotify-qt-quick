/**
 * @namespace spotify
 * @property {Array} playlists
 * @property {Object} playback
 * @property {boolean} playing
 * @property {boolean} shuffle
 * @property {boolean} repeat
 * @property {number} position
 * @property {Array<Track>} recentlyPlayed
 * @property {Array<Track>} savedTracks
 * @property {Array<Track>} topTracks
 * @property {Array<Album>} savedAlbums
 * @property {Array} topArtists
 * @property {Array} followedArtists
 */

/**
 * @function getPlaylistTracks
 * @memberOf spotify
 * @param {string} playlistId
 * @returns Array<Track>
 */

/**
 * @function getAlbumTracks
 * @memberOf spotify
 * @param {string} albumId
 * @returns Array<Track>
 */

/**
 * @function playTracksWithContext
 * @memberOf spotify
 * @param {number} trackIndex
 * @param {string} context
 * @returns string
 */

/**
 * @function playTrack
 * @memberOf spotify
 * @param {string} track
 * @returns string
 */

/**
 * @function addToPlaylist
 * @memberOf spotify
 * @param {string} playlistId
 * @param {string} trackId
 * @returns string
 */

/**
 * @function removeFromPlaylist
 * @memberOf spotify
 * @param {string} playlistId
 * @param {string} trackId
 * @returns string
 */

/**
 * @function previous
 * @memberOf spotify
 * @returns string
 */

/**
 * @function next
 * @memberOf spotify
 * @returns string
 */

/**
 * @function requestPlayback
 * @memberOf spotify
 */

/**
 * @function systemInfo
 * @memberOf spotify
 * @returns string
 */

/**
 * @function search
 * @memberOf spotify
 * @param {string} query
 * @returns Object
 */

/**
 * @function getArtist
 * @memberOf spotify
 * @param {string} id
 * @returns Object
 */

/**
 * @typedef ArtistPages
 * @property {Object} popular
 * @property {Object} albums
 * @property {Object} singles
 * @property {Object} related
 */

/**
 * @function getArtistPages
 * @memberOf spotify
 * @param {string} id
 * @returns ArtistPages
 */

/**
 * @function isSavedTrack
 * @memberOf spotify
 * @param {string} trackId
 * @returns boolean
 */

/**
 * @function setSavedTrack
 * @memberOf spotify
 * @param {string} trackId
 * @param {boolean} saved
 * @returns string
 */

/**
 * @function addToQueue
 * @memberOf spotify
 * @param {string} trackId
 * @returns string
 */