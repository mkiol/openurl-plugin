/* Copyright (C) 2022 Michal Kosciesza <michal@mkiol.net>
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    property var shareAction
    property var content
    property var accountId
    property var methodId

    function close() {
        if (pageStack.busy) {
            _doPop = true
        } else {
            _doPop = false
            pageStack.pop(null, PageStackAction.Immediate)
            if (pageStack.depth > 1) pageStack.pop(null, PageStackAction.Immediate)
        }
    }

    property bool _doPop: false
    Connections {
        target: pageStack
        onBusyChanged: close()
    }

    onContentChanged: {
        if (content !== undefined && content.status !== undefined && content.status.length > 0) {
            Qt.openUrlExternally(content.status)
        }

        close()
    }

    Component.onCompleted: {
        if (shareAction !== undefined) {
            if (shareAction.resources !== undefined) {
                for(var i = 0, size = shareAction.resources.length; i < size; i++) {
                    if (shareAction.resources[i].status.length > 0) {
                        Qt.openUrlExternally(shareAction.resources[i].status)
                    }
                }
            }
            shareAction.done()
        }
    }
}
