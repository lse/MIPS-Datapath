/*
 *  
 *  MIPS-Datapath - Graphical MIPS CPU Simulator.
 *  Copyright 2008 Andrew Gascoyne-Cecil.
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

#include <GL/glut.h>

#include "MyFrame.h"
#include "Config.h" 

#include "MyApp.h"

MyApp::MyApp()
{
	
}

MyApp::~MyApp()
{
}
 
bool MyApp::OnInit()
{
#ifndef DEBUG_BUILD
	glutInit(&argc, (char**)argv);
	frame = new MyFrame( _T("MIPS-Datapath"), wxPoint(50,50), wxSize(450,340) );
    frame->Show(TRUE);
 	SetTopWindow(frame);
 	frame->finishInit();
    return TRUE;
#endif
}
