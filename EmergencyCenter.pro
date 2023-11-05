QT -= gui

TEMPLATE = lib
DEFINES += EMERGENCYCENTER_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    customer.cpp \
    emergencycenter.cpp \
    sensor.cpp \
    sensorfactory.cpp \
    sensorgroup.cpp

HEADERS += \
    EmergencyCenter_global.h \
    action.h \
    concrete_actions.h \
    customer.h \
    emergencycenter.h \
    messages.h \
    observer.h \
    sensor.h \
    sensorcomponent.h \
    sensorfactory.h \
    sensorgroup.h \
    subject.h

# Default rules for deployment.
unix {
    target.path = /Users/maximebellis/AdvancedProgramming
}
!isEmpty(target.path): INSTALLS += target
