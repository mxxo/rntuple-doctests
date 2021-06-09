#include <iostream>
#include <ROOT/RNTuple.hxx>

using ROOT::Experimental::RNTupleReader;

int main() {
   auto ntuple = RNTupleReader::Open("myNTuple", "some/file.root");
   std::cout << "myNTuple has " << ntuple->GetNEntries() << " entries\n";

   for (auto i : ntuple->GetEntryRange()) {
      ntuple->Show(i);
   }
}
