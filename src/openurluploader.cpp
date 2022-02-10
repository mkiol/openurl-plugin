/* Copyright (C) 2022 Michal Kosciesza <michal@mkiol.net>
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "openurluploader.h"

#include <QString>
#include <QUrl>
#include <TransferEngine-qt5/mediaitem.h>

#include "info.h"

OpenUrlUploader::OpenUrlUploader(QObject *parent):
    MediaTransferInterface{parent}
{
}

QString OpenUrlUploader::displayName() const
{
    return tr("Open link");
}

QUrl OpenUrlUploader::serviceIcon() const
{
    return QUrl{OpenUrl::iconFile};
}

bool OpenUrlUploader::cancelEnabled() const
{
    return false;
}

bool OpenUrlUploader::restartEnabled() const
{
    return false;
}

void OpenUrlUploader::start()
{
}

void OpenUrlUploader::cancel()
{
}

