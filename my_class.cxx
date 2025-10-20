#include "my_class.h"
#include <cmath>

ClassImp(my_class) 

my_class::my_class() 
    : TObject(), px(0), py(0), pz(0), p(0)

{
}

my_class::my_class(Double_t px_, Double_t py_, Double_t pz_) 
    : TObject(), px(px_), py(py_), pz(pz_)

{
   void CalcP();
}

my_class::~my_class(){
}
void my_class::CalcP()
{
    p = std::sqrt(px * px + py * py + pz * pz);
}
