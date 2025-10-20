#ifndef __YOUR_CLASS_H__
#define __YOUR_CLASS_H__
#include <TObject.h>
#include <iostream>
class my_class : public TObject {
public:
    my_class();                 
    my_class(Double_t px, Double_t py, Double_t pz);   
    virtual ~my_class(); 
    
    void CalcP();
    Double_t GetPx() const { return px; }
    Double_t GetPy() const { return py; }
    Double_t GetPz() const { return pz; }
    Double_t GetP() const { return p;}
private:
    Double_t px;
    Double_t py;
    Double_t pz;
    Double_t p;           

    ClassDef(my_class, 1);      
};
#endif // __YOUR_CLASS_H__