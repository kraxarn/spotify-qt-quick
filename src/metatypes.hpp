#pragma once

#include "lib/settings/account.hpp"
#include "lib/settings/general.hpp"
#include "lib/settings/spotify.hpp"

#include <QMetaType>

Q_DECLARE_METATYPE(lib::setting::account)
Q_DECLARE_METATYPE(lib::setting::general)
Q_DECLARE_METATYPE(lib::setting::spotify)