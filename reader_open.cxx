#include <iostream>
#include <ROOT/RNTuple.hxx>

using ROOT::Experimental::RNTupleReader;

int main() {
   //auto model = ROOT::Experimental::RNTupleModel::Create();
   //auto pt = model->MakeField<float>({"pt", "transverse momentum"});

   //{
   //   auto ntuple = ROOT::Experimental::RNTupleWriter::Recreate(std::move(model), "myNTuple", "some/file.root");
   //   for (int i = 0; i < 100; i++)
   //      ntuple->Fill();
   //}
   auto ntuple = RNTupleReader::Open("myNTuple", "some/file.root");
   std::cout << "myNTuple has " << ntuple->GetNEntries() << " entries\n";
}
