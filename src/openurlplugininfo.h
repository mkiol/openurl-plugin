/* Copyright (C) 2022 Michal Kosciesza <michal@mkiol.net>
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef OPENURLPLUGININFO_H
#define OPENURLPLUGININFO_H

#include <QObject>

#include <TransferEngine-qt5/transferplugininfo.h>
#include <TransferEngine-qt5/transfermethodinfo.h>

class OpenUrlPluginInfo : public TransferPluginInfo
{
    Q_OBJECT
public:
    OpenUrlPluginInfo();

    QList<TransferMethodInfo> info() const override;
    void query() override;
    bool ready() const override;

private:
    QList<TransferMethodInfo> m_infoList;
    bool m_ready;
};

#endif // OPENURLPLUGININFO_H
