#include <ROOT/RNTuple.hxx>
using ROOT::Experimental::ENTupleInfo;
using ROOT::Experimental::RNTupleReader;

#include <iostream>

int main() {
   auto ntuple = RNTupleReader::Open("myNTuple", "some/file.root");
   // metrics must be turned on beforehand
   ntuple->EnableMetrics();

   for (auto i : ntuple->GetEntryRange()) {
      ntuple->LoadEntry(i);
   }
   // print out the reader metrics after loading every entry
   ntuple->PrintInfo(ENTupleInfo::kMetrics);
}
