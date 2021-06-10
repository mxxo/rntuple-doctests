CXXFLAGS_CUSTOM = -std=c++14 -Wall -pthread -Wall -g -O2
ifeq ($(shell root-config --cflags),)
  $(error Cannot find root-config. Please source thisroot.sh)
endif
CXXFLAGS_ROOT = $(shell root-config --cflags)
LDFLAGS_CUSTOM =
LDFLAGS_ROOT = $(shell root-config --libs) -lROOTNTuple
CXXFLAGS = $(CXXFLAGS_CUSTOM) $(CXXFLAGS_ROOT)
LDFLAGS = $(LDFLAGS_CUSTOM) $(LDFLAGS_ROOT)

.PHONY = all clean
all: reader_open reader_printInfo reader_GetEntryRange reader_EnableMetrics

reader_open: reader_open.cxx
	g++ $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

reader_printInfo: reader_printInfo.cxx
	g++ $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

reader_GetEntryRange: reader_GetEntryRange.cxx
	g++ $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

reader_EnableMetrics: reader_EnableMetrics.cxx
	g++ $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f reader_open reader_printInfo reader_GetEntryRange reader_EnableMetrics
