/* Copyright (C) 2022 Michal Kosciesza <michal@mkiol.net>
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "openurlplugin.h"

#include "info.h"
#include "openurlplugininfo.h"

SharingPluginInfo* OpenUrlPlugin::infoObject() { return new OpenUrlPluginInfo; }

QString OpenUrlPlugin::pluginId() const { return OpenUrl::appName; }
