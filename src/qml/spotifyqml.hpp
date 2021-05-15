#pragma once

#include "common.hpp"

class SpotifyQml: public QObject
{
Q_OBJECT
	Q_PROPERTY(QJsonArray playlists READ getPlaylists NOTIFY playlistsChanged)
	Q_PROPERTY(QJsonObject playback READ getPlayback NOTIFY playbackChanged)

	Q_PROPERTY(bool playing READ getPlaying WRITE setPlaying NOTIFY playingChanged)
	Q_PROPERTY(bool shuffle READ getShuffle WRITE setShuffle)
	Q_PROPERTY(bool repeat READ getRepeat WRITE setRepeat)
	Q_PROPERTY(int position READ getPosition WRITE setPosition)

	Q_PROPERTY(QJsonArray recentlyPlayed READ getRecentlyPlayed)
	Q_PROPERTY(QJsonArray savedTracks READ getSavedTracks)
	Q_PROPERTY(QJsonArray topTracks READ getTopTracks)
	Q_PROPERTY(QJsonArray savedAlbums READ getSavedAlbums)
	Q_PROPERTY(QJsonArray topArtists READ getTopArtists)
	Q_PROPERTY(QJsonArray followedArtists READ getFollowedArtists)

	QML_ELEMENT

public:
	explicit SpotifyQml(QObject *parent = nullptr);
	~SpotifyQml() override;

	auto getPlaylists() -> QJsonArray;
	auto getPlayback() -> QJsonObject;

	auto getPlaying() -> bool;
	void setPlaying(bool playing);

	auto getShuffle() -> bool;
	void setShuffle(bool shuffle);

	auto getRepeat() -> bool;
	void setRepeat(bool repeat);

	auto getPosition() -> int;
	void setPosition(int position);

	auto getRecentlyPlayed() const -> QJsonArray;
	auto getSavedTracks() const -> QJsonArray;
	auto getTopTracks() const -> QJsonArray;
	auto getSavedAlbums() const -> QJsonArray;
	auto getTopArtists() const -> QJsonArray;
	auto getFollowedArtists() const -> QJsonArray;

	// Get tracks
	Q_INVOKABLE auto getPlaylistTracks(const QString &playlistId) -> QJsonArray;
	Q_INVOKABLE auto getAlbumTracks(const QString &albumId) -> QJsonArray;

	// Play tracks
	Q_INVOKABLE auto playTracksWithContext(int trackIndex, const QString &context) -> QString;
	Q_INVOKABLE auto playTrack(const QString &track) -> QString;

	// Playlists
	Q_INVOKABLE auto addToPlaylist(const QString &playlistId, const QString &trackId) -> QString;
	Q_INVOKABLE auto removeFromPlaylist(const QString &playlistId, const QString &trackId) -> QString;

	// Playback control
	Q_INVOKABLE auto previous() -> QString;
	Q_INVOKABLE auto next() -> QString;

	// Other
	Q_INVOKABLE void requestPlayback();
	Q_INVOKABLE auto systemInfo() -> QString;
	Q_INVOKABLE auto search(const QString &query) -> QJsonObject;
	Q_INVOKABLE auto getArtist(const QString &id) -> QJsonObject;
	Q_INVOKABLE auto getArtistPages(const QString &id) -> QJsonObject;
	Q_INVOKABLE auto isSavedTrack(const QString &trackId) -> bool;
	Q_INVOKABLE auto setSavedTrack(const QString &trackId, bool saved) -> QString;
	Q_INVOKABLE auto addToQueue(const QString &trackId) -> QString;

signals:
	void playlistsChanged();
	void playbackChanged();
	void playingChanged();

private:
	lib::spt::api *spotify = nullptr;
	SettingsQml settings;
	lib::spt::playback current;

	int refreshCount = -1;

	void refresh();
	void refreshed(const lib::spt::playback &playback);
	static auto tracksToJson(QVector<lib::spt::track> &tracks) -> QJsonArray;
	void requestCurrentPlayback();
};


