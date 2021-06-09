/// ~~~ {.cpp}
/// #include <iostream>
/// #include <RNTuple.hxx>
/// using ROOT::Experimental::ENTupleInfo;
/// using ROOT::Experimental::RNTupleReader;
///
/// auto ntuple = RNTupleReader::Open("myNTuple", "some/file.root");
/// ntuple->PrintInfo();
/// // or, equivalently:
/// ntuple->PrintInfo(ENTupleInfo::kSummary, std::cout);
/// ~~~
/// **Example: print detailed column storage data to stderr**
/// ~~~ {.cpp}
/// #include <iostream>
/// #include <RNTuple.hxx>
/// using ROOT::Experimental::ENTupleInfo;
/// using ROOT::Experimental::RNTupleReader;
///
/// auto ntuple = RNTupleReader::Open("myNTuple", "some/file.root");
/// ntuple->PrintInfo(ENTupleInfo::kStorageDetails, std::cerr);
/// ~~~


#include <iostream>
#include <ROOT/RNTuple.hxx>
using ROOT::Experimental::ENTupleInfo;
using ROOT::Experimental::RNTupleReader;

int main() {
   auto ntuple = RNTupleReader::Open("myNTuple", "some/file.root");
   ntuple->PrintInfo();
   // or, equivalently:
   ntuple->PrintInfo(ENTupleInfo::kSummary, std::cout);

   ntuple->PrintInfo(ENTupleInfo::kStorageDetails, std::cerr);
}
