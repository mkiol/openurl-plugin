/* Copyright (C) 2022 Michal Kosciesza <michal@mkiol.net>
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "openurlplugin.h"

#include "openurluploader.h"
#include "openurlplugininfo.h"
#include "info.h"

MediaTransferInterface * OpenUrlPlugin::transferObject()
{
    return new OpenUrlUploader;
}

TransferPluginInfo *OpenUrlPlugin::infoObject()
{
    return new OpenUrlPluginInfo;
}

QString OpenUrlPlugin::pluginId() const
{
    return OpenUrl::appName;
}

bool OpenUrlPlugin::enabled() const
{
    return true;
}

