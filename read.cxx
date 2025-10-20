#include <iostream>
#include <TFile.h>
#include <TTree.h>
#include <TH2D.h>
#include <TCanvas.h>
#include "my_class.h"

void read() {
    my_class *obj = new my_class();

    TFile *f = new TFile("tree_file.root", "READ");
    TTree *tree = (TTree*)f->Get("tree");

    
    tree->SetBranchAddress("myBranch", &obj);


    TH2D *h_px_py = new TH2D("h_px_py", "px vs py;px;py", 100, -0.1, 0.1, 100, -0.1, 0.1);


    Long64_t N = tree->GetEntries();
    for (Long64_t i = 0; i < N; i++) {
        tree->GetEntry(i);

        h_px_py->Fill(obj->GetPx(), obj->GetPy());
    }


    TCanvas *c1 = new TCanvas("c1", "Momentum plots", 800, 600);
    h_px_py->Draw("COLZ");


    TCanvas *c2 = new TCanvas("c2", "Scatter plot", 800, 600);
    tree->Draw("myBranch.px*myBranch.py:myBranch.pz", "", "COLZ");
 


    c1->Update();
    c2->Update();
}