# Microsoft Developer Studio Project File - Name="GraphicsKit" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=GraphicsKit - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "GraphicsKit.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "GraphicsKit.mak" CFG="GraphicsKit - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "GraphicsKit - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "GraphicsKit - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName "GraphicsKit"
# PROP Scc_LocalPath "."
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "GraphicsKit - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\..\lib"
# PROP Intermediate_Dir "vc6/ReleaseS\obj"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /I "$(VCF_INCLUDE)" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /D "BUILD_GRAPHICSKIT_LIB" /Yu"GraphicsKit.h" /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"..\..\..\lib\GraphicsKit_vc6_s.bsc"
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\..\..\lib\GraphicsKit_vc6_s.lib"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\..\lib"
# PROP Intermediate_Dir "vc6/DebugS\obj"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /ZI /Od /I "$(VCF_INCLUDE)" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /D "BUILD_GRAPHICSKIT_LIB" /FR /Yu"GraphicsKit.h" /Fd"..\..\..\lib/GraphicsKit_vc6_sd.pdb" /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"..\..\..\lib\GraphicsKit_vc6_sd.bsc"
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\..\..\lib\GraphicsKit_vc6_sd.lib"

!ENDIF 

# Begin Target

# Name "GraphicsKit - Win32 Release"
# Name "GraphicsKit - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\Graphics\AbstractImage.cpp

!IF  "$(CFG)" == "GraphicsKit - Win32 Release"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\src\Graphics\BasicFill.cpp

!IF  "$(CFG)" == "GraphicsKit - Win32 Release"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\src\Graphics\BasicStroke.cpp

!IF  "$(CFG)" == "GraphicsKit - Win32 Release"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\src\Graphics\Color.cpp

!IF  "$(CFG)" == "GraphicsKit - Win32 Release"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\src\Graphics\Font.cpp

!IF  "$(CFG)" == "GraphicsKit - Win32 Release"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\src\Graphics\FontState.cpp

!IF  "$(CFG)" == "GraphicsKit - Win32 Release"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\src\Graphics\GlyphCollection.cpp

!IF  "$(CFG)" == "GraphicsKit - Win32 Release"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\src\Graphics\GraphicsContext.cpp

!IF  "$(CFG)" == "GraphicsKit - Win32 Release"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\src\Graphics\GraphicsKit.cpp

!IF  "$(CFG)" == "GraphicsKit - Win32 Release"

# ADD CPP /Yc"GraphicsKit.h"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 Debug"

# ADD CPP /Yc"GraphicsKit.h"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\src\Graphics\GraphicsObject.cpp

!IF  "$(CFG)" == "GraphicsKit - Win32 Release"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\src\Utils\GraphicsToolKit.cpp

!IF  "$(CFG)" == "GraphicsKit - Win32 Release"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\src\Events\ImageEvent.cpp

!IF  "$(CFG)" == "GraphicsKit - Win32 Release"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\src\Graphics\Matrix2D.cpp

!IF  "$(CFG)" == "GraphicsKit - Win32 Release"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\src\Graphics\Polygon.cpp

!IF  "$(CFG)" == "GraphicsKit - Win32 Release"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\src\Graphics\Vector2D.cpp

!IF  "$(CFG)" == "GraphicsKit - Win32 Release"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\src\ImplementerKit\Win32Context.cpp

!IF  "$(CFG)" == "GraphicsKit - Win32 Release"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\src\ImplementerKit\Win32Font.cpp

!IF  "$(CFG)" == "GraphicsKit - Win32 Release"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\src\ImplementerKit\Win32FontManager.cpp

!IF  "$(CFG)" == "GraphicsKit - Win32 Release"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\src\ImplementerKit\Win32GraphicsToolkit.cpp

!IF  "$(CFG)" == "GraphicsKit - Win32 Release"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\src\ImplementerKit\Win32Image.cpp

!IF  "$(CFG)" == "GraphicsKit - Win32 Release"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 Debug"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\include\graphics\AbstractImage.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\AlphaGamma.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\ArtStroke.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\Basic3DBorder.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\BasicFill.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\BasicRectangle.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\BasicStroke.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\Border.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\Circle.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\ClippingRegion.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\Color.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\implementer\Contextpeer.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\ControlGraphicsContext.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\Curve.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\Ellipse.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\Fill.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\Filter.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\Font.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\FontPeer.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\Glyph.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\GlyphCollection.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\GraphicsContext.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\GraphicsKit.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\GraphicsObject.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\GraphicsResourceMgr.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\utils\GraphicsToolKit.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\Image.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\ImageBits.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\ImageList.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\ImageLoader.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\exceptions\ImageLoaderException.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\Matrix.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\Matrix2D.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\MatrixFunction.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\Path.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\PathEnumerator.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\Polygon.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\Printable.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\PrintContext.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\Stroke.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\VCFOpenGL.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\Vector2D.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\implementerKit\Win32Context.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\implementerKit\Win32Font.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\implementerKit\Win32GraphicsToolkit.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\implementerKit\Win32Image.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\implementerkit\Win32OpenGLPeer.h
# End Source File
# End Group
# End Target
# End Project
