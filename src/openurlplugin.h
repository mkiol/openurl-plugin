/* Copyright (C) 2022 Michal Kosciesza <michal@mkiol.net>
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef OPENURLPLUGIN_H
#define OPENURLPLUGIN_H

#include <TransferEngine-qt5/sharingplugininfo.h>
#include <TransferEngine-qt5/sharingplugininterface.h>

#include <QObject>
#include <QString>

class Q_DECL_EXPORT OpenUrlPlugin : public QObject,
                                    public SharingPluginInterface {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.mkiol.sharing.plugin.harbour-openurl")
    Q_INTERFACES(SharingPluginInterface)

   public:
    SharingPluginInfo *infoObject() override;
    QString pluginId() const override;
};

#endif  // OPENURLPLUGIN_H
