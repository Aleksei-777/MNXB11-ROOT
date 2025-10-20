#include <iostream>
#include <TFile.h>
#include <TTree.h>
#include <TRandom.h>
#include "my_class.h"
void write(){
    my_class *obj = new my_class();
    TFile *f1 = new TFile ("tree_file.root", "RECREATE");
    TTree *tree = new TTree ("tree","Tree containing momentum objects");
    tree->Branch("myBranch", "my_class", &obj);
    Int_t nEvents = 1000; 

    for (Int_t i = 0; i < nEvents; i++) {
        Double_t px = gRandom->Gaus(0, 0.02);
        Double_t py = gRandom->Gaus(0, 0.02);
        Double_t pz = gRandom->Gaus(0, 0.02);



        obj = new my_class(px, py, pz);  

        tree->Fill();

        delete obj;
    }

    tree->Write();
    f1->Close();


    delete tree;
    delete f1;
}

