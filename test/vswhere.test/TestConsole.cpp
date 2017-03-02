// <copyright file="TestConsole.h" company="Microsoft Corporation">
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT license. See LICENSE.txt in the project root for license information.
// </copyright>

#include "stdafx.h"

using namespace std;

void __cdecl TestConsole::Write(_In_ LPCWSTR wzFormat, va_list args)
{
    // include space for trailing null character
    size_t ch = ::_vscwprintf(wzFormat, args) + 1;
    size_t pos = m_output.size();
    m_output.resize(m_output.size() + ch);

    size_t rem = m_output.size() - pos;
    auto end = const_cast<LPWSTR>(m_output.c_str()) + pos;
    ::vswprintf_s(end, rem, wzFormat, args);

    // remove trailing null character
    m_output.resize(m_output.size() - 1);
}
