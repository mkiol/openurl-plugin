/* Copyright (C) 2022 Michal Kosciesza <michal@mkiol.net>
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef OPENURLPLUGININFO_H
#define OPENURLPLUGININFO_H

#include <TransferEngine-qt5/sharingmethodinfo.h>
#include <TransferEngine-qt5/sharingplugininfo.h>

#include <QObject>

class OpenUrlPluginInfo : public SharingPluginInfo {
    Q_OBJECT
   public:
    OpenUrlPluginInfo();

    QList<SharingMethodInfo> info() const override;
    void query() override;

   private:
    QList<SharingMethodInfo> m_infoList;
};

#endif  // OPENURLPLUGININFO_H
