#ifndef __RBHIRATELESCOPE_H
#define __RBHIRATELESCOPE_H

#include <iostream>
#include <stdio.h>

#include <TNamed.h>
#include <TTree.h>

#include <TROOT.h>
#include <TObject.h>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//                                                                       //
// RBHiRATelescope                                                       //
//                                                                       //
// A RBHiRATelescope class derives from RBHiRATelescope.  This Class     //
// provides the structure for a HiRA telescope.  Raw event data is       //
// filled into the class members.                                        //
//                                                                       //
///////////////////////////////////////////////////////////////////////////

static const UShort_t fgNCsICh   = 4;           //! Number of CsI channels (crystals).
static const UShort_t fgNSSDCh   = 32;          //! Number of Silicon Strip Detector channels.

class RBDetector : public TNamed
{
  ClassDef(RBDetector,1);
};

class RBHiRASiDet : public RBDetector{
 public:
  Int_t        fTele;                         // Telescope ID

  vector< vector<int> > testVec;
  //  vector<int> hitStrips;

  //  Double_t     stripThreshold[fgNSSDCh];

  Short_t      fCbSequence;                   //
  Short_t      fChSequence;                   //  MB channel readout sequence. Number of ch's read prior to and including this CB.
  UInt_t       fHitSequence;                  //  CB strips fired. Also can be used as bitmask.

  Short_t      ERawHi[fgNSSDCh];                // Raw energy deposited in a Ef Si strip.
  Short_t      ERawLo[fgNSSDCh];                // Raw energy deposited in a Ef Si strip.
  //  Double_t     EVolt[fgNSSDCh];               // Raw energy signal calibrated quadratically to the pulser data
  //  Double_t     EThreshold[fgNSSDCh];          // Calibrated energy that has been subjected to a threshold
  Short_t      TRaw[fgNSSDCh];                // Raw time values.
  Double_t     EHi[fgNSSDCh];                   // Energy deposited in a Ef Si strip.
  Double_t     ELo[fgNSSDCh];                   // Energy deposited in a Ef Si strip.
  Double_t     T[fgNSSDCh];                   // Time value.
  Double_t     ELoMax;                          // Maximum energy deposited in a Si strip for each telescope.
  Double_t     EHiMax;                          // Maximum energy deposited in a Si strip for each telescope.
  Short_t      ELoMaxCh;                        // Channel number corresponding to the channel with the maximum energy.
  Short_t      EHiMaxCh;                        // Channel number corresponding to the channel with the maximum energy.
  Short_t      fRawMult;                      // Multiplicity of Si for each telescope.
  Short_t      fCalMult;                      // Multiplicity of Si based on EThreshold
  //  Short_t      fCalMult;                      // Multiplicity of thick Si: coincidence of EF and EB 

 public:
  RBHiRASiDet()
  {
     fCbSequence = 0;
     fChSequence = 0;
     fHitSequence =0;

     for(int i = 0; i < fgNSSDCh; ++i)
     {
        ERawHi[i] = 0;
        ERawLo[i]= 0;
        TRaw[i] = 0;
        EHi[i] = 0;
        ELo[i] = 0;
        T[i] = 0;
        
     }

     ELoMax   = 0; 
     EHiMax   = 0; 
     ELoMaxCh = 0; 
     EHiMaxCh = 0; 
     fRawMult = 0; 
     fCalMult = 0; 
     fTele    = -100;

  };
  ~RBHiRASiDet(){};

  void Clear()
  {
     fCbSequence = 0;
     fChSequence = 0;
     fHitSequence =0;

     for(int i = 0; i < fgNSSDCh; ++i)
     {
        ERawHi[i] = 0;
        ERawLo[i]= 0;
        TRaw[i] = 0;
        EHi[i] = 0;
        ELo[i] = 0;
        T[i] = 0;
        
     }

     ELoMax   = 0; 
     EHiMax   = 0; 
     ELoMaxCh = 0; 
     EHiMaxCh = 0; 
     fRawMult = 0; 
     fCalMult = 0; 

  };

  void Print()
  {
     std::cout << "fchsequence " << fCbSequence << "\n";;
     std::cout << "fchsequence " << fChSequence << "\n";
     std::cout << "fhitsequence " << fHitSequence << "\n";;

     for(int i = 0; i < fgNSSDCh; ++i)
     {
        std::cout << "ERaw " << ERawHi[i] << "\n";
        std::cout << "ERAW " << ERawLo[i]<< "\n";
        std::cout << "TRaw " << TRaw[i] << "\n";
        std::cout << "EHi " <<EHi[i] << "\n";
        std::cout << "ELo " <<ELo[i] << "\n";
        std::cout << "T " << T[i] << "\n";
        
     }

     std::cout << "ELoMax " << ELoMax   << "\n"; 
     std::cout << "EHiMax " << EHiMax   << "\n"; 
     std::cout << "ELoMaxCh " << ELoMaxCh << "\n"; 
     std::cout << "EHiMaxCh " << EHiMaxCh << "\n"; 
     std::cout << "fRawMult " << fRawMult << "\n"; 
     std::cout << "fCalMult " << fCalMult << "\n"; 

  };

