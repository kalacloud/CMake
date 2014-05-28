/*============================================================================
  CMake - Cross Platform Makefile Generator
  Copyright 2014 Kitware, Inc.

  Distributed under the OSI-approved BSD License (the "License");
  see accompanying file Copyright.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/

#ifndef cmWIXFilesSourceWriter_h
#define cmWIXFilesSourceWriter_h

#include "cmWIXSourceWriter.h"
#include "cmWIXShortcut.h"
#include "cmWIXPatch.h"

#include <CPack/cmCPackGenerator.h>

/** \class cmWIXFilesSourceWriter
 * \brief Helper class to generate files.wxs
 */
class cmWIXFilesSourceWriter : public cmWIXSourceWriter
{
public:
  cmWIXFilesSourceWriter(cmCPackLog* logger,
    std::string const& filename);

  void EmitShortcut(
      std::string const& id,
      cmWIXShortcut const& shortcut,
      bool desktop);

  void EmitRemoveFolder(std::string const& id);

  void EmitStartMenuShortcutRegistryValue(
    std::string const& registryKey,
    std::string const& cpackComponentName);

  void EmitDesktopShortcutRegistryValue(
    std::string const& registryKey,
    std::string const& cpackComponentName);

  void EmitUninstallShortcut(std::string const& packageName);

  std::string EmitComponentCreateFolder(
    std::string const& directoryId,
    std::string const& guid);

  std::string EmitComponentFile(
    std::string const& directoryId,
    std::string const& id,
    std::string const& filePath,
    cmWIXPatch &patch,
    cmInstalledFile const* installedFile);

private:
  void EmitInstallRegistryValue(
    std::string const& registryKey,
    std::string const& cpackComponentName,
    std::string const& suffix);
};


#endif
