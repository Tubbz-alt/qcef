// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef QCEF_CORE_QCEF_GLOBAL_SETTINGS_H
#define QCEF_CORE_QCEF_GLOBAL_SETTINGS_H

#include <QPair>
#include <QStringList>
#include <QUrl>

#include "qcef_core_export.h"
#include "qcef_scheme_handler.h"

struct QCefGlobalSettingsPrivate;

// Setup cef switches during initialization.
class QCEF_CORE_EXPORT QCefGlobalSettings {
 public:
  QCefGlobalSettings();
  ~QCefGlobalSettings();

  // Enable single process mode, browser and render process are located in
  // the same process. Default is false.
  void setSingleProcess(bool enabled);
  bool singleProcess() const;

  // Disable sandbox or not for sub-processes, default is false.
  void setNoSandbox(bool enabled);
  bool noSandbox() const;

  // Allows cef to parse command line arguments. Default is true.
  void setDisableCommandLineArgs(bool enabled);
  bool disableCommandLineArgs() const;

  // The location where cache data will be stored on disk. If empty then
  // browsers will be created in "incognito mode" where in-memory caches are
  // used for storage and no data is persisted to disk.
  void setCachePath(const QString& path);
  const QString& cachePath() const;

  // The location where user data such as spell checking dictionary files will
  // be stored on disk. If empty then the default user data directory
  // ("~/.cef_user_data") will be used.
  void setUserDataPath(const QString& path);
  const QString& userDataPath() const;

  // To persist session cookies (cookies without an expiry date or validity
  // interval) by default when using the global cookie manager set this value to
  // true (1). Session cookies are generally intended to be transient and most
  // Web browsers do not persist them. A |cache_path| value must also be
  // specified to enable this feature.
  void setPersistSessionCcookies(bool enabled);
  bool persistSessionCookies() const;

  // To persist user preferences as a JSON file in the cache path directory set
  // this value to true. A |cache_path| value must also be specified
  // to enable this feature.
  void setPersistUserPreferences(bool enabled);
  bool persistUserPreferences() const;

  // Set User-Agent http header, if |ua| is empty, default value will be used.
  void setUserAgent(const QString& ua);
  const QString& userAgent() const;

  // Set absolute path to debug log file.
  void setLogFile(const QString& filepath);
  const QString& logFile() const;

  enum class LogSeverity {
    Default,
    Verbose,
    Info,
    Warning,
    Error,
    Disable,
  };
  // Set log level.
  void setLogSeverity(LogSeverity level);
  LogSeverity logSeverity() const;

  // Set remote debug port, default is 9222.
  void setRemoteDebugPort(int port);
  int remoteDebugPort() const;

  // Enable/disable remote debug. Default is false.
  void setRemoteDebug(bool enabled);
  bool remoteDebug() const;

  // Enable this switch to ignore invalid SSl certificates. Default is false.
  void setIgnoresCertificateErrors(bool enabled);
  bool ignoresCertificateErrors() const;

  // Comma delimited ordered list of language codes without any whitespace that
  // will be used in the "Accept-Language" HTTP header. May be overridden on a
  // per-browser basis using the CefBrowserSettings.accept_language_list value.
  // If both values are empty then "en-US,en" will be used.
  void setAcceptLanguageList(const QString& list);
  const QString& acceptLanguageList() const;

  // Enable or disable pepper flash plugin. Default is false.
  // Requires "pepperflashplugin-nonfree" package.
  void setPepperFlash(bool enabled);
  bool pepperFlash() const;
  QString getPepperFlashPath() const;
  QString getPepperFlashVersion() const;

  // Register custom scheme. i.e. addCustomScheme("local:/domain")
  void addCustomScheme(const QUrl& url);
  const QList<QUrl>& customSchemes() const;

  void setCustomSchemeHandler(QCefSchemeHandler handler);
  QCefSchemeHandler getCustomSchemeHandler() const;

 private:
  QCefGlobalSettingsPrivate* p_ = nullptr;
};

#endif  // QCEF_CORE_QCEF_GLOBAL_SETTINGS_H
