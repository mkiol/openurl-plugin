/* Copyright (C) 2022 Michal Kosciesza <michal@mkiol.net>
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef OPENURLPLUGIN_H
#define OPENURLPLUGIN_H

#include <QObject>
#include <QString>

#include <TransferEngine-qt5/transferplugininterface.h>
#include <TransferEngine-qt5/transferplugininfo.h>
#include <TransferEngine-qt5/transfermethodinfo.h>
#include <TransferEngine-qt5/mediatransferinterface.h>

class Q_DECL_EXPORT OpenUrlPlugin : public QObject, public TransferPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.mkiol.transfer.plugin.harbour-openurl")
    Q_INTERFACES(TransferPluginInterface)

public:
    MediaTransferInterface * transferObject() override;
    TransferPluginInfo *infoObject() override;
    QString pluginId() const override;
    bool enabled() const override;
};

#endif // OPENURLPLUGIN_H
