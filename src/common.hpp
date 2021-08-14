#pragma once

#include "lib/qt/spotify/auth.hpp"
#include "lib/spotify/playlist.hpp"
#include "lib/spotify/api.hpp"
#include "lib/qt/systeminfo.hpp"

#include <QObject>
#include <qqml.h>

// For Qt versions that don't use QML_ELEMENT
#ifndef QML_ELEMENT
#define QML_ELEMENT
#endif