/* Copyright (C) 2022 Michal Kosciesza <michal@mkiol.net>
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "openurlplugininfo.h"

#include <QDebug>
#include <QLocale>
#include <QTranslator>

#include "info.h"

OpenUrlPluginInfo::OpenUrlPluginInfo()
    : m_ready(false)
{
    auto qtr = new QTranslator{this};
    if (qtr->load(QLocale{}, {}, {}, OpenUrl::trDir, ".qm") ||
        qtr->load(QLocale{"en"}, {}, {}, OpenUrl::appName, ".qm")) {
        qApp->installTranslator(qtr);
    } else {
        delete qtr;
    }

    TransferMethodInfo info;
    info.displayName = tr("Open link");
    info.methodId = OpenUrl::appName;
    info.shareUIPath = OpenUrl::uiFile;
    info.capabilitities << QLatin1String{"text/x-url"};
    info.accountIcon = OpenUrl::iconFile;
    m_infoList << info;
}

QList<TransferMethodInfo> OpenUrlPluginInfo::info() const
{
    return m_infoList;
}

void OpenUrlPluginInfo::query()
{
    m_ready = true;
    emit infoReady();
}


bool OpenUrlPluginInfo::ready() const
{
    return m_ready;
}
