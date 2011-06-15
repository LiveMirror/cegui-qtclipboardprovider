/***********************************************************************
    filename:   CEGUIQtClipboardProvider.cpp
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
#include "CEGUIQtClipboardProvider.h"
#include <QtGui/QApplication>
#include <QtGui/QClipboard>
#include <QtCore/QMimeData>

// Start of CEGUI namespace section
namespace CEGUI
{

QtClipboardProvider::QtClipboardProvider():
    d_fakeArgc(0),
    d_fakeArgv(new char*[0]),
    
    d_qtApplication(new QApplication(d_fakeArgc, d_fakeArgv)),

    d_buffer(new QByteArray())
{}
    
QtClipboardProvider::~QtClipboardProvider()
{
    delete d_buffer;
    
    delete d_qtApplication;
    delete [] d_fakeArgv;
}

//----------------------------------------------------------------------------//
void QtClipboardProvider::sendToClipboard(const String& mimeType, void* buffer, size_t size)
{
    // we only support plain text for starters
    if (mimeType == "text/plain")
    {
        // Qt works with utf16 nativelly, we want to work with utf8 (because Kulik chose so!)
        // this is why this is a special case
        QMimeData mimeData;
        mimeData.setText(QString::fromUtf8(static_cast<char*>(buffer), size));
    
        QApplication::clipboard()->setMimeData(&mimeData);
    }
}

//----------------------------------------------------------------------------//
void QtClipboardProvider::retrieveFromClipboard(String& mimeType, void*& buffer, size_t& size)
{
    const QMimeData* mimeData = QApplication::clipboard()->mimeData();
    if (mimeData->hasText())
    {
        const QString text = mimeData->text();
        *d_buffer = text.toUtf8();
        
        buffer = static_cast<void*>(d_buffer->data());
        size = d_buffer->size();
    }
}

//----------------------------------------------------------------------------//

} // End of  CEGUI namespace section
