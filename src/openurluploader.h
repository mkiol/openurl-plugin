/* Copyright (C) 2022 Michal Kosciesza <michal@mkiol.net>
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef OPENURLUPLOADER_H
#define OPENURLUPLOADER_H

#include <QObject>
#include <QString>
#include <QUrl>
#include <TransferEngine-qt5/mediatransferinterface.h>

class OpenUrlUploader : public MediaTransferInterface
{
    Q_OBJECT
public:
    OpenUrlUploader(QObject *parent = nullptr);

    QString displayName() const override;
    QUrl serviceIcon() const override;
    bool cancelEnabled() const override;
    bool restartEnabled() const override;

public slots:
    void start() override;
    void cancel() override;
};

#endif // OPENURLUPLOADER_H
