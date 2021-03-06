#ifndef PHG4VInnerHcalSteppingAction_h
#define PHG4VInnerHcalSteppingAction_h

#include <g4main/PHG4SteppingAction.h>

class PHG4InnerHcalDetector;
class PHG4Parameters;
class PHG4Hit;
class PHG4HitContainer;
class PHG4Shower;

class PHG4InnerHcalSteppingAction : public PHG4SteppingAction
{

  public:

  //! constructor
  PHG4InnerHcalSteppingAction( PHG4InnerHcalDetector*, PHG4Parameters *parameters );

  //! destroctor
  virtual ~PHG4InnerHcalSteppingAction()
  {}

  //! stepping action
  virtual bool UserSteppingAction(const G4Step*, bool);

  //! reimplemented from base class
  virtual void SetInterfacePointers( PHCompositeNode* );

  double GetLightCorrection(const double r) const;

  void flush_cached_values();

  private:

  void save_previous_g4hit();

  //! pointer to the detector
  PHG4InnerHcalDetector* detector_;

  //! pointer to hit container
  PHG4HitContainer *hits_;
  PHG4HitContainer *absorberhits_;
  PHG4Hit *hit;
  PHG4Parameters *params;
  PHG4HitContainer *savehitcontainer;
  PHG4Shower *saveshower;
  // since getting parameters is a map search we do not want to
  // do this in every step, the parameters used are cached
  // in the following variables
  int save_layer_id;
  int absorbertruth;
  int IsActive;
  int IsBlackHole;
  int light_scint_model;
  
  double light_balance_inner_corr;
  double light_balance_inner_radius;
  double light_balance_outer_corr;
  double light_balance_outer_radius;
};


#endif // PHG4InnerHcalSteppingAction_h
