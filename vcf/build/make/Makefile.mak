## generic makefile included from builddir

SRC=../../../../src
LIB=../../../../lib


OBJECTS  := $(SOURCES:.cpp=.o) 

ifeq ($(KIT), GraphicsKit)
   ifeq ($(BUILD), Debug)
      OBJECTS += $(LIB)/libagg_d.a
   else
      OBJECTS += $(LIB)/libagg.a
   endif
endif


CXXFLAGS  = -DVCF_GCC -DVCF_POSIX -Wno-multichar -I$(SRC) 
CXXFLAGS += -DVCF_GTK $(shell pkg-config gtk+-2.0 --cflags)

ifeq ($(KIT), LibAGG)
   CXXFLAGS += -I$(SRC)/thirdparty/common/agg/include
   VPATH = $(SRC)/thirdparty/common/agg/src
else
   VPATH = $(SRC)/vcf/$(KIT)
endif

LDFLAGS   = -L$(VCF_LIB)
LDFLAGS  +=  $(shell pkg-config gtk+-2.0 --libs)
LDFLAGS  += -lpthread -ldl -shared

ARFLAGS   = -cru

all: debug release

%.dep: %.cpp
	@set -e; echo "Building dependencies: $(notdir $<)";\
	$(CXX) -MM $(CXXFLAGS) $< > $@.$$$$;\
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@;\
	rm -f $@.$$$$

-include $(SOURCES:.cpp=.dep)

debug:   CXXFLAGS += -ggdb -D_DEBUG
debug:   LDFLAGS   += -ggdb
debug:   $(TARGET)

release: CXXFLAGS += -DNDEBUG -Os
release: $(TARGET)

$(TARGET): $(OBJECTS)
ifeq ($(KIT), LibAGG)
	$(AR) $(ARFLAGS) $(LIB)/$@ $^
else
	$(CXX) $(LDFLAGS) -o $(LIB)/$@ $^
endif

