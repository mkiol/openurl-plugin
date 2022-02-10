TEMPLATE = lib
TARGET = $$qtLibraryTarget(harbouropenurlplugin)
CONFIG += c++1z plugin link_pkgconfig
PKGCONFIG += nemotransferengine-qt5

QT += qml

NAME = harbour-openurl
UI_DIR = /usr/share/$${NAME}
TR_DIR = $${UI_DIR}/translations

QMAKE_CXXFLAGS += -Wpedantic

INCLUDEPATH += \
    transferengine

DEFINES += \
    NAME=\\\"$${NAME}\\\" \
    UI_DIR=\\\"$${UI_DIR}\\\" \
    TR_DIR=\\\"$${TR_DIR}\\\"

CONFIG(debug, debug|release) {
    DEFINES += DEBUG
}

OTHER_FILES += \
    qml/*.qml \
    rpm/*.spec \
    images/*.svg \
    translations/*.ts

HEADERS += \
    src/info.h \
    src/openurlplugininfo.h \
    src/openurlplugin.h \
    src/openurluploader.h

SOURCES += \
    src/openurlplugininfo.cpp \
    src/openurlplugin.cpp \
    src/openurluploader.cpp

TR_SOURCES = \
  $${_PRO_FILE_PWD_}/qml \
  $${_PRO_FILE_PWD_}/src

# source: https://github.com/martonmiklos/harbour-sms-share-plugin
defineTest(addTrFile) {
    in = $${_PRO_FILE_PWD_}/translations/$$1
    out = $${OUT_PWD}/translations/$$1

    s = $$replace(1,-,_)
    lupdate_target = lupdate_$$s
    lrelease_target = lrelease_$$s

    $${lupdate_target}.commands = lupdate -source-language en -target-language $$1 -noobsolete -locations none $${TR_SOURCES} -ts \"$${in}.ts\" && \
        mkdir -p \"$${OUT_PWD}/translations\" &&  [ \"$${in}.ts\" != \"$${out}.ts\" ] && \
        cp -af \"$${in}.ts\" \"$${out}.ts\" || :

    $${lrelease_target}.target = $${out}.qm
    $${lrelease_target}.depends = $${lupdate_target}
    $${lrelease_target}.commands = lrelease \"$${out}.ts\"

    QMAKE_EXTRA_TARGETS += $${lrelease_target} $${lupdate_target}
    PRE_TARGETDEPS += $${out}.qm
    qm.files += $${out}.qm

    export($${lupdate_target}.commands)
    export($${lrelease_target}.target)
    export($${lrelease_target}.depends)
    export($${lrelease_target}.commands)
    export(QMAKE_EXTRA_TARGETS)
    export(PRE_TARGETDEPS)
    export(qm.files)
}

LANGUAGES = bg cs da de en et el es hu fr fi it lt lv nb nl pl pt ro ru sk sl sv tr uk vi zh_CN zh_TW

for(l, LANGUAGES) {
    addTrFile($$l)
}

qm.path = $$TR_DIR
qm.CONFIG += no_check_exist
INSTALLS += qm

target.path = $$[QT_INSTALL_LIBS]/nemo-transferengine/plugins
INSTALLS += target

images.files = images/*
images.path = $${UI_DIR}
INSTALLS += images

qml.files = qml/*
qml.path = $${UI_DIR}
INSTALLS += qml