  RBHiRASiDet& operator=(RBHiRASiDet& other)
  {
     fCbSequence = other.fCbSequence;
     fChSequence = other.fChSequence;
     fHitSequence = other.fHitSequence;

     for(int i = 0; i < fgNSSDCh; ++i)
     {
        ERawHi[i] = other.ERawHi[i];
        ERawLo[i]= other.ERawLo[i];
        TRaw[i] = other.TRaw[i];
        EHi[i] = other.EHi[i];
        ELo[i] = other.ELo[i];
        T[i] = other.T[i];
        
     }

     ELoMax   = other.ELoMax;   
     EHiMax   = other.EHiMax; 
     ELoMaxCh = other.ELoMaxCh;
     EHiMaxCh = other.EHiMaxCh;
     fRawMult = other.fRawMult;
     fCalMult = other.fCalMult;
     return *this;

  }

  ClassDef(RBHiRASiDet,2);     // HiRA Silicon Strip Detector.

};


class RBHiRACsI : public RBDetector{
 public:
  Short_t     ERaw[fgNCsICh];                 //  Energy deposited in a CsI crystal.
  Short_t     TRaw[fgNCsICh];                 //  CsI crystal time signal.
  Double_t    E[fgNCsICh];                    //  Calibrated energy deposited in a CsI crystal.
  Double_t    T[fgNCsICh];                    //  Calibrated time signal.
  Double_t    Emax;                           //  Maximum energy deopsited in the CsI for each telescope.
  Short_t     EmaxCh;                         //  Channel number corresponding to the channel with the maximum energy.
  Short_t     fRawMult;                       //  Multiplicity of CsI for each telescope.

 public:
  RBHiRACsI()
  {
     for(int i = 0; i < fgNCsICh; ++i)
     {
        ERaw[i] = 0;
        TRaw[i] = 0;
        E[i] = 0;
        T[i] = 0;
     }
     Emax = 0;
     EmaxCh = 0;
     fRawMult = 0;
  };
  ~RBHiRACsI() {};

  void Clear()
  {
     for(int i = 0; i < fgNCsICh; ++i)
     {
        ERaw[i] = 0;
        TRaw[i] = 0;
        E[i] = 0;
        T[i] = 0;
     }
     Emax = 0;
     EmaxCh = 0;
     fRawMult = 0;
  };

  void Print()
  {
     for(int i = 0; i < fgNCsICh; ++i)
     {
        std::cout << "ERAW " << ERaw[i] << "\n";
        std::cout << " TRAW " << TRaw[i] << "\n";
        std::cout << " E " << E[i] << "\n";
        std::cout << " T " << T[i] << "\n";
     }
     std::cout << " EMAX " << Emax << "\n";
     std::cout << " EMAXCH " << EmaxCh << "\n";
     std::cout << "FRAWMULT " <<fRawMult << "\n";
  };

  RBHiRACsI& operator=(RBHiRACsI& other)
  {
     for(int i = 0; i < fgNCsICh; ++i)
     {
        ERaw[i] = other.ERaw[i];
        TRaw[i] = other.TRaw[i];
        E[i] = other.E[i];
        T[i] = other.T[i];
     }
     Emax = other.Emax;
     EmaxCh = other.EmaxCh;
     fRawMult = other.fRawMult;
     return *this;
  };
  
  ClassDef(RBHiRACsI,1);     // HiRA CsI.
  
};

class RBHiRATelescope : public RBDetector{
 public:
  Int_t      fHits;                                            //  Number of hits in the telescope.
  //  Int_t      fRealMult;                                        //  Real multiplicity determined by EF-EB comparison

  //  Double_t    EFhitPosition[fgNSSDCh];                         //  Store the hit EF strips of real events
  //Double_t    EBhitPosition[fgNSSDCh];                         //  Store the hit EB strips of real events 
  //Double_t    DEhitPosition[fgNSSDCh];                         //  Store the hit DE strips of real events

  //Initialize detectors inside of each HiRA telescope
  RBHiRASiDet     DE;                                          //||  Si dE member class.
  RBHiRASiDet     EF;                                          //||  Si Ef member class.
  RBHiRASiDet     EB;                                          //||  Si Eb member class.
  RBHiRACsI       CsI;                                         //||  CsI member class.
  double          theta;
  double          phi;

 public:
  RBHiRATelescope() : theta(-1000), phi(-1000){};
  ~RBHiRATelescope() {};

  RBHiRATelescope& operator=(RBHiRATelescope& other)
  {
     DE = other.DE;
     EF = other.EF;
     EB = other.EB;
     CsI = other.CsI;
     theta = other.theta;
     phi = other.phi;
     return *this;
  };

  void Clear()
  {
     DE.Clear();
     EF.Clear();
     EB.Clear();
     CsI.Clear();
     theta = -1000;
     phi = -1000;
  }

  void Print()
  {
    DE.Print();
    EF.Print();
    EB.Print();
    CsI.Print();
    std::cout << "Theta " << theta << "\n";
    std::cout << "Phi " << phi << "\n";
  }


  ClassDef(RBHiRATelescope,2);     // A HiRA telescope.
  
};

#endif
