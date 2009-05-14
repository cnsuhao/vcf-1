# =========================================================================
#     This configuration file was generated by
#     Bakefile 0.2.6 (http://www.bakefile.org)
#     Beware that all changes made to this file will be overwritten next
#     time you run Bakefile!
# =========================================================================


# -------------------------------------------------------------------------
# These are configurable options:
# -------------------------------------------------------------------------

# 'install' program location 
INSTALL ?= install

# Location where the package is installed by 'make install' 
prefix ?= /usr/local

# Destination root (/ is used if empty) 
DESTDIR ?= 

#  
AR ?= ar

#  
RANLIB ?= ranlib

# Compiler flags to link shared library 
LINK_DLL_FLAGS ?= -shared

# Compiler flags to link loadable module 
LINK_MODULE_FLAGS ?= -shared

# C compiler 
CC = gcc

# C++ compiler 
CXX = g++

# Standard flags for CC 
CFLAGS ?= 

# Standard flags for C++ 
CXXFLAGS ?= 

# Standard preprocessor flags (common for CC and CXX) 
CPPFLAGS ?= 

# Standard linker flags 
LDFLAGS ?= 

# Some meaningful string that will be added to the names
# of the target files. Any string is possible.
# For example, if the value is _vc6,
# then the name of, say, the foundation kit debug dll
# will be like this: FoundationKit_vc6_d.dll.
# The default value is an empty string.
# Backward compatibility: []
OPTION_SELECTLIB ?= 

# The type of libraries: [0,1]
OPTION_SHARED ?= 1

# The type of the runtime libraries: [static,dynamic]
OPTION_RUNTIME ?= dynamic

# The build configuration: [0,1]
OPTION_DEBUG ?= 1

# Threading: [single,multi]
OPTION_THREADING ?= multi

# Enable or disable RTTI: [0,1]
OPTION_CPP_RTTI ?= 1

# Enable or disable C++ exceptions: [0,1]
OPTION_CPP_EXCEPTIONS ?= 1

# Warnings level: [no,default,max]
OPTION_WARNINGS ?= default

# Make the all-in-1 library: [0,1]
OPTION_ALLIN1 ?= 0

# Compile the Zip library: [0,1]
OPTION_ZLIB ?= 1

# Compile the AGG library: [0,1]
OPTION_AGG ?= 1

# Compile the JPEG library: [0,1]
OPTION_LIBJPEG ?= 1

# Compile the PNG library: [0,1]
OPTION_LIBPNG ?= 1

# Compile the TIFF library: [0,1]
OPTION_LIBTIFF ?= 1

# Depends on:
#     OPTION_LIBPNG
#     OPTION_LIBJPEG
#     OPTION_LIBTIFF
# Compile the paintlib library: [0,1]
OPTION_PAINTLIB ?= 1

# Compile the oniguruma library: [0,1]
OPTION_ONIGURUMA ?= 1

# Compile the libxml library: [0,1]
OPTION_LIBXML ?= 1

# Depends on:
#     OPTION_LIBXML
# Compile the libxslt library: [0,1]
OPTION_LIBXSLT ?= 1

# Compile the fdlibm library: [0,1]
OPTION_FDLIBM ?= 1

# Compile the javascript library: [0,1]
OPTION_JS ?= 1

# Compile the scintilla library: [0,1]
OPTION_SCINTILLA ?= 1

# Compile FoundationKit: [0,1]
OPTION_FOUNDATIONKIT ?= 1

# Depends on:
#     OPTION_FOUNDATIONKIT
#     OPTION_AGG
#     OPTION_ZLIB
# Compile GraphicsKit: [0,1]
OPTION_GRAPHICSKIT ?= 1

# Depends on:
#     OPTION_GRAPHICSKIT
# Compile ApplicationKit: [0,1]
OPTION_APPLICATIONKIT ?= 1

# Depends on:
#     OPTION_APPLICATIONKIT
# Compile HTMLKit: [0,1]
OPTION_HTMLKIT ?= 0

# Depends on:
#     OPTION_APPLICATIONKIT
# Compile OpenGLKit: [0,1]
OPTION_OPENGLKIT ?= 1

# Depends on:
#     OPTION_FOUNDATIONKIT
# Compile NetworkKit: [0,1]
OPTION_NETWORKKIT ?= 1

# Depends on:
#     OPTION_NETWORKKIT
# Compile RemoteObjectKit: [0,1]
OPTION_REMOTEOBJECTKIT ?= 0

# Depends on:
#     OPTION_FOUNDATIONKIT
# Compile InternetKit: [0,1]
OPTION_INTERNETKIT ?= 0

# Depends on:
#     OPTION_FOUNDATIONKIT
#     OPTION_ONIGURUMA
# Compile RegExKit: [0,1]
OPTION_REGEXKIT ?= 1

# Depends on:
#     OPTION_FOUNDATIONKIT
#     OPTION_LIBXML
#     OPTION_LIBXSLT
# Compile XMLKit: [0,1]
OPTION_XMLKIT ?= 1

# Depends on:
#     OPTION_FOUNDATIONKIT
#     OPTION_FDLIBM
# Compile JavaScriptKit: [0,1]
OPTION_JAVASCRIPTKIT ?= 1

# Depends on:
#     OPTION_APPLICATIONKIT
# Compile ScintillaKit: [0,1]
OPTION_SCINTILLAKIT ?= 1

# Depends on:
#     OPTION_PAINTLIB
#     OPTION_APPLICATIONKIT
# Compile ImageFormats: [0,1]
OPTION_IMAGEFORMATS ?= 0

