/***********************************************************************
    filename:   CEGUIQtClipboardProvider.h
    created:    15/6/2011
    author:     Martin Preisler

    purpose:    Native clipboard provider using QClipboard from Qt
*************************************************************************/
/***************************************************************************
 *   Copyright (C) 2004 - 2011 Paul D Turner & The CEGUI Development Team
 *
 *   Permission is hereby granted, free of charge, to any person obtaining
 *   a copy of this software and associated documentation files (the
 *   "Software"), to deal in the Software without restriction, including
 *   without limitation the rights to use, copy, modify, merge, publish,
 *   distribute, sublicense, and/or sell copies of the Software, and to
 *   permit persons to whom the Software is furnished to do so, subject to
 *   the following conditions:
 *
 *   The above copyright notice and this permission notice shall be
 *   included in all copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 *   IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 *   OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 *   ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *   OTHER DEALINGS IN THE SOFTWARE.
 ***************************************************************************/
#ifndef _CEGUIQtClipboardProvider_h_
#define _CEGUIQtClipboardProvider_h_

#include "CEGUIClipboard.h"

#if defined(_MSC_VER)
#   pragma warning(push)
#   pragma warning(disable : 4251)
#endif

class QApplication;
class QByteArray;

// Start of CEGUI namespace section
namespace CEGUI
{

/*!
\brief
    Native clipboard provider using Qt
*/
class QtClipboardProvider : public NativeClipboardProvider
{
public:
    QtClipboardProvider();
    
    virtual ~QtClipboardProvider();
    
    //! \copydoc NativeClipboardProvider::sendToClipboard
    virtual void sendToClipboard(const String& mimeType, void* buffer, size_t size) = 0;
    
    //! \copydoc NativeClipboardProvider::receiveFromClipboard
    virtual void retrieveFromClipboard(String& mimeType, void*& buffer, size_t& size) = 0;
    
private:
    QApplication* d_qtApplication;
    
    int d_fakeArgc;
    char** d_fakeArgv;

    QByteArray* d_buffer;
};

} // End of  CEGUI namespace section

#if defined(_MSC_VER)
#   pragma warning(pop)
#endif

#endif  // end of guard _CEGUIQtClipboardProvider_h_
