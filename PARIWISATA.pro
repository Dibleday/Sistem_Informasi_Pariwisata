QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    formdesa.cpp \
    formdetail.cpp \
    formevent.cpp \
    formkategori.cpp \
    formkecamatan.cpp \
    formlokasi.cpp \
    formpengelola.cpp \
    formpengunjung.cpp \
    formpromosi.cpp \
    main.cpp \
    halamanutama.cpp

HEADERS += \
    formdesa.h \
    formdetail.h \
    formevent.h \
    formkategori.h \
    formkecamatan.h \
    formlokasi.h \
    formpengelola.h \
    formpengunjung.h \
    formpromosi.h \
    halamanutama.h

FORMS += \
    formdesa.ui \
    formdetail.ui \
    formevent.ui \
    formkategori.ui \
    formkecamatan.ui \
    formlokasi.ui \
    formpengelola.ui \
    formpengunjung.ui \
    formpromosi.ui \
    halamanutama.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
