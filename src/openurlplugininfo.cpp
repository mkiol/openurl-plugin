/* Copyright (C) 2022 Michal Kosciesza <michal@mkiol.net>
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "openurlplugininfo.h"

#include <QDebug>
#include <QGuiApplication>
#include <QLocale>
#include <QTranslator>

#include "info.h"

OpenUrlPluginInfo::OpenUrlPluginInfo() {
    auto qtr = new QTranslator{this};
    if (qtr->load(QLocale{}, {}, {}, OpenUrl::trDir, ".qm") ||
        qtr->load(QLocale{"en"}, {}, {}, OpenUrl::appName, ".qm")) {
        qApp->installTranslator(qtr);
    } else {
        delete qtr;
    }

    SharingMethodInfo info;
    info.setDisplayName(tr("Open link"));
    info.setMethodId(OpenUrl::appName);
    info.setShareUIPath(OpenUrl::uiFile);
    info.setCapabilities({QLatin1String{"text/x-url"}});
    info.setMethodIcon(OpenUrl::iconFile);
    m_infoList << info;
}

QList<SharingMethodInfo> OpenUrlPluginInfo::info() const { return m_infoList; }

void OpenUrlPluginInfo::query() { emit infoReady(); }
