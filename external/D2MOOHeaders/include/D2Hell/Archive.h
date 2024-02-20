/**
 * D2MOO
 * Copyright (c) 2020-2022  The Phrozen Keep community
 *
 * This file belongs to D2MOO.
 * File authors: Lectem, Mir Drualga
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#pragma once

#include <stddef.h>
#include <windows.h>

// TODO: Replace this include with the header file that defines
// HSFILE.
#include <Fog.h>

#pragma pack(push, 1)
struct D2ArchiveHandleStrc
{
	HSARCHIVE hArchive;
	char szPath[MAX_PATH];
};
#pragma pack(pop)

// Name comes from D2Lang: Unicode::loadSysMap(struct HD2ARCHIVE__ *hArchive, char *szFileName)
// Most likely not the same as storm's HARCHIVE and probably D2ArchiveHandleStrc?
typedef struct HD2ARCHIVE__* HD2ARCHIVE; // NOLINT(bugprone-reserved-identifier)

#define ARCHIVE_READ_FILE_TO_ALLOC_BUFFER(hArchive, szFilePath, pBytesWritten) ARCHIVE_ReadFileToAllocBuffer(hArchive, szFilePath, pBytesWritten, __FILE__, __LINE__)

using ARCHIVE_ShowMessageFunctionPtr = BOOL (__stdcall*)();
