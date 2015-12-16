void runLatinosTreeScript(Double_t luminosity    = 19.365,
			  Int_t    jetChannel    = 0,
			  TString  flavorChannel = "EMu",
			  TString  theSample     = "WJetsFakes_Total",
			  Bool_t   verbose       = true)
{
  gInterpreter->LoadMacro("LatinosTreeScript.C+");
  //gInterpreter->LoadMacro("LatinosTreeScript.C+");
  gSystem->Load("LatinosTreeScript_C.so");

  LatinosTreeScript(luminosity, jetChannel, flavorChannel, theSample, verbose);
}
