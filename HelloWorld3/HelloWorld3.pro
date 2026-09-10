QT += quick

SOURCES += \
        main.cpp \
        networkcheck.cpp

resources.files = main.qml 
resources.prefix = /$${TARGET}
RESOURCES += resources

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    android/AndroidManifest.xml \
    android/build.gradle \
    android/gradle.properties \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew \
    android/gradlew.bat \
    android/res/drawable-hdpi/icon.png \
    android/res/drawable-ldpi/icon.png \
    android/res/drawable-mdpi/icon.png \
    android/res/drawable-xhdpi/icon.png \
    android/res/drawable-xxhdpi/icon.png \
    android/res/drawable-xxxhdpi/icon.png \
    android/res/values/libs.xml

contains(ANDROID_TARGET_ARCH,armeabi-v7a) {
    ANDROID_PACKAGE_SOURCE_DIR = \
        $$PWD/android \
}

# Stuff to get web page source code reading working. Must use Qt Maintenance Tool to add QT > Build Tools > OpenSSL 3.0.16 Toolkit (or equivalent) first
# You also need to update the PATH environmental variable to include the following location:
# C:\Qt\Tools\OpenSSLv3\Win_x64\bin
# https://www.youtube.com/watch?v=MtylaMlmzZg
android: include(android_openssl-master/openssl.pri)
LIBS += -LC:/Qt/Tools/OpenSSLv3/Win_x64/lib/libssl.lib
LIBS += -LC:/Qt/Tools/OpenSSLv3/Win_x64/lib/libcrypto.lib
INCLUDEPATH += C:/Qt/Tools/OpenSSLv3/Win_x64/include

HEADERS += \
    networkcheck.h
