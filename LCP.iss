#pragma option -v+
#pragma verboselevel 9

;#define Debug

;#define AppName "LiliCP"
#define AppName "LCP"
#define ApplicationVersion "0.0.1"
#define VSRedist_Release "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\redist\x64\Microsoft.VC120.CRT"
#define VSRedist_Debug "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\redist\Debug_NonRedist\x64\Microsoft.VC120.DebugCRT"
#define QtDir "C:\Qt\5.4\msvc2013_64\bin"

#ifdef Debug
  #define ExePath  "..\build-LCP-Desktop_Qt_5_4_MSVC2013_64bit-Debug\debug"
#else
  #define ExePath  "..\build-LCP-Desktop_Qt_5_4_MSVC2013_64bit-Release\release"
#endif

[Setup]
AppName={#AppName}
AppPublisher=iColdo, Inc.
AppPublisherURL=http://www.icoldo.com
AppVersion=0.9
AppVerName={#AppName} version {#ApplicationVersion}
DefaultDirName={pf32}\{#AppName}
DefaultGroupName={#AppName}
Compression=lzma2
SolidCompression=yes
OutputDir=userdocs:Inno Setup Examples Output
RestartIfNeededByRun=no
UninstallDisplayIcon={app}\app-icon.ico
OutputBaseFilename={#AppName}

[Types]
Name: "full"; Description: "Full installation"
Name: "custom"; Description: "Custom installation"; Flags: iscustom

[Components]
Name: "main"; Description: "Main Files"; Types: full custom; Flags: fixed
Name: "qt_plugins"; Description: "Qt Plugins"; Types: full
Name: "qt_libraries"; Description: "Qt Libraries"; Types: full; Flags: fixed

[Files]
;Source: "{#OtherInstallers}\{#FlashInstaller}"; DestDir: "{tmp}"; 
;Flags: nocompression createallsubdirs recursesubdirs deleteafterinstall

#ifdef Debug
Source: "{#ExePath}\{#AppName}.exe"; DestDir: "{app}"; Components: main
Source: "{#VSRedist_Debug}\msvcp120d.dll"; DestDir: "{app}"; Components: main
Source: "{#VSRedist_Debug}\msvcr120d.dll"; DestDir: "{app}"; Components: main
Source: "{#VSRedist_Release}\msvcp120.dll"; DestDir: "{app}"; Components: main
Source: "{#VSRedist_Release}\msvcr120.dll"; DestDir: "{app}"; Components: main
;Source: "{#SSL_Libs}\libeay32.dll"; DestDir: "{app}"; Components: ssl_libraries
;Source: "{#SSL_Libs}\ssleay32.dll"; DestDir: "{app}"; Components: ssl_libraries
#else
Source: "{#ExePath}\{#AppName}.exe"; DestDir: "{app}"; Components: main
Source: "{#VSRedist_Release}\msvcp120.dll"; DestDir: "{app}"; Components: main
Source: "{#VSRedist_Release}\msvcr120.dll"; DestDir: "{app}"; Components: main
;Source: "{#SSL_Libs}\libeay32.dll"; DestDir: "{app}"; Components: ssl_libraries;
;Source: "{#SSL_Libs}\ssleay32.dll"; DestDir: "{app}"; Components: ssl_libraries
#endif

;Source: "{#ExePath}\{#AppName}.exe.embed.manifest"; DestDir: "{app}"; Components: main
;Source: "Readme.txt"; DestDir: "{app}"; Components: main
Source: ".\images\app-icon.ico"; DestDir: "{app}"; Components: main
;
; Standard Qt Libraries
;
Source: "{#QtDir}\icudt53.dll"; DestDir: "{app}"; Components: qt_libraries
Source: "{#QtDir}\icuin53.dll"; DestDir: "{app}"; Components: qt_libraries
Source: "{#QtDir}\icuuc53.dll"; DestDir: "{app}"; Components: qt_libraries
#ifdef Debug
Source: "{#QtDir}\libEGLd.dll"; DestDir: "{app}"; Components: qt_libraries
Source: "{#QtDir}\libGLESv2d.dll"; DestDir: "{app}"; Components: qt_libraries
Source: "{#QtDir}\Qt5Cored.dll"; DestDir: "{app}"; Components: qt_libraries
Source: "{#QtDir}\Qt5Guid.dll"; DestDir: "{app}"; Components: qt_libraries
Source: "{#QtDir}\Qt5Multimediad.dll"; DestDir: "{app}"; Components: qt_libraries
Source: "{#QtDir}\Qt5MultimediaWidgetsd.dll"; DestDir: "{app}"; Components: qt_libraries
Source: "{#QtDir}\Qt5Networkd.dll"; DestDir: "{app}"; Components: qt_libraries
Source: "{#QtDir}\Qt5OpenGLd.dll"; DestDir: "{app}"; Components: qt_libraries
Source: "{#QtDir}\Qt5PrintSupportd.dll"; DestDir: "{app}"; Components: qt_libraries
Source: "{#QtDir}\Qt5Qmld.dll"; DestDir: "{app}"; Components: qt_libraries
Source: "{#QtDir}\Qt5Quickd.dll"; DestDir: "{app}"; Components: qt_libraries
Source: "{#QtDir}\Qt5Sensorsd.dll"; DestDir: "{app}"; Components: qt_libraries
Source: "{#QtDir}\Qt5Sqld.dll"; DestDir: "{app}"; Components: qt_libraries
Source: "{#QtDir}\Qt5Svgd.dll"; DestDir: "{app}"; Components: qt_libraries
Source: "{#QtDir}\Qt5V8d.dll"; DestDir: "{app}"; Components: qt_libraries
Source: "{#QtDir}\Qt5WebKitd.dll"; DestDir: "{app}"; Components: qt_libraries
Source: "{#QtDir}\Qt5WebKitWidgetsd.dll"; DestDir: "{app}"; Components: qt_libraries
Source: "{#QtDir}\Qt5Widgetsd.dll"; DestDir: "{app}"; Components: qt_libraries
Source: "{#QtDir}\QT5positioningd.dll"; DestDir: "{app}"; Components: qt_libraries
#else
Source: "{#QtDir}\libEGL.dll"; DestDir: "{app}"; Components: qt_libraries
Source: "{#QtDir}\libGLESv2.dll"; DestDir: "{app}"; Components: qt_libraries
Source: "{#QtDir}\Qt5Core.dll"; DestDir: "{app}"; Components: qt_libraries
Source: "{#QtDir}\Qt5Gui.dll"; DestDir: "{app}"; Components: qt_libraries
Source: "{#QtDir}\Qt5Multimedia.dll"; DestDir: "{app}"; Components: qt_libraries
Source: "{#QtDir}\Qt5MultimediaWidgets.dll"; DestDir: "{app}"; Components: qt_libraries
Source: "{#QtDir}\Qt5Network.dll"; DestDir: "{app}"; Components: qt_libraries
Source: "{#QtDir}\Qt5OpenGL.dll"; DestDir: "{app}"; Components: qt_libraries
Source: "{#QtDir}\Qt5PrintSupport.dll"; DestDir: "{app}"; Components: qt_libraries
Source: "{#QtDir}\Qt5Qml.dll"; DestDir: "{app}"; Components: qt_libraries
Source: "{#QtDir}\Qt5Quick.dll"; DestDir: "{app}"; Components: qt_libraries
Source: "{#QtDir}\Qt5Sensors.dll"; DestDir: "{app}"; Components: qt_libraries
Source: "{#QtDir}\Qt5Sql.dll"; DestDir: "{app}"; Components: qt_libraries
Source: "{#QtDir}\Qt5Svg.dll"; DestDir: "{app}"; Components: qt_libraries
;Source: "{#QtDir}\Qt5V8.dll"; DestDir: "{app}"; Components: qt_libraries
Source: "{#QtDir}\Qt5WebKit.dll"; DestDir: "{app}"; Components: qt_libraries
Source: "{#QtDir}\Qt5WebKitWidgets.dll"; DestDir: "{app}"; Components: qt_libraries
Source: "{#QtDir}\Qt5Widgets.dll"; DestDir: "{app}"; Components: qt_libraries
Source: "{#QtDir}\QT5positioning.dll"; DestDir: "{app}"; Components: qt_libraries
#endif
;
; Qt Plugins
;
Source: "{#QtDir}\..\plugins\designer\qaxwidget.dll"; DestDir: "{app}\plugins\designer"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\designer\qdeclarativeview.dll"; DestDir: "{app}\plugins\designer"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\designer\qwebview.dll"; DestDir: "{app}\plugins\designer"; Components: qt_plugins

#ifdef Debug
;Source: "{#QtDir}\..\plugins\accessible\qtaccessiblequickd.dll"; DestDir: "{app}\accessible"; Components: qt_plugins
;Source: "{#QtDir}\..\plugins\accessible\qtaccessiblewidgetsd.dll"; DestDir: "{app}\accessible"; Components: qt_plugins

Source: "{#QtDir}\..\plugins\audio\qtaudio_windowsd.dll"; DestDir: "{app}\audio"; Components: qt_plugins

Source: "{#QtDir}\..\plugins\bearer\qgenericbearerd.dll"; DestDir: "{app}\bearer"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\bearer\qnativewifibearerd.dll"; DestDir: "{app}\bearer"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\iconengines\qsvgicond.dll"; DestDir: "{app}\iconengines"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\imageformats\qddsd.dll"; DestDir: "{app}\imageformats"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\imageformats\qgifd.dll"; DestDir: "{app}\imageformats"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\imageformats\qicod.dll"; DestDir: "{app}\imageformats"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\imageformats\qjpegd.dll"; DestDir: "{app}\imageformats"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\imageformats\qmngd.dll"; DestDir: "{app}\imageformats"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\imageformats\qsvgd.dll"; DestDir: "{app}\imageformats"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\imageformats\qtgad.dll"; DestDir: "{app}\imageformats"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\imageformats\qtiffd.dll"; DestDir: "{app}\imageformats"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\imageformats\qwbmpd.dll"; DestDir: "{app}\imageformats"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\imageformats\qwebpd.dll"; DestDir: "{app}\imageformats"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\mediaservice\dsengined.dll"; DestDir: "{app}\mediaservice"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\mediaservice\qtmedia_audioengined.dll"; DestDir: "{app}\mediaservice"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\mediaservice\wmfengined.dll"; DestDir: "{app}\mediaservice"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\platforms\qminimald.dll"; DestDir: "{app}\platforms"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\platforms\qoffscreend.dll"; DestDir: "{app}\platforms"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\platforms\qwindowsd.dll"; DestDir: "{app}\platforms"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\playlistformats\qtmultimedia_m3ud.dll"; DestDir: "{app}\playlistformats"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\printsupport\windowsprintersupportd.dll"; DestDir: "{app}\printsupport"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\qml1tooling\qmldbg_inspectord.dll"; DestDir: "{app}\qml1tooling"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\qml1tooling\qmldbg_tcp_qtdeclaratived.dll"; DestDir: "{app}\qml1tooling"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\qmltooling\qmldbg_qtquick2d.dll"; DestDir: "{app}\qmltooling"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\qmltooling\qmldbg_tcpd.dll"; DestDir: "{app}\qmltooling"; Components: qt_plugins

Source: "{#QtDir}\..\plugins\qtwebengine\ffmpegsumo.dll"; DestDir: "{app}\qmltooling"; Components: qt_plugins

Source: "{#QtDir}\..\plugins\sensorgestures\qtsensorgestures_plugind.dll"; DestDir: "{app}\sensorgestures"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\sensorgestures\qtsensorgestures_shakeplugind.dll"; DestDir: "{app}\sensorgestures"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\sensors\qtsensors_dummyd.dll"; DestDir: "{app}\sensors"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\sensors\qtsensors_genericd.dll"; DestDir: "{app}\sensors"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\sqldrivers\qsqlited.dll"; DestDir: "{app}\sqldrivers"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\sqldrivers\qsqlodbcd.dll"; DestDir: "{app}\sqldrivers"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\sqldrivers\qsqlpsqld.dll"; DestDir: "{app}\sqldrivers"; Components: qt_plugins
#else
;Source: "{#QtDir}\..\plugins\accessible\qtaccessiblequick.dll"; DestDir: "{app}\accessible"; Components: qt_plugins
;Source: "{#QtDir}\..\plugins\accessible\qtaccessiblewidgets.dll"; DestDir: "{app}\accessible"; Components: qt_plugins

Source: "{#QtDir}\..\plugins\audio\qtaudio_windows.dll"; DestDir: "{app}\audio"; Components: qt_plugins


Source: "{#QtDir}\..\plugins\bearer\qgenericbearer.dll"; DestDir: "{app}\bearer"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\bearer\qnativewifibearer.dll"; DestDir: "{app}\bearer"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\iconengines\qsvgicon.dll"; DestDir: "{app}\iconengines"; Components: qt_plugins

Source: "{#QtDir}\..\plugins\imageformats\qdds.dll"; DestDir: "{app}\imageformats"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\imageformats\qgif.dll"; DestDir: "{app}\imageformats"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\imageformats\qico.dll"; DestDir: "{app}\imageformats"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\imageformats\qjpeg.dll"; DestDir: "{app}\imageformats"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\imageformats\qmng.dll"; DestDir: "{app}\imageformats"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\imageformats\qsvg.dll"; DestDir: "{app}\imageformats"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\imageformats\qtga.dll"; DestDir: "{app}\imageformats"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\imageformats\qtiff.dll"; DestDir: "{app}\imageformats"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\imageformats\qwbmp.dll"; DestDir: "{app}\imageformats"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\imageformats\qwebp.dll"; DestDir: "{app}\imageformats"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\mediaservice\dsengine.dll"; DestDir: "{app}\mediaservice"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\mediaservice\qtmedia_audioengine.dll"; DestDir: "{app}\mediaservice"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\mediaservice\wmfengine.dll"; DestDir: "{app}\mediaservice"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\platforms\qminimal.dll"; DestDir: "{app}\platforms"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\platforms\qoffscreen.dll"; DestDir: "{app}\platforms"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\platforms\qwindows.dll"; DestDir: "{app}\platforms"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\playlistformats\qtmultimedia_m3u.dll"; DestDir: "{app}\playlistformats"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\printsupport\windowsprintersupport.dll"; DestDir: "{app}\printsupport"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\qml1tooling\qmldbg_inspector.dll"; DestDir: "{app}\qml1tooling"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\qml1tooling\qmldbg_tcp_qtdeclarative.dll"; DestDir: "{app}\qml1tooling"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\qmltooling\qmldbg_qtquick2.dll"; DestDir: "{app}\qmltooling"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\qmltooling\qmldbg_tcp.dll"; DestDir: "{app}\qmltooling"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\qtwebengine\ffmpegsumo.dll"; DestDir: "{app}\qmltooling"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\sensorgestures\qtsensorgestures_plugin.dll"; DestDir: "{app}\sensorgestures"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\sensorgestures\qtsensorgestures_shakeplugin.dll"; DestDir: "{app}\sensorgestures"; Components: qt_plugins
;Source: "{#QtDir}\..\plugins\sensors\qtsensors_dummy.dll"; DestDir: "{app}\sensors"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\sensors\qtsensors_generic.dll"; DestDir: "{app}\sensors"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\sqldrivers\qsqlite.dll"; DestDir: "{app}\sqldrivers"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\sqldrivers\qsqlodbc.dll"; DestDir: "{app}\sqldrivers"; Components: qt_plugins
Source: "{#QtDir}\..\plugins\sqldrivers\qsqlpsql.dll"; DestDir: "{app}\sqldrivers"; Components: qt_plugins
#endif

[Icons]
Name: "{group}\{#AppName}"; Filename: "{app}\{#AppName}.exe"; IconFilename: "{app}\app-icon.ico"
Name: "{group}\Uninstall {#AppName}"; Filename: "{uninstallexe}"; IconFilename: "{app}\app-icon.ico"

[Run]
;Filename: "{tmp}\{#FlashInstaller}"; Description: "Install Flash Player"; Flags: postinstall unchecked
;Filename: "{app}\Readme.txt"; Description: "View the README file"; Flags: postinstall unchecked
Filename: "{app}\{#AppName}.exe"; Flags: postinstall unchecked