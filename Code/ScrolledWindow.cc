/*
*  
*  MIPS-Datapath - Graphical MIPS CPU Simulator.
*  Copyright 2012 Andrew Gascoyne-Cecil.
* 
*  This program is free software: you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with this program.  If not, see <http://www.gnu.org/licenses/>.
* 
*  Contact: gascoyne+mips@gmail.com
* 
*/

#include "ScrolledWindow.h"

#include "GLCanvas.h"

BEGIN_EVENT_TABLE(ScrolledWindow, wxScrolledWindow)
	EVT_SCROLLWIN(ScrolledWindow::OnScroll)
	EVT_SIZE(ScrolledWindow::OnSize)
	EVT_ERASE_BACKGROUND(ScrolledWindow::OnEraseBackground)
END_EVENT_TABLE()

ScrolledWindow::ScrolledWindow(wxWindow *parent,
	wxWindowID winid,
	const wxPoint& pos,
	const wxSize& size,
	long style,
	const wxString& name)
	: wxScrolledWindow(parent, winid, pos, size, style, name),
	glCanvas(NULL)
{
	/* Nothing else to do. */
}

void ScrolledWindow::SetCanvas(GLCanvas *canvas)
{
	glCanvas = canvas;
}

void ScrolledWindow::OnScroll(wxScrollWinEvent &event)
{
	/* Manually update the scroll position. */
	wxSize size = GetVirtualSize();
	wxPoint start = GetViewStart();
	if( event.GetOrientation() == wxHORIZONTAL )
	{
		start.x = event.GetPosition();
	}
	else
	{
		start.y = event.GetPosition();
	}
	updateScrollbars(size, start);
}

void ScrolledWindow::OnSize(wxSizeEvent &event)
{
	wxSize size = glCanvas->GetCanvasSize();
	SetVirtualSize(size.GetWidth() * glCanvas->GetScale(), size.GetHeight() * glCanvas->GetScale());
	updateScrollbars(GetVirtualSize(), GetViewStart());
}

void ScrolledWindow::OnEraseBackground(wxEraseEvent &event)
{
	/* Do nothing to prevent flicker. */
}

void ScrolledWindow::updateScrollbars(const wxSize& size, const wxPoint& start)
{
	SetScrollbars(1, 1, size.GetWidth(), size.GetHeight(), start.x, start.y);

	if( glCanvas )
	{
		/* Force GL canvas to redraw. */
		glCanvas->Render();
	}
}